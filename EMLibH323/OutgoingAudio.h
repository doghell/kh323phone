#pragma once

#include "HPQueueBuffer.h"

class CMyH323EndPoint;
class COutgoingAudio 
	: public PChannel
	, public IHPAudioInput
	, public HPQueueBuffer
{
  PCLASSINFO(COutgoingAudio, PChannel);
public:
	COutgoingAudio(CMyH323EndPoint & ep, H323Connection & conn);
	virtual ~COutgoingAudio(void);

	BOOL Read(void * buffer, PINDEX amount);
	BOOL Close();

	void InputAudioFrame(unsigned char*pFrameData,int nFrameSize);

protected:
	CMyH323EndPoint & ep;
	H323Connection & conn;

	PAdaptiveDelay delay;
	PMutex audioChanMutex;
};
