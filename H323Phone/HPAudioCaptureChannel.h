#ifndef __HPAUDIOCAPTURECHANNEL_H__
#define __HPAUDIOCAPTURECHANNEL_H__

#include "IHPAudioCaptureChannel.h"

class HPAudioCapture;
class HPAudioCaptureChannel 
	: public IHPAudioCaptureChannel
{
public:
	HPAudioCaptureChannel(IHPAudioCaptureChannelNotify&rIHPAudioCaptureChannelNotify,HPAudioCapture&rHPAudioCapture);
	virtual~HPAudioCaptureChannel(void);
public:
	bool Connect(void);
	void ReleaseConnections(void);
	void OnCapturedSamples(short*pSamples,int nSamples);
protected:
	IHPAudioCaptureChannelNotify&	m_rIHPAudioCaptureChannelNotify;
	HPAudioCapture&					m_rHPAudioCapture;
};

#endif