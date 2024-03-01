// CSemantic.cpp: 구현 파일
//

#include "pch.h"
#include "gZeroMaster.h"
#include "CSemantic.h"
#include "afxdialogex.h"
#include "gZeroMasterDlg.h"
#include "CRawBase.h"
#include "CRegister.h"


// CSemantic 대화 상자

IMPLEMENT_DYNAMIC(CSemantic, CSemanticBase)

CSemantic::CSemantic(CWnd* pParent, CRawBase* pRawBase, CRegister* pReg)
	: CSemanticBase(pParent, pRawBase, pReg)
{
}

CSemantic::~CSemantic()
{
	delete m_pReg;
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


BEGIN_MESSAGE_MAP(CSemantic, CSemanticBase)
	ON_BN_CLICKED(IDC_SEMANTIC_EDIT_CHECK, &OnBnClickedSemanticEditCheck)
	ON_WM_CTLCOLOR()
	ON_STN_CLICKED(IDC_LNA_GAIN_VALUE_STATIC, &OnStnClickedLnaGainValueStatic)
	ON_STN_CLICKED(IDC_DUTY_CYCLE_VALUE_STATIC, &OnStnClickedDutyCycleValueStatic)
	ON_STN_CLICKED(IDC_VCO_OSC_FREQ_VALUE_STATIC, &OnStnClickedVcoOscFreqValueStatic)
	ON_STN_CLICKED(IDC_VCO_VDD_VALUE_STATIC, &OnStnClickedVcoVddValueStatic)
	ON_STN_CLICKED(IDC_PA_GAIN_CONTROL1_VALUE_STATIC, &OnStnClickedPaGainControl1ValueStatic)
	ON_STN_CLICKED(IDC_PA_GAIN_CONTROL2_VALUE_STATIC, &OnStnClickedPaGainControl2ValueStatic)
	ON_STN_CLICKED(IDC_TEST_BUFFER_CURRENT_VALUE_STATIC, &OnStnClickedTestBufferCurrentValueStatic)
	ON_STN_CLICKED(IDC_LNA1_BIAS_CURRENT_VALUE_STATIC, &OnStnClickedLna1BiasCurrentValueStatic)
	ON_STN_CLICKED(IDC_LNA2_BIAS_CURRENT_VALUE_STATIC, &OnStnClickedLna2BiasCurrentValueStatic)
	ON_STN_CLICKED(IDC_LNA3_BIAS_CURRENT_VALUE_STATIC, &OnStnClickedLna3BiasCurrentValueStatic)
	ON_STN_CLICKED(IDC_LNA4_BIAS_CURRENT_VALUE_STATIC, &OnStnClickedLna4BiasCurrentValueStatic)
	ON_STN_CLICKED(IDC_LNA5_BIAS_CURRENT_VALUE_STATIC, &OnStnClickedLna5BiasCurrentValueStatic)
	ON_STN_CLICKED(IDC_DEMOD_REF_STAGE_CURRENT_VALUE_STATIC, &OnStnClickedDemodRefStageCurrentValueStatic)
	ON_STN_CLICKED(IDC_DEMOD_IP_STAGE_CURRENT_VALUE_STATIC, &OnStnClickedDemodIpStageCurrentValueStatic)
	ON_STN_CLICKED(IDC_LA_FB_CURRENT_VALUE_STATIC, &OnStnClickedLaFbCurrentValueStatic)
	ON_STN_CLICKED(IDC_LA_CORE_CURRENT_VALUE_STATIC, &OnStnClickedLaCoreCurrentValueStatic)
	ON_STN_CLICKED(IDC_LA_OP_BUFFER_CURRENT_VALUE_STATIC, &OnStnClickedLaOpBufferCurrentValueStatic)
	ON_STN_CLICKED(IDC_LA_IP_BUFFER_CURRENT_VALUE_STATIC, &OnStnClickedLaIpBufferCurrentValueStatic)
	ON_STN_CLICKED(IDC_LA_HL_DATA_RATE_CURRENT_VALUE_STATIC, &OnStnClickedLaHlDataRateCurrentValueStatic)
	ON_STN_CLICKED(IDC_CMOS_GAIN_STAGE_CURRENT_VALUE_STATIC, &OnStnClickedCmosGainStageCurrentValueStatic)
	ON_STN_CLICKED(IDC_CML_INTERFACE_STAGE_CURRENT_VALUE_STATIC, &OnStnClickedCmlInterfaceStageCurrentValueStatic)
	ON_STN_CLICKED(IDC_FD_CORE_CURRENT_VALUE_STATIC, &OnStnClickedFdCoreCurrentValueStatic)
	ON_STN_CLICKED(IDC_FD_BUFFER_CURRENT_VALUE_STATIC, &OnStnClickedFdBufferCurrentValueStatic)
	ON_STN_CLICKED(IDC_RX_DATA_IF_ENABLE_VALUE_STATIC, &OnStnClickedRxDataIfEnableValueStatic)
	ON_STN_CLICKED(IDC_LIMITING_AMP_ENABLE_VALUE_STATIC, &OnStnClickedLimitingAmpEnableValueStatic)
	ON_STN_CLICKED(IDC_REG_REF_VOLT_VALUE_STATIC, &OnStnClickedRegRefVoltValueStatic)
	ON_STN_CLICKED(IDC_VCO_POWER_VALUE_STATIC, &OnStnClickedVcoPowerValueStatic)
	ON_STN_CLICKED(IDC_MODULATOR_POWER_VALUE_STATIC, &OnStnClickedModulatorPowerValueStatic)
	ON_STN_CLICKED(IDC_TEST_BUFFER_POWER_VALUE_STATIC, &OnStnClickedTestBufferPowerValueStatic)
	ON_STN_CLICKED(IDC_DATA_INPUT_SELECT_VALUE_STATIC, &OnStnClickedDataInputSelectValueStatic)
	ON_STN_CLICKED(IDC_PA_POWER_VALUE_STATIC, &OnStnClickedPaPowerValueStatic)
	ON_STN_CLICKED(IDC_BIAS_BLOCK_ENABLE_VALUE_STATIC, &OnStnClickedBiasBlockEnableValueStatic)
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_READ_ALL_BUTTON, &OnBnClickedReadAllButton)
	ON_CBN_SELCHANGE(IDC_CONTROL_COMBO, &OnCbnSelchangeControlCombo)
	ON_BN_CLICKED(IDC_WRITE_BUTTON, &OnBnClickedWriteButton)
	ON_BN_CLICKED(IDC_WRITE_ALL_BUTTON, &OnBnClickedWriteAllButton)
	ON_BN_CLICKED(IDC_AUTO_WRITE_CHECK, &OnBnClickedAutoWriteCheck)
	ON_BN_CLICKED(IDC_DEFAULT_VALUE_BUTTON, &OnBnClickedDefaultValueButton)
