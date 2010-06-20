#pragma once

typedef enum
{
	COLOR_SPACE_TYPE_I420 = 0,
	COLOR_SPACE_TYPE_RGB24,
	COLOR_SPACE_TYPE_YUY2,
	COLOR_SPACE_TYPE_YV12,
	COLOR_SPACE_TYPE_COUNT,

}COLOR_SPACE_TYPE;

class CUSBVideoCaptureNotify
{
public:
	virtual void OnVideoCaptureFrame(const void* pFrameData,int nFrameLen)=0;
};

#include "TransGetVideoSample.h"
#include "ColorSpaceConvert.h"

class CUSBVideoCapture
	: public CColorSpaceConvert
{
public:
	CUSBVideoCapture(CUSBVideoCaptureNotify& rNotify);
	virtual ~CUSBVideoCapture(void);
public:
	bool Connect(HWND hWnd,int nDevice,unsigned short usWidth,unsigned short usHeight,unsigned char ucFrameRate);
	void ReleaseConnections(void);
	bool InitVMR();
	void ShowProperty();
	void SetVideoWindowPosition(int x,int y,int width,int height);
	HRESULT SetVideoCapFormat(unsigned short usWidth,unsigned short usHeight,unsigned char ucFrameRate,COLOR_SPACE_TYPE nColorSpace);
	void RepaintVideo(HWND hWnd,HDC hDC);
	GUID GetColorSpaceGUID(void);
	bool OnVideoData(char * szData, long lLen);
	void StopVideoCapture(void);
	bool ConvertToI420(unsigned short usWidth,unsigned short usHeight,const void* pFrameData,int nFrameLen,COLOR_SPACE_TYPE nColorSpaceType,unsigned char** ppOutData,int& nOutLen);
	void OnVideoCaptureFrame(const void* pFrameData,int nFrameLen,COLOR_SPACE_TYPE nColorSpaceType);
private:
	CComPtr<IGraphBuilder>	m_pGraph;
	CComPtr<ICaptureGraphBuilder2>	m_pBuild;
	CComPtr<IBaseFilter>	m_pCap;
	CComPtr<IMediaControl>	m_pControl;
	CComPtr<IVideoWindow>	m_pVW;
	CComPtr<IBaseFilter>	m_pVMR9Renderer;
	CComPtr<IVMRWindowlessControl9> m_pWC;

	CTransGetVideoSample	*m_pGrabber;
	__int64 m_Freg;
	__int64 m_OldCnt, m_CurCnt;
	__int64	m_MoreTime;
public:
	COLOR_SPACE_TYPE m_ColorSpaceType;
	unsigned short m_usWidth;
	unsigned short m_usHeight;
	unsigned char m_ucFrameRate;

	int	m_nDevice;
	HWND m_hWnd;
	CUSBVideoCaptureNotify& m_rNotify;
};
