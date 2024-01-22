#pragma once

#include "CRawBase.h"

#define CHIP_MODEL_ADDRESS		0xff
#define CHIP_MODEL_INFO_SIZE	7

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
	CString m_strRxReg1;
	CString m_strTxReg1Top;
	CString m_strTxReg1Mid;
	CString m_strTxReg1Bot;
	CString m_strTxReg2Top;
	CString m_strTxReg2Mid;
	CString m_strTxReg2Bot;
	CString m_strBiasReg1;
	CString m_strBiasReg2;
	CString m_strBiasReg3;
	CString m_strBiasReg4;
	CString m_strBiasReg5;
	CString m_strBiasReg6;
	CString m_strBiasReg7;
	CString m_strBiasReg8;
	CString m_strBiasReg9;
	CString m_strChosenRegister;
	BOOL m_bEdit;

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnStnClickedRxReg1Static();
	afx_msg void OnStnClickedTxReg1TopStatic();
	afx_msg void OnStnClickedTxReg1MidStatic();
	afx_msg void OnStnClickedTxReg1BotStatic();
	afx_msg void OnStnClickedTxReg2TopStatic();
	afx_msg void OnStnClickedTxReg2MidStatic();
	afx_msg void OnStnClickedTxReg2BotStatic();
	afx_msg void OnStnClickedBiasReg1Static();
	afx_msg void OnStnClickedBiasReg2Static();
	afx_msg void OnStnClickedBiasReg3Static();
	afx_msg void OnStnClickedBiasReg4Static();
	afx_msg void OnStnClickedBiasReg5Static();
	afx_msg void OnStnClickedBiasReg6Static();
	afx_msg void OnStnClickedBiasReg7Static();
	afx_msg void OnStnClickedBiasReg8Static();
	afx_msg void OnStnClickedBiasReg9Static();
	void RegisterButtons();
	afx_msg void OnBnClickedEditCheck();
	void BitControlEnable(BOOL b);
	void ShowWriteButtons(int nCmdShow);
	void ToggleBit(CEdit& bit);
	afx_msg void OnBnClickedBit7Button();
	afx_msg void OnBnClickedBit6Button();
	afx_msg void OnBnClickedBit5Button();
	afx_msg void OnBnClickedBit4Button();
	afx_msg void OnBnClickedBit3Button();
	afx_msg void OnBnClickedBit2Button();
	afx_msg void OnBnClickedBit1Button();
	afx_msg void OnBnClickedBit0Button();
	afx_msg void OnBnClickedReadAllButton();
	BOOL WriteRegister(int addr, int value);
	afx_msg void OnBnClickedWriteButton();
	void ResetValues();
	COLORREF SetColor(CDC* pDC, CString given);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	void OnChipConnect(CString chipModel);
};
