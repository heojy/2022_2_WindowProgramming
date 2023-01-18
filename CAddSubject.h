#pragma once


// CAddSubject 대화 상자

class CAddSubject : public CDialogEx
{
	DECLARE_DYNAMIC(CAddSubject)

public:
	CAddSubject(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CAddSubject();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_SUBJECT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	CString m_strSubName;
	virtual BOOL OnInitDialog();

	int Credit;
	int Major;
	afx_msg void OnDestroy();

};
