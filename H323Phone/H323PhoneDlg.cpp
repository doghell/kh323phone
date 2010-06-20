
#include "stdafx.h"
#include "H323Phone.h"
#include "H323PhoneDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    


protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


#define UM_RING_IN					(WM_USER+1)
#define UM_CALL_ESTABLISHED			(WM_USER+2)
#define UM_CALL_ENDED				(WM_USER+3)
#define UM_AUDIO_INPUT				(WM_USER+6)
#define UM_AUDIO_OUTPUT				(WM_USER+7)
#define UM_VIDEO_INPUT				(WM_USER+4)
#define UM_VIDEO_OUTPUT				(WM_USER+5)

#define BOTTOM_TOOL_BAR_HEIGHT		20
#define BOTTOM_STATUS_BAR_HEIGHT	16
#define CTR_BAR_CMD_WIDTH			50

CH323PhoneDlg::CH323PhoneDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CH323PhoneDlg::IDD, pParent)
	, m_pIH323(NULL)
	, m_HPCallSM(HP_CALL_SM_IDLE)
	, m_pDlgCapture(NULL)
	, m_pDlgPlayer(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strCallUserID = "";
}

void CH323PhoneDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ADDRESS, m_editAddress);
	DDX_Control(pDX, IDC_BUTTON_CALL, m_btnCall);
	DDX_Control(pDX, IDC_BUTTON_HANGUP, m_btnHangup);
	DDX_Control(pDX, IDC_STATIC_STATUS, m_staticStatus);
	DDX_Control(pDX, IDC_BUTTON_SUB_VIDEO, m_btnSubVideo);
	DDX_Control(pDX, IDC_CHECK_PREVIEW, m_btnPreview);
}

BEGIN_MESSAGE_MAP(CH323PhoneDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_CALL, OnBnClickedButtonCall)
	ON_MESSAGE(UM_RING_IN,OnRingIn)
	ON_MESSAGE(UM_CALL_ESTABLISHED,OnCallEstablished)
	ON_MESSAGE(UM_CALL_ENDED,OnCallEnded)
	ON_BN_CLICKED(IDC_BUTTON_HANGUP, OnBnClickedButtonHangup)
	ON_EN_UPDATE(IDC_EDIT_ADDRESS, OnUpdateEditAddress)
	ON_EN_CHANGE(IDC_EDIT_ADDRESS, OnChangeEditAddress)
	ON_MESSAGE(UM_AUDIO_INPUT,OnAudioInput)
	ON_MESSAGE(UM_AUDIO_OUTPUT,OnAudioOutput)
	ON_WM_SIZE()
	ON_MESSAGE(UM_VIDEO_INPUT,OnVideoInput)
	ON_MESSAGE(UM_VIDEO_OUTPUT,OnVideoOutput)
	ON_BN_CLICKED(IDC_BUTTON_SUB_VIDEO, OnBnClickedButtonSubVideo)
	ON_BN_CLICKED(IDC_CHECK_PREVIEW, OnBnClickedCheckPreview)
END_MESSAGE_MAP()


BOOL CH323PhoneDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);		
	SetIcon(m_hIcon, FALSE);

	m_HPVoiceEngine.Connect(0,0);

	m_pDlgCapture=new DlgCapture(*this);
	m_pDlgCapture->Create(DlgCapture::IDD,this);

	m_HPCallSM=(HP_CALL_SM_IDLE);
	OnCallStatusChanged();

	ResizeControls();

	if(StartH323() == false)
	{
		AfxMessageBox(_T("Kh323Phone initialization failed, please close the other h.323 endpoint and then restart Kh323Phone."));
		return FALSE;
	}

	return TRUE;
}

void CH323PhoneDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

void CH323PhoneDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this);

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CH323PhoneDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CH323PhoneDlg::OnDestroy()
{
	__super::OnDestroy();

	if (m_strCallUserID.length())
	{
		if (m_pIH323)
		{
			m_pIH323->EndCall(m_strCallUserID.c_str());
		}
	}

	StopH323();

	if (m_pDlgCapture)
	{
		m_pDlgCapture->DestroyWindow();
		delete m_pDlgCapture;
		m_pDlgCapture=NULL;
	}
	if (m_pDlgPlayer)
	{
		m_pDlgPlayer->DestroyWindow();
		delete m_pDlgPlayer;
		m_pDlgPlayer=NULL;
	}

	m_HPVoiceEngine.ReleaseConnections();
}

