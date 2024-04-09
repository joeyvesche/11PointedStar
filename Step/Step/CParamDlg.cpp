// CParamDlg.cpp : implementation file
//

#include "pch.h"
#include "Step.h"
#include "afxdialogex.h"
#include "CParamDlg.h"


// CParamDlg dialog

IMPLEMENT_DYNAMIC(CParamDlg, CDialog)

CParamDlg::CParamDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOGROTATE, pParent)
	, m_xcoord(0)
	, m_ycoord(0)
	, m_rotation(0)
	, m_edgelength(0)
{

}

CParamDlg::~CParamDlg()
{
}

void CParamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_XCOORD, m_xcoord);
	DDX_Text(pDX, IDC_YCOORD, m_ycoord);
	DDX_Text(pDX, IDC_ROTATION, m_rotation);
	DDX_Text(pDX, IDC_EDGELENGTH, m_edgelength);
}


BEGIN_MESSAGE_MAP(CParamDlg, CDialog)
END_MESSAGE_MAP()


// CParamDlg message handlers
