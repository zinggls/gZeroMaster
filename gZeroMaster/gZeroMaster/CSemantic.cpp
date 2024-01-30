﻿// CSemantic.cpp: 구현 파일
//

#include "pch.h"
#include "gZeroMaster.h"
#include "CSemantic.h"
#include "afxdialogex.h"
#include "gZeroMasterDlg.h"
#include "CRaw.h"


// CSemantic 대화 상자

IMPLEMENT_DYNAMIC(CSemantic, CSemanticBase)

CSemantic::CSemantic(CWnd* pParent /*=nullptr*/)
	: CSemanticBase(pParent)
	, m_strRxDataInterface(_T(""))
	, m_strLimitingAmplifier(_T(""))
	, m_strLnaGain(_T(""))
	, m_strRegRefVolt(_T(""))
	, m_strVcoPower(_T(""))
	, m_strModPower(_T(""))
	, m_strTestBufferPower(_T(""))
	, m_strDataInputSelect(_T(""))
	, m_strPaPower(_T(""))
	, m_strPaGainControl1(_T(""))
	, m_strPaGainControl2(_T(""))
	, m_strTestBufferCurrent(_T(""))
	, m_strBiasBlockEnable(_T(""))
	, m_strLna1Current(_T(""))
	, m_strLna2Current(_T(""))
	, m_strLna3Current(_T(""))
	, m_strLna4Current(_T(""))
	, m_strLna5Current(_T(""))
	, m_strDemodRefStageCurrent(_T(""))
	, m_strDemodIPStageCurrent(_T(""))
	, m_strLaCoreCurrent(_T(""))
	, m_strLaOPBufferCurrent(_T(""))
	, m_strLaIPBufferCurrent(_T(""))
	, m_strLaHLDataRateCurrent(_T(""))
	, m_strCMOSGainStageCurrent(_T(""))
	, m_strCMLInterfaceStageCurrent(_T(""))
	, m_strFdCoreCur(_T(""))
	, m_strFdBufCur(_T(""))
{
}

CSemantic::~CSemantic()
{
}

void CSemantic::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RX_DATA_IF_ENABLE_VALUE_STATIC, m_strRxDataInterface);
	DDX_Text(pDX, IDC_LIMITING_AMP_ENABLE_VALUE_STATIC, m_strLimitingAmplifier);
	DDX_Text(pDX, IDC_LNA_GAIN_VALUE_STATIC, m_strLnaGain);
	DDX_Text(pDX, IDC_DUTY_CYCLE_VALUE_STATIC, m_strDutyCycle);
	DDX_Text(pDX, IDC_VCO_OSC_FREQ_VALUE_STATIC, m_strVcoOscFreq);
	DDX_Text(pDX, IDC_VCO_OSC_FREQ_VALUE_STATIC, m_strVcoOscFreq);
	DDX_Text(pDX, IDC_REG_REF_VOLT_VALUE_STATIC, m_strRegRefVolt);
	DDX_Text(pDX, IDC_VCO_VDD_VALUE_STATIC, m_strVcoVdd);
	DDX_Text(pDX, IDC_VCO_POWER_VALUE_STATIC, m_strVcoPower);
	DDX_Text(pDX, IDC_MODULATOR_POWER_VALUE_STATIC, m_strModPower);
	DDX_Text(pDX, IDC_TEST_BUFFER_POWER_VALUE_STATIC, m_strTestBufferPower);
	DDX_Text(pDX, IDC_DATA_INPUT_SELECT_VALUE_STATIC, m_strDataInputSelect);
	DDX_Text(pDX, IDC_PA_POWER_VALUE_STATIC, m_strPaPower);
	DDX_Text(pDX, IDC_PA_GAIN_CONTROL1_VALUE_STATIC, m_strPaGainControl1);
	DDX_Text(pDX, IDC_PA_GAIN_CONTROL2_VALUE_STATIC, m_strPaGainControl2);
	DDX_Text(pDX, IDC_TEST_BUFFER_CURRENT_VALUE_STATIC, m_strTestBufferCurrent);
	DDX_Text(pDX, IDC_BIAS_BLOCK_ENABLE_VALUE_STATIC, m_strBiasBlockEnable);
	DDX_Text(pDX, IDC_LNA1_BIAS_CURRENT_VALUE_STATIC, m_strLna1Current);
	DDX_Text(pDX, IDC_LNA2_BIAS_CURRENT_VALUE_STATIC, m_strLna2Current);
	DDX_Text(pDX, IDC_LNA3_BIAS_CURRENT_VALUE_STATIC, m_strLna3Current);
	DDX_Text(pDX, IDC_LNA4_BIAS_CURRENT_VALUE_STATIC, m_strLna4Current);
	DDX_Text(pDX, IDC_LNA5_BIAS_CURRENT_VALUE_STATIC, m_strLna5Current);
	DDX_Text(pDX, IDC_DEMOD_REF_STAGE_CURRENT_VALUE_STATIC, m_strDemodRefStageCurrent);
	DDX_Text(pDX, IDC_DEMOD_IP_STAGE_CURRENT_VALUE_STATIC, m_strDemodIPStageCurrent);
	DDX_Text(pDX, IDC_LA_FB_CURRENT_VALUE_STATIC, m_strLaFBCurrent);
	DDX_Text(pDX, IDC_LA_CORE_CURRENT_VALUE_STATIC, m_strLaCoreCurrent);
	DDX_Text(pDX, IDC_LA_OP_BUFFER_CURRENT_VALUE_STATIC, m_strLaOPBufferCurrent);
	DDX_Text(pDX, IDC_LA_IP_BUFFER_CURRENT_VALUE_STATIC, m_strLaIPBufferCurrent);
	DDX_Text(pDX, IDC_LA_HL_DATA_RATE_CURRENT_VALUE_STATIC, m_strLaHLDataRateCurrent);
	DDX_Text(pDX, IDC_CMOS_GAIN_STAGE_CURRENT_VALUE_STATIC, m_strCMOSGainStageCurrent);
	DDX_Text(pDX, IDC_CML_INTERFACE_STAGE_CURRENT_VALUE_STATIC, m_strCMLInterfaceStageCurrent);
	DDX_Text(pDX, IDC_FD_CORE_CURRENT_VALUE_STATIC, m_strFdCoreCur);
	DDX_Text(pDX, IDC_FD_BUFFER_CURRENT_VALUE_STATIC, m_strFdBufCur);
	DDX_Control(pDX, IDC_CONTROL_SLIDER, m_controlSlider);
	DDX_Check(pDX, IDC_SEMANTIC_EDIT_CHECK, m_bSemanticEdit);
	DDX_Text(pDX, IDC_SELECTED_STATIC, m_strSelectedStatic);
	DDX_Text(pDX, IDC_SLIDER_MIN_STATIC, m_strSliderMin);
	DDX_Text(pDX, IDC_SLIDER_MAX_STATIC, m_strSliderMax);
	DDX_Text(pDX, IDC_SLIDER_VALUE_STATIC, m_strSliderValue);
	DDX_Text(pDX, IDC_SLIDER_VALUE_HEX_STATIC, m_strSliderValueHex);
	DDX_Text(pDX, IDC_SLIDER_VALUE_BIN_STATIC, m_strSliderValueBin);
	DDX_Control(pDX, IDC_CONTROL_COMBO, m_controlCombo);
	DDX_Check(pDX, IDC_AUTO_WRITE_CHECK, m_bAutoWrite);
}


