// CMainViewDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Cuckoo2.h"
#include "CMainViewDlg.h"
#include "MainFrm.h"


// CMainViewDlg

IMPLEMENT_DYNCREATE(CMainViewDlg, CFormView)

CMainViewDlg::CMainViewDlg()
	: CFormView(IDD_TODO)
	, m_strTODO(_T(""))
{
}

CMainViewDlg::~CMainViewDlg()
{
}

void CMainViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_TODO, m_listTODO);
	DDX_Text(pDX, IDC_EDIT_TODO, m_strTODO);
}

BEGIN_MESSAGE_MAP(CMainViewDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_TODO_ADD, &CMainViewDlg::OnClickedButtonTodoAdd)
	ON_BN_CLICKED(IDC_BUTTON_TODO_COMPLETE, &CMainViewDlg::OnClickedButtonTodoComplete)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_TODO, &CMainViewDlg::OnLvnItemchangedListTodo)
	ON_COMMAND(IDC_RADIO_IMPORTANT, &CMainViewDlg::OnRadioImportant)
	ON_COMMAND(IDC_RADIO_TRIVIAL, &CMainViewDlg::OnRadioTrivial)
	ON_BN_CLICKED(IDC_BUTTON_TODO_MODIFY, &CMainViewDlg::OnClickedButtonTodoModify)
END_MESSAGE_MAP()


// CMainViewDlg 진단

#ifdef _DEBUG
void CMainViewDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CMainViewDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMainViewDlg 메시지 처리기


void CMainViewDlg::OnClickedButtonTodoAdd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nCount = m_listTODO.GetItemCount();
	CString strCount;
	
	UpdateData(TRUE);

	if (!m_strTODO.IsEmpty()) {
		strCount.Format(_T("%d"), nCount + 1);
		m_listTODO.InsertItem(nCount, strCount);
		m_listTODO.SetItem(nCount, 1, LVIF_TEXT, m_strTODO, 0, 0, 0, 0);
		
		if (m_nImportant == 0) {
			m_listTODO.SetItem(nCount, 2, LVIF_TEXT, _T("O"), 0, 0, 0, 0);
		}
		else {
			m_listTODO.SetItem(nCount, 2, LVIF_TEXT, _T("X"), 0, 0, 0, 0);
		}

		m_strTODO.Empty();
		//할 일 수정, 완료 버튼 비활성화
		((CButton*)GetDlgItem(IDC_BUTTON_TODO_MODIFY))->EnableWindow(TRUE);
		((CButton*)GetDlgItem(IDC_BUTTON_TODO_COMPLETE))->EnableWindow(FALSE);
		
		UpdateData(FALSE);
	}
	else {
		MessageBox(_T("할 일을 입력해주세요."), _T("잠깐"), MB_OK);
	}
}


void CMainViewDlg::OnClickedButtonTodoComplete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_nSelectedItem >= 0) {
		m_listTODO.DeleteItem(m_nSelectedItem);

		for (int i = m_nSelectedItem - 1; i < m_listTODO.GetItemCount(); i++) {
			CString strIndex;
			strIndex.Format(_T("%d"), i + 1);
			m_listTODO.SetItemText(i, 0, strIndex);
		}
		m_strTODO.Empty();

		((CButton*)GetDlgItem(IDC_BUTTON_TODO_MODIFY))->EnableWindow(TRUE);
		((CButton*)GetDlgItem(IDC_BUTTON_TODO_COMPLETE))->EnableWindow(FALSE);
		
		UpdateData(FALSE);	
	}
	else {
		MessageBox(_T("할 일을 선택하지 않았습니다."), _T("잠깐"), MB_OK);

	}
}


void CMainViewDlg::OnLvnItemchangedListTodo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nSelectedItem = pNMLV->iItem;

	//m_strSelectedItem.Format(_T("%d"), m_nSelectedItem + 1);
	m_strTODO = m_listTODO.GetItemText(m_nSelectedItem, 1);

	((CButton*)GetDlgItem(IDC_BUTTON_TODO_MODIFY))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_TODO_COMPLETE))->EnableWindow(TRUE);
	
	if (m_listTODO.GetItemText(m_nSelectedItem, 2) == _T("O")) {
		CButton *pCheck; 
		pCheck = (CButton*)GetDlgItem(IDC_RADIO_TRIVIAL);
		pCheck->SetCheck(FALSE);
		m_nImportant = 0;
		pCheck = (CButton*)GetDlgItem(IDC_RADIO_IMPORTANT);
		pCheck->SetCheck(TRUE);
		
	}
	else {
		CButton *pCheck;
		pCheck = (CButton*)GetDlgItem(IDC_RADIO_IMPORTANT);
		pCheck->SetCheck(FALSE);
		m_nImportant = 1;
		pCheck = (CButton*)GetDlgItem(IDC_RADIO_TRIVIAL);
		pCheck->SetCheck(TRUE);
	}

	UpdateData(FALSE);
	*pResult = 0;
}


void CMainViewDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	LPWSTR list[3] = { _T("순서"),_T("해야 할 일"), _T("중요")};
	int nWidth[3] = { 60,200,60 };

	for (int i = 0; i < 3; i++) {
		m_listTODO.InsertColumn(i, list[i], LVCFMT_LEFT, nWidth[i]);
	}

	m_listTODO.SetExtendedStyle(m_listTODO.GetExtendedStyle()| LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	
	//할 일 완료 버튼 비활성화
	((CButton*)GetDlgItem(IDC_BUTTON_TODO_MODIFY))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_TODO_COMPLETE))->EnableWindow(FALSE);

	//라디오 버튼 기본 O
	CButton *pCheck;
	pCheck = (CButton*)GetDlgItem(IDC_RADIO_IMPORTANT);
	pCheck->SetCheck(TRUE);
	m_nImportant = 0;
}


void CMainViewDlg::OnRadioImportant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nImportant = 0;
}


void CMainViewDlg::OnRadioTrivial()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nImportant = 1;
}


void CMainViewDlg::OnClickedButtonTodoModify()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CString strTODO;
	strTODO = m_strTODO;

	if (m_nSelectedItem >= 0) {
		if (!m_strTODO.IsEmpty()) {
			
			m_listTODO.SetItem(m_nSelectedItem, 1, LVIF_TEXT, strTODO, 0, 0, 0, 0);

			if (m_nImportant == 0) {
				m_listTODO.SetItem(m_nSelectedItem, 2, LVIF_TEXT, _T("O"), 0, 0, 0, 0);
			}
			else {
				m_listTODO.SetItem(m_nSelectedItem, 2, LVIF_TEXT, _T("X"), 0, 0, 0, 0);
			}
			m_strTODO.Empty();
			//할 일 수정, 완료 버튼 비활성화
			((CButton*)GetDlgItem(IDC_BUTTON_TODO_MODIFY))->EnableWindow(TRUE);
			((CButton*)GetDlgItem(IDC_BUTTON_TODO_COMPLETE))->EnableWindow(FALSE);

			UpdateData(FALSE);
		}
		else {
			MessageBox(_T("할 일을 선택해주세요."), _T("잠깐"), MB_OK);
		}
	}
	else {
		MessageBox(_T("할 일을 선택하지 않았습니다."), _T("잠깐"), MB_OK);
	}
}
