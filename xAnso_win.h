
// xAnso_win.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CxAnso_winApp: 
// �йش����ʵ�֣������ xAnso_win.cpp
//

class CxAnso_winApp : public CWinApp
{
public:
	CxAnso_winApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CxAnso_winApp theApp;