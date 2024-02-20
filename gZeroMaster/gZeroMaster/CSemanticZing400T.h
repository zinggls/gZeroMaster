#pragma once

#include "CSemanticBase.h"
#include "CVspsBlock.h"

// CSemanticZing400T 대화 상자

class CSemanticZing400T : public CSemanticBase
{
	DECLARE_DYNAMIC(CSemanticZing400T)

public:
	CSemanticZing400T(CWnd* pParent, CRawBase* pRawBase);   // 표준 생성자입니다.
	virtual ~CSemanticZing400T();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEMANTIC_ZING400T_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

	CString m_strBiasBlockEnable;
	CString m_strVspsPaBiasVoltage;
	CString m_strVspsVgaBiasVoltage;
	CString m_strVspsCsBiasVoltage;
	CVspsBlock m_vspsBlock[4];

public:
	virtual BOOL OnInitDialog();
	virtual void OnChipConnect(CString chipModel);
	virtual void ControlLabelEnable(BOOL b);
	virtual void ControlValueEnable(BOOL b);
	virtual const CRegister& Parse();
	virtual void UpdateRegisters();
	static void UpdateTxReg1(CString strTxRegTop, CString strTxRegMid, CString strTxRegBot, CRegister& reg);
};
