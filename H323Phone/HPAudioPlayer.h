#ifndef __HPAUDIOPLAYER_H__
#define __HPAUDIOPLAYER_H__

#include "libHPWaveRender.h"
#include "HPAudioPlayerChannel.h"
#include <map>
#include "AVAutoLock.h"

typedef std::map<void*,HPAudioPlayerChannel*>	MapHPAudioPlayerChannel;

class HPVoiceEngine;
class HPAudioPlayer
	: public IHPWaveRenderNotify
{
public:
	HPAudioPlayer(HPVoiceEngine&rHPVoiceEngine);
	virtual ~HPAudioPlayer(void);
public:
	bool Connect(unsigned int nWaveOutDevice);
	void ReleaseConnections(void);

	void OnHPAudioPlayerChannelConnected(HPAudioPlayerChannel*pHPAudioPlayerChannel);
	void OnHPAudioPlayerChannelReleased(HPAudioPlayerChannel*pHPAudioPlayerChannel);
protected:
	void OnIHPWaveRenderNotifyRenderedSamples(short*pSamples,int nSamples);
	int OnIHPWaveRenderNotifyReadNextFrame(short*pSamples,int nSamples);
protected:
	HPVoiceEngine&			m_rHPVoiceEngine;
	unsigned int			m_nWaveOutDevice;
	IHPWaveRender*			m_pIHPWaveRender;
	MapHPAudioPlayerChannel	m_MapHPAudioPlayerChannel;
	AVCritSec				m_AVCritSecMapHPAudioPlayerChannel;
};

#endif