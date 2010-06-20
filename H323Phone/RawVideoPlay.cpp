#include "StdAfx.h"
#include "RawVideoPlay.h"

CRawVideoPlay::CRawVideoPlay(void)
: m_pControl(NULL)
, m_pGraph(NULL)
, m_pVW(NULL)
, m_pWC(NULL)
, m_pSourceFilter(NULL)
, m_hWnd(NULL)
, m_usPlayWidth(0)
, m_usPlayHeight(0)
, m_bReady(false)
{
}

CRawVideoPlay::~CRawVideoPlay(void)
{
}

bool CRawVideoPlay::Connect(HWND hWnd,unsigned short usWidth,unsigned short usHeight)
{
	HRESULT hr;
	hr = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC, IID_IGraphBuilder, (void**)&m_pGraph);
	if (FAILED(hr))
	{
		return false;
	}
	
	InitVMR(hWnd);
	
	CComPtr<IMediaFilter>	graphF;
	hr = m_pGraph->QueryInterface(IID_IMediaFilter, (void **) &graphF);
	if (FAILED(hr))
	{
		return false;
	}

	hr = graphF->SetSyncSource(NULL);
	if (FAILED(hr))
	{
		return false;
	}

	m_pSourceFilter	= new VideoFilter();
	if (!m_pSourceFilter)
	{
		return false;
	}
	
	m_pSourceFilter->AddRef();
	if(m_pSourceFilter->SetOutputMediaType(usWidth,usHeight) == false)
	{
		return false;
	}
	
	hr = m_pGraph->AddFilter(m_pSourceFilter, NULL);
	if (FAILED(hr))
	{
		return false;
	}

	hr = m_pGraph->Render(&m_pSourceFilter->m_VideoOutputPin);
	if (FAILED(hr))
	{
		return false;
	}

	hr = m_pGraph->QueryInterface(IID_IMediaControl, (void **)&this->m_pControl);
	if(FAILED(hr)) 
	{
		return false;
	}

	hr = m_pGraph->QueryInterface(IID_IVideoWindow,(void **)&this->m_pVW);
	if(FAILED(hr)) 
	{
		return false;
	}

	if(m_pWC)
	{
		RECT rcDest;
		GetClientRect(hWnd,&rcDest);
		m_pWC->SetVideoPosition(NULL, &rcDest);
	}
	else
	{
		m_pVW->put_Owner((OAHWND)hWnd);    // We own the window now
		hr = m_pVW->put_MessageDrain((OAHWND)hWnd);
		if(FAILED(hr)) 
		{
			return false;
		}
		m_pVW->put_WindowStyle(WS_CHILD| WS_CLIPSIBLINGS | WS_CLIPCHILDREN);    // you are now a child
		RECT rcDest;
		GetClientRect(hWnd,&rcDest);
		m_pVW->SetWindowPosition(0,0,rcDest.right - rcDest.left,rcDest.bottom - rcDest.top);
		m_pVW->put_Visible(OATRUE);
	}

	hr = m_pControl->Run();
	if(FAILED(hr))
	{
		return false;
	}

	m_usPlayWidth = usWidth;
	m_usPlayHeight = usHeight;

	m_bReady = true;
	return true;
}

bool CRawVideoPlay::InitVMR(HWND hWnd)
{
     CComPtr<IBaseFilter> pVmr;

    // Create the VMR and add it to the filter graph.
    HRESULT hr = CoCreateInstance(CLSID_VideoMixingRenderer9, NULL,
                                  CLSCTX_INPROC, IID_IBaseFilter, (void**)&pVmr);
    if (SUCCEEDED(hr)) 
    {
        hr = m_pGraph->AddFilter(pVmr, L"Video Mixing Renderer9");
        if (SUCCEEDED(hr)) 
        {
            // Set the rendering mode and number of streams.  
            CComPtr<IVMRFilterConfig9> pConfig;
            hr = pVmr->QueryInterface(IID_IVMRFilterConfig9, (void**)&pConfig);
            if( SUCCEEDED(hr)) 
            {
               if(FAILED(pConfig->SetRenderingMode(VMRMode_Windowless)))
			   {
				   return false;
			   }
            }

            hr = pVmr->QueryInterface(IID_IVMRWindowlessControl9, (void**)&m_pWC);
            if( SUCCEEDED(hr)) 
            {
                if(FAILED(m_pWC->SetVideoClippingWindow(hWnd)))
				{
					return false;
				}
            }

			return true;
		}
        //pVmr->Release();
	}
	return false;
}

void CRawVideoPlay::SetVideoWindowPosition(int x,int y,int width,int height)
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
	else if(m_pVW)
	{
		m_pVW->SetWindowPosition(x, y, width, height); // be this big
		m_pVW->put_Visible(OATRUE);
	}
}

void CRawVideoPlay::PlayVideo(unsigned char* pData,int nLen)
{
	if(m_bReady == false)
	{
		return;
	}

	if (!pData || nLen<=0 || m_pSourceFilter==NULL)
		return;

	m_pSourceFilter->DeliverData((char*)pData,nLen,GetTickCount());
}

void CRawVideoPlay::ReleaseConnections(void)
{
	m_bReady = false;

	if(m_pControl)
	{
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
	m_pGraph = NULL;
	if(m_pSourceFilter)
	{
		m_pSourceFilter->Release();
		//delete m_pSourceFilter;
		m_pSourceFilter = NULL;
	}

	m_usPlayWidth = 0;
	m_usPlayHeight = 0;
}

void CRawVideoPlay::RepaintVideo(HWND hWnd,HDC hDC)
{
	if(m_pWC)
	{
		m_pWC->RepaintVideo(hWnd,hDC);
	}
}

bool CRawVideoPlay::IsWantCreateVideoPlay(unsigned short usWidth,unsigned short usHeight)
{
	if(m_usPlayWidth != usWidth || m_usPlayHeight != usHeight)
	{
		return true;
	}
	return false;
}

bool CRawVideoPlay::ResetRawVideoPlay(unsigned short usWidth,unsigned short usHeight)
{
	if(IsWantCreateVideoPlay(usWidth,usHeight))
	{
		ReleaseConnections();
	}
	if(Connect(m_hWnd,usWidth,usHeight) == false)
	{
		ReleaseConnections();
		return false;
	}
	return true;
}