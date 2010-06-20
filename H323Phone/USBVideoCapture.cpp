#include "StdAfx.h"
#include ".\usbvideocapture.h"

HRESULT InitCaptureGraphBuilder(IGraphBuilder **ppGraph,ICaptureGraphBuilder2 **ppBuild)
{
	if (!ppGraph || !ppBuild)
	{
		return E_POINTER;
	}

	IGraphBuilder *pGraph = NULL;
	ICaptureGraphBuilder2 *pBuild = NULL;

	HRESULT hr = CoCreateInstance(CLSID_CaptureGraphBuilder2, NULL, 
		CLSCTX_INPROC_SERVER, IID_ICaptureGraphBuilder2, (void**)&pBuild);
	if (SUCCEEDED(hr))
	{
		hr = CoCreateInstance(CLSID_FilterGraph, 0, CLSCTX_INPROC_SERVER,
			IID_IGraphBuilder, (void**)&pGraph);
		if (SUCCEEDED(hr))
		{
			pBuild->SetFiltergraph(pGraph);

			*ppBuild = pBuild;
			*ppGraph = pGraph;
			return S_OK;
		}
		else
		{
			pBuild->Release();
		}
	}
	return hr;
}

HRESULT FindCaptureDevice(int iDeviceid,IBaseFilter ** ppSrcFilter)
{
	HRESULT hr;
	IBaseFilter * pSrc = NULL;
	CComPtr <IMoniker> pMoniker = NULL;
	ULONG cFetched = NULL;

	if (!ppSrcFilter)
		return E_POINTER;

	CComPtr <ICreateDevEnum> pDevEnum =NULL;

	hr = CoCreateInstance (CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC,
		IID_ICreateDevEnum, (void **) &pDevEnum);
	if (FAILED(hr))
	{
		return hr;
	}

	CComPtr <IEnumMoniker> pClassEnum = NULL;

	hr = pDevEnum->CreateClassEnumerator (CLSID_VideoInputDeviceCategory, &pClassEnum, 0);
	if (FAILED(hr))
	{
		return hr;
	}

	if (pClassEnum == NULL)
	{
		return E_FAIL;
	}

	for(int i = 0; i <= iDeviceid; i++)
	{
		hr = pClassEnum->Next (1, &pMoniker.p, &cFetched);
	}

	if (S_OK == hr)
	{
		hr = pMoniker->BindToObject(0,0,IID_IBaseFilter, (void**)&pSrc);
		if (FAILED(hr))
		{
			return hr;
		}
	}
	else
	{
		return E_FAIL;
	}

	*ppSrcFilter = pSrc;

	return hr;
}

CUSBVideoCapture::CUSBVideoCapture(CUSBVideoCaptureNotify& rNotify)
: m_pGrabber(NULL)
, m_ColorSpaceType(COLOR_SPACE_TYPE_COUNT)
, m_usWidth(0)
, m_usHeight(0)
, m_hWnd(NULL)
, m_ucFrameRate(0)
, m_nDevice(0)
, m_rNotify(rNotify)
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&m_Freg);
	m_Freg /=5;
	m_OldCnt = 0;
	m_CurCnt = 0;
	m_MoreTime = 0;
}

CUSBVideoCapture::~CUSBVideoCapture(void)
{
}

