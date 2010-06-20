#include "stdafx.h"
#include "H323Phone.h"
#include "DlgPlayer.h"
#include "H323PhoneDlg.h"

IMPLEMENT_DYNAMIC(DlgPlayer, CDialog)
DlgPlayer::DlgPlayer(CH323PhoneDlg&rDlgHPHONE)
	: CDialog(DlgPlayer::IDD, &rDlgHPHONE)
	, m_rDlgHPHONE(rDlgHPHONE)
	, m_pIHPAudioPlayerChannel(NULL)
	, m_pRawVideoPlay(NULL)
{
}

DlgPlayer::~DlgPlayer()
{
}

void DlgPlayer::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgPlayer, CDialog)
	ON_WM_CLOSE()
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_SIZE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


void DlgPlayer::OnCancel()
{
}

void DlgPlayer::OnOK()
{
}

void DlgPlayer::OnClose()
{
}
int DlgPlayer::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_pIHPAudioPlayerChannel=m_rDlgHPHONE.m_HPVoiceEngine.CreateIHPAudioPlayerChannel();

	return 0;
}

BOOL DlgPlayer::OnEraseBkgnd(CDC* pDC)
{
	if(m_pRawVideoPlay == NULL)
	{
		CRect rcClient;
		GetClientRect(&rcClient);
		pDC->FillRect(rcClient, &CBrush(RGB(57, 125, 243)));
		pDC->FrameRect(rcClient,&CBrush(RGB(255,255,255)));
	}

	return TRUE;
}

void DlgPlayer::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CDialog::OnLButtonDblClk(nFlags, point);
}

void DlgPlayer::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	if (m_pRawVideoPlay)
	{
		CRect rc;
		GetClientRect(rc);
		m_pRawVideoPlay->SetVideoWindowPosition(0,0,rc.Width(),rc.Height());
	}
}

BOOL DlgPlayer::DestroyWindow()
{
	if(m_pRawVideoPlay)
	{
		m_pRawVideoPlay->ReleaseConnections();
		delete m_pRawVideoPlay;
		m_pRawVideoPlay = NULL;
	}
	if (m_pIHPAudioPlayerChannel)
	{
		m_pIHPAudioPlayerChannel->ReleaseConnections();
		delete m_pIHPAudioPlayerChannel;
		m_pIHPAudioPlayerChannel=NULL;
	}

	return CDialog::DestroyWindow();
}

void DlgPlayer::OutputAudioFrame(unsigned char*pFrameData,int nFrameSize)
{
	if (m_pIHPAudioPlayerChannel)
	{
		m_pIHPAudioPlayerChannel->PlayFrame((char*)pFrameData,nFrameSize);
	}
}

void DlgPlayer::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	
	if(m_pRawVideoPlay)
	{
		m_pRawVideoPlay->RepaintVideo(m_hWnd,dc.m_hDC);
	}
}

void DlgPlayer::OutputVideoFrame(unsigned char*pFrameData,int nFrameSize)
{
	if(m_pRawVideoPlay)
	{
		m_pRawVideoPlay->PlayVideo(pFrameData,nFrameSize);
	}
}

void DlgPlayer::SetFrameSize(int nWidth,int nHeight)
{
	if(m_pRawVideoPlay)
	{
		m_pRawVideoPlay->ReleaseConnections();
		delete m_pRawVideoPlay;
		m_pRawVideoPlay = NULL;
	}
	m_pRawVideoPlay = new CRawVideoPlay;
	if(m_pRawVideoPlay->Connect(m_hWnd,nWidth,nHeight))
	{
		CRect rc;
		GetClientRect(rc);
		m_pRawVideoPlay->SetVideoWindowPosition(0,0,rc.Width(),rc.Height());
	}
	else
	{
		m_pRawVideoPlay->ReleaseConnections();
		delete m_pRawVideoPlay;
		m_pRawVideoPlay = NULL;
	}
}