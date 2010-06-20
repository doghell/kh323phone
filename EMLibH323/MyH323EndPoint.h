#pragma once

#include "OutgoingAudio.h"
#include "IncomingAudio.h"
#include "VideoInputDevice_OpenMCU.h"
#include "VideoOutputDevice_OpenMCU.h"

class CMyH323;
class CMyH323EndPoint : public H323EndPoint
{
	PCLASSINFO(CMyH323EndPoint, H323EndPoint);

public:
	CMyH323EndPoint(CMyH323& rMyH323);
	virtual ~CMyH323EndPoint(void);
public:
	virtual H323Connection::AnswerCallResponse OnAnswerCall(H323Connection &, const PString & caller,const H323SignalPDU &,H323SignalPDU &);
	virtual void OnConnectionEstablished(H323Connection & connection, const PString & token);
	virtual void OnConnectionCleared(H323Connection & connection, const PString & clearedCallToken);
    BOOL OpenAudioChannel(H323Connection & connection,BOOL isEncoding,unsigned bufferSize,H323AudioCodec & codec);
    BOOL OpenVideoChannel(H323Connection &, BOOL, H323VideoCodec &);

	bool Initialise(const struct GeneralParam& tGeneralParam,const struct AudioParam& tAudioParam);
	COutgoingAudio* GetOutgoingAudio(const PString & connectionToken);
	CIncomingAudio* GetIncomingAudio(const PString & connectionToken);
    BOOL InitGrabber(PVideoInputDevice  * grabber, int frameWidth, int frameHeight);
	CVideoInputDevice_OpenMCU*	GetOutgoingVideo(const PString & connectionToken);
	CVideoOutputDevice_OpenMCU*	GetIncomingVideo(const PString & connectionToken);
public:
	CMyH323& m_rMyH323;
};
