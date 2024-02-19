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
	virtual BOOL ReadRegisters();
	afx_msg void OnBnClickedReadAllButton();
	afx_msg void OnStnClickedTxReg1TopStatic();
	afx_msg void OnStnClickedTxReg1MidStatic();
	afx_msg void OnStnClickedTxReg1BotStatic();
	afx_msg void OnStnClickedTxReg2TopStatic();
	afx_msg void OnStnClickedTxReg2MidStatic();
	afx_msg void OnStnClickedTxReg2BotStatic();
	afx_msg void OnBnClickedEditCheck();
	afx_msg void OnBnClickedBit7Button();
	afx_msg void OnBnClickedBit6Button();
	afx_msg void OnBnClickedBit5Button();
	afx_msg void OnBnClickedBit4Button();
	afx_msg void OnBnClickedBit3Button();
	afx_msg void OnBnClickedBit2Button();
	afx_msg void OnBnClickedBit1Button();
	afx_msg void OnBnClickedBit0Button();
	afx_msg void OnBnClickedWriteButton();
	virtual void DefaultValues(CString strChip);
};
