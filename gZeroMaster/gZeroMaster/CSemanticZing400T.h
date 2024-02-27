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
		static const UINT Ch3Phase = 37;
		static const UINT Ch2Block = 38;
		static const UINT Ch2Phase = 39;
		static const UINT Ch1Block = 40;
		static const UINT Ch1Phase = 41;
		static const UINT Ch0Block = 42;
		static const UINT Ch0Phase = 43;
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
	virtual void ResetValues();
	virtual void SetSliderGroup(UINT ss, int min, int max, CString strCurVal, int ticFreq, int lineSize, int pageSize, UINT idcStatic, void(CSemanticBase::* pControl)(int, int, CString, int, int, int) = NULL);
	virtual void ShowSlider(int nCmdShow);
	virtual int SliderValueUpdate();
	virtual void ControlSliderCommon(int min, int max, CString strCurVal, int ticFreq, int lineSize, int pageSize);
	virtual void SetControlSlider(int min, int max, CString strCurVal, int ticFreq, int lineSize, int pageSize);
	virtual void SetControlSliderForPhase(int min, int max, CString strCurVal, int ticFreq, int lineSize, int pageSize);
	virtual afx_msg void OnBnClickedWriteButton();
	virtual BOOL UpdateSelected(UINT selected, BOOL bCommonControl);
	static void UpdateTxReg1(CString strTxRegTop, CString strTxRegMid, CString strTxRegBot, CRegister& reg);
	static void UpdateRegOut24(CString strRegOut24, CRegister& reg);
	static void UpdateRegOut25(CString strRegOut25, CRegisterZing400T& reg);
	static void UpdateRegOut26(CString strRegOut26, CRegisterZing400T& reg);
	static void UpdateRegOut27(CString strRegOut27, CRegisterZing400T& reg);
	static void UpdateRegOut28(CString strRegOut28, CRegisterZing400T& reg);
	static void UpdateRegOut29(CString strRegOut29, CRegisterZing400T& reg);
	static void UpdateRegOut2A(CString strRegOut2A, CRegisterZing400T& reg);
	static void UpdateRegOut2B(CString strRegOut2B, CRegisterZing400T& reg);
	void UpdateBiasBlockEnable(const CRegisterZing400T& reg);
	void UpdateVspsPaBiasVoltage(const CRegisterZing400T& reg);
	void UpdateVspsVgaBiasVoltage(const CRegisterZing400T& reg);
	void UpdateVspsCsBiasVoltage(const CRegisterZing400T& reg);
	void UpdateCh3VspsBlockEnable(const CRegisterZing400T& reg);
	void UpdateCh3Phase(const CRegisterZing400T& reg);
	void UpdateCh2VspsBlockEnable(const CRegisterZing400T& reg);
	void UpdateCh2Phase(const CRegisterZing400T& reg);
	void UpdateCh1VspsBlockEnable(const CRegisterZing400T& reg);
	void UpdateCh1Phase(const CRegisterZing400T& reg);
	void UpdateCh0VspsBlockEnable(const CRegisterZing400T& reg);
	void UpdateCh0Phase(const CRegisterZing400T& reg);
	afx_msg void OnStnClickedTxBiasBlockEnableValueStatic();
	afx_msg void OnStnClickedTxVspsPaBiasVoltageValueStatic();
	afx_msg void OnStnClickedTxVspsVgaBiasVoltageValueStatic();
	afx_msg void OnStnClickedTxVspsCsBiasVoltageValueStatic();
	afx_msg void OnStnClickedTxCh3VspsBlockEnableValueStatic();
	afx_msg void OnStnClickedTxCh3PhaseValueStatic();
	afx_msg void OnStnClickedTxCh2VspsBlockEnableValueStatic();
	afx_msg void OnStnClickedTxCh2PhaseValueStatic();
	afx_msg void OnStnClickedTxCh1VspsBlockEnableValueStatic();
	afx_msg void OnStnClickedTxCh1PhaseValueStatic();
	afx_msg void OnStnClickedTxCh0VspsBlockEnableValueStatic();
	afx_msg void OnStnClickedTxCh0PhaseValueStatic();
	int Ch3Block();
	static int OnNewCh3Block(int val, int newVal);
	void UpdateCh3Block(const CRegister& reg);
	int Ch2Block();
	static int OnNewCh2Block(int val, int newVal);
	void UpdateCh2Block(const CRegister& reg);
	int Ch1Block();
	static int OnNewCh1Block(int val, int newVal);
	void UpdateCh1Block(const CRegister& reg);
	int Ch0Block();
	static int OnNewCh0Block(int val, int newVal);
	void UpdateCh0Block(const CRegister& reg);
	int VspsPa();
	static int OnNewVspsPa(int val, int newVal);
	void UpdateVspsPa(const CRegister& reg);
	int VspsVga();
	static int OnNewVspsVga(int val, int newVal);
	void UpdateVspsVga(const CRegister& reg);
};
