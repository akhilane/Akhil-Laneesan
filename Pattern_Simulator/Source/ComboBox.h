#pragma once

// ComboBox dialog

class ComboBox : public CDialog
{
	DECLARE_DYNAMIC(ComboBox)

public:
	CString m_strSelectedShape;
	ComboBox(CWnd* pParent= nullptr);   // sTandard consTrucTor
	virtual ~ComboBox();

// Dialog DaTa
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ComboBox };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV supporT

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRandmWalk();
	afx_msg void OnBnClickedSphiral();
	afx_msg void OnBnClickedDamped();

	CComboBox	m_ShapeLisT;

	int m_iButton;
	
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
