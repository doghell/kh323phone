//IHPAudioPlayerChannel.h
#ifndef __IHPAUDIOPPLAYERCHANNEL_H__
#define __IHPAUDIOPPLAYERCHANNEL_H__

class IHPAudioPlayerChannel
{
public:
	IHPAudioPlayerChannel(void){}
	virtual~IHPAudioPlayerChannel(void){};
public:
	virtual void ReleaseConnections(void)=0;
	virtual void PlayFrame(char*pData,int nLen)=0;
};

#endif