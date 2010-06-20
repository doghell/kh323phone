#include "stdafx.h"
#include "HPAudioCapture.h"
#include "HPVoiceEngine.h"

HPAudioCapture::HPAudioCapture(HPVoiceEngine&rHPVoiceEngine)
:m_rHPVoiceEngine(rHPVoiceEngine)
,m_nWaveInDevice(-1)
,m_pIHPWaveCapture(NULL)
{
}

HPAudioCapture::~HPAudioCapture(void)
{
}

bool HPAudioCapture::Connect(unsigned int nWaveInDevice)
{
	m_nWaveInDevice=nWaveInDevice;
	return true;
}

void HPAudioCapture::ReleaseConnections(void)
{
	if (m_pIHPWaveCapture)
	{
		m_pIHPWaveCapture->ReleaseConnections();
		delete m_pIHPWaveCapture;
		m_pIHPWaveCapture=NULL;
	}
}

void HPAudioCapture::OnHPAudioCaptureChannelConnected(HPAudioCaptureChannel*pHPAudioCaptureChannel)
{	
	{
		AVAutoLock l(&m_AVCritSecMapHPAudioCaptureChannel);
		m_MapHPAudioCaptureChannel[pHPAudioCaptureChannel]=pHPAudioCaptureChannel;
	}

	m_AVCritSecMapHPAudioCaptureChannel.Lock();
	if (m_MapHPAudioCaptureChannel.size())
	{
		m_AVCritSecMapHPAudioCaptureChannel.Unlock();

		if (!m_pIHPWaveCapture)
		{
			m_pIHPWaveCapture=CreateIHPWaveCapture(*this,m_nWaveInDevice);
		}
	}
	else
	{
		m_AVCritSecMapHPAudioCaptureChannel.Unlock();
	}
}

void HPAudioCapture::OnHPAudioCaptureChannelReleased(HPAudioCaptureChannel*pHPAudioCaptureChannel)
{
	{
		AVAutoLock l(&m_AVCritSecMapHPAudioCaptureChannel);
		m_MapHPAudioCaptureChannel.erase(pHPAudioCaptureChannel);
	}

	m_AVCritSecMapHPAudioCaptureChannel.Lock();
	if (m_MapHPAudioCaptureChannel.size()==0)
	{
		m_AVCritSecMapHPAudioCaptureChannel.Unlock();
		if (m_pIHPWaveCapture)
		{
			m_pIHPWaveCapture->ReleaseConnections();
			delete m_pIHPWaveCapture;
			m_pIHPWaveCapture=NULL;
		}
	}
	else
	{
		m_AVCritSecMapHPAudioCaptureChannel.Unlock();
	}
}

void HPAudioCapture::OnCapturedSamples(short*pSamples,int nSamples)
{
	AVAutoLock l(&m_AVCritSecMapHPAudioCaptureChannel);
	MapHPAudioCaptureChannel::iterator it=m_MapHPAudioCaptureChannel.begin();
	while (it!=m_MapHPAudioCaptureChannel.end())
	{
		HPAudioCaptureChannel*pHPAudioCaptureChannel=(*it).second;
		pHPAudioCaptureChannel->OnCapturedSamples(pSamples,nSamples);
		++it;
	}
}

void HPAudioCapture::OnIHPWaveCaptureNotifyCapturedSamples(short*pSamples,int nSamples)
{
	OnCapturedSamples(pSamples,nSamples);
}
