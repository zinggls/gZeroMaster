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
	virtual BOOL OnInitDialog();
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
	BOOL UpdateSemanticValue(int addr, int (* fpNewRegVal)(int, int), int newVal, void (CSemantic::* fpUpdateData)(const CRegister&));
	afx_msg void OnBnClickedWriteButton();
	afx_msg void OnBnClickedWriteAllButton();
	BOOL UpdateSelected(SelectStatic selected, BOOL bCommonControl);
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
