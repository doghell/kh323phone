#if !defined(__GETVIDEOSAMPLE_H__)
#define __GETVIDEOSAMPLE_H__


class CUSBVideoCapture;
class CTransGetVideoSample : public CTransInPlaceFilter
{

public:
	CTransGetVideoSample(LPUNKNOWN punk, HRESULT *phr);
	virtual ~CTransGetVideoSample();

	CUSBVideoCapture*		m_pMgr;
public:
	HRESULT Transform(IMediaSample *pSample);
	HRESULT CheckInputType(const CMediaType *mtIn);
};

#endif