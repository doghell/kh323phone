#pragma once

class CIncomingAudio 
	: public PChannel
{
	PCLASSINFO(CIncomingAudio, PChannel);
public:
	CIncomingAudio(H323EndPoint & _ep, H323Connection & _conn);
	virtual ~CIncomingAudio(void);

	BOOL Write(const void * buffer, PINDEX amount);
	BOOL Close();

	void SetIHPAudioOutput(IHPAudioOutput*pIHPAudioOutput);

protected:
	H323EndPoint & ep;
	H323Connection & conn;
	PMutex audioChanMutex;
	PAdaptiveDelay delay;

	IHPAudioOutput*	m_pIHPAudioOutput;
};
