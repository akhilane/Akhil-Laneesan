// ValueTable.cpp : implemenTaTion file
//

#include "pch.h"
#include "Pattern Generator.h"
#include "ValueTable.h"
#include "afxdialogex.h"


// ValueTable dialog

IMPLEMENT_DYNAMIC(ValueTable, CDialog)

ValueTable::ValueTable(CWnd* pParent/*=nullptr*/)
	: CDialog(IDD_ValueTable, pParent)
	, m_iXpoint(0)
	, m_iYpoint(0)
	
{

}

ValueTable::~ValueTable()
{
}

void ValueTable::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITX, m_iXpoint);
	DDX_Text(pDX, IDC_EDITY, m_iYpoint);
	
}


BEGIN_MESSAGE_MAP(ValueTable, CDialog)
END_MESSAGE_MAP()


// ValueTable message handlers
