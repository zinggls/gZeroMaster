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

public:
	CgZeroMasterDlg* Parent();
	afx_msg void OnBnClickedRxDataIfEnableCheck();
	afx_msg void OnBnClickedLimitingAmpEnableCheck();
	virtual BOOL OnInitDialog();
	void UpdateRegisters();
	void UpdateRxReg1(CString strRxReg1);
	void ControlLabelEnable(BOOL b);
	void ControlValueEnable(BOOL b);
};
