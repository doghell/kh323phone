#include "StdAfx.h"
#include ".\myh323endpoint.h"
#include "MyH323.h"

PluginLoaderStartup2  PWLibProcess::pluginLoader;
CMyH323EndPoint::CMyH323EndPoint(CMyH323& rMyH323)
: m_rMyH323(rMyH323)
{
	PWLibProcess::pluginLoader.OnStartup();
}

CMyH323EndPoint::~CMyH323EndPoint(void)
{
	PWLibProcess::pluginLoader.OnShutdown();
}

bool CMyH323EndPoint::Initialise(const struct GeneralParam& tGeneralParam,const struct AudioParam& tAudioParam)
{
	SetAudioJitterDelay(tAudioParam.m_nJitter,GetMaxAudioJitterDelay());
	SetSilenceDetectionMode(tAudioParam.m_bVAD
		? H323AudioCodec::AdaptiveSilenceDetection
		: H323AudioCodec::NoSilenceDetection);

	DisableFastStart(tGeneralParam.m_bDisableFastStart ? TRUE : FALSE);
	DisableH245Tunneling(tGeneralParam.m_bDisableH245Tunneling ? TRUE : FALSE);
	SetInitialBandwidth(tGeneralParam.m_nBandwidth);
	SetRtpIpTypeofService(tGeneralParam.m_nToS);
	SetRtpIpPorts(tGeneralParam.m_usRTPBasePort,tGeneralParam.m_usRTPBasePort);
	SetLocalUserName(tGeneralParam.m_strUserName);

	capabilities.RemoveAll();	
    AddAllCapabilities(0, 0, "*"); 
    AddAllUserInputCapabilities(0, 1);

	if(tAudioParam.m_bG711ALaw == false)
	{
		capabilities.Remove("G.711-ALaw-64k");
	}
	if(tAudioParam.m_bG711uLaw == false)
	{
		capabilities.Remove("G.711-uLaw-64k");
	}
	if(tAudioParam.m_bG7231 == false)
	{
		capabilities.Remove("G.7231-6.3k[m]{sw}");
	}

	PString interfaces = "*";
	if(StartListeners(interfaces.Tokenise(',')))
	{
		return true;
	}

	return false;
}

H323Connection::AnswerCallResponse CMyH323EndPoint::OnAnswerCall(H323Connection & connection, const PString &caller, const H323SignalPDU &, H323SignalPDU &)
{
	m_rMyH323.m_rNotify.OnIHPH323NotifyCalled(connection.GetCallToken());
	return H323Connection::AnswerCallPending;
}

void CMyH323EndPoint::OnConnectionEstablished(H323Connection & connection, const PString & token)
{
	m_rMyH323.m_rNotify.OnIHPH323NotifyEstablished(token);
}

void CMyH323EndPoint::OnConnectionCleared(H323Connection & connection, const PString & clearedCallToken)
{
	m_rMyH323.m_rNotify.OnIHPH323NotifyCleared(clearedCallToken);
}

BOOL CMyH323EndPoint::OpenAudioChannel(H323Connection & connection,BOOL isEncoding,unsigned bufferSize,H323AudioCodec & codec)
{
	if (!isEncoding) 
	{
		codec.AttachChannel(new CIncomingAudio(*this, connection), TRUE);
		m_rMyH323.m_rNotify.OnIHPH323NotifyIHPAudioOutput(connection.GetCallToken());
	} 
	else 
	{
		codec.AttachChannel(new COutgoingAudio(*this, connection), TRUE);
		m_rMyH323.m_rNotify.OnIHPH323NotifyIHPAudioInput(connection.GetCallToken());
	}

	return TRUE;
}

COutgoingAudio* CMyH323EndPoint::GetOutgoingAudio(const PString & connectionToken)
{
	H323Connection * connection = FindConnectionWithoutLocks(connectionToken);
	if (NULL != connection)
	{
		H323Channel * logicalChannel = connection->FindChannel(RTP_Session::DefaultAudioSessionID, FALSE);
		if(logicalChannel)
		{
			H323Codec * codec = logicalChannel->GetCodec();
			if(codec)
			{
				PChannel * rawChannel = codec->GetRawDataChannel();
				if (rawChannel->IsClass("COutgoingAudio"))
				{
					return (COutgoingAudio*)rawChannel;
				}
			}
		}
	}
	return NULL;
}

CIncomingAudio* CMyH323EndPoint::GetIncomingAudio(const PString & connectionToken)
{
	H323Connection * connection = FindConnectionWithoutLocks(connectionToken);
	if (NULL != connection)
	{
		H323Channel * logicalChannel = connection->FindChannel(RTP_Session::DefaultAudioSessionID, TRUE);
		if(logicalChannel)
		{
			H323Codec * codec = logicalChannel->GetCodec();
			if(codec)
			{
				PChannel * rawChannel = codec->GetRawDataChannel();
				if (rawChannel->IsClass("CIncomingAudio"))
				{
					return (CIncomingAudio*)rawChannel;
				}
			}
		}
	}
	return NULL;
}