void CH323PhoneDlg::OnBnClickedButtonCall()
{
	switch (m_HPCallSM)
	{
	case HP_CALL_SM_IDLE:
		{
			CString strText;
			m_editAddress.GetWindowText(strText);
			if (strText.GetLength())
			{
				USES_CONVERSION;
				if (m_pIH323)
				{
					m_strCallUserID=m_pIH323->MakeCall(W2A(strText));
					if (m_strCallUserID.length())
					{
						m_HPCallSM=HP_CALL_SM_RING_OUT;
					}
					else
					{

					}
				}
			}
		}
		break;
	case HP_CALL_SM_RING_IN:
		{
			if (m_pIH323)
			{
				m_pIH323->AcceptCall(m_strCallUserID.c_str());
			}
		}
		break;
	case HP_CALL_SM_RING_OUT:
		break;
	case HP_CALL_SM_TALKING:
		break;
	case HP_CALL_SM_ENDED:
		{

		}
		break;
	}
	OnCallStatusChanged();
}

void CH323PhoneDlg::OnCallStatusChanged(void)
{
	switch (m_HPCallSM)
	{
	case HP_CALL_SM_IDLE:
		{
			m_btnCall.SetWindowText(_T("Call"));
			m_btnHangup.SetWindowText(_T("Hangup"));

			CString strAddr;
			m_editAddress.GetWindowText(strAddr);
			m_btnCall.EnableWindow(strAddr.GetLength()!=0);

			m_btnHangup.EnableWindow(FALSE);
			m_btnSubVideo.EnableWindow(FALSE);
			m_btnPreview.EnableWindow(TRUE);
			
			SetStatus(_T("Kh323Phone - free"));

			if (m_btnPreview.GetCheck())
			{
				if (m_pDlgCapture)
				{
					m_pDlgCapture->OpenVideoCapture(true);
				}
			}
		}
		break;
	case HP_CALL_SM_RING_IN:
		{
			m_btnCall.SetWindowText(_T("Answer"));
			m_btnHangup.SetWindowText(_T("Reject"));
			m_btnCall.EnableWindow(TRUE);
			m_btnHangup.EnableWindow(TRUE);
			m_btnSubVideo.EnableWindow(FALSE);
			m_btnPreview.EnableWindow(FALSE);

			if (m_pIH323)
			{
				std::string strUserName=m_pIH323->GetUserName(m_strCallUserID.c_str());

				USES_CONVERSION;
				CString strText;
				strText.Format(_T("Kh323Phone - %s is calling..."),A2W(strUserName.c_str()));
				SetStatus(strText);
			}
		}
		break;
	case HP_CALL_SM_RING_OUT:
		{
			m_btnCall.SetWindowText(_T("Call"));
			m_btnHangup.SetWindowText(_T("Hangup"));
			m_btnCall.EnableWindow(FALSE);
			m_btnHangup.EnableWindow(TRUE);
			m_btnSubVideo.EnableWindow(FALSE);
			m_btnPreview.EnableWindow(FALSE);

			if (m_pIH323)
			{
				std::string strUserName=m_pIH323->GetUserName(m_strCallUserID.c_str());

				USES_CONVERSION;
				CString strText;
				strText.Format(_T("Kh323Phone - Calling %s..."),A2W(strUserName.c_str()));
				SetStatus(strText);
			}
		}
		break;
	case HP_CALL_SM_TALKING:
		{
			m_btnCall.SetWindowText(_T("Call"));
			m_btnHangup.SetWindowText(_T("Hangup"));
			m_btnCall.EnableWindow(FALSE);
			m_btnHangup.EnableWindow(TRUE);
			m_btnSubVideo.EnableWindow(TRUE);
			m_btnPreview.EnableWindow(FALSE);

			if (m_pIH323)
			{
				std::string strUserName=m_pIH323->GetUserName(m_strCallUserID.c_str());
			
				USES_CONVERSION;
				CString strText;
				strText.Format(_T("Kh323Phone - Talking to %s..."),A2W(strUserName.c_str()));
				SetStatus(strText);
			}
		}
		break;
	case HP_CALL_SM_ENDED:
		{
			m_btnCall.SetWindowText(_T("Call"));
			m_btnHangup.SetWindowText(_T("Hangup"));
			m_btnCall.EnableWindow(FALSE);
			m_btnHangup.EnableWindow(FALSE);
			m_btnSubVideo.EnableWindow(FALSE);
			m_btnPreview.EnableWindow(FALSE);
		}
		break;
	}
	ResizeControls();
}

