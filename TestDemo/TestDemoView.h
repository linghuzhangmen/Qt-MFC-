
// TestDemoView.h : CTestDemoView ��Ľӿ�
//

#pragma once


class CTestDemoView : public CView
{
protected: // �������л�����
	CTestDemoView();
	DECLARE_DYNCREATE(CTestDemoView)

// ����
public:
	CTestDemoDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CTestDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // TestDemoView.cpp �еĵ��԰汾
inline CTestDemoDoc* CTestDemoView::GetDocument() const
   { return reinterpret_cast<CTestDemoDoc*>(m_pDocument); }
#endif

