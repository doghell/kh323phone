#include "StdAfx.h"
#include ".\videooutputdevice_openmcu.h"

CVideoOutputDevice_OpenMCU::CVideoOutputDevice_OpenMCU(H323Connection & _mcuConnection)
: mcuConnection(_mcuConnection)
, m_pIHPVideoOutput(NULL)
{
}

CVideoOutputDevice_OpenMCU::~CVideoOutputDevice_OpenMCU(void)
{
}

BOOL CVideoOutputDevice_OpenMCU::Open(const PString & _deviceName, BOOL /*startImmediate*/)
{
  deviceName = _deviceName;
  return TRUE;
}

BOOL CVideoOutputDevice_OpenMCU::Close()
{
  return TRUE;
}

BOOL CVideoOutputDevice_OpenMCU::Start()
{
  return TRUE;
}

BOOL CVideoOutputDevice_OpenMCU::Stop()
{
  return TRUE;
}

BOOL CVideoOutputDevice_OpenMCU::IsOpen()
{
  return TRUE;
}


PStringList CVideoOutputDevice_OpenMCU::GetOutputDeviceNames()
{
  PStringList list;
  return list;
}


PINDEX CVideoOutputDevice_OpenMCU::GetMaxFrameBytes()
{
  return GetMaxFrameBytesConverted(CalculateFrameBytes(frameWidth, frameHeight, colourFormat));
}


BOOL CVideoOutputDevice_OpenMCU::SetFrameData(unsigned x, unsigned y,
                                              unsigned width, unsigned height,
                                              const BYTE * data,
                                              BOOL /*endFrame*/)
{
  if (x != 0 || y != 0 || width != frameWidth || height != frameHeight) {
    PTRACE(1, "YUVFile output device only supports full frame writes");
    return FALSE;
  }

  if(m_pIHPVideoOutput)
  {
	  m_pIHPVideoOutput->OutputVideoFrame((unsigned char*)data,width*height*3/2);
  }
  return TRUE;
}


BOOL CVideoOutputDevice_OpenMCU::EndFrame()
{
  return TRUE;
}

void CVideoOutputDevice_OpenMCU::SetIHPVideoOutput(IHPVideoOutput*pIHPVideoOutput)
{
	if(pIHPVideoOutput)
	{
		pIHPVideoOutput->SetFrameSize(frameWidth,frameHeight);
	}
	m_pIHPVideoOutput = pIHPVideoOutput;
}