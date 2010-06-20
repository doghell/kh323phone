#include "StdAfx.h"
#include ".\myh323.h"

extern "C" __declspec(dllexport) IH323* CreateIH323(IH323Notify&rIH323Notify,const GeneralParam& tGeneralParam,const AudioParam& tAudioParam)
{
	CMyH323* pMyH323 = new CMyH323(rIH323Notify);
	if(pMyH323)
	{
		if(pMyH323->Connect(tGeneralParam,tAudioParam) == false)
		{
			pMyH323->ReleaseConnections();
			pMyH323 = NULL;
		}
	}
	return pMyH323;
}

CMyH323::CMyH323(IH323Notify& rIH323Notify)
: m_pEndPoint(NULL)
, m_rNotify(rIH323Notify)
{
#ifdef LOG
    myTraceFile = NULL;
	OpenTraceFile();
#endif
}

CMyH323::~CMyH323(void)
{
#ifdef LOG
	if(myTraceFile)
	{
		delete myTraceFile;
		myTraceFile = NULL;
	}
#endif
}

bool CMyH323::Connect(const GeneralParam& tGeneralParam,const AudioParam& tAudioParam)
{
	PTRACE(4, "MyH323\tCall Endpoint Initialize");
	m_pEndPoint = new CMyH323EndPoint(*this);
	if(m_pEndPoint == NULL)
	{
		return false;
	}
	if(m_pEndPoint->Initialise(tGeneralParam,tAudioParam) == false)
	{
		return false;
	}
	return true;
}

void CMyH323::ReleaseConnections(void)
{
	if(m_pEndPoint)
	{
		delete m_pEndPoint;
		m_pEndPoint = NULL;
	}
	delete this;
}

const char* CMyH323::MakeCall(const char*cszIPAddress)
{
	PString szToken;
	m_pEndPoint->MakeCall(cszIPAddress,szToken);
	return szToken;
}

void CMyH323::AcceptCall(const char*cszUserID)
{
	if(m_pEndPoint->HasConnection(cszUserID))
	{
		H323Connection * connection = m_pEndPoint->FindConnectionWithLock(cszUserID);
		if (connection)
		{
			connection->AnsweringCall(H323Connection::AnswerCallNow);
			connection->Unlock();
		}
	}
}

void CMyH323::RejectCall(const char*cszUserID)
{
	if(m_pEndPoint->HasConnection(cszUserID))
	{
		H323Connection * connection = m_pEndPoint->FindConnectionWithLock(cszUserID);
		if (connection)
		{
			connection->AnsweringCall(H323Connection::AnswerCallDenied);
			connection->Unlock();
		}
	}
}

void CMyH323::EndCall(const char*cszUserID)
{
	if(m_pEndPoint->HasConnection(cszUserID))
	{
		m_pEndPoint->ClearCall(cszUserID);
	}
}

std::string CMyH323::GetUserName(const char*cszUserID)
{
	PString szUserName;
	if(m_pEndPoint->HasConnection(cszUserID))
	{
		H323Connection * connection = m_pEndPoint->FindConnectionWithLock(cszUserID);
		if (connection)
		{
			szUserName = connection->GetRemotePartyName();
			connection->Unlock();
		}
	}
	if(szUserName.IsEmpty())
	{
		szUserName = cszUserID;
	}
	return szUserName;
}

void CMyH323::SetIHPAudioOutput(const char*cszUserID,IHPAudioOutput*pIHPAudioOutput)
{
	CIncomingAudio* pIncomingAudio = m_pEndPoint->GetIncomingAudio(cszUserID);
	if(pIncomingAudio)
	{
		pIncomingAudio->SetIHPAudioOutput(pIHPAudioOutput);
	}
}

IHPAudioInput* CMyH323::GetIHPAudioInput(const char*cszUserID)
{
	COutgoingAudio* pOutgoingAudio = m_pEndPoint->GetOutgoingAudio(cszUserID);
	if(pOutgoingAudio)
	{
		return pOutgoingAudio;
	}
	return NULL;
}

IHPVideoInput* CMyH323::GetIHPVideoInput(const char*cszUserID)
{
	CVideoInputDevice_OpenMCU* pOutgoingVideo = m_pEndPoint->GetOutgoingVideo(cszUserID);
	if(pOutgoingVideo)
	{
		return pOutgoingVideo;
	}
	return NULL;
}

void CMyH323::SetIHPVideoOutput(const char*cszUserID,IHPVideoOutput*pIHPVideoOutput)
{
	CVideoOutputDevice_OpenMCU* pIncomingVideo = m_pEndPoint->GetIncomingVideo(cszUserID);
	if(pIncomingVideo)
	{
		pIncomingVideo->SetIHPVideoOutput(pIHPVideoOutput);
	}
}

#ifdef LOG	// If Compiled with PTlib Tracing support (like in OpenH323)

BOOL CMyH323::OpenTraceFile()
{
	PTrace::SetLevel(6);
	PTrace::SetOptions(PTrace::FileAndLine);
	PTrace::SetOptions(PTrace::TraceLevel);
	PTrace::SetOptions(PTrace::DateAndTime);
	
	PString traceFileName = "h323phone_trc.txt";
	
	// If already have a trace file, see if need to close it
	if (myTraceFile != NULL) 
	{
		// If no change, do nothing more
		if (myTraceFile->GetFilePath() == PFilePath(traceFileName))
			return TRUE;
		
		PTrace::SetStream(NULL);
		delete myTraceFile;
		myTraceFile = NULL;
	}
	
	// Have stopped 
	if (traceFileName.IsEmpty())
		return TRUE;
	
	PTextFile * traceFile = new PTextFile;
	if (traceFile->Open(traceFileName, PFile::WriteOnly)) {
		myTraceFile = traceFile;
		PTrace::SetStream(traceFile);
		PProcess & process = PProcess::Current();
		PTRACE(0, process.GetName()
			<< " Version " << process.GetVersion(TRUE)
			<< " by " << process.GetManufacturer()
			<< " on " << process.GetOSClass() << ' ' << process.GetOSName()
			<< " (" << process.GetOSVersion() << '-' << process.GetOSHardware() << ')');
		
		return TRUE;
	}
	
	delete traceFile;
	return FALSE;
}

#endif