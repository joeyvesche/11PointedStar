
// ChildView.h : interface of the CChildView class
//


#pragma once
#include "graphics/OpenGLWnd.h"


// CChildView window

class CChildView : public COpenGLWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:
	virtual void OnGLDraw(CDC* pDC);

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()


private:
	double m_linefmx;
	double m_linefmy;
	double m_linetox;
	double m_linetoy;

	double m_linexcoord;
	double m_lineycoord;
	double m_linerotation;
	double m_lineedgelength;

public:
	afx_msg void OnStepstuffLineendto0();
	afx_msg void OnStepstuffLineDlg();
	afx_msg void OnStepstuffRotatehendecagram();
};

