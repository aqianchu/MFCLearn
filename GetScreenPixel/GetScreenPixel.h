
// GetScreenPixel.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGetScreenPixelApp:
// �йش����ʵ�֣������ GetScreenPixel.cpp
//

class CGetScreenPixelApp : public CWinApp
{
public:
	CGetScreenPixelApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CGetScreenPixelApp theApp;