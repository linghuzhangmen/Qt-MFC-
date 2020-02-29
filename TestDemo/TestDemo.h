
// TestDemo.h : TestDemo Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������
#include <QSplashScreen>
#include "MainUI.h"


// CTestDemoApp:
// �йش����ʵ�֣������ TestDemo.cpp
//

class CTestDemoApp : public CWinAppEx
{
public:
	CTestDemoApp();

	//��дRun�������ض�MFC��Ϣ����
	virtual BOOL Run();

// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

	afx_msg void onMainUI(WPARAM wParam, LPARAM lParam);
	afx_msg void onMainExit(WPARAM wParam, LPARAM lParam);

private:
	QSplashScreen *m_SplashScreen;
	CMainUI *m_UI;
};

extern CTestDemoApp theApp;
