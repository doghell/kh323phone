#ifndef __HPAUDIOCAPTURE_H__
#define __HPAUDIOCAPTURE_H__

#include "libHPWaveCapture.h"
#include "HPAudioCaptureChannel.h"
#include "AVAutoLock.h"
#include <map>

typedef std::map<void*,HPAudioCaptureChannel*>	MapHPAudioCaptureChannel;

class HPVoiceEngine;
class HPAudioCapture
	: public IHPWaveCaptureNotify
{
public:
	HPAudioCapture(HPVoiceEngine&rHPVoiceEngine);
	virtual ~HPAudioCapture(void);
public:
	bool Connect(unsigned int nWaveInDevice);
	void ReleaseConnections(void);

	void OnHPAudioCaptureChannelConnected(HPAudioCaptureChannel*pHPAudioCaptureChannel);
	void OnHPAudioCaptureChannelReleased(HPAudioCaptureChannel*pHPAudioCaptureChannel);
	void OnCapturedSamples(short*pSamples,int nSamples);
protected:
	void OnIHPWaveCaptureNotifyCapturedSamples(short*pSamples,int nSamples);
protected:
	HPVoiceEngine&				m_rHPVoiceEngine;
	MapHPAudioCaptureChannel	m_MapHPAudioCaptureChannel;
	AVCritSec					m_AVCritSecMapHPAudioCaptureChannel;
	unsigned int				m_nWaveInDevice;
	IHPWaveCapture*				m_pIHPWaveCapture;
};

#endif