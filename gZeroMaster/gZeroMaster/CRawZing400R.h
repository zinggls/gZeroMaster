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

public:
	virtual BOOL OnInitDialog();
	virtual void OnHideRegisterButtons(CString strChosenRegister);
	virtual void OnChipConnect(CString chipModel);
	virtual BOOL ReadRegisters();
	afx_msg void OnBnClickedReadAllButton();
	afx_msg void OnStnClickedRxReg1Static();
	afx_msg void OnStnClickedBiasReg1Static();
	afx_msg void OnStnClickedBiasReg4Static();
	afx_msg void OnStnClickedBiasReg5Static();
	afx_msg void OnStnClickedBiasReg6Static();
	afx_msg void OnStnClickedBiasReg7Static();
	afx_msg void OnStnClickedBiasReg8Static();
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
