#include "stdafx.h"
#include "H323Phone.h"
#include "DlgCapture.h"
#include "H323PhoneDlg.h"

IMPLEMENT_DYNAMIC(DlgCapture, CDialog)
DlgCapture::DlgCapture(CH323PhoneDlg&rDlgHPHONE)
	: CDialog(DlgCapture::IDD, &rDlgHPHONE)
	, m_rDlgHPHONE(rDlgHPHONE)
	, m_pIHPAudioCaptureChannel(NULL)
	, m_pUSBVideoCapture(NULL)
{
	m_pIHPAudioInput=NULL;
	m_pIHPVideoInput=NULL;
}

DlgCapture::~DlgCapture()
{
}

void DlgCapture::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgCapture, CDialog)
	ON_WM_CLOSE()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

void DlgCapture::OnCancel()
{
}

void DlgCapture::OnOK()
{
}

void DlgCapture::OnClose()
{
}


BOOL DlgCapture::OnEraseBkgnd(CDC* pDC)
{
	if(m_pUSBVideoCapture == NULL)
	{
		CRect rcClient;
		GetClientRect(&rcClient);
		pDC->FillRect(rcClient, &CBrush(RGB(57, 125, 243)));
		pDC->FrameRect(rcClient,&CBrush(RGB(255,255,255)));
	}

	return TRUE;
}

BOOL DlgCapture::DestroyWindow()
{
	CloseVideoCapture();
	CloseAudioCapture();

	return CDialog::DestroyWindow();
}

void DlgCapture::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	if (m_pUSBVideoCapture)
	{
		CRect rc;
		GetClientRect(rc);
		m_pUSBVideoCapture->SetVideoWindowPosition(0,0,rc.Width(),rc.Height());
	}
}

void DlgCapture::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CDialog::OnLButtonDblClk(nFlags, point);
}

void DlgCapture::OnIHPAudioCaptureChannelNotifyData(char*pData,int nLen)
{
	if (m_pIHPAudioInput)
	{
		m_pIHPAudioInput->InputAudioFrame((unsigned char*)pData,nLen);
	}
}

void DlgCapture::OpenAudioCapture(void)
{
	if (m_pIHPAudioCaptureChannel==NULL)
	{
		m_pIHPAudioCaptureChannel=m_rDlgHPHONE.m_HPVoiceEngine.CreateIHPAudioCaptureChannel(*this);
	}
}

void DlgCapture::CloseAudioCapture(void)
{
	if (m_pIHPAudioCaptureChannel)
	{
		m_pIHPAudioCaptureChannel->ReleaseConnections();
		delete m_pIHPAudioCaptureChannel;
		m_pIHPAudioCaptureChannel=NULL;
	}
}

void DlgCapture::OpenVideoCapture(bool bVideoLarge)
{
	CloseVideoCapture();

	int nDevice = 0;
	unsigned short usFrameRate=10;
	unsigned short usWidth=bVideoLarge?352:176;
	unsigned short usHeight=bVideoLarge?288:144;

	m_pUSBVideoCapture=new CUSBVideoCapture(*this);
	if(m_pUSBVideoCapture->Connect(m_hWnd,nDevice,usWidth,usHeight,usFrameRate) == false)
	{
		m_pUSBVideoCapture->ReleaseConnections();
		delete m_pUSBVideoCapture;
		m_pUSBVideoCapture=NULL;
	}
}

void DlgCapture::CloseVideoCapture(void)
{
	if (m_pUSBVideoCapture)
	{
		m_pUSBVideoCapture->ReleaseConnections();
		delete m_pUSBVideoCapture;
		m_pUSBVideoCapture=NULL;
	}
}

void DlgCapture::OnVideoCaptureFrame(const void* pFrameData,int nFrameLen)
{
	if (m_pIHPVideoInput)
	{
		m_pIHPVideoInput->InputVideoFrame((unsigned char*)pFrameData,nFrameLen);
	}
}