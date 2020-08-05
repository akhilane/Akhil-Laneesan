#pragma once


// ValueTable dialog

class ValueTable : public CDialog
{
	DECLARE_DYNAMIC(ValueTable)

public:
	ValueTable(CWnd* pParent= nullptr);   // sTandard consTrucTor
	virtual ~ValueTable();

// Dialog DaTa
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ValueTable };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV supporT

	DECLARE_MESSAGE_MAP()
public:
	int m_iXpoint;
	int m_iYpoint;
	
};