void CH323PhoneDlg::SetStatus(const CString&strStatus)
{
	m_staticStatus.SetWindowText(strStatus);
}

void CH323PhoneDlg::OnIHPH323NotifyCalled(const char*cszUserID)
{
	if (m_strCallUserID.length())
	{
		if (m_pIH323)
		{
			m_pIH323->RejectCall(cszUserID);
		}
	}
	else
	{
		m_strCallUserID=cszUserID;
		PostMessage(UM_RING_IN);
	}
}

LRESULT CH323PhoneDlg::OnRingIn(WPARAM wParam, LPARAM lParam)
{
	if (m_pIH323)
	{
		if (m_HPCallSM==HP_CALL_SM_IDLE)
		{
			m_HPCallSM=HP_CALL_SM_RING_IN;

			OnCallStatusChanged();
		}
	}

	return 0;
}

LRESULT CH323PhoneDlg::OnCallEstablished(WPARAM wParam, LPARAM lParam)
{
	m_HPCallSM=HP_CALL_SM_TALKING;

	OnCallStatusChanged();
	return 0;
}

LRESULT CH323PhoneDlg::OnCallEnded(WPARAM wParam, LPARAM lParam)
{
	if (m_pDlgPlayer)
	{
		if (m_pIH323)
		{
			m_pIH323->SetIHPVideoOutput(m_strCallUserID.c_str(),NULL);
			m_pIH323->SetIHPAudioOutput(m_strCallUserID.c_str(),NULL);
		}	
		
		m_pDlgPlayer->DestroyWindow();
		delete m_pDlgPlayer;
		m_pDlgPlayer=NULL;
	}

	m_HPCallSM=HP_CALL_SM_IDLE;
	m_strCallUserID="";

	OnCallStatusChanged();
	
	return 0;
}

void CH323PhoneDlg::OnIHPH323NotifyEstablished(const char*cszUserID)
{
	PostMessage(UM_CALL_ESTABLISHED);
}

void CH323PhoneDlg::OnIHPH323NotifyCleared(const char*cszUserID)
{
	PostMessage(UM_CALL_ENDED);
}

