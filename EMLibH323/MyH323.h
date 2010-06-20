#pragma once

#include "MyH323EndPoint.h"
//#define LOG	1
class CMyH323
	: public IH323
{
public:
	CMyH323(IH323Notify& rIH323Notify);
	virtual ~CMyH323(void);
public:
	void ReleaseConnections(void);
	const char* MakeCall(const char*cszIPAddress);
	void AcceptCall(const char*cszUserID);
	void RejectCall(const char*cszUserID);
	void EndCall(const char*cszUserID);
	std::string GetUserName(const char*cszUserID);
	void SetIHPAudioOutput(const char*cszUserID,IHPAudioOutput*pIHPAudioOutput);
	IHPAudioInput*GetIHPAudioInput(const char*cszUserID);
	IHPVideoInput*GetIHPVideoInput(const char*cszUserID);
	void SetIHPVideoOutput(const char*cszUserID,IHPVideoOutput*pIHPVideoOutput);

	bool Connect(const GeneralParam& tGeneralParam,const AudioParam& tAudioParam);
public:
	CMyH323EndPoint* m_pEndPoint;
	IH323Notify&	m_rNotify;

#ifdef LOG
    BOOL OpenTraceFile();
    PTextFile * myTraceFile;
#endif
};