bool CUSBVideoCapture::Connect(HWND hWnd,int nDevice,unsigned short usWidth,unsigned short usHeight,unsigned char ucFrameRate)
{
	m_usWidth = usWidth;
	m_usHeight = usHeight;
	m_ucFrameRate = ucFrameRate;
	m_nDevice = nDevice;
	m_hWnd = hWnd;

	HRESULT hr = InitCaptureGraphBuilder(&m_pGraph,&m_pBuild);
	if(FAILED(hr))
	{
		return false;
	}

	InitVMR();

	hr = FindCaptureDevice(nDevice,&m_pCap);
	if(FAILED(hr))
	{
		return false;
	}

	hr = m_pGraph->AddFilter(m_pCap,L"Video Capture");
	if(FAILED(hr)) 
	{
		return false;
	}

	hr = SetVideoCapFormat(m_usWidth,m_usHeight,m_ucFrameRate,COLOR_SPACE_TYPE_I420);
	if(FAILED(hr))
	{	
		hr = SetVideoCapFormat(m_usWidth,m_usHeight,m_ucFrameRate,COLOR_SPACE_TYPE_YUY2);
		if(FAILED(hr))
		{
			hr = SetVideoCapFormat(m_usWidth,m_usHeight,m_ucFrameRate,COLOR_SPACE_TYPE_RGB24);
			if(FAILED(hr))
			{
				return false;
			}
			else
			{
				m_ColorSpaceType = COLOR_SPACE_TYPE_RGB24;
			}
		}
		else
		{
			m_ColorSpaceType = COLOR_SPACE_TYPE_YUY2;
		}
	}
	else
	{
		m_ColorSpaceType = COLOR_SPACE_TYPE_I420;
	}

	m_pGrabber	= new CTransGetVideoSample(m_pCap, &hr);
	m_pGrabber->m_pMgr = this;

	m_pGrabber->AddRef();

	hr = m_pGraph->AddFilter(m_pGrabber, NULL);
	if(FAILED(hr))
	{
		return false;
	}

	hr = m_pBuild->RenderStream(&PIN_CATEGORY_CAPTURE, &MEDIATYPE_Video,m_pCap, m_pGrabber, m_pVMR9Renderer);
	if(FAILED(hr)) 
	{
		return false;
	}

	hr = m_pGraph->QueryInterface(IID_IMediaControl, (void **)&this->m_pControl);
	if(FAILED(hr)) 
	{
		return false;
	}

	if(m_pWC)
	{	
		RECT rcDest;
		GetClientRect(m_hWnd,&rcDest);
		m_pWC->SetVideoPosition(NULL, &rcDest);
	}
	else
	{
		if(SUCCEEDED(m_pGraph->QueryInterface(IID_IVideoWindow,(void **)&this->m_pVW)))
		{
			if(m_hWnd)
			{
				RECT rcClient;
				GetClientRect(m_hWnd,&rcClient);
				m_pVW->put_Owner((OAHWND)m_hWnd);    // We own the window now
				m_pVW->put_MessageDrain((OAHWND)m_hWnd);
				m_pVW->put_WindowStyle(WS_CHILD | WS_CLIPCHILDREN | WS_CLIPSIBLINGS);    // you are now a child
				m_pVW->SetWindowPosition(0, 0, rcClient.right, rcClient.bottom); // be this big
				m_pVW->put_Visible(OATRUE);
			}
		}
	}
	QueryPerformanceFrequency((LARGE_INTEGER*)&m_Freg);
	m_Freg /= m_ucFrameRate;
	m_CurCnt=0;
	m_OldCnt=0;
	m_MoreTime=0;

	if(m_pControl )
	{
		m_pControl->Run();
	}

	return 	true;
}

bool CUSBVideoCapture::InitVMR()
{
    // Create the VMR and add it to the filter graph.
    HRESULT hr = CoCreateInstance(CLSID_VideoMixingRenderer9, NULL,
                                  CLSCTX_INPROC, IID_IBaseFilter, (void**)&m_pVMR9Renderer);
    if (SUCCEEDED(hr)) 
    {
        hr = m_pGraph->AddFilter(m_pVMR9Renderer, L"Video Mixing Renderer9");
        if (SUCCEEDED(hr)) 
        {
            // Set the rendering mode and number of streams.  
            CComPtr<IVMRFilterConfig9> pConfig;
            hr = m_pVMR9Renderer->QueryInterface(IID_IVMRFilterConfig9, (void**)&pConfig);
            if( SUCCEEDED(hr)) 
            {
                if(FAILED(pConfig->SetRenderingMode(VMRMode_Windowless)))
				{
					return false;
				}
            }

            hr = m_pVMR9Renderer->QueryInterface(IID_IVMRWindowlessControl9, (void**)&m_pWC);
            if( SUCCEEDED(hr)) 
            {
                if(FAILED(m_pWC->SetVideoClippingWindow(m_hWnd)))
				{
					return false;
				}
            }
			return true;
		}
	}
	return false;
}

void CUSBVideoCapture::ReleaseConnections(void)
{
	StopVideoCapture();

	m_ColorSpaceType = COLOR_SPACE_TYPE_COUNT;
	m_usWidth = 0;
	m_usHeight = 0;
	m_ucFrameRate = 0;
	m_nDevice = 0;
	m_hWnd = NULL;
}

