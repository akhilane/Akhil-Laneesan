
// Pattern GeneratorView.cpp : implementation of the CPatternGeneratorView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Pattern Generator.h"
#endif

#include "Pattern GeneratorDoc.h"
#include "Pattern GeneratorView.h"
#include"Thread.h"
#include"ValueTable.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPatternGeneratorView

IMPLEMENT_DYNCREATE(CPatternGeneratorView, CView)

BEGIN_MESSAGE_MAP(CPatternGeneratorView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_THREAD_START, &CPatternGeneratorView::OnThreadStart)
	ON_COMMAND(ID_THREAD_STOP, &CPatternGeneratorView::OnThreadStop)
	ON_COMMAND(ID_SELECTPATTERN_SELECTPATTERN, &CPatternGeneratorView::OnSelectpatternSelectpattern)
	ON_COMMAND(ID_THREAD_RESUME, &CPatternGeneratorView::OnThreadResume)
END_MESSAGE_MAP()

// CPatternGeneratorView consTrucTion/desTrucTion

CPatternGeneratorView::CPatternGeneratorView() noexcept
{
	// TODO: add consTrucTion code here

}

CPatternGeneratorView::~CPatternGeneratorView()
{
}

BOOL CPatternGeneratorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify The Window class or sTyles here by modifying
	//  The CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CPatternGeneratorView drawing

void CPatternGeneratorView::OnDraw(CDC* pDC)
{
	CPatternGeneratorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;


	if (m_iCounter == 1)
	{

		pDC->MoveTo(m_iXpoint, m_iYpoint);
		pDC->LineTo(m_PointArray[1].x, m_PointArray[1].y);

		for (int i = 0; i < m_PointArray.GetSize() - 2; i++)
		{
			pDC->MoveTo(m_PointArray[i].x, m_PointArray[i].y);
			pDC->LineTo(m_PointArray[i + 1].x, m_PointArray[i + 1].y);
		}
	}

	else if (m_iCounter == 2)
	{

		pDC->MoveTo(m_iXpoint, m_iYpoint);

		for (int i = 0; i < m_SphiralArray.GetSize() - 2; i++)
		{


			pDC->LineTo(m_SphiralArray[i].x, m_SphiralArray[i].y);

		}
	}
	else if (m_iCounter == 3)
	{
		
		{
			// Axis Co-ordinaTes
		pDC->MoveTo(700, 400);
		pDC->LineTo(20 , 400);
		pDC->MoveTo(20,500 );
		pDC->LineTo(20,100);
		}

		pDC->MoveTo(m_iXpoint, m_iYpoint);

		for (int i = 0; i <= m_DampedArray.GetSize() - 1; i++)
		{
			pDC->LineTo(m_DampedArray[i].m_dXd, m_DampedArray[i].m_dYd);

		}
	}
	UpdateData();
}
	
	// TODO: add draw code for naTive daTa here



// CPatternGeneratorView printing

BOOL CPatternGeneratorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// defaulT preparaTion
	return DoPreparePrinting(pInfo);
}

void CPatternGeneratorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add exTra initialization before printing
}

void CPatternGeneratorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup afTer printing
}


// CPatternGeneratorView diagnosTics

#ifdef _DEBUG
void CPatternGeneratorView::AssertValid() const
{
	CView::AssertValid();
}

void CPatternGeneratorView::Dump(CDumpConText& dc) const
{
	CView::Dump(dc);
}

CPatternGeneratorDoc* CPatternGeneratorView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocumenT->IsKindOf(RUNTIME_CLASS(CPatternGeneratorDoc)));
	return (CPatternGeneratorDoc*)m_pDocumenT;
}
#endif //_DEBUG


// CPatternGeneratorView message handlers


void CPatternGeneratorView::OnThreadStart()
{
	// TODO: Add your command handler code here
	
		pThread = AfxBeginThread(Thread::RunThreadFunction, this);
	
}


void CPatternGeneratorView::OnThreadStop()
{
	// TODO: Add your command handler code here
	pThread->SuspendThread();
}




void CPatternGeneratorView::OnSelectpatternSelectpattern()
{
	// TODO: Add your command handler code here
	ComboBox comboDlg;
	comboDlg.DoModal();
	
	m_iCounter = comboDlg.m_iButton;

	ValueTable valueDlg;
	valueDlg.DoModal();

	m_iXpoint = valueDlg.m_iXpoint;
	m_iYpoint = valueDlg.m_iYpoint;

	
	
}


void CPatternGeneratorView::OnThreadResume()
{
	// TODO: Add your command handler code here

		pThread->ResumeThread();
	
}
