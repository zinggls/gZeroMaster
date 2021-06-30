#pragma once

class CgZeroMasterDlg;

// CSemantic 대화 상자

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
	BOOL m_bRxDataInterface;
	BOOL m_bLimitingAmplifier;
	CString m_strLnaGain;
	CWnd* m_pParent;
	CString m_strDutyCycle;
	CString m_strVcoOscFreq;
	CComboBox m_regRefVolt;
	CString m_strVcoVdd;
	CComboBox m_vcoPower;
	CComboBox m_modPower;
	CComboBox m_testBufferPower;
	CComboBox m_dataInputSelect;
	CComboBox m_paPower;
	CString m_strPaGainControl1;
	CString m_strPaGainControl2;
	CString m_strTestBufferCurrent;
	BOOL m_bBiasBlockEnable;
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

public:
	CgZeroMasterDlg* Parent();
	afx_msg void OnBnClickedRxDataIfEnableCheck();
	afx_msg void OnBnClickedLimitingAmpEnableCheck();
	virtual BOOL OnInitDialog();
	void UpdateRegisters();
	void UpdateRxReg1(CString strRxReg1);
	void UpdateTxReg1(CString strTxReg1Top, CString strTxReg1Mid, CString strTxReg1Bot);
	void UpdateTxReg2(CString strTxReg2Top, CString strTxReg2Mid, CString strTxReg2Bot);
	void UpdateBiasReg1(CString strBiasReg1);
	void UpdateBiasReg2(CString strBiasReg2);
	void UpdateBiasReg3(CString strBiasReg3);
	void UpdateBiasReg4(CString strBiasReg4);
	void ControlLabelEnable(BOOL b);
	void ControlValueEnable(BOOL b);
};
