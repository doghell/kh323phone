#include "StdAfx.h"
#include ".\videofilter.h"

struct _GUID g_guidVideoNULL;

VideoFilter::VideoFilter(void)
:CBaseFilter(NAME("AV Video Filter"), NULL, this, g_guidVideoNULL)
,m_VideoOutputPin(NAME("Video Output"), this, NULL, L"Video Output")
{
}

VideoFilter::~VideoFilter(void)
{
}

CBasePin *VideoFilter::GetPin(int n)
{
	if (n!=0)
		return NULL;

	return &m_VideoOutputPin;
}

int VideoFilter::GetPinCount()
{
	return 1;
}

bool VideoFilter::DeliverData(char*szData,int nLen,unsigned long ulTimeStamp)
{
	return m_VideoOutputPin.DeliverData(szData,nLen,ulTimeStamp);
}

// 设置输出视频帧格式
bool VideoFilter::SetOutputMediaType(int nWidht,int nHeight)
{
	m_GUID = MEDIASUBTYPE_I420;

	ZeroMemory(&m_MediaType,sizeof(BITMAPINFOHEADER));
	m_MediaType.biSize = sizeof(BITMAPINFOHEADER);
	m_MediaType.biWidth = nWidht;
	m_MediaType.biHeight = nHeight;
	m_MediaType.biPlanes = 1;
	m_MediaType.biBitCount = 12;
	m_MediaType.biCompression = mmioFOURCC('I','4','2','0');
	m_MediaType.biSizeImage = m_MediaType.biWidth * m_MediaType.biHeight * 3 / 2;

	return true;
}
