#pragma once
#include "VideoFilter.h"

class CRawVideoPlay
{
public:
	CRawVideoPlay(void);
	virtual ~CRawVideoPlay(void);
public:
	bool Connect(HWND hWnd,unsigned short usWidth,unsigned short usHeight);
	void ReleaseConnections(void);
	void SetVideoWindowPosition(int x,int y,int width,int height);
	void PlayVideo(unsigned char* pData,int nLen);
	void RepaintVideo(HWND hWnd,HDC hDC);
	bool IsWantCreateVideoPlay(unsigned short usWidth,unsigned short usHeight);
	bool InitVMR(HWND hWnd);
	bool ResetRawVideoPlay(unsigned short usWidth,unsigned short usHeight);
protected:
	HWND		m_hWnd;
private:
	CComPtr<IGraphBuilder>	m_pGraph;
	CComPtr<IMediaControl>	m_pControl;
	CComPtr<IVideoWindow>	m_pVW;
	CComPtr<IVMRWindowlessControl9> m_pWC;

	VideoFilter *m_pSourceFilter;
	unsigned short m_usPlayWidth;
	unsigned short m_usPlayHeight;
	bool m_bReady;
};
