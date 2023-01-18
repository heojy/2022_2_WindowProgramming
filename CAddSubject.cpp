// CAddSubject.cpp: 구현 파일
//

#include "pch.h"
#include "Cuckoo2.h"
#include "CAddSubject.h"
#include "afxdialogex.h"

#include "MainFrm.h"
#include "Cuckoo2View.h"
#include "Cuckoo2Doc.h"

// CAddSubject 대화 상자

IMPLEMENT_DYNAMIC(CAddSubject, CDialogEx)

CAddSubject::CAddSubject(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD_SUBJECT, pParent)
	, m_strName(_T(""))
	, m_strSubName(_T(""))
{

}

CAddSubject::~CAddSubject()
{
}

void CAddSubject::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_SUB_NAME, m_strSubName);
}


BEGIN_MESSAGE_MAP(CAddSubject, CDialogEx)
	
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CAddSubject 메시지 처리기


BOOL CAddSubject::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CCuckoo2View *pView = (CCuckoo2View*)pFrame->GetActiveView();

	m_strName = pView->m_strName;
	m_strSubName = pView->m_strSubName;

	CButton* pCheck = (CButton*)GetDlgItem(IDC_RADIO3);
	CButton* pCheck_M = (CButton*)GetDlgItem(IDC_RADIO7);

	pCheck->SetCheck(3);
	pCheck_M->SetCheck(1);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CAddSubject::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	int nSelect = GetCheckedRadioButton(IDC_RADIO1, IDC_RADIO3);
	int nSelect_M = GetCheckedRadioButton(IDC_RADIO7, IDC_RADIO8);

	if (nSelect == IDC_RADIO1)
	{
		Credit = 1; // 1번이 선택되었을 때 수행할 작업
	}
	else if (nSelect == IDC_RADIO2)
	{
		Credit = 2; // 2번이 선택되었을 때 수행할 작업
	}
	else if (nSelect == IDC_RADIO3)
	{
		Credit = 3; // 3번이 선택되었을 때 수행할 작업
	}
	else
		Credit = -1;

	if (nSelect_M == IDC_RADIO7) {
		Major = 1;
	}
	else if (nSelect_M == IDC_RADIO8) {
		Major = 0;
	}
	else
		Major = -1;
}