END_MESSAGE_MAP()


// CSemantic 메시지 처리기


BOOL CSemantic::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	InitialControlState();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CSemantic::OnChipConnect(CString chipModel)
{
	ASSERT(chipModel == _T("A0") || chipModel == _T("Zing200x"));

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
	else if (chipModel == _T("Zing200x")) {
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

const CRegister& CSemantic::Parse()
{
	CSemanticBase::UpdateRxReg1(m_pRawBase->m_strRxReg1, *m_pReg);
	CSemanticBase::UpdateTxReg1(m_pRawBase->m_strTxReg1Top, m_pRawBase->m_strTxReg1Mid, m_pRawBase->m_strTxReg1Bot, *m_pReg, m_pRawBase->Parent()->m_chip);
	if (m_pRawBase->Parent()->m_chip == _T("Zing200x"))
		CSemanticBase::UpdateTxReg2(m_pRawBase->m_strTxReg2Top, m_pRawBase->m_strTxReg2Mid, m_pRawBase->m_strTxReg2Bot, *m_pReg);

	CSemanticBase::UpdateBiasReg1(m_pRawBase->m_strBiasReg1, *m_pReg);
	CSemanticBase::UpdateBiasReg2(m_pRawBase->m_strBiasReg2, *m_pReg);
	CSemanticBase::UpdateBiasReg3(m_pRawBase->m_strBiasReg3, *m_pReg);
	CSemanticBase::UpdateBiasReg4(m_pRawBase->m_strBiasReg4, *m_pReg);
	CSemanticBase::UpdateBiasReg5(m_pRawBase->m_strBiasReg5, *m_pReg);
	CSemanticBase::UpdateBiasReg6(m_pRawBase->m_strBiasReg6, *m_pReg);
	CSemanticBase::UpdateBiasReg7(m_pRawBase->m_strBiasReg7, *m_pReg);
	CSemanticBase::UpdateBiasReg8(m_pRawBase->m_strBiasReg8, *m_pReg);
	if (m_pRawBase->Parent()->m_chip == _T("A0"))
		CSemanticBase::UpdateBiasReg9(m_pRawBase->m_strBiasReg9, *m_pReg);
	return *m_pReg;
}

void CSemantic::UpdateRegisters()
{
	CSemanticBase::UpdateRegisters();
}