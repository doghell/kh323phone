// VideoOutputPin.cpp: implementation of the VideoOutputPin class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "VideoOutputPin.h"
#include "VideoFilter.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#define MAX_VIDEO_SAMPLE_SIZE		1024*1024*4

VideoOutputPin::VideoOutputPin(TCHAR *pObjName,VideoFilter *pVideoFilter,HRESULT *phr,LPCWSTR pPinName)
:CBaseOutputPin(pObjName, pVideoFilter, pVideoFilter, phr, pPinName)
,m_pVideoFilter(pVideoFilter)
,m_bDiscontinuity(true)
,m_dwStartTimeStamp(0)
,m_dwLastTimeStamp(0)
{

}

VideoOutputPin::~VideoOutputPin()
{

}

//
// DecideBufferSize
//
// This has to be present to override the PURE virtual class base function
//
HRESULT VideoOutputPin::DecideBufferSize(IMemAllocator *pAlloc,ALLOCATOR_PROPERTIES *pProperties)
{
	HRESULT hr;
	ALLOCATOR_PROPERTIES Actual;

	pProperties->cBuffers = 1;
	pProperties->cbBuffer = MAX_VIDEO_SAMPLE_SIZE;

	hr = pAlloc->SetProperties(pProperties, &Actual);
	if (FAILED(hr)) {
		return hr;
	}

	// verify that the allocator is able to allocate what requested
	if (Actual.cbBuffer < pProperties->cbBuffer) {
		return E_FAIL;
	}

	return S_OK;
} // DecideBufferSize

//
// CheckMediaType
//
HRESULT VideoOutputPin::CheckMediaType(const CMediaType *pMediaType)
{
	 CheckPointer(pMediaType,E_POINTER);

    // we only want fixed size video
    //
    if( *(pMediaType->Type()) != MEDIATYPE_Video ) 
    {
        return E_INVALIDARG;
    }
    if( !pMediaType->IsFixedSize( ) ) 
    {
        return E_INVALIDARG;
    }
    if( *pMediaType->Subtype( ) !=  m_pVideoFilter->m_GUID)
    {
        return E_INVALIDARG;
    }
    if( *pMediaType->FormatType( ) != FORMAT_VideoInfo )
    {
        return E_INVALIDARG;
    }

    // Get the format area of the media type
    //
    VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) pMediaType->Format();

    if (pvi == NULL)
    {
        return E_INVALIDARG;
    }

    if( pvi->bmiHeader.biHeight < 0 )
    {
        return E_INVALIDARG;
    }

    return S_OK;
} // CheckMediaType

//
// GetMediaType
//
// I support one type, namely the type of the input pin
// We must be connected to support the single output type
//
HRESULT VideoOutputPin::GetMediaType(int iPosition, CMediaType *pMediaType)
{
    if (iPosition < 0) {
        return E_INVALIDARG;
    }

    // Have we run off the end of types

    if (iPosition > 0) {
        return VFW_S_NO_MORE_ITEMS;
    }

	VIDEOINFOHEADER thisVideoInfoHeader;
	ZeroMemory(&thisVideoInfoHeader,sizeof(VIDEOINFOHEADER));
	memcpy(&thisVideoInfoHeader.bmiHeader,&m_pVideoFilter->m_MediaType,sizeof(BITMAPINFOHEADER));
	pMediaType->SetType(&MEDIATYPE_Video);
	pMediaType->SetFormatType(&FORMAT_VideoInfo);
	pMediaType->SetFormat( (BYTE*) &thisVideoInfoHeader, sizeof( thisVideoInfoHeader ) );
	pMediaType->SetSubtype(&m_pVideoFilter->m_GUID);
	pMediaType->SetSampleSize(thisVideoInfoHeader.bmiHeader.biSizeImage);

    return NOERROR;
} // GetMediaType

bool VideoOutputPin::DeliverData(char*szData,int nLen)
{
	if (nLen >= MAX_VIDEO_SAMPLE_SIZE)
		return false;

	IMediaSample* pSample=NULL;
	PBYTE pbDeliveryBuffer=NULL;

	GetDeliveryBuffer(&pSample,NULL,NULL,0);
	if (!pSample)
		return false;

	pSample->GetPointer(&pbDeliveryBuffer); 
	memcpy(pbDeliveryBuffer,szData,nLen);

	pSample->SetActualDataLength(nLen);

	if (m_bDiscontinuity)
	{
		m_bDiscontinuity=false;

		BeginFlush();
		EndFlush();
		NewSegment(0, 0x7F00000000000000, 1.0) ;
		pSample->SetDiscontinuity(TRUE);
	}

	pSample->SetTime(NULL,NULL);

	Deliver(pSample);

	pSample->Release();

	return true;
}

bool VideoOutputPin::DeliverData(char*szData,int nLen,unsigned long ulTimeStamp)
{
	if (nLen >= MAX_VIDEO_SAMPLE_SIZE)
		return false;

	IMediaSample* pSample=NULL;
	PBYTE pbDeliveryBuffer=NULL;

	if (m_dwStartTimeStamp==0)
	{
		m_dwStartTimeStamp=ulTimeStamp;
	}

	HRESULT hr = GetDeliveryBuffer(&pSample,NULL,NULL,0);
	if (!pSample)
		return false;


	pSample->GetPointer(&pbDeliveryBuffer); 
	memcpy(pbDeliveryBuffer,szData,nLen);

	pSample->SetActualDataLength(nLen);

	pSample->SetSyncPoint(TRUE);

	LONGLONG llTimeStart=(ulTimeStamp-m_dwStartTimeStamp)*10000;
	LONGLONG llTimeEnd=llTimeStart+1;
	
	m_bDiscontinuity=(ulTimeStamp-m_dwLastTimeStamp>1000);

	if (m_bDiscontinuity)
	{
		m_bDiscontinuity=false;

		BeginFlush();
		EndFlush();
		NewSegment(0, 0x7F00000000000000, 1.0) ;
		pSample->SetDiscontinuity(TRUE);
	}

	pSample->SetTime(&llTimeStart,&llTimeEnd);

	Deliver(pSample);

	pSample->Release();

	m_dwLastTimeStamp=ulTimeStamp;

	return true;
}
