
#pragma once

typedef enum
{
	HP_CALL_SM_IDLE=0,
	HP_CALL_SM_RING_IN,
	HP_CALL_SM_RING_OUT,
	HP_CALL_SM_TALKING,
	HP_CALL_SM_ENDED
}HP_CALL_SM;

#include "HPVoiceEngine.h"
#include "DlgCapture.h"
#include "DlgPlayer.h"


class CH323PhoneDlg 
	: public CDialog
	, public IH323Notify
{

public:
	CH323PhoneDlg(CWnd* pParent = NULL);	


	enum { IDD = IDD_H323PHONE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	
public:
	
	virtual void OnIHPH323NotifyCalled(const char*cszUserID);
	
	virtual void OnIHPH323NotifyEstablished(const char*cszUserID);
	
	virtual void OnIHPH323NotifyCleared(const char*cszUserID);
	
	virtual void OnIHPH323NotifyIHPAudioInput(const char*cszUserID);
	
	virtual void OnIHPH323NotifyIHPAudioOutput(const char*cszUserID);
	virtual void OnIHPH323NotifyIHPAudioInputClose(const char*cszUserID);
	
	virtual void OnIHPH323NotifyIHPVideoInput(const char*cszUserID);
	
	virtual void OnIHPH323NotifyIHPVideoOutput(const char*cszUserID);
	virtual void OnIHPH323NotifyIHPVideoInputClose(const char*cszUserID);
public:
	IH323*	m_pIH323;
		
	std::string		m_strCallUserID;
	HP_CALL_SM		m_HPCallSM;
	HPVoiceEngine	m_HPVoiceEngine;
	DlgCapture*		m_pDlgCapture;
	DlgPlayer*		m_pDlgPlayer;

	CButton m_btnSubVideo;
	CEdit	m_editAddress;
	CButton m_btnCall;
	CButton m_btnHangup;
	CStatic m_staticStatus;
	CButton m_btnPreview;

	bool StartH323(void);
	void StopH323(void);
	void ResizeControls(void);
	void ResetWindowRgn(CWnd*pMainWnd,CWnd*pSubWnd);
	void OnCallStatusChanged(void);
	void SetStatus(const CString&strStatus);

	LRESULT OnRingIn(WPARAM wParam, LPARAM lParam);
	LRESULT OnCallEstablished(WPARAM wParam, LPARAM lParam);
	LRESULT OnCallEnded(WPARAM wParam, LPARAM lParam);
	LRESULT OnAudioInput(WPARAM wParam, LPARAM lParam);
	LRESULT OnAudioOutput(WPARAM wParam, LPARAM lParam);
	LRESULT OnVideoInput(WPARAM wParam, LPARAM lParam);
	LRESULT OnVideoOutput(WPARAM wParam, LPARAM lParam);


protected:
	HICON m_hIcon;


	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButtonCall();
	afx_msg void OnBnClickedButtonHangup();
	afx_msg void OnUpdateEditAddress();
	afx_msg void OnChangeEditAddress();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedButtonSubVideo();
	afx_msg void OnBnClickedCheckPreview();
};
