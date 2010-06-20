//libHPWaveRender.h
#ifndef __LIBHPWAVERENDER_H__
#define __LIBHPWAVERENDER_H__

class IHPWaveRenderNotify
{
public:
	IHPWaveRenderNotify(void){};
	virtual~IHPWaveRenderNotify(void){};
public:
	virtual void OnIHPWaveRenderNotifyRenderedSamples(short*pSamples,int nSamples)=0;
	virtual int OnIHPWaveRenderNotifyReadNextFrame(short*pSamples,int nSamples)=0;
};

class IHPWaveRender
{
public:
	IHPWaveRender(void){};
	virtual~IHPWaveRender(void){};
public:
	virtual void ReleaseConnections(void)=0;
};

IHPWaveRender*CreateIHPWaveRender(IHPWaveRenderNotify&rIHPWaveRenderNotify,unsigned int nDevice);


int GetAudioOutputDeviceCount(void);
bool GetAudioOutputDeviceName(int nAudioOutputDeviceIndex,TCHAR*szAudioOutputDeviceName);

#endif