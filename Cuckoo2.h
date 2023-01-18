
// Cuckoo2.h: Cuckoo2 응용 프로그램의 기본 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 주 기호입니다.


// CCuckoo2App:
// 이 클래스의 구현에 대해서는 Cuckoo2.cpp을(를) 참조하세요.
//

class CCuckoo2App : public CWinAppEx
{
public:
	CCuckoo2App() noexcept;


// 재정의입니다.
public:
	virtual BOOL InitInstance();

// 구현입니다.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCuckoo2App theApp;
