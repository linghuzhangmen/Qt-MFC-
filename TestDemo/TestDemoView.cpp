
// TestDemoView.cpp : CTestDemoView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "TestDemo.h"
#endif

#include "TestDemoDoc.h"
#include "TestDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestDemoView

IMPLEMENT_DYNCREATE(CTestDemoView, CView)

BEGIN_MESSAGE_MAP(CTestDemoView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CTestDemoView ����/����

CTestDemoView::CTestDemoView()
{
	// TODO: �ڴ˴���ӹ������

}

CTestDemoView::~CTestDemoView()
{
}

BOOL CTestDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CTestDemoView ����

void CTestDemoView::OnDraw(CDC* /*pDC*/)
{
	CTestDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CTestDemoView ��ӡ

BOOL CTestDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CTestDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CTestDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CTestDemoView ���

#ifdef _DEBUG
void CTestDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CTestDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestDemoDoc* CTestDemoView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDemoDoc)));
	return (CTestDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestDemoView ��Ϣ�������
