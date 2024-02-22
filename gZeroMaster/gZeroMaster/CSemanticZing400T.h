#pragma once

#include "CSemanticBase.h"
#include "CVspsBlock.h"

class CRegisterZing400T;

// CSemanticZing400T 대화 상자

class CSemanticZing400T : public CSemanticBase
{
	DECLARE_DYNAMIC(CSemanticZing400T)

public:
	CSemanticZing400T(CWnd* pParent, CRawBase* pRawBase, CRegister* pReg);   // 표준 생성자입니다.
	virtual ~CSemanticZing400T();

	class CSelect :public CSemanticBase::CSelect {
	public:
		static const UINT VspsPa = 33;
		static const UINT VspsVga = 34;
		static const UINT VspsCs = 35;
		static const UINT Ch3Block = 36;
		static const UINT Ch3_Q = 37;
		static const UINT Ch3_I = 38;
		static const UINT Ch2Block = 39;
		static const UINT Ch2_Q = 40;
		static const UINT Ch2_I = 41;
		static const UINT Ch1Block = 42;
		static const UINT Ch1_Q = 43;
		static const UINT Ch1_I = 44;
		static const UINT Ch0Block = 45;
		static const UINT Ch0_Q = 46;
		static const UINT Ch0_I = 47;
	};

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
	static void UpdateRegOut24(CString strRegOut24, CRegister& reg);
	static void UpdateRegOut25(CString strRegOut25, CRegister& reg);
	static void UpdateRegOut26(CString strRegOut26, CRegister& reg);
	static void UpdateRegOut27(CString strRegOut27, CRegister& reg);
	static void UpdateRegOut28(CString strRegOut28, CRegister& reg);
	static void UpdateRegOut29(CString strRegOut29, CRegister& reg);
	static void UpdateRegOut2A(CString strRegOut2A, CRegister& reg);
	static void UpdateRegOut2B(CString strRegOut2B, CRegister& reg);
	void UpdateBiasBlockEnable(const CRegisterZing400T& reg);
	void UpdateVspsPaBiasVoltage(const CRegisterZing400T& reg);
	void UpdateVspsVgaBiasVoltage(const CRegisterZing400T& reg);
	void UpdateVspsCsBiasVoltage(const CRegisterZing400T& reg);
	void UpdateCh3VspsBlockEnable(const CRegisterZing400T& reg);
	void UpdateCh3VspsPhaseControlBitQ(const CRegisterZing400T& reg);
	void UpdateCh3VspsPhaseControlBitI(const CRegisterZing400T& reg);
	void UpdateCh2VspsBlockEnable(const CRegisterZing400T& reg);
};
