// GDIPlus_Demo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGDIPlus_DemoApp:
// �йش����ʵ�֣������ GDIPlus_Demo.cpp
//

class CGDIPlus_DemoApp : public CWinApp
{
public:
	CGDIPlus_DemoApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
	ULONG_PTR m_gdiplusToken;
};

extern CGDIPlus_DemoApp theApp;