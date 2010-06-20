//IHPAudioCaptureChannel.h
#ifndef __IHPAUDIOCAPTURECHANNEL_H__
#define __IHPAUDIOCAPTURECHANNEL_H__


class IHPAudioCaptureChannelNotify
{
public:
	IHPAudioCaptureChannelNotify(void){};
	virtual~IHPAudioCaptureChannelNotify(void){};
public:
	virtual void OnIHPAudioCaptureChannelNotifyData(char*pData,int nLen)=0;
};

class IHPAudioCaptureChannel
{
public:
	IHPAudioCaptureChannel(void){};
	virtual~IHPAudioCaptureChannel(void){};
public:
	virtual void ReleaseConnections(void)=0;
};

#endif