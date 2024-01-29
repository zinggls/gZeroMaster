#pragma once

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

	enum class SelectStatic {
		None = 0, RxData, LimAmp, LnaGain, DutyCycle, VcoOsc, RegRef, VcoVdd, VcoPow, ModPow, TestBufPow,
		DataInp, PaPow, PaGain1, PaGain2, TestBuffer, BiasBlock, Lna1, Lna2, Lna3, Lna4, Lna5, RefStage, IpStage, Fb, Core, OP, IP, HL, CMOS, CML, FdCore, FdBuf
	};
	SelectStatic m_selected;

	CString m_strSelectedStatic;
	CString m_strSliderMin;
	CString m_strSliderMax;
	CString m_strSliderValue;
	CString m_strSliderValueHex;
	CString m_strSliderValueBin;
	CComboBox m_controlCombo;

public:
	CgZeroMasterDlg* Parent();
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
};