
// MyUtils.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMyUtilsApp: 
// �йش����ʵ�֣������ MyUtils.cpp
//

class CMyUtilsApp : public CWinApp
{
public:
	CMyUtilsApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMyUtilsApp theApp;