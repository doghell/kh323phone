#include "stdafx.h"
#include "HPAudioCaptureChannel.h"
#include "HPAudioCapture.h"

HPAudioCaptureChannel::HPAudioCaptureChannel(IHPAudioCaptureChannelNotify&rIHPAudioCaptureChannelNotify,HPAudioCapture&rHPAudioCapture)
:m_rIHPAudioCaptureChannelNotify(rIHPAudioCaptureChannelNotify)
,m_rHPAudioCapture(rHPAudioCapture)
{
}

HPAudioCaptureChannel::~HPAudioCaptureChannel(void)
{
}

bool HPAudioCaptureChannel::Connect(void)
{
	m_rHPAudioCapture.OnHPAudioCaptureChannelConnected(this);
	return true;
}

void HPAudioCaptureChannel::ReleaseConnections(void)
{
	m_rHPAudioCapture.OnHPAudioCaptureChannelReleased(this);
}

void HPAudioCaptureChannel::OnCapturedSamples(short*pSamples,int nSamples)
{
	m_rIHPAudioCaptureChannelNotify.OnIHPAudioCaptureChannelNotifyData((char*)pSamples,nSamples<<1);
}

