
// Pattern GeneratorView.h : interface of The CPatternGeneratorView class
//

#pragma once
#include "Pattern GeneratorDoc.h"
#include"ComboBox.h"
#include"CPoints.h"

class CPatternGeneratorView : public CView
{
protected: // creaTe from serializaTion only
	CPatternGeneratorView() noexcept;
	DECLARE_DYNCREATE(CPatternGeneratorView)

// ATTribuTes
public:
	CPatternGeneratorDoc* GetDocument() const;

// OperaTions
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden To draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ImplemenTaTion
public:
	virtual ~CPatternGeneratorView();
	CWinThread* pThread;
	long m_lCounter;
	CString m_strSelectedShape;
	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
public:
	CArray<CPoint, CPoint> m_PointArray;
	CArray<CPoint, CPoint> m_SphiralArray;
	CArray<CPointDamp, CPointDamp> m_DampedArray;

	
	int m_iCounter = 0;
	int m_iXpoint;
	int m_iYpoint;
protected:

// GeneraTed message map funcTions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnThreadStart();
	afx_msg void OnThreadStop();
	
	afx_msg void OnSelectpatternSelectpattern();
	afx_msg void OnThreadResume();
};

#ifndef _DEBUG  // debug version in Pattern GeneratorView.cpp
inline CPatternGeneratorDoc* CPatternGeneratorView::GetDocument() const
   { return reinterpret_cast<CPatternGeneratorDoc*>(m_pDocument); }
#endif

