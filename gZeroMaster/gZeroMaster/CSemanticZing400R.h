#pragma once

#include "CSemanticBase.h"
#include "CVspsBlock.h"

// CSemanticZing400R 대화 상자

class CSemanticZing400R : public CSemanticBase
{
	DECLARE_DYNAMIC(CSemanticZing400R)

public:
	CSemanticZing400R(CWnd* pParent, CRawBase* pRawBase, CRegister* pReg);   // 표준 생성자입니다.
	virtual ~CSemanticZing400R();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEMANTIC_ZING400T_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

	CVspsBlock m_vspsBlock[4];
	CString m_strVspsBiasControlBit;
	CString m_strVspsLnaControlBit;

public:
	virtual BOOL OnInitDialog();
	virtual void OnChipConnect(CString chipModel);
	virtual void ControlLabelEnable(BOOL b);
	virtual void ControlValueEnable(BOOL b);
	virtual const CRegister& Parse();
	virtual void UpdateRegisters();
	void UpdateRxReg1(CString strRxReg1, CRegister& reg);
};
