// CLineDlg.cpp : implementation file
//

#include "pch.h"
#include "Step.h"
#include "afxdialogex.h"
#include "CLineDlg.h"


// CLineDlg dialog

IMPLEMENT_DYNAMIC(CLineDlg, CDialog)

CLineDlg::CLineDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_LINEDLG, pParent)
	, m_fmx(0)
	, m_fmy(0)
	, m_fmtox(0)
	, m_fmtoy(0)
{

}

CLineDlg::~CLineDlg()
{
}

void CLineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FMX, m_fmx);
	DDX_Text(pDX, IDC_FMY, m_fmy);
	DDX_Text(pDX, IDC_TOX, m_fmtox);
	DDX_Text(pDX, IDC_TOY, m_fmtoy);
}


BEGIN_MESSAGE_MAP(CLineDlg, CDialog)
END_MESSAGE_MAP()


// CLineDlg message handlers
