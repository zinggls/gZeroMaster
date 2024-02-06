#pragma once

#include "CRawBase.h"

// CRawZing400T 대화 상자

class CRawZing400T : public CRawBase
{
	DECLARE_DYNAMIC(CRawZing400T)

public:
	CRawZing400T(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CRawZing400T();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RAW_ZING400T_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	virtual void OnHideRegisterButtons(CString strChosenRegister);
	virtual void OnChipConnect(CString chipModel);
	virtual afx_msg void OnBnClickedDefaultValueButton();
};
