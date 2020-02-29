
// TestDemo.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "TestDemo.h"
#include "MainFrm.h"
#include "TestDemoDoc.h"
#include "TestDemoView.h"
#include <QtWidgets/QApplication>
#include <QDateTime>
#include "MyApp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//�Զ�����Ϣ��MFC����Qt����
#define MainUI     WM_USER + 1000

//�Զ�����Ϣ���쳣�˳�
#define MainExit   WM_USER + 1001


// CTestDemoApp

BEGIN_MESSAGE_MAP(CTestDemoApp, CWinAppEx)
	//ON_COMMAND(ID_APP_ABOUT, &CTestDemoApp::OnAppAbout)
	//// �����ļ��ı�׼�ĵ�����
	//ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	//ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	//// ��׼��ӡ��������
	//ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)

	ON_THREAD_MESSAGE(MainUI, onMainUI)
	ON_THREAD_MESSAGE(MainExit, onMainExit)
END_MESSAGE_MAP()


// CTestDemoApp ����

CTestDemoApp::CTestDemoApp()
{
	// ֧����������������
//	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
//#ifdef _MANAGED
//	// ���Ӧ�ó��������ù�����������ʱ֧��(/clr)�����ģ���: 
//	//     1) �����д˸������ã�������������������֧�ֲ�������������
//	//     2) ��������Ŀ�У������밴������˳���� System.Windows.Forms ������á�
//	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
//#endif
//
//	// TODO: ������Ӧ�ó��� ID �ַ����滻ΪΨһ�� ID �ַ�����������ַ�����ʽ
//	//Ϊ CompanyName.ProductName.SubProduct.VersionInformation
//	SetAppID(_T("TestDemo.AppID.NoVersion"));

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CTestDemoApp ����

CTestDemoApp theApp;


// CTestDemoApp ��ʼ��

BOOL CTestDemoApp::InitInstance()
{
	CWinApp::InitInstance();

	//Qt������ʾ����Ϣ
	PostMessage(NULL, MainUI, 0, 0);

	return TRUE;
}

int CTestDemoApp::ExitInstance()
{
	//TODO: �����������ӵĸ�����Դ
	//AfxOleTerm(FALSE);
	SAFE_DELETE(m_UI);

	return CWinAppEx::ExitInstance();
}

// CTestDemoApp ��Ϣ�������


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// �������жԻ����Ӧ�ó�������
void CTestDemoApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CTestDemoApp ��Ϣ�������
void CTestDemoApp::onMainUI(WPARAM wParam, LPARAM lParam)
{
	// ����������ʾλ��
	Qt::Alignment topRight = Qt::AlignBottom | Qt::AlignRight;
	QString startPng = qApp->applicationDirPath() + "\\start.png";

	//������������ͼƬ
	QSplashScreen *m_AppSplash = new QSplashScreen(QPixmap(startPng));
	m_AppSplash->show();

	//��ʾ����ʾ��
	m_AppSplash->showMessage(QString::fromLocal8Bit("���������У����3��"), topRight, Qt::white);

	((QApplication *)QApplication::instance())->processEvents();
	QDateTime n = QDateTime::currentDateTime();
	QDateTime now;

	//������ʱ�����߲����ã����������������ʾ����������Ҳ����ʧ
	do
	{
		now = QDateTime::currentDateTime();
	} 
	while (n.secsTo(now) <= 3);  //3Ϊ��Ҫ��ʱ������

	m_UI = new CMainUI();
	m_UI->show();   //��������ʾ

	m_AppSplash->finish(m_UI); //��mainwindow��ʾ���Լ�����ʧ
	delete m_AppSplash;      //�ͷ���Դ
	m_AppSplash = NULL;
}

void CTestDemoApp::onMainExit(WPARAM wParam, LPARAM lParam)
{

}

//�ض�MFC��Ϣѭ��������Qt��Ϣѭ��
BOOL CTestDemoApp::Run()
{
	return CMyApp::run(this);
}

