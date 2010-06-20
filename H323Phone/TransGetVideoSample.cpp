#include "stdafx.h"
#include "TransGetVideoSample.h"
#include "USBVideoCapture.h"

const _GUID	g_thisNULL_GUID;


CTransGetVideoSample::CTransGetVideoSample(LPUNKNOWN punk, HRESULT *phr)
		: CTransInPlaceFilter(_T("Trans Get Video Sample"), NULL, g_thisNULL_GUID, phr)
{
}

CTransGetVideoSample::~CTransGetVideoSample()
{
}

HRESULT CTransGetVideoSample::CheckInputType(const CMediaType *mtIn)
{
    CheckPointer(mtIn,E_POINTER);

    if (*mtIn->FormatType() != FORMAT_VideoInfo)
    {
        return E_INVALIDARG;
    }

    if( *mtIn->Type( ) != MEDIATYPE_Video )
    {
        return E_INVALIDARG;
    }

	if( *mtIn->Subtype( ) != m_pMgr->GetColorSpaceGUID() )
    {
        return E_INVALIDARG;
    }

    VIDEOINFO *pVI = (VIDEOINFO *) mtIn->Format();
    CheckPointer(pVI,E_UNEXPECTED);

    // Reject negative height bitmaps to prevent drawing upside-down text
	if( pVI->bmiHeader.biHeight != m_pMgr->m_usHeight || pVI->bmiHeader.biWidth != m_pMgr->m_usWidth )
    {
        return E_INVALIDARG;
    }

    return NOERROR;
}

HRESULT CTransGetVideoSample::Transform(IMediaSample *pSample)
{
    CheckPointer(pSample,E_POINTER);

	LPBYTE				pBuffer			= 0;
	VIDEOINFO			*pVI			= (VIDEOINFO*) m_pInput->CurrentMediaType( ).Format( );

    CheckPointer(pVI,E_UNEXPECTED);
	pSample->GetPointer( &pBuffer );

	if (m_pMgr)
	{
		if(m_pMgr->OnVideoData((char *)pBuffer, pVI->bmiHeader.biSizeImage) == false)
		{
			return S_FALSE;
		}
	}

    return NOERROR;
}