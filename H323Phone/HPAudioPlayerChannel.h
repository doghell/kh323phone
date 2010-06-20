#ifndef __HPAUDIOPPLAYERCHANNEL_H__
#define __HPAUDIOPPLAYERCHANNEL_H__

#include "HPQueueBuffer.h"
#include "IHPAudioPlayerChannel.h"

class HPAudioPlayer;
class HPAudioPlayerChannel
	: public HPQueueBuffer
	, public IHPAudioPlayerChannel
{
public:
	HPAudioPlayerChannel(HPAudioPlayer&rHPAudioPlayer);
	virtual ~HPAudioPlayerChannel(void);
public:
	virtual bool Connect(void);
	virtual void ReleaseConnections(void);
	virtual int ReadNextFrame(short*pSamples,int nSamples);
	virtual void PlayFrame(char*pData,int nLen);
protected:
	HPAudioPlayer&	m_rHPAudioPlayer;
};


#endif