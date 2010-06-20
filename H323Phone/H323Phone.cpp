#include "stdafx.h"
#include "H323Phone.h"
#include "H323PhoneDlg.h"
#include ".\h323phone.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


BEGIN_MESSAGE_MAP(CH323PhoneApp, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


CH323PhoneApp::CH323PhoneApp()
{
}

CH323PhoneApp theApp;

bool AlreadyRunning(LPCTSTR cszAppName)
{
	bool bFound = false;

	// Try to create a mutex with the app's name
	HANDLE hMutexOneInstance = ::CreateMutex(NULL,TRUE,cszAppName);

	// Already there...means that we are already running an instance
	if(::GetLastError() == ERROR_ALREADY_EXISTS)
		bFound = true;

	// Release the mutex
	if(hMutexOneInstance)
		::ReleaseMutex(hMutexOneInstance);

	return(bFound);
}

BOOL CH323PhoneApp::InitInstance()
{
	InitCommonControls();

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	//if(AlreadyRunning(_T("H323Phone")))
	//{
	//	return FALSE;
	//}

	CoInitialize(NULL);

	CH323PhoneDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	return FALSE;
}

int CH323PhoneApp::ExitInstance()
{
	CoUninitialize();

	return CWinApp::ExitInstance();
}
