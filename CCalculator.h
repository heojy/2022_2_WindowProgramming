#pragma once

#include "Cuckoo2View.h"
// CCalculator 대화 상자

class CCalculator : public CDialogEx
{
	DECLARE_DYNAMIC(CCalculator)

public:
	CCalculator(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CCalculator();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox m_listSub;
	CString m_strSub;
	CString m_strSubject[20] = { _T("") };
	int temp_sub = 0;
	float temp_grd = 4.5;
	float Grade[20] = { -1, -1, -1, -1, -1,
						-1, -1, -1, -1, -1, 
						-1, -1, -1, -1, -1, 
						-1, -1, -1, -1, -1 };
	//float G
	//CCuckoo2View::Credit[20];
	afx_msg void OnClickedButtonGradeSave();
	afx_msg void OnCbnSelchangeListSub();
	afx_msg void OnCbnSelchangeListGrade();
	CComboBox m_listGrade;
	CString m_strGrade;
	float sum_grade = 0;
	float sum_grade_major = 0;
	float sum_credit = 0;
	float sum_credit_major = 0;
	CString m_strMajor;
	CString m_strTotal;

	int S=0;
	CString m_strRegister = _T("");

	CString m_strPrintMajor;
	CString m_strPrintTotal;
};
