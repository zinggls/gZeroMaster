#pragma once

#include <map>
#include "SemanticUserDefinedMessage.h"
#include "CRegister.h"
#include "IBase.h"

class CgZeroMasterDlg;
class CRaw;

enum class SelectStatic {
	None = 0, RxData, LimAmp, LnaGain, DutyCycle, VcoOsc, RegRef, VcoVdd, VcoPow, ModPow, TestBufPow,
	DataInp, PaPow, PaGain1, PaGain2, TestBuffer, BiasBlock, Lna1, Lna2, Lna3, Lna4, Lna5, RefStage, IpStage, Fb, Core, OP, IP, HL, CMOS, CML, FdCore, FdBuf
};

class CStaticElem {
	CStaticElem();
public:
	CStaticElem(UINT idc, int* pRegVal, CString& strVal) :m_uIdc(idc), m_pRegVal(pRegVal), m_strVal(strVal) {}
	UINT m_uIdc;
	int* m_pRegVal;
	CString& m_strVal;
};

class CSemanticBase : public IBase
{
	DECLARE_DYNAMIC(CSemanticBase)

public:
	CSemanticBase(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSemanticBase();

protected:
	DECLARE_MESSAGE_MAP()

public:
	CSliderCtrl m_controlSlider;
	BOOL m_bSemanticEdit;
	BOOL m_bAutoWrite;
	SelectStatic m_selected;

	CString m_strSelectedStatic;
	CString m_strSliderMin;
	CString m_strSliderMax;
	CString m_strSliderValue;
	CString m_strSliderValueHex;
	CString m_strSliderValueBin;
	CComboBox m_controlCombo;
	std::map<SelectStatic, CStaticElem> m_staticMap;

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

private:
	CRegister m_reg;

public:
	CgZeroMasterDlg* Parent();
	const CRegister& getRegister();
	static void UpdateRxReg1(CString strRxReg1, CRegister& reg);
	static void UpdateTxReg1(CString strTxRegTop, CString strTxRegMid, CString strTxRegBot, CRegister& reg, CString chip);
	static void UpdateTxReg2(CString strTxRegTop, CString strTxRegMid, CString strTxRegBot, CRegister& reg);
	static void UpdateBiasReg1(CString strBiasReg1, CRegister& reg);
	static void UpdateBiasReg2(CString strBiasReg2, CRegister& reg);
	static void UpdateBiasReg3(CString strBiasReg3, CRegister& reg);
	static void UpdateBiasReg4(CString strBiasReg4, CRegister& reg);
	static void UpdateBiasReg5(CString strBiasReg5, CRegister& reg);
	static void UpdateBiasReg6(CString strBiasReg6, CRegister& reg);
	static void UpdateBiasReg7(CString strBiasReg7, CRegister& reg);
	static void UpdateBiasReg8(CString strBiasReg8, CRegister& reg);
	static void UpdateBiasReg9(CString strBiasReg9, CRegister& reg);
	int SliderPos();
	void ShowSlider(int nCmdShow);
	void ControlValueEnable(BOOL b);
	afx_msg void OnBnClickedSemanticEditCheck();
	void OnBnClickedAutoWriteCheck();
	COLORREF SetColor(CDC* pDC, SelectStatic given);
	static CString DecToBin(int dec);
	int SliderValueUpdate();
	void SetControlSlider(int min, int max, CString strCurVal, int ticFreq, int lineSize, int pageSize);
	void SetSliderGroup(SelectStatic ss, int min, int max, CString strCurVal, int ticFreq, int lineSize, int pageSize, UINT idcStatic);
	void SetComboGroup(SelectStatic ss, CString strVal0, CString strVal1, int nVal, UINT idcStatic);
	void ControlLabelEnable(BOOL b);
	int ComboSel();
	static int Read4BitValue(CString str);
	static int Read8BitValue(CString str);
	static int OnNewRxData(int val, int newVal);
	static int OnNewLimAmp(int val, int newVal);
	static int OnNewRegRef(int val, int newVal);
	static int OnNewVcoPow(int val, int newVal);
	static int OnNewModPow(int val, int newVal);
	static int OnNewTestBufPow(int val, int newVal);
	static int OnNewDataInp(int val, int newVal);
	static int OnNewPaPow(int val, int newVal);
	static int OnNewBiasBlock(int val, int newVal);
	static int OnNewLnaGain(int val, int newVal);
	static int OnNewDutyCycle(int val, int newVal);
	static int OnNewVcoOscUp(int val, int newVal);
	static int OnNewVcoOscDown(int val, int newVal);
	static int OnNewVcoVdd(int val, int newVal);
	static int OnNewPaGain1(int val, int newVal);
	static int OnNewPaGain2(int val, int newVal);
	static int OnNewTestBuffer(int val, int newVal);
	static int OnNewLna1(int val, int newVal);
	static int OnNewLna2(int val, int newVal);
	static int OnNewLna3(int val, int newVal);
	static int OnNewLna4(int val, int newVal);
	static int OnNewLna5(int val, int newVal);
	static int OnNewRefStage(int val, int newVal);
	static int OnNewIpStage(int val, int newVal);
	static int OnNewFb(int val, int newVal);
	static int OnNewCore(int val, int newVal);
	static int OnNewOP(int val, int newVal);
	static int OnNewIP(int val, int newVal);
	static int OnNewHL(int val, int newVal);
	static int OnNewCMOS(int val, int newVal);
	static int OnNewCML(int val, int newVal);
	static int OnNewFdCore(int val, int newVal);
	static int OnNewFdBuf(int val, int newVal);
	static int disableOrEnable(CString str);
	static int strToInt(CString zero, CString one, CString str);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnCbnSelchangeControlCombo();
	void UpdateRxData(const CRegister& reg);
	void UpdateLimitAmp(const CRegister& reg);
	void UpdateLnaGain(const CRegister& reg);
	void UpdateDutyCycle(const CRegister& reg);
	void UpdateVcoOscFreq(const CRegister& reg);
	void UpdateRegRefVolt(const CRegister& reg);
	void UpdateVcoVdd(const CRegister& reg);
	void UpdateVcoPower(const CRegister& reg);
	void UpdateModPower(const CRegister& reg);
	void UpdateTestBufferPower(const CRegister& reg);
	void UpdateDataInputSelect(const CRegister& reg);
	void UpdateDataPaPower(const CRegister& reg);
	void UpdatePaGainControl2(const CRegister& reg);
	void UpdatePaGainControl1(const CRegister& reg);
	void UpdateTestBufferCurrent(const CRegister& reg);
	void UpdateBiasBlockEnable(const CRegister& reg);
	void UpdateLna3Current(const CRegister& reg);
	void UpdateLna1Current(const CRegister& reg);
	void UpdateLna2Current(const CRegister& reg);
	void UpdateLna5Current(const CRegister& reg);
	void UpdateLna4Current(const CRegister& reg);
	void UpdateDemodRefStageCurrent(const CRegister& reg);
	void UpdateDemodIPStageCurrent(const CRegister& reg);
	void UpdateLaFBCurrent(const CRegister& reg);
	void UpdateLaCoreCurrent(const CRegister& reg);
	void UpdateLaOPBufferCurrent(const CRegister& reg);
	void UpdateLaIPBufferCurrent(const CRegister& reg);
	void UpdateLaHLDataRateCurrent(const CRegister& reg);
	void UpdateCMOSGainStageCurrent(const CRegister& reg);
	void UpdateCMLInterfaceStageCurrent(const CRegister& reg);
	void UpdateFdCoreCurrent(const CRegister& reg);
	void UpdateFdBufferCurrent(const CRegister& reg);
	void UpdateRegisters();
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
	afx_msg void OnStnClickedRxDataIfEnableValueStatic();
	afx_msg void OnStnClickedLimitingAmpEnableValueStatic();
	afx_msg void OnStnClickedRegRefVoltValueStatic();
	afx_msg void OnStnClickedVcoPowerValueStatic();
	afx_msg void OnStnClickedModulatorPowerValueStatic();
	afx_msg void OnStnClickedTestBufferPowerValueStatic();
	afx_msg void OnStnClickedDataInputSelectValueStatic();
	afx_msg void OnStnClickedPaPowerValueStatic();
	afx_msg void OnStnClickedBiasBlockEnableValueStatic();
	int RxData();
	int LimAmp();
	int LnaGain();
	int DutyCycle();
	int VcoOsc();
	int RegRef();
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
	void ResetValues();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	BOOL UpdateSemanticValue(int addr, int (*fpNewRegVal)(int, int), int newVal, void (CSemanticBase::* fpUpdateData)(const CRegister&));
	BOOL UpdateSelected(SelectStatic selected, BOOL bCommonControl);
	virtual afx_msg void OnBnClickedWriteButton();
	virtual afx_msg void OnBnClickedReadAllButton();
	virtual afx_msg void OnBnClickedWriteAllButton();
};