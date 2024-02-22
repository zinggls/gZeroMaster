#pragma once

#include "CSemanticBase.h"
#include "CVspsBlock.h"

class CRegisterZing400R;

// CSemanticZing400R 대화 상자

class CSemanticZing400R : public CSemanticBase
{
	DECLARE_DYNAMIC(CSemanticZing400R)

public:
	CSemanticZing400R(CWnd* pParent, CRawBase* pRawBase, CRegister* pReg);   // 표준 생성자입니다.
	virtual ~CSemanticZing400R();

	class CSelect :public CSemanticBase::CSelect {
	public:
		static const UINT Ch3Block = 33;
		static const UINT Ch3_Q = 34;
		static const UINT Ch3_I = 35;
		static const UINT Ch2Block = 36;
		static const UINT Ch2_Q = 37;
		static const UINT Ch2_I = 38;
		static const UINT Ch1Block = 39;
		static const UINT Ch1_Q = 40;
		static const UINT Ch1_I = 41;
		static const UINT Ch0Block = 42;
		static const UINT Ch0_Q = 43;
		static const UINT Ch0_I = 44;
		static const UINT VspsBias = 45;
		static const UINT LnasBias = 46;
	};

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEMANTIC_ZING400T_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

	CVspsBlock m_vspsBlock[4];
	CString m_strVspsBiasControlBit;
	CString m_strLnaControlBit;

public:
	virtual BOOL OnInitDialog();
	virtual void OnChipConnect(CString chipModel);
	virtual void ControlLabelEnable(BOOL b);
	virtual void ControlValueEnable(BOOL b);
	virtual const CRegister& Parse();
	virtual void UpdateRegisters();
	void UpdateRxReg1(CString strRxReg1, CRegister& reg);
	void UpdateRegOut26(CString strRegOut26, CRegisterZing400R& reg);
	void UpdateRegOut27(CString strRegOut27, CRegisterZing400R& reg);
	void UpdateRegOut28(CString strRegOut28, CRegisterZing400R& reg);
	void UpdateRegOut29(CString strRegOut29, CRegisterZing400R& reg);
	void UpdateRegOut2A(CString strRegOut2A, CRegisterZing400R& reg);
	void UpdateRegOut2B(CString strRegOut2B, CRegisterZing400R& reg);
};
