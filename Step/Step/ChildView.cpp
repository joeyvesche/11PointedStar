
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "Step.h"
#include "ChildView.h"
#include "CLineDlg.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "CParamDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{

    m_linefmx = 0.5;
    m_linefmy = 0.5;
    m_linetox = 0.2;
    m_linetoy = 0.55;

    m_linexcoord = 1.2;
    m_lineycoord = 0.5;
    m_linerotation = 0.0;
    m_lineedgelength = 0.7;

}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, COpenGLWnd)
	ON_WM_PAINT()
    ON_COMMAND(ID_STEPSTUFF_LINEENDTO0, &CChildView::OnStepstuffLineendto0)
    ON_COMMAND(ID_LINEDIALOG_ABOUTLINEDLG, &CChildView::OnStepstuffLineDlg)

    ON_COMMAND(ID_STEPSTUFF_ROTATEHENDECAGRAM, &CChildView::OnStepstuffRotatehendecagram)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!COpenGLWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnGLDraw(CDC* pDC)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int width, height;
    GetSize(width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, // left
        GLdouble(width) / GLdouble(height), // right
        0.0, // bottom
        1.0, // top
        1.0, // near
        -1.0); // far

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3d(1., 0., 0.);

    glBegin(GL_POLYGON);
    glVertex2d(0.25, 0.25);
    glVertex2d(0.75, 0.25);
    glVertex2d(0.75, 0.75);
    glVertex2d(0.25, 0.75);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2d(0.1, 0.1);
    glVertex2d(0.8, 0.22);
    glVertex2d(0.78, 0.9);
    glVertex2d(0.2, 0.9);
    glEnd();


	// Draw the line
    glColor3d(1., 1., 0.);
	glBegin(GL_LINES);
	glVertex2d(m_linefmx, m_linefmy);
	glVertex2d(m_linetox, m_linetoy);
	glEnd();

    // Making the rectangle rotate with star
    
    // Save the current matrix
    glPushMatrix();

    // Translate to the center of star
    glTranslated(m_linexcoord, m_lineycoord, 0.0);

    // Rotate the whole coordinate system
    double rotation = m_linerotation * M_PI / 180;
    glRotated(m_linerotation, 0.0, 0.0, 1.0);

    // Translate back
    glTranslated(-m_linexcoord, -m_lineycoord, 0.0);

    // Drawing the rectangle
    glColor3d(0., 1., 0.);
    glBegin(GL_LINE_LOOP);
    double halfEdgeLength = m_lineedgelength / 2;
    glVertex2d(m_linexcoord - halfEdgeLength, m_lineycoord - halfEdgeLength);
    glVertex2d(m_linexcoord + halfEdgeLength, m_lineycoord - halfEdgeLength);
    glVertex2d(m_linexcoord + halfEdgeLength, m_lineycoord + halfEdgeLength);
    glVertex2d(m_linexcoord - halfEdgeLength, m_lineycoord + halfEdgeLength);
    glEnd();

    // Draw the hendecagram (11-pointed star) inside the rectangle
    glColor3d(1., 0., 0.); // Red color for the star
    glBegin(GL_LINES);
    int sides = 11;
    int skip = 3; // Add skip to adjust pattern
    for (int i = 0; i < sides; ++i) {
        double angle = i * (2 * M_PI / sides);
        double x = halfEdgeLength * cos(angle);
        double y = halfEdgeLength * sin(angle);

        int connectTo = (i + skip) % sides;
        double connectAngle = connectTo * (2 * M_PI / sides);
        double connectX = halfEdgeLength * cos(connectAngle);
        double connectY = halfEdgeLength * sin(connectAngle);

        glVertex2d(m_linexcoord + x, m_lineycoord + y);
        glVertex2d(m_linexcoord + connectX, m_lineycoord + connectY);
    }
    glEnd();

    // Restore matrix
    glPopMatrix();

}


void CChildView::OnStepstuffLineendto0()
{
    m_linetox = 0.1;
    m_linetoy = 0.1;

    Invalidate();
}


void CChildView::OnStepstuffLineDlg() {
   
    CLineDlg dlg;

    dlg.m_fmx = m_linefmx;
    dlg.m_fmy = m_linefmy;
    dlg.m_fmtox = m_linetox;
    dlg.m_fmtoy = m_linetoy;

    if (dlg.DoModal() == IDOK)
    {
        m_linefmx = dlg.m_fmx;
        m_linefmy = dlg.m_fmy;
        m_linetox = dlg.m_fmtox;
        m_linetoy = dlg.m_fmtoy;

        Invalidate();
    }

    

}

void CChildView::OnStepstuffRotatehendecagram()
{
    CParamDlg ParamDlg;
    
    ParamDlg.m_xcoord = m_linexcoord;
    ParamDlg.m_ycoord = m_lineycoord;
    ParamDlg.m_rotation = m_linerotation;
    ParamDlg.m_edgelength = m_lineedgelength;

    if (ParamDlg.DoModal() == IDOK)
    {
        m_linexcoord = ParamDlg.m_xcoord;
        m_lineycoord = ParamDlg.m_ycoord;
        m_linerotation = ParamDlg.m_rotation;
        m_lineedgelength = ParamDlg.m_edgelength;

        Invalidate();
    }

}
