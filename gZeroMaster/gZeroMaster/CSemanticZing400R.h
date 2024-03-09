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
		static const UINT Ch3Phase = 34;
		static const UINT Ch2Block = 35;
		static const UINT Ch2Phase = 36;
		static const UINT Ch1Block = 37;
		static const UINT Ch1Phase = 38;
		static const UINT Ch0Block = 39;
		static const UINT Ch0Phase = 40;
		static const UINT VspsBias = 41;
		static const UINT LnaBias = 42;
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
	CComboBox m_phaseDiffCombo;

public:
	virtual BOOL OnInitDialog();
	virtual void OnChipConnect(CString chipModel);
	virtual void ControlLabelEnable(BOOL b);
	virtual void ControlValueEnable(BOOL b);
	virtual const CRegister& Parse();
	virtual void UpdateRegisters();
	virtual void ResetValues();
	void ShowChipPic(int nCmdShow);
	void ShowPhaseSync(int nCmdShow);
	virtual void ShowSlider(int nCmdShow);
	virtual int SliderValueUpdate();
	virtual afx_msg void OnBnClickedWriteButton();
	virtual BOOL UpdateSelected(UINT selected, BOOL bCommonControl);
	virtual afx_msg void OnBnClickedWriteAllButton();
	static void UpdateRxReg1(CString strRxReg1, CRegister& reg);
	static void UpdateRegOut26(CString strRegOut26, CRegisterZing400R& reg);
	static void UpdateRegOut27(CString strRegOut27, CRegisterZing400R& reg);
	static void UpdateRegOut28(CString strRegOut28, CRegisterZing400R& reg);
	static void UpdateRegOut29(CString strRegOut29, CRegisterZing400R& reg);
	static void UpdateRegOut2A(CString strRegOut2A, CRegisterZing400R& reg);
	static void UpdateRegOut2B(CString strRegOut2B, CRegisterZing400R& reg);
	static void UpdateRegOut2C(CString strRegOut2C, CRegisterZing400R& reg);
	void UpdateCh3VspsBlockEnable(const CRegisterZing400R& reg);
	void UpdateCh3Phase(const CRegisterZing400R& reg);
	void UpdateCh2VspsBlockEnable(const CRegisterZing400R& reg);
	void UpdateCh2Phase(const CRegisterZing400R& reg);
	void UpdateCh1VspsBlockEnable(const CRegisterZing400R& reg);
	void UpdateCh1Phase(const CRegisterZing400R& reg);
	void UpdateCh0VspsBlockEnable(const CRegisterZing400R& reg);
	void UpdateCh0Phase(const CRegisterZing400R& reg);
	void UpdateVspsBiasControlBit(const CRegisterZing400R& reg);
	void UpdateLnaControlBit(const CRegisterZing400R& reg);
	afx_msg void OnStnClickedRxCh3VspsBlockEnableValueStatic();
	afx_msg void OnStnClickedRxCh3PhaseValueStatic();
	afx_msg void OnStnClickedRxCh2VspsBlockEnableValueStatic();
	afx_msg void OnStnClickedRxCh2PhaseValueStatic();
	afx_msg void OnStnClickedRxCh1VspsBlockEnableValueStatic();
	afx_msg void OnStnClickedRxCh1PhaseValueStatic();
	afx_msg void OnStnClickedRxCh0VspsBlockEnableValueStatic();
	afx_msg void OnStnClickedRxCh0PhaseValueStatic();
	afx_msg void OnStnClickedRxVspsBiasControlBitValueStatic();
	afx_msg void OnStnClickedRxLnaBiasControlBitValueStatic();
	virtual afx_msg LRESULT OnSemCh3VspsBlockEnableClick(WPARAM w, LPARAM l);
	virtual afx_msg LRESULT OnSemCh3PhaseClick(WPARAM w, LPARAM l);
	virtual afx_msg LRESULT OnSemCh2VspsBlockEnableClick(WPARAM w, LPARAM l);
	virtual afx_msg LRESULT OnSemCh2PhaseClick(WPARAM w, LPARAM l);
	virtual afx_msg LRESULT OnSemCh1VspsBlockEnableClick(WPARAM w, LPARAM l);
	virtual afx_msg LRESULT OnSemCh1PhaseClick(WPARAM w, LPARAM l);
	virtual afx_msg LRESULT OnSemCh0VspsBlockEnableClick(WPARAM w, LPARAM l);
	virtual afx_msg LRESULT OnSemCh0PhaseClick(WPARAM w, LPARAM l);
	virtual afx_msg LRESULT OnSemVspsBiasControlBitClick(WPARAM w, LPARAM l);
	virtual afx_msg LRESULT OnSemLnaBiasControlBitClick(WPARAM w, LPARAM l);
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
	int VspsBias();
	static int OnNewVspsBias(int val, int newVal);
	void UpdateVspsBias(const CRegister& reg);
	int LnaBias();
	static int OnNewLnaBias(int val, int newVal);
	void UpdateLnaBias(const CRegister& reg);
	int Ch3Phase();
	static int OnNewCh3PhaseFirst(int val, int newVal);
	static int OnNewCh3PhaseNext(int val, int newVal);
	void UpdateCh3PhaseIQ(const CRegister& reg);
	int Ch2Phase();
	static int OnNewCh2PhaseFirst(int val, int newVal);
	static int OnNewCh2PhaseNext(int val, int newVal);
	void UpdateCh2PhaseIQ(const CRegister& reg);
	int Ch1Phase();
	static int OnNewCh1PhaseFirst(int val, int newVal);
	static int OnNewCh1PhaseNext(int val, int newVal);
	void UpdateCh1PhaseIQ(const CRegister& reg);
	int Ch0Phase();
	static int OnNewCh0PhaseFirst(int val, int newVal);
	static int OnNewCh0PhaseNext(int val, int newVal);
	void UpdateCh0PhaseIQ(const CRegister& reg);
};
