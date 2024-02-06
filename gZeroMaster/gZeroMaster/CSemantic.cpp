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


BEGIN_MESSAGE_MAP(CSemantic, CSemanticBase)
	ON_BN_CLICKED(IDC_SEMANTIC_EDIT_CHECK, &CSemantic::OnBnClickedSemanticEditCheck)
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
	ON_BN_CLICKED(IDC_READ_ALL_BUTTON, &CSemantic::OnBnClickedReadAllButton)
	ON_CBN_SELCHANGE(IDC_CONTROL_COMBO, &CSemantic::OnCbnSelchangeControlCombo)
	ON_BN_CLICKED(IDC_WRITE_BUTTON, &CSemantic::OnBnClickedWriteButton)
	ON_BN_CLICKED(IDC_WRITE_ALL_BUTTON, &CSemantic::OnBnClickedWriteAllButton)
	ON_BN_CLICKED(IDC_AUTO_WRITE_CHECK, &CSemantic::OnBnClickedAutoWriteCheck)
	ON_BN_CLICKED(IDC_DEFAULT_VALUE_BUTTON, &CSemantic::OnBnClickedDefaultValueButton)
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


void CSemantic::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (CSemanticBase::OnVScroll(nSBCode, nPos, pScrollBar) && m_bAutoWrite) OnBnClickedWriteButton();
}


void CSemantic::OnBnClickedReadAllButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ResetValues();
	Parent()->m_pRaw->OnBnClickedReadAllButton();
	UpdateRegisters();
}


void CSemantic::OnCbnSelchangeControlCombo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (CSemanticBase::OnCbnSelchangeControlCombo() && m_bAutoWrite) OnBnClickedWriteButton();
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