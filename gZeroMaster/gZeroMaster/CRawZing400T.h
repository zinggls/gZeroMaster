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
	CString m_strRegOut24;
	CString m_strRegOut25;
	CString m_strRegOut26;
	CString m_strRegOut27;
	CString m_strRegOut28;
	CString m_strRegOut29;
	CString m_strRegOut2A;
	CString m_strRegOut2B;

public:
	virtual BOOL OnInitDialog();
	virtual void OnHideRegisterButtons(CString strChosenRegister);
	virtual void OnChipConnect(CString chipModel);
	afx_msg void OnStnClickedTxReg1MidStatic();
	afx_msg void OnStnClickedTxReg1BotStatic();
	afx_msg void OnStnClickedTxReg2MidStatic();
	afx_msg void OnStnClickedTxReg2BotStatic();
	afx_msg void OnStnClickedTxRegOut24Static();
	afx_msg void OnStnClickedTxRegOut25Static();
	afx_msg void OnStnClickedTxRegOut26Static();
	afx_msg void OnStnClickedTxRegOut27Static();
	afx_msg void OnStnClickedTxRegOut28Static();
	afx_msg void OnStnClickedTxRegOut29Static();
	afx_msg void OnStnClickedTxRegOut2AStatic();
	afx_msg void OnStnClickedTxRegOut2BStatic();
	virtual void DefaultValues(CString strChip);
};