BEGIN_MESSAGE_MAP(CSemantic, CDialogEx)
	ON_BN_CLICKED(IDC_SEMANTIC_EDIT_CHECK, &CSemantic::OnBnClickedSemanticEditCheck)
	ON_WM_CTLCOLOR()
	ON_STN_CLICKED(IDC_LNA_GAIN_VALUE_STATIC, &CSemantic::OnStnClickedLnaGainValueStatic)
	ON_STN_CLICKED(IDC_DUTY_CYCLE_VALUE_STATIC, &CSemantic::OnStnClickedDutyCycleValueStatic)
	ON_STN_CLICKED(IDC_VCO_OSC_FREQ_VALUE_STATIC, &CSemantic::OnStnClickedVcoOscFreqValueStatic)
	ON_STN_CLICKED(IDC_VCO_VDD_VALUE_STATIC, &CSemantic::OnStnClickedVcoVddValueStatic)
	ON_STN_CLICKED(IDC_PA_GAIN_CONTROL1_VALUE_STATIC, &CSemantic::OnStnClickedPaGainControl1ValueStatic)
	ON_STN_CLICKED(IDC_PA_GAIN_CONTROL2_VALUE_STATIC, &CSemantic::OnStnClickedPaGainControl2ValueStatic)
	ON_STN_CLICKED(IDC_TEST_BUFFER_CURRENT_VALUE_STATIC, &CSemantic::OnStnClickedTestBufferCurrentValueStatic)
	ON_STN_CLICKED(IDC_LNA1_BIAS_CURRENT_VALUE_STATIC, &CSemantic::OnStnClickedLna1BiasCurrentValueStatic)
	ON_STN_CLICKED(IDC_LNA2_BIAS_CURRENT_VALUE_STATIC, &CSemantic::OnStnClickedLna2BiasCurrentValueStatic)
	ON_STN_CLICKED(IDC_LNA3_BIAS_CURRENT_VALUE_STATIC, &CSemantic::OnStnClickedLna3BiasCurrentValueStatic)
	ON_STN_CLICKED(IDC_LNA4_BIAS_CURRENT_VALUE_STATIC, &CSemantic::OnStnClickedLna4BiasCurrentValueStatic)
	ON_STN_CLICKED(IDC_LNA5_BIAS_CURRENT_VALUE_STATIC, &CSemantic::OnStnClickedLna5BiasCurrentValueStatic)
	ON_STN_CLICKED(IDC_DEMOD_REF_STAGE_CURRENT_VALUE_STATIC, &CSemantic::OnStnClickedDemodRefStageCurrentValueStatic)
	ON_STN_CLICKED(IDC_DEMOD_IP_STAGE_CURRENT_VALUE_STATIC, &CSemantic::OnStnClickedDemodIpStageCurrentValueStatic)
	ON_STN_CLICKED(IDC_LA_FB_CURRENT_VALUE_STATIC, &CSemantic::OnStnClickedLaFbCurrentValueStatic)
	ON_STN_CLICKED(IDC_LA_CORE_CURRENT_VALUE_STATIC, &CSemantic::OnStnClickedLaCoreCurrentValueStatic)
	ON_STN_CLICKED(IDC_LA_OP_BUFFER_CURRENT_VALUE_STATIC, &CSemantic::OnStnClickedLaOpBufferCurrentValueStatic)
	ON_STN_CLICKED(IDC_LA_IP_BUFFER_CURRENT_VALUE_STATIC, &CSemantic::OnStnClickedLaIpBufferCurrentValueStatic)
	ON_STN_CLICKED(IDC_LA_HL_DATA_RATE_CURRENT_VALUE_STATIC, &CSemantic::OnStnClickedLaHlDataRateCurrentValueStatic)
	ON_STN_CLICKED(IDC_CMOS_GAIN_STAGE_CURRENT_VALUE_STATIC, &CSemantic::OnStnClickedCmosGainStageCurrentValueStatic)
	ON_STN_CLICKED(IDC_CML_INTERFACE_STAGE_CURRENT_VALUE_STATIC, &CSemantic::OnStnClickedCmlInterfaceStageCurrentValueStatic)
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_READ_ALL_BUTTON, &CSemantic::OnBnClickedReadAllButton)
	ON_STN_CLICKED(IDC_RX_DATA_IF_ENABLE_VALUE_STATIC, &CSemantic::OnStnClickedRxDataIfEnableValueStatic)
	ON_STN_CLICKED(IDC_LIMITING_AMP_ENABLE_VALUE_STATIC, &CSemantic::OnStnClickedLimitingAmpEnableValueStatic)
	ON_STN_CLICKED(IDC_REG_REF_VOLT_VALUE_STATIC, &CSemantic::OnStnClickedRegRefVoltValueStatic)
	ON_STN_CLICKED(IDC_VCO_POWER_VALUE_STATIC, &CSemantic::OnStnClickedVcoPowerValueStatic)
	ON_STN_CLICKED(IDC_MODULATOR_POWER_VALUE_STATIC, &CSemantic::OnStnClickedModulatorPowerValueStatic)
	ON_STN_CLICKED(IDC_TEST_BUFFER_POWER_VALUE_STATIC, &CSemantic::OnStnClickedTestBufferPowerValueStatic)
	ON_STN_CLICKED(IDC_DATA_INPUT_SELECT_VALUE_STATIC, &CSemantic::OnStnClickedDataInputSelectValueStatic)
	ON_STN_CLICKED(IDC_PA_POWER_VALUE_STATIC, &CSemantic::OnStnClickedPaPowerValueStatic)
	ON_STN_CLICKED(IDC_BIAS_BLOCK_ENABLE_VALUE_STATIC, &CSemantic::OnStnClickedBiasBlockEnableValueStatic)
	ON_CBN_SELCHANGE(IDC_CONTROL_COMBO, &CSemantic::OnCbnSelchangeControlCombo)
	ON_BN_CLICKED(IDC_WRITE_BUTTON, &CSemantic::OnBnClickedWriteButton)
	ON_BN_CLICKED(IDC_WRITE_ALL_BUTTON, &CSemantic::OnBnClickedWriteAllButton)
	ON_STN_CLICKED(IDC_FD_CORE_CURRENT_VALUE_STATIC, &CSemantic::OnStnClickedFdCoreCurrentValueStatic)
	ON_STN_CLICKED(IDC_FD_BUFFER_CURRENT_VALUE_STATIC, &CSemantic::OnStnClickedFdBufferCurrentValueStatic)
	ON_BN_CLICKED(IDC_AUTO_WRITE_CHECK, &CSemantic::OnBnClickedAutoWriteCheck)
	ON_BN_CLICKED(IDC_DEFAULT_VALUE_BUTTON, &CSemantic::OnBnClickedDefaultValueButton)
	ON_MESSAGE(UDM_SEM_EDIT_CLICK, OnSemEditClick)
	ON_MESSAGE(UDM_SEM_RX_DATA_INTERFACE_CLICK, OnSemRxDataInterfaceClick)
	ON_MESSAGE(UDM_SEM_LIMIT_AMP_ENABLE_CLICK, OnSemLimitAmpEnableClick)
	ON_MESSAGE(UDM_SEM_LNA_GAIN_CLICK, OnSemLnaGainClick)
	ON_MESSAGE(UDM_SEM_DUTY_CYCLE_CLICK, OnSemDutyCycleClick)
	ON_MESSAGE(UDM_SEM_VCO_OSC_FREQ_CLICK, OnSemVcoOscFreqClick)
	ON_MESSAGE(UDM_SEM_REG_REF_VOLT_CLICK, OnSemRegRefVoltClick)
	ON_MESSAGE(UDM_SEM_VCO_VDD_CLICK, OnSemVcoVddClick)
	ON_MESSAGE(UDM_SEM_VCO_POWER_CLICK, OnSemVcoPowerClick)
	ON_MESSAGE(UDM_SEM_MODULATOR_POWER_CLICK, OnSemModulatorPowerClick)
	ON_MESSAGE(UDM_SEM_TEST_BUFFER_POWER_CLICK, OnSemTestBufferPowerClick)
	ON_MESSAGE(UDM_SEM_DATA_INPUT_SELECT_CLICK, OnSemDataInputSelectClick)
	ON_MESSAGE(UDM_SEM_PA_POWER_CLICK, OnSemPaPowerClick)
	ON_MESSAGE(UDM_SEM_PA_GAIN_CONTROL1, OnSemPaGainControl1Click)
	ON_MESSAGE(UDM_SEM_PA_GAIN_CONTROL2, OnSemPaGainControl2Click)
	ON_MESSAGE(UDM_SEM_TEST_BUFFER_CURRENT_CLICK, OnSemTestBufferCurrentClick)
	ON_MESSAGE(UDM_SEM_BIAS_BLOCK_ENABLE_CLICK, OnSemBiasBlockEnableClick)
	ON_MESSAGE(UDM_SEM_1ST_STAGE_BIAS_CURRENT_CLICK, OnSem1stStageBiasCurrentClick)
	ON_MESSAGE(UDM_SEM_3RD_STAGE_BIAS_CURRENT_CLICK, OnSem3rdStageBiasCurrentClick)
	ON_MESSAGE(UDM_SEM_4TH_STAGE_BIAS_CURRENT_CLICK, OnSem4thStageBiasCurrentClick)
	ON_MESSAGE(UDM_SEM_5TH_STAGE_BIAS_CURRENT_CLICK, OnSem5thStageBiasCurrentClick)
	ON_MESSAGE(UDM_SEM_REF_STAGE_CURRENT_CLICK, OnSemRefStageCurrentClick)
	ON_MESSAGE(UDM_SEM_IP_STAGE_CURRENT_CLICK, OnSemIpStageCurrentClick)
	ON_MESSAGE(UDM_SEM_FB_CURRENT_CLICK, OnSemFbCurrentClick)
	ON_MESSAGE(UDM_SEM_CORE_CURRENT_CLICK, OnSemCoreCurrentClick)
	ON_MESSAGE(UDM_SEM_OP_BUFFER_CURRENT_CLICK, OnSemOpBufferCurrentClick)
	ON_MESSAGE(UDM_SEM_IP_BUFFER_CURRENT_CLICK, OnSemIpBufferCurrentClick)
	ON_MESSAGE(UDM_SEM_HIGHLOW_DATA_RATE_CURRENT_CLICK, OnSemHighlowDataRateCurrentClick)
	ON_MESSAGE(UDM_SEM_CMOS_GAIN_STAGE_CURRENT_CLICK, OnSemCmosGainStageCurrentClick)
	ON_MESSAGE(UDM_SEM_CML_INTERFACE_STAGE_CURRENT_CLICK, OnSemCmlInterfaceStageCurrentClick)
