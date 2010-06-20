#include "StdAfx.h"
#include ".\outgoingaudio.h"
#include "MyH323.h"

COutgoingAudio::COutgoingAudio(CMyH323EndPoint & _ep, H323Connection & _conn)
: ep(_ep), conn(_conn)
, HPQueueBuffer(80*24*2)
{
	os_handle = 0;
}

COutgoingAudio::~COutgoingAudio(void)
{
}

BOOL COutgoingAudio::Read(void * buffer, PINDEX amount)
{
	PWaitAndSignal mutexR(audioChanMutex);

	if (!IsOpen())
		return FALSE;

	int nRead = HPQueueBuffer::Read((char*)buffer,amount);
	if (nRead < amount)
	{
		memset((char*)buffer + nRead,0,amount - nRead);
	}
	
	delay.Delay(amount / 16);

	lastReadCount = amount;

	return TRUE;
}

BOOL COutgoingAudio::Close()
{
	if (!IsOpen()) 
		return FALSE;

	PWaitAndSignal mutexC(audioChanMutex);
	os_handle = -1;

	ep.m_rMyH323.m_rNotify.OnIHPH323NotifyIHPAudioInputClose(conn.GetCallToken());

	return TRUE;
}

void COutgoingAudio::InputAudioFrame(unsigned char*pFrameData,int nFrameSize)
{
	HPQueueBuffer::Write((char*)pFrameData,nFrameSize);
}