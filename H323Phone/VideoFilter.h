#pragma once

#include "VideoOutputPin.h"

class VideoFilter :
	public CCritSec, 
	public CBaseFilter
{
public:
	CBasePin *GetPin(int n);
	int GetPinCount();

public:
	VideoFilter(void);
	~VideoFilter(void);

	bool DeliverData(char*szData,int nLen,unsigned long ulTimeStamp);

public:	
	VideoOutputPin		m_VideoOutputPin;
	BITMAPINFOHEADER m_MediaType;
	GUID				m_GUID;
public:
	
	bool SetOutputMediaType(int nWidht,int nHeight);
};
