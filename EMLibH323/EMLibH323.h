#ifndef __EMLibH323_H__
#define __EMLibH323_H__

#include <string>

struct GeneralParam
{
	GeneralParam(int nToS,bool bDisableFastStart,bool bDisableH245Tunneling,int nBandwidth,unsigned short usRTPBasePort,const std::string&strUserName)
		:m_nToS(nToS)
		,m_usRTPBasePort(usRTPBasePort)
		,m_bDisableFastStart(bDisableFastStart)
		,m_bDisableH245Tunneling(bDisableH245Tunneling)
		,m_nBandwidth(nBandwidth)
		,m_strUserName(strUserName)
	{

	}
	int				m_nToS;
	unsigned short	m_usRTPBasePort;
	bool			m_bDisableFastStart;
	bool			m_bDisableH245Tunneling;
	int				m_nBandwidth;

	std::string		m_strUserName;
};

struct AudioParam
{
	AudioParam(bool bG7231,bool bG711ALaw,bool bG711uLaw,bool bVAD,int nJitter)
		:m_bG7231(bG7231)
		,m_bG711ALaw(bG711ALaw)
		,m_bG711uLaw(bG711uLaw)
		,m_bVAD(bVAD)
		,m_nJitter(nJitter)
	{
	}
	bool	m_bG7231;
	bool	m_bG711ALaw;
	bool	m_bG711uLaw;
	bool	m_bVAD;
	int		m_nJitter;
};

class IHPAudioInput
{
public:
	virtual void InputAudioFrame(unsigned char*pFrameData,int nFrameSize)=0;
};

class IHPAudioOutput
{
public:
	virtual void OutputAudioFrame(unsigned char*pFrameData,int nFrameSize)=0;//8000,16,mono
};

class IHPVideoInput
{
public:
	virtual bool IsVideoLarge(void)=0;
	virtual void InputVideoFrame(unsigned char*pFrameData,int nFrameSize)=0;//YUV420P
};

class IHPVideoOutput
{
public:
	virtual void SetFrameSize(int nWidth,int nHeight)=0;
	virtual void OutputVideoFrame(unsigned char*pFrameData,int nFrameSize)=0;//YUV420P
};

class IH323Notify
{
public:
	
	virtual void OnIHPH323NotifyCalled(const char*cszUserID)=0;
	
	virtual void OnIHPH323NotifyEstablished(const char*cszUserID)=0;
	
	virtual void OnIHPH323NotifyCleared(const char*cszUserID)=0;
	
	virtual void OnIHPH323NotifyIHPAudioInput(const char*cszUserID)=0;
	
	virtual void OnIHPH323NotifyIHPAudioOutput(const char*cszUserID)=0;
	virtual void OnIHPH323NotifyIHPAudioInputClose(const char*cszUserID)=0;
	
	virtual void OnIHPH323NotifyIHPVideoInput(const char*cszUserID)=0;
	
	virtual void OnIHPH323NotifyIHPVideoOutput(const char*cszUserID)=0;
	virtual void OnIHPH323NotifyIHPVideoInputClose(const char*cszUserID)=0;

};

class IH323
{
public:
	
	virtual void ReleaseConnections(void)=0;
	
	virtual const char* MakeCall(const char*cszIPAddress)=0;
	
	virtual void EndCall(const char*cszUserID)=0;
	
	virtual void AcceptCall(const char*cszUserID)=0;
	
	virtual void RejectCall(const char*cszUserID)=0;

	virtual std::string GetUserName(const char*cszUserID)=0;

	virtual void SetIHPAudioOutput(const char*cszUserID,IHPAudioOutput*pIHPAudioOutput)=0;
	virtual IHPAudioInput*GetIHPAudioInput(const char*cszUserID)=0;
	virtual IHPVideoInput*GetIHPVideoInput(const char*cszUserID)=0;
	virtual void SetIHPVideoOutput(const char*cszUserID,IHPVideoOutput*pIHPVideoOutput)=0;

};

extern "C" __declspec(dllexport) IH323* CreateIH323(IH323Notify&rIH323Notify,const GeneralParam& tGeneralParam,const AudioParam& tAudioParam);

#endif