END_MESSAGE_MAP()


// CSemantic 메시지 처리기


BOOL CSemantic::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	ControlLabelEnable(FALSE);
	ControlValueEnable(FALSE);

	ShowSlider(SW_HIDE);
	GetDlgItem(IDC_CONTROL_COMBO)->ShowWindow(SW_HIDE);
	m_selected = SelectStatic::None;

	GetDlgItem(IDC_READ_ALL_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_WRITE_ALL_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AUTO_WRITE_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_DEFAULT_VALUE_BUTTON)->ShowWindow(SW_HIDE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CSemantic::UpdateRxData(CRegister &reg)
{
	(reg.m_nRxData) ? m_strRxDataInterface.Format(_T("enable")) : m_strRxDataInterface.Format(_T("disable"));
}


void CSemantic::UpdateLimitAmp(CRegister& reg)
{
	(reg.m_nLimitAmp) ? m_strLimitingAmplifier.Format(_T("enable")) : m_strLimitingAmplifier.Format(_T("disable"));
}


void CSemantic::UpdateLnaGain(CRegister& reg)
{
	m_strLnaGain.Format(_T("0x%02x"), reg.m_nLnaGain);
}


void CSemantic::UpdateDutyCycle(CRegister& reg)
{
	m_strDutyCycle.Format(_T("0x%02x"), reg.m_nDutyCycle);
}


void CSemantic::UpdateVcoOscFreq(CRegister& reg)
{
	m_strVcoOscFreq.Format(_T("0x%02x"), reg.m_nVcoOsc);
}


void CSemantic::UpdateRegRefVolt(CRegister& reg)
{
	(reg.m_nRegRef) ? m_strRegRefVolt.Format(_T("400mV")) : m_strRegRefVolt.Format(_T("500mV"));
}


void CSemantic::UpdateVcoVdd(CRegister& reg)
{
	m_strVcoVdd.Format(_T("0x%02x"), reg.m_nVcoVdd);
}


void CSemantic::UpdateVcoPower(CRegister& reg)
{
	(reg.m_nVcoPower) ? m_strVcoPower.Format(_T("VCO on")) : m_strVcoPower.Format(_T("VCO off"));
}


void CSemantic::UpdateModPower(CRegister& reg)
{
	(reg.m_nModPower) ? m_strModPower.Format(_T("MOD on")) : m_strModPower.Format(_T("MOD off"));
}


void CSemantic::UpdateTestBufferPower(CRegister& reg)
{
	(reg.m_nTestBufPower) ? m_strTestBufferPower.Format(_T("test buff on")) : m_strTestBufferPower.Format(_T("test buff off"));
}


void CSemantic::UpdateDataInputSelect(CRegister& reg)
{
	(reg.m_nDataInpSel) ? m_strDataInputSelect.Format(_T("Test buff(External)")) : m_strDataInputSelect.Format(_T("SER(Internal)"));
}


void CSemantic::UpdateDataPaPower(CRegister& reg)
{
	(reg.m_nPaPower) ? m_strPaPower.Format(_T("PA on")) : m_strPaPower.Format(_T("PA off"));
}


void CSemantic::UpdatePaGainControl2(CRegister& reg)
{
	m_strPaGainControl2.Format(_T("0x%02x"), reg.m_nPaGainCon2);
}


void CSemantic::UpdatePaGainControl1(CRegister& reg)
{
	m_strPaGainControl1.Format(_T("0x%02x"), reg.m_nPaGainCon1);
}


void CSemantic::UpdateTestBufferCurrent(CRegister& reg)
{
	m_strTestBufferCurrent.Format(_T("0x%02x"), reg.m_nTestBufCur);
}


void CSemantic::UpdateBiasBlockEnable(CRegister& reg)
{
	(reg.m_nBiasBlock) ? m_strBiasBlockEnable.Format(_T("enable")) : m_strBiasBlockEnable.Format(_T("disable"));
}


void CSemantic::UpdateLna3Current(CRegister& reg)
{
	m_strLna3Current.Format(_T("0x%02x"), reg.m_nLna3Cur);
}


void CSemantic::UpdateLna1Current(CRegister& reg)
{
	m_strLna1Current.Format(_T("0x%02x"), reg.m_nLna1Cur);
	m_strLna2Current = m_strLna1Current;
}


void CSemantic::UpdateLna2Current(CRegister& reg)
{
	m_strLna2Current.Format(_T("0x%02x"), reg.m_nLna1Cur);
	m_strLna1Current = m_strLna2Current;
}


void CSemantic::UpdateLna5Current(CRegister& reg)
{
	m_strLna5Current.Format(_T("0x%02x"), reg.m_nLna5Cur);
}


void CSemantic::UpdateLna4Current(CRegister& reg)
{
	m_strLna4Current.Format(_T("0x%02x"), reg.m_nLna4Cur);
}


void CSemantic::UpdateDemodRefStageCurrent(CRegister& reg)
{
	m_strDemodRefStageCurrent.Format(_T("0x%02x"), reg.m_nDemodRefStageCur);
}


void CSemantic::UpdateDemodIPStageCurrent(CRegister& reg)
{
	m_strDemodIPStageCurrent.Format(_T("0x%02x"), reg.m_nDemodIPStageCur);
}


void CSemantic::UpdateLaFBCurrent(CRegister& reg)
{
	m_strLaFBCurrent.Format(_T("0x%02x"), reg.m_nLaFBCur);
}


void CSemantic::UpdateLaCoreCurrent(CRegister& reg)
{
	m_strLaCoreCurrent.Format(_T("0x%02x"), reg.m_nLaCoreCur);
}


void CSemantic::UpdateLaOPBufferCurrent(CRegister& reg)
{
	m_strLaOPBufferCurrent.Format(_T("0x%02x"), reg.m_nLaOPBufCur);
}


void CSemantic::UpdateLaIPBufferCurrent(CRegister& reg)
{
	m_strLaIPBufferCurrent.Format(_T("0x%02x"), reg.m_nLaIPBufCur);
}


void CSemantic::UpdateLaHLDataRateCurrent(CRegister& reg)
{
	m_strLaHLDataRateCurrent.Format(_T("0x%02x"), reg.m_nLaHLDataRateCur);
}


void CSemantic::UpdateCMOSGainStageCurrent(CRegister& reg)
{
	m_strCMOSGainStageCurrent.Format(_T("0x%02x"), reg.m_nCMOSGainStageCur);
}


void CSemantic::UpdateCMLInterfaceStageCurrent(CRegister& reg)
{
	m_strCMLInterfaceStageCurrent.Format(_T("0x%02x"), reg.m_nCMLInterfaceStageCur);
}


void CSemantic::UpdateFdCoreCurrent(CRegister& reg)
{
	m_strFdCoreCur.Format(_T("0x%02x"), reg.m_nFdCoreCur);
}


void CSemantic::UpdateFdBufferCurrent(CRegister& reg)
{
	m_strFdBufCur.Format(_T("0x%02x"), reg.m_nFdBufCur);
}


void CSemantic::UpdateRegisters()
{
	ASSERT(Parent());
	CRegister reg;
	Parse(Parent()->m_pRaw, reg);

	UpdateRxData(reg);
	UpdateLimitAmp(reg);
	UpdateLnaGain(reg);

	UpdateDutyCycle(reg);
	UpdateVcoOscFreq(reg);
	UpdateRegRefVolt(reg);
	UpdateVcoVdd(reg);

	UpdateVcoPower(reg);
	UpdateModPower(reg);
	UpdateTestBufferPower(reg);
	UpdateDataInputSelect(reg);
	UpdateDataPaPower(reg);
	UpdatePaGainControl2(reg);
	UpdatePaGainControl1(reg);
	UpdateTestBufferCurrent(reg);

	UpdateBiasBlockEnable(reg);

	UpdateLna3Current(reg);
	UpdateLna1Current(reg);
	UpdateLna2Current(reg);

	UpdateLna5Current(reg);
	UpdateLna4Current(reg);

	UpdateDemodRefStageCurrent(reg);
	UpdateDemodIPStageCurrent(reg);

	UpdateLaFBCurrent(reg);
	UpdateLaCoreCurrent(reg);

	UpdateLaOPBufferCurrent(reg);
	UpdateLaIPBufferCurrent(reg);

	UpdateLaHLDataRateCurrent(reg);
	UpdateCMOSGainStageCurrent(reg);

	UpdateCMLInterfaceStageCurrent(reg);

	UpdateFdCoreCurrent(reg);
	UpdateFdBufferCurrent(reg);
	UpdateData(FALSE);
}


HBRUSH CSemantic::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	if (pWnd->GetDlgCtrlID() == IDC_LNA_GAIN_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::LnaGain);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_DUTY_CYCLE_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::DutyCycle);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_VCO_OSC_FREQ_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::VcoOsc);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_VCO_VDD_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::VcoVdd);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_PA_GAIN_CONTROL1_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::PaGain1);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_PA_GAIN_CONTROL2_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::PaGain2);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_TEST_BUFFER_CURRENT_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::TestBuffer);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_LNA1_BIAS_CURRENT_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::Lna1);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_LNA2_BIAS_CURRENT_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::Lna2);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_LNA3_BIAS_CURRENT_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::Lna3);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_LNA4_BIAS_CURRENT_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::Lna4);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_LNA5_BIAS_CURRENT_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::Lna5);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_DEMOD_REF_STAGE_CURRENT_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::RefStage);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_DEMOD_IP_STAGE_CURRENT_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::IpStage);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_LA_FB_CURRENT_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::Fb);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_LA_CORE_CURRENT_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::Core);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_LA_OP_BUFFER_CURRENT_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::OP);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_LA_IP_BUFFER_CURRENT_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::IP);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_LA_HL_DATA_RATE_CURRENT_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::HL);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_CMOS_GAIN_STAGE_CURRENT_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::CMOS);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_CML_INTERFACE_STAGE_CURRENT_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::CML);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_RX_DATA_IF_ENABLE_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::RxData);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_LIMITING_AMP_ENABLE_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::LimAmp);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_REG_REF_VOLT_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::RegRef);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_VCO_POWER_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::VcoPow);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_MODULATOR_POWER_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::ModPow);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_TEST_BUFFER_POWER_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::TestBufPow);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_DATA_INPUT_SELECT_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::DataInp);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_PA_POWER_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::PaPow);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_BIAS_BLOCK_ENABLE_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::BiasBlock);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_FD_CORE_CURRENT_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::FdCore);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_FD_BUFFER_CURRENT_VALUE_STATIC) {
		SetColor(pDC, SelectStatic::FdBuf);
	}

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


void CSemantic::OnStnClickedLnaGainValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(SelectStatic::LnaGain, 0, 7, m_strLnaGain, 1, 1, 10, IDC_LNA_GAIN_STATIC);
}


void CSemantic::OnStnClickedDutyCycleValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(SelectStatic::DutyCycle, 0, 255, m_strDutyCycle, 10, 1, 10, IDC_DUTY_CYCLE_STATIC);
}


void CSemantic::OnStnClickedVcoOscFreqValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(SelectStatic::VcoOsc, 0, 2047, m_strVcoOscFreq, 50, 1, 50, IDC_VCO_OSC_FREQ_STATIC);
}


void CSemantic::OnStnClickedVcoVddValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(SelectStatic::VcoVdd, 0, 15, m_strVcoVdd, 1, 1, 10, IDC_VCO_VDD_STATIC);
}


void CSemantic::OnStnClickedPaGainControl1ValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(SelectStatic::PaGain1, 0, 15, m_strPaGainControl1, 1, 1, 10, IDC_PA_GAIN_CONTROL1_STATIC);
}


void CSemantic::OnStnClickedPaGainControl2ValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(SelectStatic::PaGain2, 0, 15, m_strPaGainControl2, 1, 1, 10, IDC_PA_GAIN_CONTROL2_STATIC);
}


void CSemantic::OnStnClickedTestBufferCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(SelectStatic::TestBuffer, 0, 15, m_strTestBufferCurrent, 1, 1, 10, IDC_TEST_BUFFER_CURRENT_STATIC);
}


void CSemantic::OnStnClickedLna1BiasCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(SelectStatic::Lna1, 0, 15, m_strLna1Current, 1, 1, 10, IDC_LNA1_BIAS_CURRENT_STATIC);
}


void CSemantic::OnStnClickedLna2BiasCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(SelectStatic::Lna2, 0, 15, m_strLna2Current, 1, 1, 10, IDC_LNA2_BIAS_CURRENT_STATIC);
}


void CSemantic::OnStnClickedLna3BiasCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(SelectStatic::Lna3, 0, 15, m_strLna3Current, 1, 1, 10, IDC_LNA3_BIAS_CURRENT_STATIC);
}


void CSemantic::OnStnClickedLna4BiasCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(SelectStatic::Lna4, 0, 15, m_strLna4Current, 1, 1, 10, IDC_LNA4_BIAS_CURRENT_STATIC);
}


void CSemantic::OnStnClickedLna5BiasCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(SelectStatic::Lna5, 0, 15, m_strLna5Current, 1, 1, 10, IDC_LNA5_BIAS_CURRENT_STATIC);
}


void CSemantic::OnStnClickedDemodRefStageCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(SelectStatic::RefStage, 0, 15, m_strDemodRefStageCurrent, 1, 1, 10, IDC_DEMOD_REF_STAGE_CURRENT_STATIC);
}


void CSemantic::OnStnClickedDemodIpStageCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(SelectStatic::IpStage, 0, 15, m_strDemodIPStageCurrent, 1, 1, 10, IDC_DEMOD_IP_STAGE_CURRENT_STATIC);
}


void CSemantic::OnStnClickedLaFbCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(SelectStatic::Fb, 0, 15, m_strLaFBCurrent, 1, 1, 10, IDC_LA_FB_CURRENT_STATIC);
}


void CSemantic::OnStnClickedLaCoreCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(SelectStatic::Core, 0, 15, m_strLaCoreCurrent, 1, 1, 10, IDC_LA_CORE_CURRENT_STATIC);
}


void CSemantic::OnStnClickedLaOpBufferCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(SelectStatic::OP, 0, 15, m_strLaOPBufferCurrent, 1, 1, 10, IDC_LA_OP_BUFFER_CURRENT_STATIC);
}


void CSemantic::OnStnClickedLaIpBufferCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(SelectStatic::IP, 0, 15, m_strLaIPBufferCurrent, 1, 1, 10, IDC_LA_IP_BUFFER_CURRENT_STATIC);
}


void CSemantic::OnStnClickedLaHlDataRateCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(SelectStatic::HL, 0, 15, m_strLaHLDataRateCurrent, 1, 1, 10, IDC_LA_HL_DATA_RATE_CURRENT_STATIC);
}