void CH323PhoneDlg::StopH323(void)
{
	OnBnClickedButtonHangup();
	while (m_HPCallSM!=HP_CALL_SM_IDLE)
	{
		MSG msg;
		if( GetMessage(&msg, NULL, 0, 0) )
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	if (m_pIH323)
	{
		m_pIH323->ReleaseConnections();
		m_pIH323=NULL;
	}
}

void CH323PhoneDlg::OnBnClickedButtonHangup()
{
	switch (m_HPCallSM)
	{
	case HP_CALL_SM_IDLE:
		break;
	case HP_CALL_SM_RING_IN:
		{
			if (m_pIH323)
			{
				m_pIH323->RejectCall(m_strCallUserID.c_str());
			}
			m_HPCallSM=HP_CALL_SM_ENDED;
		}
		break;
	case HP_CALL_SM_RING_OUT:
		{
			if (m_pIH323)
			{
				m_pIH323->EndCall(m_strCallUserID.c_str());
			}
			m_HPCallSM=HP_CALL_SM_ENDED;
		}
		break;
	case HP_CALL_SM_TALKING:
		{
			if (m_pIH323)
			{
				m_pIH323->EndCall(m_strCallUserID.c_str());
			}
			m_HPCallSM=HP_CALL_SM_ENDED;
		}
		break;
	case HP_CALL_SM_ENDED:
		{

		}
		break;
	}

	OnCallStatusChanged();
}

bool CH323PhoneDlg::StartH323(void)
{
	StopH323();

	GeneralParam tGeneralParam(0xB0,false,false,128000,5000,"Kh323Phone");
	AudioParam tAudioParam(true,true,true,true,50);

	m_pIH323 = CreateIH323(*this,tGeneralParam,tAudioParam);
	return (m_pIH323 != NULL);
}

void CH323PhoneDlg::OnUpdateEditAddress() 
{
	CString strAddr;
	m_editAddress.GetWindowText(strAddr);
	m_btnCall.EnableWindow(strAddr.GetLength()!=0);
}

void CH323PhoneDlg::OnChangeEditAddress() 
{
	CString strAddr;
	m_editAddress.GetWindowText(strAddr);
	m_btnCall.EnableWindow(strAddr.GetLength()!=0);
}

void CH323PhoneDlg::OnIHPH323NotifyIHPAudioInput(const char*cszUserID)
{
	PostMessage(UM_AUDIO_INPUT);
}

void CH323PhoneDlg::OnIHPH323NotifyIHPAudioOutput(const char*cszUserID)
{
	PostMessage(UM_AUDIO_OUTPUT);
}

LRESULT CH323PhoneDlg::OnAudioInput(WPARAM wParam, LPARAM lParam)
{
	if (m_pDlgCapture)
	{
		m_pDlgCapture->CloseAudioCapture();

		if (m_pIH323)
		{
			m_pDlgCapture->m_pIHPAudioInput=m_pIH323->GetIHPAudioInput(m_strCallUserID.c_str());
			if (m_pDlgCapture->m_pIHPAudioInput)
			{
				m_pDlgCapture->OpenAudioCapture();
			}
		}
	}

	return 0;
}

LRESULT CH323PhoneDlg::OnAudioOutput(WPARAM wParam, LPARAM lParam)
{
	if (m_pDlgPlayer==NULL)
	{
		m_pDlgPlayer=new DlgPlayer(*this);
		m_pDlgPlayer->Create(DlgPlayer::IDD,this);
	}
	if (m_pIH323)
	{
		m_pIH323->SetIHPAudioOutput(m_strCallUserID.c_str(),m_pDlgPlayer);
	}	

	return 0;
}

void CH323PhoneDlg::ResizeControls(void)
{
	CRect rc;
	GetClientRect(rc);
	int y=0;

	if (m_editAddress.GetSafeHwnd())
	{
		m_editAddress.SetWindowPos(NULL,0,y,rc.Width()-4*CTR_BAR_CMD_WIDTH,BOTTOM_TOOL_BAR_HEIGHT,SWP_SHOWWINDOW|SWP_NOACTIVATE);
	}
	if (m_btnCall.GetSafeHwnd())
	{
		m_btnCall.SetWindowPos(NULL,rc.Width()-4*CTR_BAR_CMD_WIDTH,y,CTR_BAR_CMD_WIDTH,BOTTOM_TOOL_BAR_HEIGHT,SWP_SHOWWINDOW|SWP_NOACTIVATE);
	}
	if (m_btnHangup.GetSafeHwnd())
	{
		m_btnHangup.SetWindowPos(NULL,rc.Width()-3*CTR_BAR_CMD_WIDTH,y,CTR_BAR_CMD_WIDTH,BOTTOM_TOOL_BAR_HEIGHT,SWP_SHOWWINDOW|SWP_NOACTIVATE);
	}
	if (m_btnSubVideo.GetSafeHwnd())
	{
		m_btnSubVideo.SetWindowPos(NULL,rc.Width()-2*CTR_BAR_CMD_WIDTH,y,CTR_BAR_CMD_WIDTH,BOTTOM_TOOL_BAR_HEIGHT,SWP_SHOWWINDOW|SWP_NOACTIVATE);
		m_btnSubVideo.EnableWindow(m_HPCallSM==HP_CALL_SM_TALKING);
	}
	if (m_btnPreview.GetSafeHwnd())
	{
		m_btnPreview.SetWindowPos(NULL,rc.Width()-CTR_BAR_CMD_WIDTH,y,CTR_BAR_CMD_WIDTH,BOTTOM_TOOL_BAR_HEIGHT,SWP_SHOWWINDOW|SWP_NOACTIVATE);
	}
	y=rc.Height() - BOTTOM_STATUS_BAR_HEIGHT;

	if (m_staticStatus.GetSafeHwnd())
	{
		m_staticStatus.SetWindowPos(NULL,0,y,rc.Width(),BOTTOM_STATUS_BAR_HEIGHT,SWP_SHOWWINDOW|SWP_NOACTIVATE);
	}

	y-=BOTTOM_TOOL_BAR_HEIGHT;

	if (m_pDlgPlayer&& m_pDlgPlayer->GetSafeHwnd())
	{
		ResetWindowRgn(m_pDlgPlayer,m_pDlgCapture);
	}
	else
	{
		if (m_pDlgCapture && m_pDlgCapture->GetSafeHwnd())
		{
			ResetWindowRgn(m_pDlgCapture,NULL);
		}
	}
}

void CH323PhoneDlg::ResetWindowRgn(CWnd*pMainWnd,CWnd*pSubWnd)
{
	if (pMainWnd)
	{
		CRect rc;
		GetClientRect(&rc);
		CRect rcFS;
		rcFS.SetRect(0,0,rc.Width(),rc.Height()-BOTTOM_TOOL_BAR_HEIGHT-BOTTOM_STATUS_BAR_HEIGHT);
		CRgn rgnDraw;
		rgnDraw.CreateRectRgnIndirect(&rcFS);
		if(pSubWnd)
		{
			int nWidth = rcFS.Width() / 3;
			int nHeight = rcFS.Height() / 3;
			CRect rcSub;
			rcSub.SetRect(nWidth * 2, nHeight * 2, rcFS.Width(),rcFS.Height());
			if (m_btnSubVideo.GetCheck()!=0)
			{
				CRgn rgnFilled;
				rgnFilled.CreateRectRgnIndirect(rcSub);
				rgnDraw.CombineRgn(&rgnDraw,&rgnFilled,RGN_DIFF);
				pSubWnd->SetWindowPos(NULL,rcSub.left,rcSub.top+BOTTOM_TOOL_BAR_HEIGHT,rcSub.Width(),rcSub.Height(),SWP_SHOWWINDOW|SWP_NOACTIVATE);
			}
			else
			{
				pSubWnd->SetWindowPos(NULL,rcSub.left,rcSub.top+BOTTOM_TOOL_BAR_HEIGHT,rcSub.Width(),rcSub.Height(),SWP_HIDEWINDOW|SWP_NOACTIVATE);
			}
		}
		::SetWindowRgn(pMainWnd->m_hWnd,(HRGN)rgnDraw,TRUE);

		pMainWnd->SetWindowPos(NULL,0,BOTTOM_TOOL_BAR_HEIGHT,rcFS.Width(),rcFS.Height(),SWP_SHOWWINDOW|SWP_NOACTIVATE);
	}
}

void CH323PhoneDlg::OnIHPH323NotifyIHPAudioInputClose(const char*cszUserID)
{
	if (m_pDlgCapture)
	{
		m_pDlgCapture->CloseAudioCapture();

		m_pDlgCapture->m_pIHPAudioInput=NULL;
	}
}

void CH323PhoneDlg::OnSize(UINT nType, int cx, int cy)
{
	__super::OnSize(nType, cx, cy);

	ResizeControls();
}

void CH323PhoneDlg::OnIHPH323NotifyIHPVideoOutput(const char*cszUserID)
{
	PostMessage(UM_VIDEO_OUTPUT);
}

LRESULT CH323PhoneDlg::OnVideoInput(WPARAM wParam, LPARAM lParam)
{
	if (m_pDlgCapture)
	{
		m_pDlgCapture->CloseVideoCapture();
		if (m_pIH323)
		{
			m_pDlgCapture->m_pIHPVideoInput=m_pIH323->GetIHPVideoInput(m_strCallUserID.c_str());
			if (m_pDlgCapture->m_pIHPVideoInput)
			{
				m_pDlgCapture->OpenVideoCapture(m_pDlgCapture->m_pIHPVideoInput->IsVideoLarge());
			}
		}
	}

	return 0;
}

LRESULT CH323PhoneDlg::OnVideoOutput(WPARAM wParam, LPARAM lParam)
{
	if (m_pDlgPlayer==NULL)
	{
		m_pDlgPlayer=new DlgPlayer(*this);
		m_pDlgPlayer->Create(DlgPlayer::IDD,this);
	}
	if (m_pIH323)
	{
		m_pIH323->SetIHPVideoOutput(m_strCallUserID.c_str(),m_pDlgPlayer);
	}

	return 0;
}

void CH323PhoneDlg::OnIHPH323NotifyIHPVideoInput(const char*cszUserID)
{
	PostMessage(UM_VIDEO_INPUT);
}

void CH323PhoneDlg::OnBnClickedButtonSubVideo()
{
	ResizeControls();
}

void CH323PhoneDlg::OnIHPH323NotifyIHPVideoInputClose(const char*cszUserID)
{
	if (m_pDlgCapture)
	{
		m_pDlgCapture->CloseVideoCapture();

		m_pDlgCapture->m_pIHPVideoInput=NULL;
	}
}

void CH323PhoneDlg::OnBnClickedCheckPreview()
{
	if (m_HPCallSM==HP_CALL_SM_IDLE)
	{
		if (m_btnPreview.GetCheck())
		{
			m_pDlgCapture->OpenVideoCapture(true);
		}
		else
		{
			m_pDlgCapture->CloseVideoCapture();
		}
	}
}
