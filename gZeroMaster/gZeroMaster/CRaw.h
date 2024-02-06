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
	virtual afx_msg void OnBnClickedReadAllButton();
	virtual afx_msg void OnBnClickedWriteButton();
	virtual void OnHideRegisterButtons(CString strChosenRegister);
	virtual void ResetValues();
	void OnChipConnect(CString chipModel);
};
