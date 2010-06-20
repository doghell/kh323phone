// HPWaveCapture.h: interface for the HPWaveCapture class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __HPWAVECAPTURE_H__
#define __HPWAVECAPTURE_H__


#include "portaudio.h"
#include "libHPWaveCapture.h"

class HPWaveCapture 
	: public IHPWaveCapture
{
public:
	HPWaveCapture(IHPWaveCaptureNotify&rIHPWaveCaptureNotify);
	virtual ~HPWaveCapture(void);
public:
	bool Connect();
	void ReleaseConnections(void);

public:
	IHPWaveCaptureNotify&	m_rIHPWaveCaptureNotify;
	PaStream* m_PaIStream;
};


#endif 