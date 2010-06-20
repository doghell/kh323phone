#pragma once

#include "IHPAudioCaptureChannel.h"
#include "USBVideoCapture.h"


class CH323PhoneDlg;
class DlgCapture 
	: public CDialog
	, public IHPAudioCaptureChannelNotify
	, public CUSBVideoCaptureNotify
{
	DECLARE_DYNAMIC(DlgCapture)

public:
	DlgCapture(CH323PhoneDlg&rDlgHPHONE); 
	virtual ~DlgCapture();

	CH323PhoneDlg&				m_rDlgHPHONE;
	IHPAudioInput*			m_pIHPAudioInput;
	IHPAudioCaptureChannel*	m_pIHPAudioCaptureChannel;
	CUSBVideoCapture*			m_pUSBVideoCapture;
	IHPVideoInput*			m_pIHPVideoInput;

	
	enum { IDD = IDD_DIALOG_CAPTURE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()

	virtual void OnCancel();
	virtual void OnOK();
public:
	afx_msg void OnClose();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL DestroyWindow();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	
	void OnIHPAudioCaptureChannelNotifyData(char*pData,int nLen);
	void OpenAudioCapture(void);
	void CloseAudioCapture(void);

	void OnVideoCaptureFrame(const void* pFrameData,int nFrameLen);
	void OpenVideoCapture(bool bVideoLarge);
	void CloseVideoCapture(void);

};
