
// Cuckoo2View.cpp: CCuckoo2View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Cuckoo2.h"
#endif

#include "Cuckoo2Doc.h"
#include "Cuckoo2View.h"
#include "CMainViewDlg.h"
#include "CAddSubject.h"
#include "CCalculator.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int CCuckoo2View::Credit[20] = { 0 };
int CCuckoo2View::Major[20] = { 0 };
// CCuckoo2View

IMPLEMENT_DYNCREATE(CCuckoo2View, CView)

BEGIN_MESSAGE_MAP(CCuckoo2View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_BUTTON_ADD_SUBJECT, &CCuckoo2View::OnButtonAddSubject)
	ON_COMMAND(ID_BUTTON_CALCULATOR, &CCuckoo2View::OnButtonCalculator)
END_MESSAGE_MAP()

// CCuckoo2View 생성/소멸

CCuckoo2View::CCuckoo2View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CCuckoo2View::~CCuckoo2View()
{
}

BOOL CCuckoo2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.
	//cs.lpszName = _T("Cuckoo2");
	//cs.style &= ~FWS_ADDTOTITLE;
	
	return CView::PreCreateWindow(cs);
}

// CCuckoo2View 그리기

void CCuckoo2View::OnDraw(CDC* pDC)
{
	CCuckoo2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

	CFont font, font1, *oldfont;
	int fontSize = 10;
	CString fontName = _T("맑은 고딕");

	font.CreatePointFont(10 * fontSize, fontName);
	oldfont = pDC->SelectObject(&font);
	CRect rect1(30, 0, 90, 30);
	CRect rect2(90, 0, 150, 30);
	CRect rect3(150, 0, 210, 30);
	CRect rect4(210, 0, 270, 30);
	CRect rect5(270, 0, 330, 30);
	CRect rect6(330, 0, 390, 30);

	pDC->DrawText(_T("월"), &rect1, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	pDC->DrawText(_T("화"), &rect2, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	pDC->DrawText(_T("수"), &rect3, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	pDC->DrawText(_T("목"), &rect4, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	pDC->DrawText(_T("금"), &rect5, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	pDC->DrawText(_T("토"), &rect6, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	
	CRect rect7(0, 0, 27, 60);
	CRect rect8(0, 30, 27, 130);
	CRect rect9(0, 80, 27, 180);
	CRect rect10(0, 130, 27, 230);
	CRect rect11(0, 180, 27, 280);
	CRect rect12(0, 230, 27, 330);
	CRect rect13(0, 280, 27, 380);
	CRect rect14(0, 330, 27, 430);
	CRect rect15(0, 380, 27, 480);
	CRect rect16(0, 430, 27, 530);
	CRect rect17(0, 480, 27, 580);
	CRect rect18(0, 530, 27, 630);
	CRect rect19(0, 580, 27, 680);
	CRect rect20(0, 630, 27, 730);

	pDC->DrawText(_T("9"), &rect7, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
	pDC->DrawText(_T("10"), &rect8, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
	pDC->DrawText(_T("11"), &rect9, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
	pDC->DrawText(_T("12"), &rect10, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
	pDC->DrawText(_T("1"), &rect11, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
	pDC->DrawText(_T("2"), &rect12, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
	pDC->DrawText(_T("3"), &rect13, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
	pDC->DrawText(_T("4"), &rect14, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
	pDC->DrawText(_T("5"), &rect15, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
	pDC->DrawText(_T("6"), &rect16, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
	pDC->DrawText(_T("7"), &rect17, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
	pDC->DrawText(_T("8"), &rect18, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
	pDC->DrawText(_T("9"), &rect19, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
	pDC->DrawText(_T("10"), &rect20, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);

	CPen pen1, *oldpen;
	pen1.CreatePen(PS_SOLID, 1, RGB(200, 200, 200));
	oldpen = pDC->SelectObject(&pen1);
	pDC->MoveTo(30, 0);
	pDC->LineTo(30, 680);
	pDC->MoveTo(90, 0);
	pDC->LineTo(90, 680);
	pDC->MoveTo(150, 0);
	pDC->LineTo(150, 680);
	pDC->MoveTo(210, 0);
	pDC->LineTo(210, 680);
	pDC->MoveTo(270, 0);
	pDC->LineTo(270, 680);
	pDC->MoveTo(330, 0);
	pDC->LineTo(330, 680);
	pDC->MoveTo(390, 0);
	pDC->LineTo(390, 680);

	pDC->MoveTo(30, 30);
	pDC->LineTo(390, 30);
	pDC->MoveTo(30, 80);
	pDC->LineTo(390, 80);
	pDC->MoveTo(30, 130);
	pDC->LineTo(390, 130);
	pDC->MoveTo(30, 180);
	pDC->LineTo(390, 180);
	pDC->MoveTo(30, 230);
	pDC->LineTo(390, 230);
	pDC->MoveTo(30, 280);
	pDC->LineTo(390, 280);
	pDC->MoveTo(30, 330);
	pDC->LineTo(390, 330);
	pDC->MoveTo(30, 380);
	pDC->LineTo(390, 380);
	pDC->MoveTo(30, 430);
	pDC->LineTo(390, 430);
	pDC->MoveTo(30, 480);
	pDC->LineTo(390, 480);
	pDC->MoveTo(30, 530);
	pDC->LineTo(390, 530);
	pDC->MoveTo(30, 580);
	pDC->LineTo(390, 580);

	pDC->MoveTo(30, 630);
	pDC->LineTo(390, 630);
	pDC->MoveTo(30, 680);
	pDC->LineTo(390, 680);
	
	pen1.DeleteObject();
	
	font1.CreatePointFont(9 * fontSize, fontName);
	oldfont = pDC->SelectObject(&font1);
		
	for (int i = 0; i < 78; i++) {
		for (int j = 2; j < 20; j++) {
			if (subject[i] == j) {
				pDC->DrawText(m_strSubject[j - 2], &m_rcSquares[i], DT_CENTER | DT_WORDBREAK);
			}
		}
	}

	oldfont = pDC->SelectObject(&font);

	for (int i = 0; i < 78; i++) {
		CString number;
		CString subject_name;
		if (subject[i] == 1) {
			pDC->DrawText(_T("#"), &m_rcSquares[i], DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		}
	}
	pDC->DrawText(m_strTotal, &m_rcGrade[0], DT_SINGLELINE | DT_LEFT | DT_VCENTER);
	pDC->DrawText(m_strMajor, &m_rcGrade[1], DT_SINGLELINE | DT_LEFT | DT_VCENTER);
	font.DeleteObject();
	font1.DeleteObject();
}

void CCuckoo2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCuckoo2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCuckoo2View 진단

#ifdef _DEBUG
void CCuckoo2View::AssertValid() const
{
	CView::AssertValid();
}

void CCuckoo2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCuckoo2Doc* CCuckoo2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCuckoo2Doc)));
	return (CCuckoo2Doc*)m_pDocument;
}
#endif //_DEBUG


// CCuckoo2View 메시지 처리기


int CCuckoo2View::GetRectID(CPoint point)
{
	// TODO: 여기에 구현 코드 추가.
	for (int i = 0; i < 78; i++) {
		if (m_rcSquares[i].PtInRect(point))
			return i;
	}
	return -1;
}

void CCuckoo2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int k = GetRectID(point);

	if (k == -1) {
		return;
	}
	subject[k] = 1;
	Invalidate(true);
	CView::OnLButtonDown(nFlags, point);
}

void CCuckoo2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int k = GetRectID(point);
	if (k == -1) {
		return;
	}
	subject[k] = 0;
	Invalidate(true);
	CView::OnRButtonDown(nFlags, point);
}


void CCuckoo2View::OnButtonAddSubject()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int b = 0;
	for (int i=0; i < 78; i++) {
		if (subject[i] == 1)
			b = 1;
	}

	if (b == 1) {
		CAddSubject* pdlgAdd = new CAddSubject;
		if (pdlgAdd->DoModal() == IDOK) {
			m_strName = pdlgAdd->m_strName;
			m_strSubName = pdlgAdd->m_strSubName;
			m_strSubject[count] = pdlgAdd->m_strSubName;
			Credit[count] = pdlgAdd->Credit;
			Major[count] = pdlgAdd->Major;
			for (int i = 0; i < 78; i++) {
				if (subject[i] == 1)
					subject[i] = subject[i] + count+1;
			}
			count++;
			Invalidate(true);
			b = 0;
		}
	}
	else
		return;
}

void CCuckoo2View::OnButtonCalculator()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (m_strSubject[0] != _T("")) {
		CCalculator* pdlgCal = new CCalculator;
		if (pdlgCal->DoModal() == IDOK) {
			m_strMajor = pdlgCal->m_strPrintMajor;
			m_strTotal = pdlgCal->m_strPrintTotal;
			Invalidate(true);
		}
	}
	else
		return;

}
