#pragma once

#include <map>

class CgZeroMasterDlg;
class CRaw;

class CRegister {
public:
	//RX
	int m_nRxData;
	int m_nLimitAmp;
	int m_nLnaGain;

	//TX
	int m_nDutyCycle;
	int m_nVcoOsc;;
	int m_nRegRef;
	int m_nVcoVdd;
	int m_nVcoPower;
	int m_nModPower;
	int m_nTestBufPower;
	int m_nDataInpSel;
	int m_nPaPower;
	int m_nPaGainCon1;
	int m_nPaGainCon2;
	int m_nTestBufCur;

	//BIAS
	int m_nBiasBlock;
	int m_nLna1Cur;
	int m_nLna2Cur;
	int m_nLna3Cur;
	int m_nLna4Cur;
	int m_nLna5Cur;
	int m_nDemodRefStageCur;
	int m_nDemodIPStageCur;
	int m_nLaFBCur;
	int m_nLaCoreCur;
	int m_nLaOPBufCur;
	int m_nLaIPBufCur;
	int m_nLaHLDataRateCur;
	int m_nCMOSGainStageCur;
	int m_nCMLInterfaceStageCur;
	int m_nFdCoreCur;
	int m_nFdBufCur;
};

enum class SelectStatic {
	None = 0, RxData, LimAmp, LnaGain, DutyCycle, VcoOsc, RegRef, VcoVdd, VcoPow, ModPow, TestBufPow,
	DataInp, PaPow, PaGain1, PaGain2, TestBuffer, BiasBlock, Lna1, Lna2, Lna3, Lna4, Lna5, RefStage, IpStage, Fb, Core, OP, IP, HL, CMOS, CML, FdCore, FdBuf
};

class CStaticElem {
	CStaticElem();
public:
	CStaticElem(UINT idc):m_uIdc(idc){}
	UINT m_uIdc;
};

class CSemanticBase : public CDialogEx
{
	DECLARE_DYNAMIC(CSemanticBase)

public:
	CSemanticBase(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSemanticBase();

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

private:
	CRegister m_reg;

public:
	CgZeroMasterDlg* Parent();
	const CRegister& getRegister();
	static void Parse(CRaw* pRaw, CRegister& reg);
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
};