void CSemantic::OnStnClickedCmosGainStageCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(SelectStatic::CMOS, 0, 15, m_strCMOSGainStageCurrent, 1, 1, 10, IDC_CMOS_GAIN_STAGE_CURRENT_STATIC);
}


void CSemantic::OnStnClickedCmlInterfaceStageCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(SelectStatic::CML, 0, 255, m_strCMLInterfaceStageCurrent, 10, 1, 10, IDC_CML_INTERFACE_STAGE_CURRENT_STATIC);
}


void CSemantic::OnStnClickedFdCoreCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(SelectStatic::FdCore, 0, 15, m_strFdCoreCur, 1, 1, 10, IDC_FD_CORE_CURRENT_STATIC);
}


void CSemantic::OnStnClickedFdBufferCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(SelectStatic::FdBuf, 0, 15, m_strFdBufCur, 1, 1, 10, IDC_FD_BUFFER_CURRENT_STATIC);
}


void CSemantic::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	BOOL bProcessed = TRUE;
	if (pScrollBar == (CScrollBar*)&m_controlSlider) {
		int curPos = SliderValueUpdate();

		CString strCur;
		strCur.Format(_T("0x%02x"), curPos);
		switch (m_selected) {
		case SelectStatic::LnaGain:
			(strCur ==m_strLnaGain) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			break;
		case SelectStatic::DutyCycle:
			(strCur == m_strDutyCycle) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			break;
		case SelectStatic::VcoOsc:
			(strCur == m_strVcoOscFreq) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			break;
		case SelectStatic::VcoVdd:
			(strCur == m_strVcoVdd) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			break;
		case SelectStatic::PaGain1:
			(strCur == m_strPaGainControl1) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			break;
		case SelectStatic::PaGain2:
			(strCur == m_strPaGainControl2) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			break;
		case SelectStatic::TestBuffer:
			(strCur == m_strTestBufferCurrent) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			break;
		case SelectStatic::Lna1:
			(strCur == m_strLna1Current) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			break;
		case SelectStatic::Lna2:
			(strCur == m_strLna2Current) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			break;
		case SelectStatic::Lna3:
			(strCur == m_strLna3Current) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			break;
		case SelectStatic::Lna4:
			(strCur == m_strLna4Current) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			break;
		case SelectStatic::Lna5:
			(strCur == m_strLna5Current) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			break;
		case SelectStatic::RefStage:
			(strCur == m_strDemodRefStageCurrent) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			break;
		case SelectStatic::IpStage:
			(strCur == m_strDemodIPStageCurrent) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			break;
		case SelectStatic::Fb:
			(strCur == m_strLaFBCurrent) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			break;
		case SelectStatic::Core:
			(strCur == m_strLaCoreCurrent) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			break;
		case SelectStatic::OP:
			(strCur == m_strLaOPBufferCurrent) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			break;
		case SelectStatic::IP:
			(strCur == m_strLaIPBufferCurrent) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			break;
		case SelectStatic::HL:
			(strCur == m_strLaHLDataRateCurrent) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			break;
		case SelectStatic::CMOS:
			(strCur == m_strCMOSGainStageCurrent) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			break;
		case SelectStatic::CML:
			(strCur == m_strCMLInterfaceStageCurrent) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			break;
		case SelectStatic::FdCore:
			(strCur == m_strFdCoreCur) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			break;
		case SelectStatic::FdBuf:
			(strCur == m_strFdBufCur) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			break;
		default:
			bProcessed = FALSE;
			break;
		}
	}

	if (bProcessed && m_bAutoWrite) OnBnClickedWriteButton();
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CSemantic::OnBnClickedReadAllButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ResetValues();
	Parent()->m_pRaw->OnBnClickedReadAllButton();
	UpdateRegisters();
}


void CSemantic::OnStnClickedRxDataIfEnableValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CRegister reg;
	Parse(Parent()->m_pRaw, reg);
	SetComboGroup(SelectStatic::RxData, _T("disable"), _T("enable"), reg.m_nRxData, IDC_RX_DATA_IF_ENABLE_STATIC);
}



void CSemantic::OnStnClickedLimitingAmpEnableValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CRegister reg;
	Parse(Parent()->m_pRaw, reg);
	SetComboGroup(SelectStatic::LimAmp, _T("disable"), _T("enable"), reg.m_nLimitAmp, IDC_LIMITING_AMP_ENABLE_STATIC);
}


void CSemantic::OnStnClickedRegRefVoltValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CRegister reg;
	Parse(Parent()->m_pRaw, reg);
	SetComboGroup(SelectStatic::RegRef, _T("500mV"), _T("400mV"), reg.m_nRegRef, IDC_REG_REF_VOLT_STATIC);
}


void CSemantic::OnStnClickedVcoPowerValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CRegister reg;
	Parse(Parent()->m_pRaw, reg);
	SetComboGroup(SelectStatic::VcoPow, _T("VCO Off"), _T("VCO On"), reg.m_nVcoPower, IDC_VCO_POWER_STATIC);
}


void CSemantic::OnStnClickedModulatorPowerValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CRegister reg;
	Parse(Parent()->m_pRaw, reg);
	SetComboGroup(SelectStatic::ModPow, _T("Mod Off"), _T("Mod On"), reg.m_nModPower, IDC_MODULATOR_POWER_STATIC);
}


void CSemantic::OnStnClickedTestBufferPowerValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CRegister reg;
	Parse(Parent()->m_pRaw, reg);
	SetComboGroup(SelectStatic::TestBufPow, _T("Test Buff Off"), _T("Test Buff On"), reg.m_nTestBufPower, IDC_TEST_BUFFER_POWER_STATIC);
}


void CSemantic::OnStnClickedDataInputSelectValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CRegister reg;
	Parse(Parent()->m_pRaw, reg);
	SetComboGroup(SelectStatic::DataInp, _T("SER(Internal)"), _T("Test Buff(External)"), reg.m_nDataInpSel, IDC_DATA_INPUT_SELECT_STATIC);
}


void CSemantic::OnStnClickedPaPowerValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CRegister reg;
	Parse(Parent()->m_pRaw, reg);
	SetComboGroup(SelectStatic::PaPow, _T("PA Off"), _T("PA On"), reg.m_nPaPower, IDC_PA_POWER_STATIC);
}


void CSemantic::OnStnClickedBiasBlockEnableValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CRegister reg;
	Parse(Parent()->m_pRaw, reg);
	SetComboGroup(SelectStatic::BiasBlock, _T("disable"), _T("enable"), reg.m_nBiasBlock, IDC_BIAS_BLOCK_ENABLE_STATIC);
}


void CSemantic::ResetValues()
{
	m_strRxDataInterface.Empty();
	m_strLimitingAmplifier.Empty();
	m_strLnaGain.Empty();
	m_strDutyCycle.Empty();
	m_strVcoOscFreq.Empty();
	m_strRegRefVolt.Empty();
	m_strVcoVdd.Empty();
	m_strVcoPower.Empty();
	m_strModPower.Empty();
	m_strTestBufferPower.Empty();
	m_strDataInputSelect.Empty();
	m_strPaPower.Empty();
	m_strPaGainControl1.Empty();
	m_strPaGainControl2.Empty();
	m_strTestBufferCurrent.Empty();
	m_strBiasBlockEnable.Empty();
	m_strLna1Current.Empty();
	m_strLna2Current.Empty();
	m_strLna3Current.Empty();
	m_strLna4Current.Empty();
	m_strLna5Current.Empty();
	m_strDemodRefStageCurrent.Empty();
	m_strDemodIPStageCurrent.Empty();
	m_strLaFBCurrent.Empty();
	m_strLaCoreCurrent.Empty();
	m_strLaOPBufferCurrent.Empty();
	m_strLaIPBufferCurrent.Empty();
	m_strLaHLDataRateCurrent.Empty();
	m_strCMOSGainStageCurrent.Empty();
	m_strCMLInterfaceStageCurrent.Empty();
	m_strFdCoreCur.Empty();
	m_strFdBufCur.Empty();
	UpdateData(FALSE);
}

