// HPWaveRender.h: interface for the HPWaveRender class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __HPWAVERENDER_H__
#define __HPWAVERENDER_H__


#include "portaudio.h"
#include "libHPWaveRender.h"

class HPWaveRender
	: public IHPWaveRender
{
public:
	HPWaveRender(IHPWaveRenderNotify&rIHPWaveRenderNotify);
	virtual ~HPWaveRender(void);
public:
	virtual bool Connect();
	virtual void ReleaseConnections(void);
public:
	IHPWaveRenderNotify&m_rIHPWaveRenderNotify;
	PaStream* m_PaOStream;
};

#endif 