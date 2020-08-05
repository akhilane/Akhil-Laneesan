
// Pattern Generator.h : main header file for The Pattern Generator application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CPatternGeneratorApp :
// See Pattern Generator.cpp for The implemenTaTion of this class
//

class CPatternGeneratorApp  : public CWinApp
{
public:
	CPatternGeneratorApp () noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ImplemenTaTion
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPatternGeneratorApp TheApp;
