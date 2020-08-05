// ComboBox.cpp : implemenTaTion file
//

#include "pch.h"
#include "Pattern Generator.h"
#include "ComboBox.h"
#include "afxdialogex.h"
#include "Pattern GeneratorDoc.h"
#include "Pattern GeneratorView.h"



// ComboBox dialog

IMPLEMENT_DYNAMIC(ComboBox, CDialog)

ComboBox::ComboBox(CWnd* pParent/*=nullptr*/)
	: CDialog(IDD_ComboBox, pParent)
{

}

ComboBox::~ComboBox()
{
}

void ComboBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ComboBox, CDialog)
	
	ON_BN_CLICKED(IDC_RANDM_WALK, &ComboBox::OnBnClickedRandmWalk)
	ON_BN_CLICKED(IDC_SPHIRAL, &ComboBox::OnBnClickedSphiral)
	ON_BN_CLICKED(IDC_DAMPED, &ComboBox::OnBnClickedDamped)
	ON_BN_CLICKED(IDOK, &ComboBox::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &ComboBox::OnBnClickedCancel)
END_MESSAGE_MAP()


// ComboBox message handlers
//CPatternGeneratorView pComboBoxView = new CPatternGeneratorView;


void ComboBox::OnBnClickedRandmWalk()
{
	// TODO: Add your conTrol noTificaTion handler code here	
	m_iButton = 1;
	
}


void ComboBox::OnBnClickedSphiral()
{
	// TODO: Add your conTrol noTificaTion handler code here
	m_iButton = 2;
}


void ComboBox::OnBnClickedDamped()
{
	// TODO: Add your conTrol noTificaTion handler code here
	m_iButton = 3;
	
}


void ComboBox::OnBnClickedOk()
{
	// TODO: Add your conTrol noTificaTion handler code here
	//UpdateData();
	

	CDialog::OnOK();
}


void ComboBox::OnBnClickedCancel()
{
	// TODO: Add your conTrol noTificaTion handler code here
	CDialog::OnCancel();
}
