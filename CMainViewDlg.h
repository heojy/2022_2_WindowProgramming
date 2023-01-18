#pragma once



// CMainViewDlg 폼 보기

class CMainViewDlg : public CFormView
{
	DECLARE_DYNCREATE(CMainViewDlg)

protected:
	CMainViewDlg();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CMainViewDlg();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TODO };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButtonTodoAdd();
	afx_msg void OnClickedButtonTodoComplete();
	afx_msg void OnLvnItemchangedListTodo(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_listTODO;
	CString m_strTODO;
	int m_nImportant;
	virtual void OnInitialUpdate();
	afx_msg void OnRadioImportant();
	afx_msg void OnRadioTrivial();
	int m_nSelectedItem; // 선택한 아이템을 저장해놓는 변수
	afx_msg void OnClickedButtonTodoModify();
};


