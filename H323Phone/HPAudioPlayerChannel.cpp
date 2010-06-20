#include "stdafx.h"
#include "HPAudioPlayerChannel.h"
#include "HPWaveRender.h"
#include "HPAudioPlayer.h"

HPAudioPlayerChannel::HPAudioPlayerChannel(HPAudioPlayer&rHPAudioPlayer)
:HPQueueBuffer(80*24*2)
,m_rHPAudioPlayer(rHPAudioPlayer)
{
}

HPAudioPlayerChannel::~HPAudioPlayerChannel(void)
{
}

bool HPAudioPlayerChannel::Connect(void)
{
	m_rHPAudioPlayer.OnHPAudioPlayerChannelConnected(this);
	return true;
}

void HPAudioPlayerChannel::ReleaseConnections(void)
{
	m_rHPAudioPlayer.OnHPAudioPlayerChannelReleased(this);
}

int HPAudioPlayerChannel::ReadNextFrame(short*pSamples,int nSamples)
{
	char*pBuffer=(char*)pSamples;
	int nLen=nSamples<<1;
	int nRead=Read((char*)pBuffer,nLen);
	if (nRead<nLen)
	{
		memset(pBuffer+nRead,0,nLen-nRead);
	}
	return nSamples;
}

void HPAudioPlayerChannel::PlayFrame(char*pData,int nLen)
{
	Write(pData,nLen);
}

