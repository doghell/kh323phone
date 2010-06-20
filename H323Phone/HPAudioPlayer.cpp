#include "stdafx.h"
#include "HPAudioPlayer.h"
#include "HPVoiceEngine.h"

HPAudioPlayer::HPAudioPlayer(HPVoiceEngine&rHPVoiceEngine)
:m_rHPVoiceEngine(rHPVoiceEngine)
,m_pIHPWaveRender(NULL)
{
}

HPAudioPlayer::~HPAudioPlayer(void)
{
}

bool HPAudioPlayer::Connect(unsigned int nWaveOutDevice)
{
	m_nWaveOutDevice=nWaveOutDevice;
	return true;
}

void HPAudioPlayer::ReleaseConnections(void)
{
	if (m_pIHPWaveRender)
	{
		m_pIHPWaveRender->ReleaseConnections();
		delete m_pIHPWaveRender;
		m_pIHPWaveRender=NULL;
	}
}

void HPAudioPlayer::OnHPAudioPlayerChannelConnected(HPAudioPlayerChannel*pHPAudioPlayerChannel)
{
	AVAutoLock l(&m_AVCritSecMapHPAudioPlayerChannel);
	m_MapHPAudioPlayerChannel[pHPAudioPlayerChannel]=pHPAudioPlayerChannel;
	if (!m_pIHPWaveRender)
	{
		m_pIHPWaveRender=CreateIHPWaveRender(*this,m_nWaveOutDevice);
	}
}

void HPAudioPlayer::OnHPAudioPlayerChannelReleased(HPAudioPlayerChannel*pHPAudioPlayerChannel)
{
	AVAutoLock l(&m_AVCritSecMapHPAudioPlayerChannel);
	m_MapHPAudioPlayerChannel.erase(pHPAudioPlayerChannel);
	if (m_MapHPAudioPlayerChannel.size()==0)
	{
		if (m_pIHPWaveRender)
		{
			m_pIHPWaveRender->ReleaseConnections();
			delete m_pIHPWaveRender;
			m_pIHPWaveRender=NULL;
		}
	}
}

void HPAudioPlayer::OnIHPWaveRenderNotifyRenderedSamples(short*pSamples,int nSamples)
{
}

int HPAudioPlayer::OnIHPWaveRenderNotifyReadNextFrame(short*pSamples,int nSamples)
{
	short*pChannelSamples=(short*)malloc(nSamples<<1);
	memset(pChannelSamples,0,nSamples<<1);
	memset(pSamples,0,nSamples<<1);
	AVAutoLock l(&m_AVCritSecMapHPAudioPlayerChannel);
	MapHPAudioPlayerChannel::iterator it=m_MapHPAudioPlayerChannel.begin();
	while (it!=m_MapHPAudioPlayerChannel.end())
	{
		HPAudioPlayerChannel*pHPAudioPlayerChannel=(*it).second;
		int nRead=pHPAudioPlayerChannel->ReadNextFrame(pChannelSamples,nSamples);
		int nNewSample=0;
		for (int i=0;i<nSamples;i++)
		{
			nNewSample=(int)pChannelSamples[i]+pSamples[i];
			if (nNewSample<-32767)
			{
				nNewSample=-32767;
			}
			else if (nNewSample>32767)
			{
				nNewSample=32767;
			}
			pSamples[i]=(short)nNewSample;
		}

		++it;
	}

	free(pChannelSamples);
	pChannelSamples=NULL;

	return nSamples;
}

