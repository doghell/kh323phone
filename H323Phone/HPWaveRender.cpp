// HPWaveRender.cpp: implementation of the HPWaveRender class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HPWaveRender.h"

IHPWaveRender*CreateIHPWaveRender(IHPWaveRenderNotify&rIHPWaveRenderNotify,unsigned int nDevice)
{
	HPWaveRender*pHPWaveRender=new HPWaveRender(rIHPWaveRenderNotify);
	if (pHPWaveRender->Connect()==false)
	{
		pHPWaveRender->ReleaseConnections();
		delete pHPWaveRender;
		pHPWaveRender=NULL;
	}
	return pHPWaveRender;
}

static int pa_callback(void *inputBuffer, void *outputBuffer,
	    unsigned long samplesPerFrame,
	    const PaStreamCallbackTimeInfo* outTime,
	    PaStreamCallbackFlags statusFlags,
	    void *userData)
{
	HPWaveRender* pthis = (HPWaveRender*)userData;
	if(outputBuffer)
	{
		pthis->m_rIHPWaveRenderNotify.OnIHPWaveRenderNotifyReadNextFrame((short*)outputBuffer,samplesPerFrame);
	}
	return 0;
}

HPWaveRender::HPWaveRender(IHPWaveRenderNotify&rIHPWaveRenderNotify)
: m_rIHPWaveRenderNotify(rIHPWaveRenderNotify)
, m_PaOStream(NULL)
{
}

HPWaveRender::~HPWaveRender(void)
{
}

bool HPWaveRender::Connect()
{
	PaError err;
    PaStreamParameters outputParameters;
    err = Pa_Initialize();
	if( err != paNoError )
	{
		return false;
	}
    outputParameters.device = Pa_GetDefaultOutputDevice(); /* default output device */
	if(outputParameters.device == paNoDevice)
	{
		return false;
	}
    outputParameters.channelCount = 1;
    outputParameters.sampleFormat =  paInt16;
    outputParameters.suggestedLatency = Pa_GetDeviceInfo( outputParameters.device )->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;
	
	err = Pa_OpenStream(
              &m_PaOStream,
              NULL, /* no input */
              &outputParameters,
              8000,
			  80,
              paClipOff,      /* we won't output out of range samples so don't bother clipping them */
              (PaStreamCallback *)pa_callback,
              this ); /* no callback, so no callback userData */
    if( err != paNoError ) 
	{
		return false;
	}
    err = Pa_StartStream(m_PaOStream);
    if( err != paNoError ) 
	{
		return false;
	}

	return true;
}

void HPWaveRender::ReleaseConnections(void)
{
	if(m_PaOStream)
	{
		Pa_AbortStream(m_PaOStream);
		Pa_CloseStream(m_PaOStream);
		m_PaOStream = NULL;
	}
	Pa_Terminate();
}