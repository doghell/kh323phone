
#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
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
