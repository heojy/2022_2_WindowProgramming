// CCalculator.cpp: 구현 파일
//

#include "pch.h"
#include "Cuckoo2.h"
#include "CCalculator.h"
#include "afxdialogex.h"

#include "MainFrm.h"
#include "Cuckoo2View.h"
#include "Cuckoo2Doc.h"


// CCalculator 대화 상자

IMPLEMENT_DYNAMIC(CCalculator, CDialogEx)

CCalculator::CCalculator(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR, pParent)
	, m_strSub(_T(""))
	, m_strGrade(_T(""))
	, m_strMajor(_T(""))
	, m_strTotal(_T(""))
	, m_strRegister(_T(""))
{

}

CCalculator::~CCalculator()
{
}

void CCalculator::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SUB, m_listSub);
	DDX_CBString(pDX, IDC_LIST_SUB, m_strSub);
	DDX_Control(pDX, IDC_LIST_GRADE, m_listGrade);
	DDX_CBString(pDX, IDC_LIST_GRADE, m_strGrade);
	DDX_Text(pDX, IDC_EDIT_MAJOR, m_strMajor);
	DDX_Text(pDX, IDC_EDIT_TOTAL, m_strTotal);
	DDX_Text(pDX, IDC_EDIT_1, m_strRegister);
}


BEGIN_MESSAGE_MAP(CCalculator, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_GRADE_SAVE, &CCalculator::OnClickedButtonGradeSave)
	ON_CBN_SELCHANGE(IDC_LIST_SUB, &CCalculator::OnCbnSelchangeListSub)
	ON_CBN_SELCHANGE(IDC_LIST_GRADE, &CCalculator::OnCbnSelchangeListGrade)
END_MESSAGE_MAP()


// CCalculator 메시지 처리기


BOOL CCalculator::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CCuckoo2View *pView = (CCuckoo2View*)pFrame->GetActiveView();
	

	for (int i = 0; i < 20; i++) {
		m_strSubject[i] = pView->m_strSubject[i];
	}
	for (int i = 0; i < 20; i++) {
		if (m_strSubject[i] != _T("")) {
			m_listSub.AddString(m_strSubject[i]);
		}
	}
	for (int i = 0; i < 20; i++) {
		S = S + CCuckoo2View::Credit[i];
	}

	m_listSub.SetCurSel(0);
	m_strRegister.Format(_T("0/%d"), S);
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CCalculator::OnClickedButtonGradeSave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Grade[temp_sub] = temp_grd;
	sum_grade = 0;
	sum_grade_major = 0;
	sum_credit = 0;
	sum_credit_major = 0;
	for (int i = 0; i < 20; i++) {
		if (Grade[i] >= 0) {
			sum_grade = sum_grade + (CCuckoo2View::Credit[i] * Grade[i]);
			sum_credit = sum_credit + CCuckoo2View::Credit[i];
			if (CCuckoo2View::Major[i] > 0) {
				sum_grade_major = sum_grade_major + (CCuckoo2View::Credit[i] * Grade[i]);
				sum_credit_major = sum_credit_major + CCuckoo2View::Credit[i];
			}
		}
		
	}
	m_strTotal.Format(_T("%.02f"), sum_grade / sum_credit);
	m_strMajor.Format(_T("%.02f"), sum_grade_major / sum_credit_major);
	m_strRegister.Format(_T("%d/%d"),int(sum_credit), S);
	m_strPrintMajor.Format(_T("전공 평점 : %.02f"), sum_grade_major / sum_credit_major);
	m_strPrintTotal.Format(_T("전체 평점 : %.02f"), sum_grade / sum_credit);
	
	UpdateData(FALSE);
}


void CCalculator::OnCbnSelchangeListSub()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	temp_sub = m_listSub.GetCurSel();
	if (Grade[temp_sub] != -1) {
		if (Grade[temp_sub] == 4.5)
			m_listGrade.SetCurSel(0);
		else if (Grade[temp_sub] == 4)
			m_listGrade.SetCurSel(1);
		else if (Grade[temp_sub] == 3.5)
			m_listGrade.SetCurSel(2);
		else if (Grade[temp_sub] == 3)
			m_listGrade.SetCurSel(3);
		else if (Grade[temp_sub] == 2.5)
			m_listGrade.SetCurSel(4);
		else if (Grade[temp_sub] == 2)
			m_listGrade.SetCurSel(5);
		else if (Grade[temp_sub] == 1.5)
			m_listGrade.SetCurSel(6);
		else if (Grade[temp_sub] == 1)
			m_listGrade.SetCurSel(7);
		else if (Grade[temp_sub] == 0)
			m_listGrade.SetCurSel(8);
		else
			return;
	}
	else 
		m_listGrade.SetCurSel(8);
	
}


void CCalculator::OnCbnSelchangeListGrade()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int k = m_listGrade.GetCurSel();
	switch (k) {
	case 0:
		temp_grd = 4.5;
		break;
	case 1:
		temp_grd = 4;
		break;
	case 2:
		temp_grd = 3.5;
		break;
	case 3:
		temp_grd = 3;
		break;
	case 4:
		temp_grd = 2.5;
		break;
	case 5:
		temp_grd = 2;
		break;
	case 6:
		temp_grd = 1.5;
		break;
	case 7:
		temp_grd = 1;
		break;
	case 8:
		temp_grd = 0;
		break;
	}
}