void CSemantic::OnCbnSelchangeControlCombo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRegister reg;
	Parse(Parent()->m_pRaw, reg);

	BOOL bProcessed = TRUE;
	switch (m_selected) {
	case SelectStatic::RxData:
		(ComboSel() == reg.m_nRxData) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
		break;
	case SelectStatic::LimAmp:
		(ComboSel() == reg.m_nLimitAmp) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
		break;
	case SelectStatic::RegRef:
		(ComboSel() == reg.m_nRegRef) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
		break;
	case SelectStatic::VcoPow:
		(ComboSel() == reg.m_nVcoPower) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
		break;
	case SelectStatic::ModPow:
		(ComboSel() == reg.m_nModPower) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
		break;
	case SelectStatic::TestBufPow:
		(ComboSel() == reg.m_nTestBufPower) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
		break;
	case SelectStatic::DataInp:
		(ComboSel() == reg.m_nDataInpSel) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
		break;
	case SelectStatic::PaPow:
		(ComboSel() == reg.m_nPaPower) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
		break;
	case SelectStatic::BiasBlock:
		(ComboSel() == reg.m_nBiasBlock) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
		break;
	default:
		bProcessed = FALSE;
		break;
	}

	if (bProcessed && m_bAutoWrite) OnBnClickedWriteButton();
}


BOOL CSemantic::UpdateSemanticValue(int addr, int (* fpNewRegVal)(int, int), int newVal, void (CSemantic::* fpUpdateData)(CRegister&))
{
	int oldRegVal;
	char buffer[3];
	while (Parent()->m_pRaw->ReadRegister(addr, 2, buffer, MAX_LOOP) != ERROR_SUCCESS) Sleep(10);	//Blocking 함수

	oldRegVal = (int)strtol(buffer, NULL, 16);
	int newRegVal = (*fpNewRegVal)(oldRegVal, newVal);
	if (Parent()->m_pRaw->WriteRegister(addr, newRegVal) != TRUE) {
		Parent()->L(_T("Error in WriteRegister"));
	}
	else {
#ifdef DEBUG_READ
		CString str;
		str.Format(_T("ReadRegister Address:0x%02x..."), addr);
		Parent()->L(str);
#endif

		Parent()->m_pRaw->ReadRegister(addr);	//Blocking함수 호출
#ifdef DEBUG_READ
		str.Format(_T("ReadRegister Address:0x%02x done"), addr);
		Parent()->L(str);
#endif

		if (fpUpdateData) {
			CRegister reg;
			Parse(Parent()->m_pRaw, reg);
			(this->*fpUpdateData)(reg);
			UpdateData(FALSE);

			CString str;
			str.Format(_T("Address:0x%02x %s 0x%02x -> 0x%02x"), addr, Parent()->m_pRaw->RegisterName(addr), oldRegVal, newRegVal);
			Parent()->L(str);
		}
		return TRUE;
	}
	return FALSE;
}


BOOL CSemantic::UpdateSelected(SelectStatic selected,BOOL bCommonControl)
{
	ASSERT(Parent()->m_chip == _T("A0") || Parent()->m_chip == _T("B0"));

	BOOL bRtn = TRUE;
	int updateValue;
	switch (selected) {
		//ControlCombo
	case SelectStatic::RxData:
		bCommonControl ? updateValue = ComboSel() : updateValue = RxData();
		bRtn = UpdateSemanticValue(2, &OnNewRxData, updateValue, &CSemantic::UpdateRxData);
		break;
	case SelectStatic::LimAmp:
		bCommonControl ? updateValue = ComboSel() : updateValue = LimAmp();
		bRtn = UpdateSemanticValue(2, &OnNewLimAmp, updateValue, &CSemantic::UpdateLimitAmp);
		break;
	case SelectStatic::RegRef:
		if (Parent()->m_chip == _T("B0")) {
			bCommonControl ? updateValue = ComboSel() : updateValue = RegRef();
			bRtn = UpdateSemanticValue(5, &OnNewRegRef, updateValue, &CSemantic::UpdateRegRefVolt);
		}
		break;
	case SelectStatic::VcoPow:
		if (Parent()->m_chip == _T("B0")) {
			bCommonControl ? updateValue = ComboSel() : updateValue = VcoPow();
			bRtn = UpdateSemanticValue(13, &OnNewVcoPow, updateValue, &CSemantic::UpdateVcoPower);
		}
		break;
	case SelectStatic::ModPow:
		bCommonControl ? updateValue = ComboSel() : updateValue = ModPow();
		bRtn = UpdateSemanticValue(12, &OnNewModPow, updateValue, &CSemantic::UpdateModPower);
		break;
	case SelectStatic::TestBufPow:
		bCommonControl ? updateValue = ComboSel() : updateValue = TestBufPow();
		bRtn = UpdateSemanticValue(12, &OnNewTestBufPow, updateValue, &CSemantic::UpdateTestBufferPower);
		break;
	case SelectStatic::DataInp:
		bCommonControl ? updateValue = ComboSel() : updateValue = DataInp();
		bRtn = UpdateSemanticValue(12, &OnNewDataInp, updateValue, &CSemantic::UpdateDataInputSelect);
		break;
	case SelectStatic::PaPow:
		bCommonControl ? updateValue = ComboSel() : updateValue = PaPow();
		bRtn = UpdateSemanticValue(12, &OnNewPaPow, updateValue, &CSemantic::UpdateDataPaPower);
		break;
	case SelectStatic::BiasBlock:
		bCommonControl ? updateValue = ComboSel() : updateValue = BiasBlock();
		bRtn = UpdateSemanticValue(17, &OnNewBiasBlock, updateValue, &CSemantic::UpdateBiasBlockEnable);
		break;

		//ControlSlide
	case SelectStatic::LnaGain:
		bCommonControl ? updateValue = SliderPos() : updateValue = LnaGain();
		bRtn = UpdateSemanticValue(2, &OnNewLnaGain, updateValue, &CSemantic::UpdateLnaGain);
		break;
	case SelectStatic::DutyCycle:
		bCommonControl ? updateValue = SliderPos() : updateValue = DutyCycle();
		bRtn = UpdateSemanticValue(7, &OnNewDutyCycle, updateValue, &CSemantic::UpdateDutyCycle);
		break;
	case SelectStatic::VcoOsc:
		if (Parent()->m_chip == _T("B0")) {
			bCommonControl ? updateValue = SliderPos() : updateValue = VcoOsc();
			bRtn = UpdateSemanticValue(6, &OnNewVcoOscUp, updateValue, NULL);
			ASSERT(bRtn);
			bRtn = UpdateSemanticValue(5, &OnNewVcoOscDown, updateValue, &CSemantic::UpdateVcoOscFreq);
		}
		break;
	case SelectStatic::VcoVdd:
		if (Parent()->m_chip == _T("B0")) {
			bCommonControl ? updateValue = SliderPos() : updateValue = VcoVdd();
			bRtn = UpdateSemanticValue(5, &OnNewVcoVdd, updateValue, &CSemantic::UpdateVcoVdd);
		}
		break;
	case SelectStatic::PaGain1:
		bCommonControl ? updateValue = SliderPos() : updateValue = PaGain1();
		bRtn = UpdateSemanticValue(11, &OnNewPaGain1, updateValue, &CSemantic::UpdatePaGainControl1);
		break;
	case SelectStatic::PaGain2:
		bCommonControl ? updateValue = SliderPos() : updateValue = PaGain2();
		bRtn = UpdateSemanticValue(12, &OnNewPaGain2, updateValue, &CSemantic::UpdatePaGainControl2);
		break;
	case SelectStatic::TestBuffer:
		bCommonControl ? updateValue = SliderPos() : updateValue = TestBuffer();
		bRtn = UpdateSemanticValue(11, &OnNewTestBuffer, updateValue, &CSemantic::UpdateTestBufferCurrent);
		break;
	case SelectStatic::Lna1:
		bCommonControl ? updateValue = SliderPos() : updateValue = Lna1();
		bRtn = UpdateSemanticValue(18, &OnNewLna1, updateValue, &CSemantic::UpdateLna1Current);
		break;
	case SelectStatic::Lna2:
		bCommonControl ? updateValue = SliderPos() : updateValue = Lna2();
		bRtn = UpdateSemanticValue(18, &OnNewLna2, updateValue, &CSemantic::UpdateLna2Current);
		break;
	case SelectStatic::Lna3:
		bCommonControl ? updateValue = SliderPos() : updateValue = Lna3();
		bRtn = UpdateSemanticValue(18, &OnNewLna3, updateValue, &CSemantic::UpdateLna3Current);
		break;
	case SelectStatic::Lna4:
		bCommonControl ? updateValue = SliderPos() : updateValue = Lna4();
		bRtn = UpdateSemanticValue(19, &OnNewLna4, updateValue, &CSemantic::UpdateLna4Current);
		break;
	case SelectStatic::Lna5:
		bCommonControl ? updateValue = SliderPos() : updateValue = Lna5();
		bRtn = UpdateSemanticValue(19, &OnNewLna5, updateValue, &CSemantic::UpdateLna5Current);
		break;
	case SelectStatic::RefStage:
		bCommonControl ? updateValue = SliderPos() : updateValue = RefStage();
		bRtn = UpdateSemanticValue(20, &OnNewRefStage, updateValue, &CSemantic::UpdateDemodRefStageCurrent);
		break;
	case SelectStatic::IpStage:
		bCommonControl ? updateValue = SliderPos() : updateValue = IpStage();
		bRtn = UpdateSemanticValue(20, &OnNewIpStage, updateValue, &CSemantic::UpdateDemodIPStageCurrent);
		break;
	case SelectStatic::Fb:
		bCommonControl ? updateValue = SliderPos() : updateValue = Fb();
		bRtn = UpdateSemanticValue(21, &OnNewFb, updateValue, &CSemantic::UpdateLaFBCurrent);
		break;
	case SelectStatic::Core:
		bCommonControl ? updateValue = SliderPos() : updateValue = Core();
		bRtn = UpdateSemanticValue(21, &OnNewCore, updateValue, &CSemantic::UpdateLaCoreCurrent);
		break;
	case SelectStatic::OP:
		bCommonControl ? updateValue = SliderPos() : updateValue = OP();
		bRtn = UpdateSemanticValue(22, &OnNewOP, updateValue, &CSemantic::UpdateLaOPBufferCurrent);
		break;
	case SelectStatic::IP:
		bCommonControl ? updateValue = SliderPos() : updateValue = IP();
		bRtn = UpdateSemanticValue(22, &OnNewIP, updateValue, &CSemantic::UpdateLaIPBufferCurrent);
		break;
	case SelectStatic::HL:
		bCommonControl ? updateValue = SliderPos() : updateValue = HL();
		bRtn = UpdateSemanticValue(23, &OnNewHL, updateValue, &CSemantic::UpdateLaHLDataRateCurrent);
		break;
	case SelectStatic::CMOS:
		bCommonControl ? updateValue = SliderPos() : updateValue = CMOS();
		bRtn = UpdateSemanticValue(23, &OnNewCMOS, updateValue, &CSemantic::UpdateCMOSGainStageCurrent);
		break;
	case SelectStatic::CML:
		bCommonControl ? updateValue = SliderPos() : updateValue = CML();
		bRtn = UpdateSemanticValue(24, &OnNewCML, updateValue, &CSemantic::UpdateCMLInterfaceStageCurrent);
		break;
	case SelectStatic::FdCore:
		if (Parent()->m_chip == _T("A0")) {
			bCommonControl ? updateValue = SliderPos() : updateValue = FdCore();
			bRtn = UpdateSemanticValue(25, &OnNewFdCore, updateValue, &CSemantic::UpdateFdCoreCurrent);
		}
		break;
	case SelectStatic::FdBuf:
		if (Parent()->m_chip == _T("A0")) {
			bCommonControl ? updateValue = SliderPos() : updateValue = FdBuf();
			bRtn = UpdateSemanticValue(25, &OnNewFdBuf, updateValue, &CSemantic::UpdateFdBufferCurrent);
		}
		break;
	default:
		break;
	}
	return bRtn;
}