void CUSBVideoCapture::ShowProperty()
{
	if(m_pCap == NULL)
	{
		return;
	}
	ISpecifyPropertyPages *pProperty = NULL;
	HRESULT hr = m_pCap->QueryInterface(IID_ISpecifyPropertyPages,(void **)&pProperty);
	if(FAILED(hr))
		return ;

	CAUUID cauid;
	if(pProperty)
	{
		pProperty->GetPages(&cauid);
		OleCreatePropertyFrame(m_hWnd,0,0,NULL,1,(IUnknown**)&pProperty,cauid.cElems,(GUID*)cauid.pElems,0,0,NULL);
		pProperty->Release();
	}
}

void CUSBVideoCapture::SetVideoWindowPosition(int x,int y,int width,int height)
{
	if(m_pWC)
	{	
		RECT rcDest;
		rcDest.left = x;
		rcDest.top = y;
		rcDest.right = x + width;
		rcDest.bottom = y + height;
		m_pWC->SetVideoPosition(NULL, &rcDest);
	}
	else 
	{
		if(m_pVW)
		{
			m_pVW->SetWindowPosition(x, y, width, height); // be this big
		}
	}
}

HRESULT CUSBVideoCapture::SetVideoCapFormat(unsigned short usWidth,unsigned short usHeight,unsigned char ucFrameRate,COLOR_SPACE_TYPE nColorSpace)
{
	GUID subtype = MEDIASUBTYPE_I420;
	if(nColorSpace == COLOR_SPACE_TYPE_I420)
	{
		subtype = MEDIASUBTYPE_I420;
	}
	else if(nColorSpace == COLOR_SPACE_TYPE_RGB24)
	{
		subtype = MEDIASUBTYPE_RGB24;
	}
	else if(nColorSpace == COLOR_SPACE_TYPE_YUY2)
	{
		subtype = MEDIASUBTYPE_YUY2;
	}
	else
	{
		return E_FAIL;
	}

	CComPtr<IAMStreamConfig>	pConfig;

	HRESULT hr = m_pBuild->FindInterface(&PIN_CATEGORY_CAPTURE,&MEDIATYPE_Video,m_pCap,IID_IAMStreamConfig,(void **)&pConfig);
	if(FAILED(hr))
	{
		return hr ;
	}

	int iCount = 0, iSize = 0;
	hr = pConfig->GetNumberOfCapabilities(&iCount, &iSize);
	if (iSize == sizeof(VIDEO_STREAM_CONFIG_CAPS))
	{
		for (int iFormat = 0; iFormat < iCount; iFormat++)
		{
			VIDEO_STREAM_CONFIG_CAPS scc;
			AM_MEDIA_TYPE *pmtConfig;
			hr = pConfig->GetStreamCaps(iFormat, &pmtConfig, (BYTE*)&scc);
			if (SUCCEEDED(hr))
			{
				if(MEDIATYPE_Video == pmtConfig->majortype)
				{
					if(pmtConfig->subtype == subtype && \
						pmtConfig->cbFormat >= sizeof(VIDEOINFOHEADER) && \
						pmtConfig->pbFormat != 0 && \
						pmtConfig->formattype == FORMAT_VideoInfo)
					{
						VIDEOINFOHEADER *pHeader = reinterpret_cast<VIDEOINFOHEADER*>(pmtConfig->pbFormat);
						if(pHeader->bmiHeader.biWidth == usWidth && pHeader->bmiHeader.biHeight == usHeight)
						{
							pHeader->AvgTimePerFrame = (LONGLONG)(10000000/ucFrameRate);//
							hr = pConfig->SetFormat( pmtConfig );
							return hr;
						}
					}	
				}
			}
		}
	}

	return E_FAIL;
}

void CUSBVideoCapture::RepaintVideo(HWND hWnd,HDC hDC)
{
	if(m_pWC)
	{
		m_pWC->RepaintVideo(hWnd,hDC);
	}
}

GUID CUSBVideoCapture::GetColorSpaceGUID(void)
{
	GUID subtype = MEDIASUBTYPE_I420;
	if(m_ColorSpaceType == COLOR_SPACE_TYPE_I420)
	{
		subtype = MEDIASUBTYPE_I420;
	}
	else if(m_ColorSpaceType == COLOR_SPACE_TYPE_RGB24)
	{
		subtype = MEDIASUBTYPE_RGB24;
	}
	else if(m_ColorSpaceType == COLOR_SPACE_TYPE_YUY2)
	{
		subtype = MEDIASUBTYPE_YUY2;
	}
	return subtype;
}

