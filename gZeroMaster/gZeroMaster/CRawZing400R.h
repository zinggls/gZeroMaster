#pragma once

#include "CRawBase.h"

// CRawZing400R 대화 상자

class CRawZing400R : public CRawBase
{
	DECLARE_DYNAMIC(CRawZing400R)

public:
	CRawZing400R(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CRawZing400R();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RAW_ZING400R_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

	CString m_strRegOut26;
	CString m_strRegOut27;
	CString m_strRegOut28;
	CString m_strRegOut29;
	CString m_strRegOut2A;
	CString m_strRegOut2B;
	CString m_strRegOut2C;

public:
	virtual BOOL OnInitDialog();
	virtual void OnHideRegisterButtons(CString strChosenRegister);
	virtual void OnChipConnect(CString chipModel);
	afx_msg void OnStnClickedRxReg1Static();
	afx_msg void OnStnClickedRxRegOut26Static();
	afx_msg void OnStnClickedRxRegOut27Static();
	afx_msg void OnStnClickedRxRegOut28Static();
	afx_msg void OnStnClickedRxRegOut29Static();
	afx_msg void OnStnClickedRxRegOut2AStatic();
	afx_msg void OnStnClickedRxRegOut2BStatic();
	afx_msg void OnStnClickedRxRegOut2CStatic();
	virtual void DefaultValues(CString strChip);
	afx_msg void OnBnClickedDefaultValueButton();
};
