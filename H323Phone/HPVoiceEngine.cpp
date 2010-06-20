#include "stdafx.h"
#include "HPVoiceEngine.h"
#include "HPAudioPlayerChannel.h"
#include "HPAudioCaptureChannel.h"

HPVoiceEngine::HPVoiceEngine(void)
:m_HPAudioCapture(*this)
,m_HPAudioPlayer(*this)

{
}

HPVoiceEngine::~HPVoiceEngine(void)
{
}

bool HPVoiceEngine::Connect(unsigned int nWaveInDevice,unsigned int nWaveOutDevice)
{
	m_HPAudioPlayer.Connect(nWaveOutDevice);
	m_HPAudioCapture.Connect(nWaveInDevice);
	return true;
}

void HPVoiceEngine::ReleaseConnections(void)
{
	m_HPAudioCapture.ReleaseConnections();
	m_HPAudioPlayer.ReleaseConnections();
}

IHPAudioCaptureChannel*HPVoiceEngine::CreateIHPAudioCaptureChannel(IHPAudioCaptureChannelNotify&rIHPAudioCaptureChannelNotify)
{
	HPAudioCaptureChannel*pHPAudioCaptureChannel=new HPAudioCaptureChannel(rIHPAudioCaptureChannelNotify,m_HPAudioCapture);
	if (pHPAudioCaptureChannel->Connect()==false)
	{
		pHPAudioCaptureChannel->ReleaseConnections();
		delete pHPAudioCaptureChannel;
		pHPAudioCaptureChannel=NULL;
	}
	return pHPAudioCaptureChannel;
}


IHPAudioPlayerChannel*HPVoiceEngine::CreateIHPAudioPlayerChannel(void)
{
	HPAudioPlayerChannel*pHPAudioPlayerChannel=new HPAudioPlayerChannel(m_HPAudioPlayer);
	if (pHPAudioPlayerChannel->Connect()==false)
	{
		pHPAudioPlayerChannel->ReleaseConnections();
		delete pHPAudioPlayerChannel;
		pHPAudioPlayerChannel=NULL;
	}
	return pHPAudioPlayerChannel;
}
