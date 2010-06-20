// VideoOutputPin.h: interface for the VideoOutputPin class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __VIDEOOUTPUTPIN_H__
#define __VIDEOOUTPUTPIN_H__


class VideoFilter;
class VideoOutputPin : public CBaseOutputPin  
{
public:
	VideoOutputPin(TCHAR *pObjName,VideoFilter *pVideoFilter,HRESULT *phr,LPCWSTR pPinName);
	~VideoOutputPin();
public:
    // Check that we can support an output type
    HRESULT CheckMediaType(const CMediaType *pMediaType);
	HRESULT GetMediaType(int iPosition, CMediaType *pMediaType);

    // Negotiation to use our input pins allocator
    HRESULT DecideBufferSize(IMemAllocator *pAlloc,ALLOCATOR_PROPERTIES *pProperties);

	bool DeliverData(char*szData,int nLen);
	bool DeliverData(char*szData,int nLen,unsigned long ulTimeStamp);
protected:
    VideoFilter*		m_pVideoFilter;                  // Main filter object pointer
    friend class VideoFilter;
	bool				m_bDiscontinuity;
	DWORD				m_dwStartTimeStamp;
	DWORD				m_dwLastTimeStamp;
};

#endif 