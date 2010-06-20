#include "StdAfx.h"
#include ".\videoinputdevice_openmcu.h"
#include "MyH323.h"

#define CIF_WIDTH     352
#define CIF_HEIGHT    288
#define CIF_SIZE      (CIF_WIDTH*CIF_HEIGHT*3/2)

#define QCIF_WIDTH    (CIF_WIDTH / 2)
#define QCIF_HEIGHT   (CIF_HEIGHT / 2)
#define QCIF_SIZE     (QCIF_WIDTH*QCIF_HEIGHT*3/2)

CVideoInputDevice_OpenMCU::CVideoInputDevice_OpenMCU(CMyH323EndPoint & ep, H323Connection & _conn)
: m_ep(ep)
, conn(_conn)
{
	SetColourFormat("YUV420P");
	channelNumber = 0; 
	grabCount = 0;
	SetFrameRate(25);
}

CVideoInputDevice_OpenMCU::~CVideoInputDevice_OpenMCU(void)
{
	m_ep.m_rMyH323.m_rNotify.OnIHPH323NotifyIHPVideoInputClose(conn.GetCallToken());
	AVBufferPool::Flush();
}

BOOL CVideoInputDevice_OpenMCU::Open(const PString & devName, BOOL /*startImmediate*/)
{
  //file.SetWidth(frameWidth);
  //file.SetHeight(frameHeight);

  deviceName = devName;

  return TRUE;    
}


BOOL CVideoInputDevice_OpenMCU::IsOpen() 
{
  return TRUE;
}


BOOL CVideoInputDevice_OpenMCU::Close()
{
	return TRUE;
}


BOOL CVideoInputDevice_OpenMCU::Start()
{
  return TRUE;
}


BOOL CVideoInputDevice_OpenMCU::Stop()
{
  return TRUE;
}


BOOL CVideoInputDevice_OpenMCU::IsCapturing()
{
  return IsOpen();
}


PStringList CVideoInputDevice_OpenMCU::GetInputDeviceNames()
{
  PStringList list;
  list.AppendString("openmcu");
  return list;
}


BOOL CVideoInputDevice_OpenMCU::SetVideoFormat(VideoFormat newFormat)
{
  return PVideoDevice::SetVideoFormat(newFormat);
}


int CVideoInputDevice_OpenMCU::GetNumChannels() 
{
  return 0;
}


BOOL CVideoInputDevice_OpenMCU::SetChannel(int newChannel)
{
  return PVideoDevice::SetChannel(newChannel);
}

BOOL CVideoInputDevice_OpenMCU::SetColourFormat(const PString & newFormat)
{
  if (!(newFormat *= "YUV420P"))
    return FALSE;

  if (!PVideoDevice::SetColourFormat(newFormat))
    return FALSE;

  return SetFrameSize(frameWidth, frameHeight);
}


BOOL CVideoInputDevice_OpenMCU::SetFrameRate(unsigned rate)
{
  if (rate < 1)
    rate = 1;
  else if (rate > 50)
    rate = 50;

  return PVideoDevice::SetFrameRate(rate);
}


BOOL CVideoInputDevice_OpenMCU::GetFrameSizeLimits(unsigned & minWidth,
                                           unsigned & minHeight,
                                           unsigned & maxWidth,
                                           unsigned & maxHeight) 
{
  maxWidth  = CIF_WIDTH;
  maxHeight = CIF_HEIGHT;
  minWidth  = QCIF_WIDTH;
  minHeight = QCIF_HEIGHT;

  return TRUE;
}


BOOL CVideoInputDevice_OpenMCU::SetFrameSize(unsigned width, unsigned height)
{
  if (!PVideoDevice::SetFrameSize(width, height))
    return FALSE;

  videoFrameSize = CalculateFrameBytes(frameWidth, frameHeight, colourFormat);
  scanLineWidth = videoFrameSize/frameHeight;
  return videoFrameSize > 0;
}


PINDEX CVideoInputDevice_OpenMCU::GetMaxFrameBytes()
{
  return GetMaxFrameBytesConverted(videoFrameSize);
}


BOOL CVideoInputDevice_OpenMCU::GetFrameData(BYTE * buffer, PINDEX * bytesReturned)
{    
  grabDelay.Delay(1000/GetFrameRate());

  return GetFrameDataNoDelay(buffer, bytesReturned);
}

 
BOOL CVideoInputDevice_OpenMCU::GetFrameDataNoDelay(BYTE *destFrame, PINDEX * bytesReturned)
{
	grabCount++;

	AVDataBuffer* pAVDataBuffer = AVBufferPool::GetDataBuffer();
	if(pAVDataBuffer)
	{
		if(pAVDataBuffer->GetLen() == videoFrameSize)
		{
			memcpy(destFrame,pAVDataBuffer->GetData(),pAVDataBuffer->GetLen());
		}

		delete pAVDataBuffer;
		pAVDataBuffer = NULL;
	}
	//if (!mcuConnection.OnOutgoingVideo(destFrame, frameWidth, frameHeight, *bytesReturned))
	//  return FALSE;

	if (converter != NULL) 
	{
		if (!converter->Convert(destFrame, destFrame, bytesReturned))
			return FALSE;
	}

	if (bytesReturned != NULL)
		*bytesReturned = videoFrameSize;

	return TRUE;
}

bool CVideoInputDevice_OpenMCU::IsVideoLarge(void)
{
	if(frameWidth == 352 && frameHeight == 288)
	{
		return true;
	}
	return false;
}

void CVideoInputDevice_OpenMCU::InputVideoFrame(unsigned char*pFrameData,int nFrameSize)
{
	AVDataBuffer* pAVDataBuffer = new AVDataBuffer;
	if(pAVDataBuffer)
	{
		pAVDataBuffer->StoreData((char*)pFrameData,nFrameSize);
		AVBufferPool::SetDataBuffer(pAVDataBuffer);
	}
}