bool CUSBVideoCapture::OnVideoData(char * szData, long lLen)
{	
	QueryPerformanceCounter((LARGE_INTEGER*)&m_CurCnt);
	if((m_CurCnt - m_OldCnt) >= m_Freg)
	{
		if (m_OldCnt == 0)//如果第一次执行，多余的时间间隔为0
		{
			m_MoreTime = 0;
		}
		else
		{
			m_MoreTime = m_CurCnt - m_OldCnt - m_Freg;//计算多余的时间间隔
		}	

		OnVideoCaptureFrame(szData,lLen,m_ColorSpaceType);

		m_OldCnt = m_CurCnt - m_MoreTime;//将多余的时间间隔弥补上

		return true;
	}
	return false;
}

void CUSBVideoCapture::StopVideoCapture(void)
{
	HRESULT hr;
	OAFilterState state;
	if(m_pControl)
	{
		hr = m_pControl->GetState(INFINITE , &state);
		if(FAILED(hr))
			return;
		if(state != State_Stopped)
			m_pControl->Stop();
		m_pControl = NULL;
	}
	if(m_pVW)
	{
		m_pVW->put_Visible(OAFALSE);
		m_pVW->put_Owner(NULL);
		m_pVW->put_Visible(OAFALSE);
		m_pVW = NULL;
	}
	
	m_pWC = NULL;
	m_pVMR9Renderer = NULL;
	m_pCap = NULL;
	m_pBuild = NULL;
	m_pGraph = NULL;
	if(m_pGrabber)
	{
		m_pGrabber->Release();
		m_pGrabber = NULL;
	}
}

bool CUSBVideoCapture::ConvertToI420(unsigned short usWidth,unsigned short usHeight,const void* pFrameData,int nFrameLen,COLOR_SPACE_TYPE nColorSpaceType,unsigned char** ppOutData,int& nOutLen)
{
	bool bRet = false;
	*ppOutData = NULL;
	nOutLen = 0;
	do
	{
		if(nColorSpaceType == COLOR_SPACE_TYPE_RGB24)
		{
			*ppOutData = new unsigned char[usWidth * usHeight * 3 / 2];
			if(*ppOutData == NULL)
			{
				break;
			}

			if(CColorSpaceConvert::RGB24_To_I420(*ppOutData,(unsigned char*)pFrameData,usWidth,usHeight) == false)
			{
				delete []*ppOutData;
				*ppOutData = NULL;
				break;
			}
			nOutLen = usWidth * usHeight * 3 / 2;
			bRet = true;
		}
		else if(nColorSpaceType == COLOR_SPACE_TYPE_YUY2)
		{
			*ppOutData = new unsigned char[usWidth * usHeight * 3 / 2];
			if(*ppOutData == NULL)
			{
				break;
			}

			if(CColorSpaceConvert::YUY2_To_I420(*ppOutData,(unsigned char*)pFrameData,usWidth,usHeight,false) == false)
			{
				delete []*ppOutData;
				*ppOutData = NULL;
				break;
			}
			nOutLen = usWidth * usHeight * 3 / 2;
			bRet = true;
		}

	}while(0);
	return bRet;
}

void CUSBVideoCapture::OnVideoCaptureFrame(const void* pFrameData,int nFrameLen,COLOR_SPACE_TYPE nColorSpaceType)
{
	unsigned char* pSrcFrameData = (unsigned char*)pFrameData;
	int nSrcLen = nFrameLen;
		
	bool bConvert = false;
	if(nColorSpaceType != COLOR_SPACE_TYPE_I420)
	{
		if(ConvertToI420(m_usWidth,m_usHeight,pFrameData,nFrameLen,nColorSpaceType,&pSrcFrameData,nSrcLen) == false)
		{
			return;
		}
		bConvert = true;
	}
	m_rNotify.OnVideoCaptureFrame(pSrcFrameData,nSrcLen);

	if(bConvert && pSrcFrameData)
	{
		delete []pSrcFrameData;
		pSrcFrameData = NULL;
	}
}