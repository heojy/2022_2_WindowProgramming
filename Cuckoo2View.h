
// Cuckoo2View.h: CCuckoo2View 클래스의 인터페이스
//

#pragma once

#include "CMainViewDlg.h"
#include "Cuckoo2Doc.h"
#include "resource.h"
class CCuckoo2View : public CView
{
protected: // serialization에서만 만들어집니다.
	CCuckoo2View();
	DECLARE_DYNCREATE(CCuckoo2View)

// 특성입니다.
public:
	CCuckoo2Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CCuckoo2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CRect m_rcSquares[78] = { 
		CRect(31,31,90,80), CRect(31,81,90,130), CRect(31,131,90,180), CRect(31,181,90,230), CRect(31,231,90,280), CRect(31,281,90,330), CRect(31,331,90,380), CRect(31,381,90,430), CRect(31,431,90,480), CRect(31,481,90,530), CRect(31,531,90,580), CRect(31,581,90,630), CRect(31,631,90,680),
		CRect(91,31,150,80), CRect(91,81,150,130), CRect(91,131,150,180), CRect(91,181,150,230), CRect(91,231,150,280), CRect(91,281,150,330), CRect(91,331,150,380), CRect(91,381,150,430), CRect(91,431,150,480), CRect(91,481,150,530), CRect(91,531,150,580), CRect(91,581,150,630), CRect(91,631,150,680),
		CRect(151,31,210,80), CRect(151,81,210,130), CRect(151,131,210,180), CRect(151,181,210,230), CRect(151,231,210,280), CRect(151,281,210,330), CRect(151,331,210,380), CRect(151,381,210,430), CRect(151,431,210,480), CRect(151,481,210,530), CRect(151,531,210,580), CRect(151,581,210,630), CRect(151,631,210,680),
		CRect(211,31,270,80), CRect(211,81,270,130), CRect(211,131,270,180), CRect(211,181,270,230), CRect(211,231,270,280), CRect(211,281,270,330), CRect(211,331,270,380), CRect(211,381,270,430), CRect(211,431,270,480), CRect(211,481,270,530), CRect(211,531,270,580), CRect(211,581,270,630), CRect(211,631,270,680),
		CRect(271,31,330,80), CRect(271,81,330,130), CRect(271,131,330,180), CRect(271,181,330,230), CRect(271,231,330,280), CRect(271,281,330,330), CRect(271,331,330,380), CRect(271,381,330,430), CRect(271,431,330,480), CRect(271,481,330,530), CRect(271,531,330,580), CRect(271,581,330,630), CRect(271,631,330,680),
		CRect(331,31,390,80), CRect(331,81,390,130), CRect(331,131,390,180), CRect(331,181,390,230), CRect(331,231,390,280), CRect(331,281,390,330), CRect(331,331,390,380), CRect(331,381,390,430), CRect(331,431,390,480), CRect(331,481,390,530), CRect(331,531,390,580), CRect(331,581,390,630), CRect(331,631,390,680) };
	int GetRectID(CPoint point);
	int subject[78] = { 0 };
	int count = 0;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnButtonAddSubject();
	CString m_strName;
	CString m_strSubName;
	CString m_strSubject[20] = {_T("")};
	afx_msg void OnButtonCalculator();
	static int Credit[20];
	static int Major[20];
	CString m_strMajor = _T("전공 평점 :");
	CString m_strTotal= _T("전체 평점 :");

	
	CRect m_rcGrade[2] = { CRect(30,680,210,730), CRect(210,680,390,730) };
};

#ifndef _DEBUG  // Cuckoo2View.cpp의 디버그 버전
inline CCuckoo2Doc* CCuckoo2View::GetDocument() const
   { return reinterpret_cast<CCuckoo2Doc*>(m_pDocument); }
#endif