BOOL CMyH323EndPoint::OpenVideoChannel(H323Connection & connection,
										BOOL isEncoding,
										H323VideoCodec & codec)
{
	if (isEncoding) 
	{
		PVideoChannel * channel = new PVideoChannel;
		CVideoInputDevice_OpenMCU * videoGrabber = new CVideoInputDevice_OpenMCU(*this,connection);
		if (videoGrabber == NULL) 
		{
			PTRACE(3, "Cannot create MCU video input driver");
			return FALSE;
		}

		if (!InitGrabber(videoGrabber, codec.GetWidth(), codec.GetHeight())) 
		{
			delete videoGrabber;
			videoGrabber = NULL;
			return FALSE;
		}

		codec.SetTxQualityLevel(10);

		videoGrabber->Start();
		channel->AttachVideoReader(videoGrabber);

		if (!codec.AttachChannel(channel,TRUE))
			return FALSE;

		m_rMyH323.m_rNotify.OnIHPH323NotifyIHPVideoInput(connection.GetCallToken());
	}
	else 
	{
		CVideoOutputDevice_OpenMCU* videoDisplay = new CVideoOutputDevice_OpenMCU(connection);
		if (!videoDisplay->Open("")) 
		{
			delete videoDisplay;
			return FALSE;
		}
	     
		videoDisplay->SetFrameSize(codec.GetWidth(), codec.GetHeight()); // needed to enable resize
		videoDisplay->SetColourFormatConverter("YUV420P");

		PVideoChannel * channel = new PVideoChannel; 
		channel->AttachVideoPlayer(videoDisplay); 
		if (!codec.AttachChannel(channel,TRUE))
			return FALSE;
	
		m_rMyH323.m_rNotify.OnIHPH323NotifyIHPVideoOutput(connection.GetCallToken());
	}

	return TRUE;
}

BOOL CMyH323EndPoint::InitGrabber(PVideoInputDevice * grabber, int newFrameWidth, int newFrameHeight)
{
	PTRACE(4, "Video grabber set to " << newFrameWidth << "x" << newFrameHeight);

	//if (!(pfdColourFormat.IsEmpty()))
	//  grabber->SetPreferredColourFormat(pfdColourFormat);

	if (!grabber->Open("", FALSE)) 
	{
		PTRACE(3, "Failed to open the video input device");
		return FALSE;
	}

	//if (!grabber->SetChannel(ep.GetVideoPlayMode())) {
	//  PTRACE(3, "Failed to set channel to " << ep.GetVideoPlayMode());
	//  return FALSE;
	//}

	//if (!grabber->SetVideoFormat(
	//    ep.GetVideoIsPal() ? PVideoDevice::PAL : PVideoDevice::NTSC)) {
	//  PTRACE(3, "Failed to set format to " << (ep.GetVideoIsPal() ? "PAL" : "NTSC"));
	//  return FALSE;
	//}

	if (!grabber->SetColourFormatConverter("YUV420P") ) 
	{
		PTRACE(3,"Failed to set format to yuv420p");
		return FALSE;
	}

	if (!grabber->SetFrameRate(30)) 
	{
		PTRACE(3, "Failed to set framerate to " << 30);
		return FALSE;
    }

	if (!grabber->SetFrameSizeConverter(newFrameWidth,newFrameHeight,FALSE)) 
	{
		PTRACE(3, "Failed to set frame size to " << newFrameWidth << "x" << newFrameHeight);
		return FALSE;
	}

	return TRUE;
}

CVideoInputDevice_OpenMCU*	CMyH323EndPoint::GetOutgoingVideo(const PString & connectionToken)
{
	H323Connection * connection = FindConnectionWithoutLocks(connectionToken);
	if (NULL != connection)
	{
		H323Channel * logicalChannel = connection->FindChannel(RTP_Session::DefaultVideoSessionID, FALSE);
		if(logicalChannel)
		{
			H323Codec * codec = logicalChannel->GetCodec();
			if(codec)
			{
				PChannel * rawChannel = codec->GetRawDataChannel();
				if (rawChannel && rawChannel->IsClass("PVideoChannel"))
				{
					PVideoChannel* pVideoChannel = (PVideoChannel*)rawChannel;
					if(pVideoChannel)
					{
						PVideoInputDevice* pVideoInputDevice = pVideoChannel->GetVideoReader();
						if(pVideoInputDevice && pVideoInputDevice->IsClass("CVideoInputDevice_OpenMCU"))
						{
							return (CVideoInputDevice_OpenMCU*)pVideoInputDevice;
						}
					}
				}
			}
		}
	}
	return NULL;
}

CVideoOutputDevice_OpenMCU*	CMyH323EndPoint::GetIncomingVideo(const PString & connectionToken)
{
	H323Connection * connection = FindConnectionWithoutLocks(connectionToken);
	if (NULL != connection)
	{
		H323Channel * logicalChannel = connection->FindChannel(RTP_Session::DefaultVideoSessionID, TRUE);
		if(logicalChannel)
		{
			H323Codec * codec = logicalChannel->GetCodec();
			if(codec)
			{
				PChannel * rawChannel = codec->GetRawDataChannel();
				if (rawChannel && rawChannel->IsClass("PVideoChannel"))
				{
					PVideoChannel* pVideoChannel = (PVideoChannel*)rawChannel;
					if(pVideoChannel)
					{
						PVideoOutputDevice* pVideoOutputDevice = pVideoChannel->GetVideoPlayer();
						if(pVideoOutputDevice && pVideoOutputDevice->IsClass("CVideoOutputDevice_OpenMCU"))
						{
							return (CVideoOutputDevice_OpenMCU*)pVideoOutputDevice;
						}
					}
				}
			}
		}
	}
	return NULL;
}