//libHPWaveCapture.h
#ifndef __LIKHPWAVECAPTURE_H__
#define __LIKHPWAVECAPTURE_H__

class IHPWaveCaptureNotify
{
public:
	IHPWaveCaptureNotify(void){};
	virtual~IHPWaveCaptureNotify(void){};
public:
	virtual void OnIHPWaveCaptureNotifyCapturedSamples(short*pSamples,int nSamples)=0;
};

class IHPWaveCapture
{
public:
	IHPWaveCapture(void){};
	virtual~IHPWaveCapture(void){};
public:
	virtual void ReleaseConnections(void)=0;
};

IHPWaveCapture*CreateIHPWaveCapture(IHPWaveCaptureNotify&rIHPWaveCaptureNotify,unsigned int nDevice);

#endif