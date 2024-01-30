#pragma once

#include "CSemanticBase.h"
#include "SemanticUserDefinedMessage.h"

// CSemantic 대화 상자

class CSemantic : public CSemanticBase
{
	DECLARE_DYNAMIC(CSemantic)

public:
	CSemantic(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSemantic();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEMANTIC_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strRxDataInterface;
	CString m_strLimitingAmplifier;
	CString m_strLnaGain;
	CString m_strDutyCycle;
	CString m_strVcoOscFreq;
	CString m_strRegRefVolt;
	CString m_strVcoVdd;
	CString m_strVcoPower;
	CString m_strModPower;
	CString m_strTestBufferPower;
	CString m_strDataInputSelect;
	CString m_strPaPower;
	CString m_strPaGainControl1;
	CString m_strPaGainControl2;
	CString m_strTestBufferCurrent;
	CString m_strBiasBlockEnable;
	CString m_strLna1Current;
	CString m_strLna2Current;
	CString m_strLna3Current;
	CString m_strLna4Current;
	CString m_strLna5Current;
	CString m_strDemodRefStageCurrent;
	CString m_strDemodIPStageCurrent;
	CString m_strLaFBCurrent;
	CString m_strLaCoreCurrent;
	CString m_strLaOPBufferCurrent;
	CString m_strLaIPBufferCurrent;
	CString m_strLaHLDataRateCurrent;
	CString m_strCMOSGainStageCurrent;
	CString m_strCMLInterfaceStageCurrent;
	CString m_strFdCoreCur;
	CString m_strFdBufCur;

public:
	virtual BOOL OnInitDialog();
	void UpdateRxData(CRegister& reg);
	void UpdateLimitAmp(CRegister& reg);
	void UpdateLnaGain(CRegister& reg);
	void UpdateDutyCycle(CRegister& reg);
	void UpdateVcoOscFreq(CRegister& reg);
	void UpdateRegRefVolt(CRegister& reg);
	void UpdateVcoVdd(CRegister& reg);
	void UpdateVcoPower(CRegister& reg);
	void UpdateModPower(CRegister& reg);
	void UpdateTestBufferPower(CRegister& reg);
	void UpdateDataInputSelect(CRegister& reg);
	void UpdateDataPaPower(CRegister& reg);
	void UpdatePaGainControl2(CRegister& reg);
	void UpdatePaGainControl1(CRegister& reg);
	void UpdateTestBufferCurrent(CRegister& reg);
	void UpdateBiasBlockEnable(CRegister& reg);
	void UpdateLna3Current(CRegister& reg);
	void UpdateLna1Current(CRegister& reg);
	void UpdateLna2Current(CRegister& reg);
	void UpdateLna5Current(CRegister& reg);
	void UpdateLna4Current(CRegister& reg);
	void UpdateDemodRefStageCurrent(CRegister& reg);
	void UpdateDemodIPStageCurrent(CRegister& reg);
	void UpdateLaFBCurrent(CRegister& reg);
	void UpdateLaCoreCurrent(CRegister& reg);
	void UpdateLaOPBufferCurrent(CRegister& reg);
	void UpdateLaIPBufferCurrent(CRegister& reg);
	void UpdateLaHLDataRateCurrent(CRegister& reg);
	void UpdateCMOSGainStageCurrent(CRegister& reg);
	void UpdateCMLInterfaceStageCurrent(CRegister& reg);
	void UpdateFdCoreCurrent(CRegister& reg);
	void UpdateFdBufferCurrent(CRegister& reg);
	void UpdateRegisters();
	void ControlLabelEnable(BOOL b);
	virtual void ControlValueEnable(BOOL b);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnStnClickedLnaGainValueStatic();
	afx_msg void OnStnClickedDutyCycleValueStatic();
	afx_msg void OnStnClickedVcoOscFreqValueStatic();
	afx_msg void OnStnClickedVcoVddValueStatic();
	afx_msg void OnStnClickedPaGainControl1ValueStatic();
	afx_msg void OnStnClickedPaGainControl2ValueStatic();
	afx_msg void OnStnClickedTestBufferCurrentValueStatic();
	afx_msg void OnStnClickedLna1BiasCurrentValueStatic();
	afx_msg void OnStnClickedLna2BiasCurrentValueStatic();
	afx_msg void OnStnClickedLna3BiasCurrentValueStatic();
	afx_msg void OnStnClickedLna4BiasCurrentValueStatic();
	afx_msg void OnStnClickedLna5BiasCurrentValueStatic();
	afx_msg void OnStnClickedDemodRefStageCurrentValueStatic();
	afx_msg void OnStnClickedDemodIpStageCurrentValueStatic();
	afx_msg void OnStnClickedLaFbCurrentValueStatic();
	afx_msg void OnStnClickedLaCoreCurrentValueStatic();
	afx_msg void OnStnClickedLaOpBufferCurrentValueStatic();
	afx_msg void OnStnClickedLaIpBufferCurrentValueStatic();
	afx_msg void OnStnClickedLaHlDataRateCurrentValueStatic();
	afx_msg void OnStnClickedCmosGainStageCurrentValueStatic();
	afx_msg void OnStnClickedCmlInterfaceStageCurrentValueStatic();
	afx_msg void OnStnClickedFdCoreCurrentValueStatic();
	afx_msg void OnStnClickedFdBufferCurrentValueStatic();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedReadAllButton();
	afx_msg void OnStnClickedRxDataIfEnableValueStatic();
	afx_msg void OnStnClickedLimitingAmpEnableValueStatic();
	afx_msg void OnStnClickedRegRefVoltValueStatic();
	afx_msg void OnStnClickedVcoPowerValueStatic();
	afx_msg void OnStnClickedModulatorPowerValueStatic();
	afx_msg void OnStnClickedTestBufferPowerValueStatic();
	afx_msg void OnStnClickedDataInputSelectValueStatic();
	afx_msg void OnStnClickedPaPowerValueStatic();
	afx_msg void OnStnClickedBiasBlockEnableValueStatic();
	void ResetValues();
	afx_msg void OnCbnSelchangeControlCombo();
	int ComboSel();
	int OnNewRxData(int val, int newVal);
	int OnNewLimAmp(int val, int newVal);
	int OnNewRegRef(int val, int newVal);
	int OnNewVcoPow(int val, int newVal);
	int OnNewModPow(int val, int newVal);
	int OnNewTestBufPow(int val, int newVal);
	int OnNewDataInp(int val, int newVal);
	int OnNewPaPow(int val, int newVal);
	int OnNewBiasBlock(int val, int newVal);
	int OnNewLnaGain(int val, int newVal);
	int OnNewDutyCycle(int val, int newVal);
	int OnNewVcoOscUp(int val, int newVal);
	int OnNewVcoOscDown(int val, int newVal);
	int OnNewVcoVdd(int val, int newVal);
	int OnNewPaGain1(int val, int newVal);
	int OnNewPaGain2(int val, int newVal);
	int OnNewTestBuffer(int val, int newVal);
	int OnNewLna1(int val, int newVal);
	int OnNewLna2(int val, int newVal);
	int OnNewLna3(int val, int newVal);
	int OnNewLna4(int val, int newVal);
	int OnNewLna5(int val, int newVal);
	int OnNewRefStage(int val, int newVal);
	int OnNewIpStage(int val, int newVal);
	int OnNewFb(int val, int newVal);
	int OnNewCore(int val, int newVal);
	int OnNewOP(int val, int newVal);
	int OnNewIP(int val, int newVal);
	int OnNewHL(int val, int newVal);
	int OnNewCMOS(int val, int newVal);
	int OnNewCML(int val, int newVal);
	int OnNewFdCore(int val, int newVal);
	int OnNewFdBuf(int val, int newVal);
	BOOL UpdateSemanticValue(int addr, int (CSemantic::* fpNewRegVal)(int, int), int newVal, void (CSemantic::* fpUpdateData)(CRegister&));
	afx_msg void OnBnClickedWriteButton();
	afx_msg void OnBnClickedWriteAllButton();
	BOOL UpdateSelected(SelectStatic selected, BOOL bCommonControl);
	static int disableOrEnable(CString str);
	static int strToInt(CString zero, CString one, CString str);
	int RxData();
	int LimAmp();
	int LnaGain();
	int DutyCycle();
	int VcoOsc();
	int RegRef();
	int Read4BitValue(CString str);
	int Read8BitValue(CString str);
	int VcoVdd();
	int VcoPow();
	int ModPow();
	int TestBufPow();
	int DataInp();
	int PaPow();
	int PaGain1();
	int PaGain2();
	int TestBuffer();
	int BiasBlock();
	int Lna1();
	int Lna2();
	int Lna3();
	int Lna4();
	int Lna5();
	int RefStage();
	int IpStage();
	int Fb();
	int Core();
	int OP();
	int IP();
	int HL();
	int CMOS();
	int CML();
	int FdCore();
	int FdBuf();
	void OnChipConnect(CString chipModel);
	afx_msg void OnBnClickedDefaultValueButton();
	afx_msg LRESULT OnSemEditClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemRxDataInterfaceClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemLimitAmpEnableClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemLnaGainClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemDutyCycleClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemVcoOscFreqClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemRegRefVoltClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemVcoVddClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemVcoPowerClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemModulatorPowerClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemTestBufferPowerClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemDataInputSelectClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemPaPowerClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemPaGainControl1Click(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemPaGainControl2Click(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemTestBufferCurrentClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemBiasBlockEnableClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSem1stStageBiasCurrentClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSem3rdStageBiasCurrentClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSem4thStageBiasCurrentClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSem5thStageBiasCurrentClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemRefStageCurrentClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemIpStageCurrentClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemFbCurrentClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemCoreCurrentClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemOpBufferCurrentClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemIpBufferCurrentClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemHighlowDataRateCurrentClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemCmosGainStageCurrentClick(WPARAM w, LPARAM l);
	afx_msg LRESULT OnSemCmlInterfaceStageCurrentClick(WPARAM w, LPARAM l);
};
