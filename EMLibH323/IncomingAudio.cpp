#include "StdAfx.h"
#include ".\incomingaudio.h"

CIncomingAudio::CIncomingAudio(H323EndPoint & _ep, H323Connection & _conn)
: ep(_ep)
, conn(_conn)
, m_pIHPAudioOutput(NULL)
{
	os_handle = 0;
}

CIncomingAudio::~CIncomingAudio(void)
{
}

BOOL CIncomingAudio::Write(const void * buffer, PINDEX amount)
{
	PWaitAndSignal mutexW(audioChanMutex);

	if (!IsOpen())
		return FALSE;

	if(m_pIHPAudioOutput)
	{
		m_pIHPAudioOutput->OutputAudioFrame((unsigned char*)buffer, amount);
	}

	delay.Delay(amount / 16);

	return TRUE;
}

BOOL CIncomingAudio::Close()
{
	if (!IsOpen())
		return FALSE;

	PWaitAndSignal mutexA(audioChanMutex);
	os_handle = -1;

	return TRUE;
}

void CIncomingAudio::SetIHPAudioOutput(IHPAudioOutput*pIHPAudioOutput)
{
	PWaitAndSignal mutexA(audioChanMutex);
	m_pIHPAudioOutput = pIHPAudioOutput;
}