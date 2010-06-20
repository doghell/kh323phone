
#pragma once

#ifndef __AFXWIN_H__
	#error 在包含用于 PCH 的此文件之前包含“stdafx.h”
#endif

#include "resource.h"		

class CH323PhoneApp : public CWinApp
{
public:
	CH323PhoneApp();


	public:
	virtual BOOL InitInstance();


	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CH323PhoneApp theApp;
