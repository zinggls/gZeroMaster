#pragma once

class CgZeroMasterDlg;
class CRaw;

// CSemantic 대화 상자

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

class CSemantic : public CDialogEx
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
	CWnd* m_pParent;
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
	CSliderCtrl m_controlSlider;
	BOOL m_bSemanticEdit;

	enum class SelectStatic{ None=0,RxData,LimAmp,LnaGain,DutyCycle,VcoOsc,RegRef,VcoVdd,VcoPow,ModPow,TestBufPow,
		DataInp,PaPow,PaGain1,PaGain2,TestBuffer,BiasBlock,Lna1,Lna2,Lna3,Lna4,Lna5,RefStage,IpStage,Fb,Core,OP,IP,HL,CMOS,CML,FdCore,FdBuf };
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
	virtual BOOL OnInitDialog();
	static void Parse(CRaw* pRaw, CRegister& reg);
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
	void ControlLabelEnable(BOOL b);
	void ControlValueEnable(BOOL b);
	afx_msg void OnBnClickedSemanticEditCheck();
	COLORREF SetColor(CDC* pDC, SelectStatic given);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	void SetControlSlider(int min, int max, CString strCurVal, int ticFreq, int lineSize, int pageSize);
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
	int SliderPos();
	int SliderValueUpdate();
	void ShowSlider(int nCmdShow);
	static CString DecToBin(int dec);
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
	void OnChipConnect(CString chipModel);
};