void CSemantic::OnBnClickedWriteButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
#ifdef DEBUG_WRITE
	Parent()->L(_T("Writing..."));
#endif

	BOOL bRtn = UpdateSelected(m_selected,TRUE);
	ASSERT(bRtn);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);

#ifdef DEBUG_WRITE
	Parent()->L(_T("Writing done"));
#endif
}


void CSemantic::OnBnClickedWriteAllButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	//스펙에 정의되지 않은 범위의 비트값들은 비트값들은 0으로 하기 위해서 0으로 초기화한뒤에 레지스터 값이 쓰여지도록 한다
	BOOL b = Parent()->m_pRaw->WriteRegister(0x02, 0x0);
	b = b && Parent()->m_pRaw->WriteRegister(0x0d, 0x0);
	b = b && Parent()->m_pRaw->WriteRegister(0x11, 0x0);
	ASSERT(b);

	int errCnt = 0;
	CString str;
	for (int i = 1; i <= static_cast<int>(SelectStatic::FdBuf); i++) {
		if (!UpdateSelected(static_cast<SelectStatic>(i), FALSE)) {
			str.Format(_T("Update failed at SelectStatic:%d"),i);
			Parent()->L(str);
			errCnt++;
		}
	}
	if (errCnt == 0)
		Parent()->L(_T("All registers are updated"));
	else {
		str.Format(_T("%d Update failures"), errCnt);
		Parent()->L(str);
	}
	OnBnClickedReadAllButton();
}


int CSemantic::disableOrEnable(CString str)
{
	return strToInt(_T("disable"), _T("enable"), str);
}


int CSemantic::strToInt(CString zero, CString one, CString str)
{
	ASSERT(str == zero || str == one);

	if (str == zero) return 0;
	ASSERT(str == one);
	return 1;
}


int CSemantic::RxData()
{
	return disableOrEnable(m_strRxDataInterface);
}


int CSemantic::LimAmp()
{
	return disableOrEnable(m_strLimitingAmplifier);
}


int CSemantic::LnaGain()
{
	int val = _tcstol(m_strLnaGain.GetBuffer(), NULL, 16);
	ASSERT(val >= 0 && val <= 0x7);
	return val;
}


int CSemantic::DutyCycle()
{
	return Read8BitValue(m_strDutyCycle);
}


int CSemantic::VcoOsc()
{
	int val = _tcstol(m_strVcoOscFreq.GetBuffer(), NULL, 16);
	ASSERT(val >= 0 && val <= 0x7ff);
	return val;
}


int CSemantic::RegRef()
{
	return strToInt(_T("500mV"), _T("400mV"), m_strRegRefVolt);
}


int CSemantic::VcoVdd()
{
	return Read4BitValue(m_strVcoVdd);
}


int CSemantic::VcoPow()
{
	return strToInt(_T("VCO off"), _T("VCO on"), m_strVcoPower);
}


int CSemantic::ModPow()
{
	return strToInt(_T("MOD off"), _T("MOD on"), m_strModPower);
}


int CSemantic::TestBufPow()
{
	return strToInt(_T("test buff off"), _T("test buff on"), m_strTestBufferPower);
}


int CSemantic::DataInp()
{
	return strToInt(_T("SER(Internal)"), _T("Test buff(External)"), m_strDataInputSelect);
}


int CSemantic::PaPow()
{
	return strToInt(_T("PA off"), _T("PA on"), m_strPaPower);
}


int CSemantic::PaGain1()
{
	return Read4BitValue(m_strPaGainControl1);
}


int CSemantic::PaGain2()
{
	return Read4BitValue(m_strPaGainControl2);
}


int CSemantic::TestBuffer()
{
	return Read4BitValue(m_strTestBufferCurrent);
}


int CSemantic::BiasBlock()
{
	return disableOrEnable(m_strBiasBlockEnable);
}


int CSemantic::Lna1()
{
	return Read4BitValue(m_strLna1Current);
}


int CSemantic::Lna2()
{
	return Read4BitValue(m_strLna2Current);
}


int CSemantic::Lna3()
{
	return Read4BitValue(m_strLna3Current);
}


int CSemantic::Lna4()
{
	return Read4BitValue(m_strLna4Current);
}


int CSemantic::Lna5()
{
	return Read4BitValue(m_strLna5Current);
}


int CSemantic::RefStage()
{
	return Read4BitValue(m_strDemodRefStageCurrent);
}


int CSemantic::IpStage()
{
	return Read4BitValue(m_strDemodIPStageCurrent);
}


int CSemantic::Fb()
{
	return Read4BitValue(m_strLaFBCurrent);
}


int CSemantic::Core()
{
	return Read4BitValue(m_strLaCoreCurrent);
}


