// HPWaveCapture.cpp: implementation of the HPWaveCapture class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HPWaveCapture.h"

IHPWaveCapture*CreateIHPWaveCapture(IHPWaveCaptureNotify&rIHPWaveCaptureNotify,unsigned int nDevice)
{
	HPWaveCapture*pHPWaveCapture=new HPWaveCapture(rIHPWaveCaptureNotify);
	if (pHPWaveCapture->Connect()==false)
	{
		pHPWaveCapture->ReleaseConnections();
		delete pHPWaveCapture;
		pHPWaveCapture=NULL;
	}
	return pHPWaveCapture;
}

static int pa_icallback(void *inputBuffer, void *outputBuffer,
	    unsigned long samplesPerFrame,
	    const PaStreamCallbackTimeInfo* outTime,
	    PaStreamCallbackFlags statusFlags,
	    void *userData)
{
	HPWaveCapture* pthis = (HPWaveCapture*)userData;
	if(inputBuffer)
	{
		pthis->m_rIHPWaveCaptureNotify.OnIHPWaveCaptureNotifyCapturedSamples((short*)inputBuffer,samplesPerFrame);
	}
	return 0;
}

HPWaveCapture::HPWaveCapture(IHPWaveCaptureNotify&rIHPWaveCaptureNotify)
: m_rIHPWaveCaptureNotify(rIHPWaveCaptureNotify)
, m_PaIStream(NULL)
{
}

HPWaveCapture::~HPWaveCapture()
{
}

bool HPWaveCapture::Connect()
{
	PaError err;
    PaStreamParameters inputParameters;
    err = Pa_Initialize();
	if( err != paNoError )
	{
		return false;
	}
    inputParameters.device = Pa_GetDefaultInputDevice(); /* default output device */
	if(inputParameters.device == paNoDevice)
	{
		return false;
	}
    inputParameters.channelCount = 1;
    inputParameters.sampleFormat =  paInt16;
    inputParameters.suggestedLatency = Pa_GetDeviceInfo( inputParameters.device )->defaultLowInputLatency;
    inputParameters.hostApiSpecificStreamInfo = NULL;
	
	err = Pa_OpenStream(
              &m_PaIStream,
              &inputParameters,
              NULL, /* no output */
              8000,
			  80,
              paClipOff,      /* we won't output out of range samples so don't bother clipping them */
              (PaStreamCallback *)pa_icallback,
              this ); /* no callback, so no callback userData */
    if( err != paNoError ) 
	{
		return false;
	}
    err = Pa_StartStream(m_PaIStream);
    if( err != paNoError ) 
	{
		return false;
	}
	
	return true;
}

void HPWaveCapture::ReleaseConnections(void)
{
	if(m_PaIStream)
	{
		Pa_AbortStream(m_PaIStream);
		Pa_CloseStream(m_PaIStream);
		m_PaIStream = NULL;
	}
	Pa_Terminate();
}