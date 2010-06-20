#ifndef __HPVOICEENGINE_H__
#define __HPVOICEENGINE_H__

#include "HPAudioCapture.h"
#include "HPAudioPlayer.h"
#include "IHPAudioPlayerChannel.h"
#include "IHPAudioCaptureChannel.h"

class HPVoiceEngine
{
public:
	HPVoiceEngine(void);
	virtual ~HPVoiceEngine(void);
public:
	bool Connect(unsigned int nWaveInDevice,unsigned int nWaveOutDevice);
	void ReleaseConnections(void);
	IHPAudioCaptureChannel*CreateIHPAudioCaptureChannel(IHPAudioCaptureChannelNotify&rIHPAudioCaptureChannelNotify);
	IHPAudioPlayerChannel*CreateIHPAudioPlayerChannel(void);
protected:
	HPAudioCapture	m_HPAudioCapture;
	HPAudioPlayer	m_HPAudioPlayer;


	friend class HPAudioCapture;
	friend class HPAudioPlayer;
};

#endif