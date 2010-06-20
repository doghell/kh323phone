#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif

#ifndef WINVER				
#define WINVER 0x0400		
#endif

#ifndef _WIN32_WINNT		
#define _WIN32_WINNT 0x0400	
#endif						

#ifndef _WIN32_WINDOWS		
#define _WIN32_WINDOWS 0x0410 
#endif

#ifndef _WIN32_IE			
#define _WIN32_IE 0x0400	
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	

#define _AFX_ALL_WARNINGS

#include <afxwin.h>         
#include <afxext.h>         
#include <afxdisp.h>        

#include <afxdtctl.h>		
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			
#endif 

#include <dshow.h>
#include <atlbase.h>
#include <d3d9.h>
#include <vmr9.h>

//#include <Qedit.h>
#include <streams.h>
#include <initguid.h>

#pragma comment(lib, "quartz.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "msacm32.lib")
#pragma comment(lib, "olepro32.lib")
#pragma comment(lib, "strmiids.lib")

#include "../EMLibH323/EMLibH323.h"
#ifdef _DEBUG
#pragma comment(lib,"../lib/debug/EMLibH323.lib")
#pragma comment(lib, "../lib/debug/strmbasd.lib")
#pragma comment(lib,"../lib/debug/portaudio_x86.lib")
#pragma comment(lib,"../lib/debug/libmplayer.lib")
#else
#pragma comment(lib,"../lib/release/EMLibH323.lib")
#pragma comment(lib, "../lib/release/STRMBASE.lib")
#pragma comment(lib,"../lib/release/portaudio_x86.lib")
#pragma comment(lib,"../lib/release/libmplayer.lib")
#endif

const GUID MEDIASUBTYPE_I420 = {0x30323449, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71};
