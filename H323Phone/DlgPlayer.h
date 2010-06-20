#pragma once
#include "IHPAudioPlayerChannel.h"
#include "RawVideoPlay.h"

class CH323PhoneDlg;
class DlgPlayer 
	: public CDialog
	, public IHPAudioOutput
	, public IHPVideoOutput
{
	DECLARE_DYNAMIC(DlgPlayer)

public:
	DlgPlayer(CH323PhoneDlg&rDlgHPHONE);   
	virtual ~DlgPlayer();
	
	virtual void SetFrameSize(int nWidth,int nHeight);
	virtual void OutputVideoFrame(unsigned char*pFrameData,int nFrameSize);

	CH323PhoneDlg&				m_rDlgHPHONE;
	IHPAudioPlayerChannel*	m_pIHPAudioPlayerChannel;
	CRawVideoPlay*				m_pRawVideoPlay;

	enum { IDD = IDD_DIALOG_PLAYER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()

	virtual void OnCancel();
	virtual void OnOK();
public:
	afx_msg void OnClose();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL DestroyWindow();
	void OutputAudioFrame(unsigned char*pFrameData,int nFrameSize);
	afx_msg void OnPaint();
};
