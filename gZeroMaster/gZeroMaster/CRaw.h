#pragma once

#include "CRawBase.h"

// CRaw 대화 상자

class CRaw : public CRawBase
{
	DECLARE_DYNAMIC(CRaw)

public:
	CRaw(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CRaw();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RAW_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	virtual afx_msg void OnBnClickedReadAllButton();
	virtual afx_msg void OnBnClickedWriteButton();
	virtual void OnHideRegisterButtons(CString strChosenRegister);
	virtual void ResetValues();
	void OnChipConnect(CString chipModel);
};
