#pragma once
#include "afxdialogex.h"


// CParamDlg dialog

class CParamDlg : public CDialog
{
	DECLARE_DYNAMIC(CParamDlg)

public:
	CParamDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CParamDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGROTATE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double m_xcoord;
	double m_ycoord;
	double m_rotation;
	double m_edgelength;
};