int CSemantic::OP()
{
	return Read4BitValue(m_strLaOPBufferCurrent);
}


int CSemantic::IP()
{
	return Read4BitValue(m_strLaIPBufferCurrent);
}


int CSemantic::HL()
{
	return Read4BitValue(m_strLaHLDataRateCurrent);
}


int CSemantic::CMOS()
{
	return Read4BitValue(m_strCMOSGainStageCurrent);
}


int CSemantic::CML()
{
	return Read8BitValue(m_strCMLInterfaceStageCurrent);
}


int CSemantic::FdCore()
{
	return Read4BitValue(m_strFdCoreCur);
}


int CSemantic::FdBuf()
{
	return Read4BitValue(m_strFdBufCur);
}


void CSemantic::OnChipConnect(CString chipModel)
{
	ASSERT(chipModel == _T("A0") || chipModel == _T("B0"));

	if (chipModel == _T("A0")) {
		GetDlgItem(IDC_VCO_OSC_FREQ_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_REG_REF_VOLT_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_VCO_VDD_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_VCO_POWER_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_FD_CORE_CURRENT_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_FD_BUFFER_CURRENT_STATIC)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_VCO_OSC_FREQ_VALUE_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_REG_REF_VOLT_VALUE_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_VCO_VDD_VALUE_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_VCO_POWER_VALUE_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_FD_CORE_CURRENT_VALUE_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_FD_BUFFER_CURRENT_VALUE_STATIC)->ShowWindow(SW_SHOW);
	}
	else if (chipModel == _T("B0")) {
		GetDlgItem(IDC_VCO_OSC_FREQ_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_REG_REF_VOLT_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_VCO_VDD_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_VCO_POWER_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_FD_CORE_CURRENT_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_FD_BUFFER_CURRENT_STATIC)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_VCO_OSC_FREQ_VALUE_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_REG_REF_VOLT_VALUE_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_VCO_VDD_VALUE_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_VCO_POWER_VALUE_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_FD_CORE_CURRENT_VALUE_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_FD_BUFFER_CURRENT_VALUE_STATIC)->ShowWindow(SW_HIDE);
	}
}


void CSemantic::OnBnClickedDefaultValueButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString chipModel = Parent()->m_chip;

	ASSERT(chipModel == _T("A0") || chipModel == _T("B0"));

	Parent()->m_pRaw->m_strRxReg1 = _T("0x18");
	Parent()->m_pRaw->m_strTxReg1Top = _T("0x00");
	Parent()->m_pRaw->m_strBiasReg1 = _T("0x01");
	Parent()->m_pRaw->m_strBiasReg2 = _T("0x99");
	Parent()->m_pRaw->m_strBiasReg3 = _T("0x99");
	Parent()->m_pRaw->m_strBiasReg4 = _T("0x96");
	Parent()->m_pRaw->m_strBiasReg5 = _T("0x66");
	Parent()->m_pRaw->m_strBiasReg6 = _T("0x66");
	Parent()->m_pRaw->m_strBiasReg7 = _T("0x06");

	if (chipModel == _T("A0")) {
		Parent()->m_pRaw->m_strTxReg1Mid = _T("0xf7");
		Parent()->m_pRaw->m_strTxReg1Bot = _T("0xb7");
		Parent()->m_pRaw->m_strBiasReg8 = _T("0x06");
		Parent()->m_pRaw->m_strBiasReg9 = _T("0x99");
	}
	else if (chipModel == _T("B0")) {
		Parent()->m_pRaw->m_strTxReg1Mid = _T("0x10");
		Parent()->m_pRaw->m_strTxReg1Bot = _T("0x10");
		Parent()->m_pRaw->m_strTxReg2Top = _T("0x01");
		Parent()->m_pRaw->m_strTxReg2Mid = _T("0xf7");
		Parent()->m_pRaw->m_strTxReg2Bot = _T("0xb7");

		Parent()->m_pRaw->m_strBiasReg8 = _T("0x50");
	}
	Parent()->m_pRaw->UpdateData(FALSE);
	UpdateRegisters();
	
	CString str;
	str.Format(_T("%s Default values have been loaded into memory"), chipModel);
	Parent()->L(str);
	Parent()->L(_T("Make sure to click 'Write All' if you want to save them to registers"));
}

LRESULT CSemantic::OnSemEditClick(WPARAM w, LPARAM l)
{
	OnBnClickedSemanticEditCheck();
	return 0;
}

LRESULT CSemantic::OnSemRxDataInterfaceClick(WPARAM w, LPARAM l)
{
	OnStnClickedRxDataIfEnableValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemLimitAmpEnableClick(WPARAM w, LPARAM l)
{
	OnStnClickedLimitingAmpEnableValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemLnaGainClick(WPARAM w, LPARAM l)
{
	OnStnClickedLnaGainValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemDutyCycleClick(WPARAM w, LPARAM l)
{
	OnStnClickedDutyCycleValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemVcoOscFreqClick(WPARAM w, LPARAM l)
{
	OnStnClickedVcoOscFreqValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemRegRefVoltClick(WPARAM w, LPARAM l)
{
	OnStnClickedRegRefVoltValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemVcoVddClick(WPARAM w, LPARAM l)
{
	OnStnClickedVcoVddValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemVcoPowerClick(WPARAM w, LPARAM l)
{
	OnStnClickedVcoPowerValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemModulatorPowerClick(WPARAM w, LPARAM l)
{
	OnStnClickedModulatorPowerValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemTestBufferPowerClick(WPARAM w, LPARAM l)
{
	OnStnClickedTestBufferPowerValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemDataInputSelectClick(WPARAM w, LPARAM l)
{
	OnStnClickedDataInputSelectValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemPaPowerClick(WPARAM w, LPARAM l)
{
	OnStnClickedPaPowerValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemPaGainControl1Click(WPARAM w, LPARAM l)
{
	OnStnClickedPaGainControl1ValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemPaGainControl2Click(WPARAM w, LPARAM l)
{
	OnStnClickedPaGainControl2ValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemTestBufferCurrentClick(WPARAM w, LPARAM l)
{
	OnStnClickedTestBufferCurrentValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemBiasBlockEnableClick(WPARAM w, LPARAM l)
{
	OnStnClickedBiasBlockEnableValueStatic();
	return 0;
}

LRESULT CSemantic::OnSem1stStageBiasCurrentClick(WPARAM w, LPARAM l)
{
	OnStnClickedLna1BiasCurrentValueStatic();
	return 0;
}

LRESULT CSemantic::OnSem3rdStageBiasCurrentClick(WPARAM w, LPARAM l)
{
	OnStnClickedLna3BiasCurrentValueStatic();
	return 0;
}

LRESULT CSemantic::OnSem4thStageBiasCurrentClick(WPARAM w, LPARAM l)
{
	OnStnClickedLna4BiasCurrentValueStatic();
	return 0;
}

LRESULT CSemantic::OnSem5thStageBiasCurrentClick(WPARAM w, LPARAM l)
{
	OnStnClickedLna5BiasCurrentValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemRefStageCurrentClick(WPARAM w, LPARAM l)
{
	OnStnClickedDemodRefStageCurrentValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemIpStageCurrentClick(WPARAM w, LPARAM l)
{
	OnStnClickedDemodIpStageCurrentValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemFbCurrentClick(WPARAM w, LPARAM l)
{
	OnStnClickedLaFbCurrentValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemCoreCurrentClick(WPARAM w, LPARAM l)
{
	OnStnClickedLaCoreCurrentValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemOpBufferCurrentClick(WPARAM w, LPARAM l)
{
	OnStnClickedLaOpBufferCurrentValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemIpBufferCurrentClick(WPARAM w, LPARAM l)
{
	OnStnClickedLaIpBufferCurrentValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemHighlowDataRateCurrentClick(WPARAM w, LPARAM l)
{
	OnStnClickedLaHlDataRateCurrentValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemCmosGainStageCurrentClick(WPARAM w, LPARAM l)
{
	OnStnClickedCmosGainStageCurrentValueStatic();
	return 0;
}

LRESULT CSemantic::OnSemCmlInterfaceStageCurrentClick(WPARAM w, LPARAM l)
{
	OnStnClickedCmlInterfaceStageCurrentValueStatic();
	return 0;
}
