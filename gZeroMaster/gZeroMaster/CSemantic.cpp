// CSemantic.cpp: 구현 파일
//

#include "pch.h"
#include "gZeroMaster.h"
#include "CSemantic.h"
#include "afxdialogex.h"
#include "gZeroMasterDlg.h"
#include "CRaw.h"


// CSemantic 대화 상자

IMPLEMENT_DYNAMIC(CSemantic, CDialogEx)

CSemantic::CSemantic(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SEMANTIC_DIALOG, pParent)
	, m_strRxDataInterface(_T(""))
	, m_strLimitingAmplifier(_T(""))
	, m_strLnaGain(_T(""))
	, m_pParent(pParent)
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
	, m_bSemanticEdit(FALSE)
	, m_bAutoWrite(FALSE)
	, m_selected(SelectStatic::None)
	, m_strSelectedStatic(_T(""))
	, m_strSliderMin(_T(""))
	, m_strSliderMax(_T(""))
	, m_strSliderValue(_T(""))
	, m_strSliderValueHex(_T(""))
	, m_strSliderValueBin(_T(""))
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
END_MESSAGE_MAP()


CgZeroMasterDlg* CSemantic::Parent()
{
	return dynamic_cast<CgZeroMasterDlg*>(m_pParent);
}


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


void CSemantic::Parse(CRaw* pRaw, CRegister& reg)
{
	ASSERT(pRaw->Parent()->m_chip == _T("A0") || pRaw->Parent()->m_chip == _T("B0"));

	UpdateRxReg1(pRaw->m_strRxReg1, reg);
	UpdateTxReg1(pRaw->m_strTxReg1Top, pRaw->m_strTxReg1Mid, pRaw->m_strTxReg1Bot, reg, pRaw->Parent()->m_chip);
	if (pRaw->Parent()->m_chip == _T("B0"))
		UpdateTxReg2(pRaw->m_strTxReg2Top, pRaw->m_strTxReg2Mid, pRaw->m_strTxReg2Bot, reg);

	UpdateBiasReg1(pRaw->m_strBiasReg1, reg);
	UpdateBiasReg2(pRaw->m_strBiasReg2, reg);
	UpdateBiasReg3(pRaw->m_strBiasReg3, reg);
	UpdateBiasReg4(pRaw->m_strBiasReg4, reg);
	UpdateBiasReg5(pRaw->m_strBiasReg5, reg);
	UpdateBiasReg6(pRaw->m_strBiasReg6, reg);
	UpdateBiasReg7(pRaw->m_strBiasReg7, reg);
	UpdateBiasReg8(pRaw->m_strBiasReg8, reg);
	if (pRaw->Parent()->m_chip == _T("A0"))
		UpdateBiasReg9(pRaw->m_strBiasReg9, reg);
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

void CSemantic::UpdateRxReg1(CString strRxReg1, CRegister &reg)
{
	int val = _tcstol(strRxReg1.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nRxData = (val & 0x10) >> 4;
	reg.m_nLimitAmp = (val & 0x08) >> 3;
	reg.m_nLnaGain = val & 0x07;
}

void CSemantic::UpdateTxReg1(CString strTxRegTop, CString strTxRegMid, CString strTxRegBot, CRegister& reg, CString chip)
{
	ASSERT(chip == _T("A0") || chip == _T("B0"));
	int mid = _tcstol(strTxRegMid.GetBuffer(), NULL, 16) & 0xff;
	int bot = _tcstol(strTxRegBot.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nDutyCycle = _tcstol(strTxRegTop.GetBuffer(), NULL, 16) & 0xff;
	if (chip == _T("A0")) {
		reg.m_nModPower = (mid & 0x80) >> 7;
		reg.m_nTestBufPower = (mid & 0x40) >> 6;
		reg.m_nDataInpSel = (mid & 0x20) >> 5;
		reg.m_nPaPower = (mid & 0x10) >> 4;
		reg.m_nPaGainCon2 = mid & 0x0f;
		reg.m_nPaGainCon1 = (bot & 0xf0) >> 4;
		reg.m_nTestBufCur = bot & 0x0f;
	}
	else if (chip == _T("B0")) {
		reg.m_nVcoOsc = (bot & 0xe0) >> 5 | (mid << 3);
		reg.m_nRegRef = (bot & 0x10) >> 4;
		reg.m_nVcoVdd = bot & 0x0f;
	}
}

void CSemantic::UpdateTxReg2(CString strTxRegTop, CString strTxRegMid, CString strTxRegBot, CRegister& reg)
{
	int top = _tcstol(strTxRegTop.GetBuffer(), NULL, 16) & 0x01;
	int mid = _tcstol(strTxRegMid.GetBuffer(), NULL, 16) & 0xff;
	int bot = _tcstol(strTxRegBot.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nVcoPower = top;
	reg.m_nModPower = (mid & 0x80) >> 7;
	reg.m_nTestBufPower = (mid & 0x40) >> 6;
	reg.m_nDataInpSel = (mid & 0x20) >> 5;
	reg.m_nPaPower = (mid & 0x10) >> 4;
	reg.m_nPaGainCon2 = mid & 0x0f;
	reg.m_nPaGainCon1 = (bot & 0xf0) >> 4;
	reg.m_nTestBufCur = bot & 0x0f;
}

void CSemantic::UpdateBiasReg1(CString strBiasReg1, CRegister& reg)
{
	reg.m_nBiasBlock = _tcstol(strBiasReg1.GetBuffer(), NULL, 16) & 0x01;
}

void CSemantic::UpdateBiasReg2(CString strBiasReg2, CRegister& reg)
{
	int reg2 = _tcstol(strBiasReg2.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nLna3Cur = (reg2 & 0xf0) >> 4;
	reg.m_nLna1Cur = reg2 & 0x0f;
	reg.m_nLna2Cur = reg.m_nLna1Cur;
}

void CSemantic::UpdateBiasReg3(CString strBiasReg3, CRegister& reg)
{
	int reg3 = _tcstol(strBiasReg3.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nLna5Cur = (reg3 & 0xf0) >> 4;
	reg.m_nLna4Cur = reg3 & 0x0f;
}

void CSemantic::UpdateBiasReg4(CString strBiasReg4, CRegister& reg)
{
	int reg4 = _tcstol(strBiasReg4.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nDemodRefStageCur = (reg4 & 0xf0) >> 4;
	reg.m_nDemodIPStageCur = reg4 & 0x0f;
}

void CSemantic::UpdateBiasReg5(CString strBiasReg5, CRegister& reg)
{
	int reg5 = _tcstol(strBiasReg5.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nLaFBCur = (reg5 & 0xf0) >> 4;
	reg.m_nLaCoreCur = reg5 & 0x0f;
}

void CSemantic::UpdateBiasReg6(CString strBiasReg6, CRegister& reg)
{
	int reg6 = _tcstol(strBiasReg6.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nLaOPBufCur = (reg6 & 0xf0) >> 4;
	reg.m_nLaIPBufCur = reg6 & 0x0f;
}

void CSemantic::UpdateBiasReg7(CString strBiasReg7, CRegister& reg)
{
	int reg7 = _tcstol(strBiasReg7.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nLaHLDataRateCur = (reg7 & 0xf0) >> 4;
	reg.m_nCMOSGainStageCur = reg7 & 0x0f;
}

void CSemantic::UpdateBiasReg8(CString strBiasReg8, CRegister& reg)
{
	reg.m_nCMLInterfaceStageCur = _tcstol(strBiasReg8.GetBuffer(), NULL, 16) & 0xff;
}

void CSemantic::UpdateBiasReg9(CString strBiasReg9, CRegister& reg)
{
	int reg9 = _tcstol(strBiasReg9.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nFdCoreCur = (reg9 & 0xf0) >> 4;
	reg.m_nFdBufCur = reg9 & 0x0f;
}

void CSemantic::ControlLabelEnable(BOOL b)
{
	GetDlgItem(IDC_RX_DATA_IF_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LIMITING_AMP_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA_GAIN_STATIC)->EnableWindow(b);

	GetDlgItem(IDC_DUTY_CYCLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_VCO_OSC_FREQ_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_REG_REF_VOLT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_VCO_VDD_STATIC)->EnableWindow(b);

	GetDlgItem(IDC_VCO_POWER_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_MODULATOR_POWER_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TEST_BUFFER_POWER_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_DATA_INPUT_SELECT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_PA_POWER_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_PA_GAIN_CONTROL1_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_PA_GAIN_CONTROL2_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TEST_BUFFER_CURRENT_STATIC)->EnableWindow(b);

	GetDlgItem(IDC_BIAS_BLOCK_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA1_BIAS_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA2_BIAS_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA3_BIAS_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA4_BIAS_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA5_BIAS_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_DEMOD_REF_STAGE_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_DEMOD_IP_STAGE_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_FB_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_CORE_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_OP_BUFFER_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_IP_BUFFER_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_HL_DATA_RATE_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_CMOS_GAIN_STAGE_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_CML_INTERFACE_STAGE_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_FD_CORE_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_FD_BUFFER_CURRENT_STATIC)->EnableWindow(b);
}

void CSemantic::ControlValueEnable(BOOL b)
{
	GetDlgItem(IDC_RX_DATA_IF_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LIMITING_AMP_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA_GAIN_VALUE_STATIC)->EnableWindow(b);

	GetDlgItem(IDC_DUTY_CYCLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_VCO_OSC_FREQ_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_REG_REF_VOLT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_VCO_VDD_VALUE_STATIC)->EnableWindow(b);

	GetDlgItem(IDC_VCO_POWER_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_MODULATOR_POWER_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TEST_BUFFER_POWER_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_DATA_INPUT_SELECT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_PA_POWER_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_PA_GAIN_CONTROL1_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_PA_GAIN_CONTROL2_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TEST_BUFFER_CURRENT_VALUE_STATIC)->EnableWindow(b);

	GetDlgItem(IDC_BIAS_BLOCK_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA1_BIAS_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA2_BIAS_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA3_BIAS_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA4_BIAS_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA5_BIAS_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_DEMOD_REF_STAGE_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_DEMOD_IP_STAGE_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_FB_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_CORE_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_OP_BUFFER_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_IP_BUFFER_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_HL_DATA_RATE_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_CMOS_GAIN_STAGE_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_CML_INTERFACE_STAGE_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_FD_CORE_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_FD_BUFFER_CURRENT_VALUE_STATIC)->EnableWindow(b);
}

void CSemantic::OnBnClickedSemanticEditCheck()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bSemanticEdit = !m_bSemanticEdit;
	if (m_bSemanticEdit) {
		m_selected = SelectStatic::None;
		ControlValueEnable(TRUE);
		GetDlgItem(IDC_AUTO_WRITE_CHECK)->ShowWindow(SW_SHOW);
	}
	else {
		ControlValueEnable(FALSE);
		ShowSlider(SW_HIDE);
		GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CONTROL_COMBO)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_AUTO_WRITE_CHECK)->ShowWindow(SW_HIDE);
	}
	UpdateData(FALSE);
}


COLORREF CSemantic::SetColor(CDC* pDC, SelectStatic given)
{
	if (m_selected == given)
		return pDC->SetTextColor(RGB(255, 0, 0));
	else
		return pDC->SetTextColor(RGB(0, 0, 0));
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


void CSemantic::SetControlSlider(int min,int max,CString strCurVal,int ticFreq,int lineSize,int pageSize)
{
	int curVal = _tcstol(strCurVal.GetBuffer(), NULL, 16);

	m_strSliderMin.Format(_T("Min:%d"), min);
	if (min != 0) {
		m_strSliderMin += _T("(");
		m_strSliderMin += DecToBin(min).TrimLeft(_T('0')).TrimLeft();
		m_strSliderMin += _T(")");
	}

	m_strSliderMax.Format(_T("Max:%d"), max);
	m_strSliderMax += _T("(");
	(max > 0xff) ? m_strSliderMax += DecToBin(max).Right(15) : m_strSliderMax += DecToBin(max).Right(10);
	m_strSliderMax += _T(")");

	//슬라이더 컨트롤이 최대값이 아래로 표시되기때문에 최대값을 -1을 곱하여 최소갑인것 처럼 표시
	m_controlSlider.SetRange(-1 * max, -1 * min);
	m_controlSlider.SetRangeMin(-1 * max);
	m_controlSlider.SetRangeMax(-1 * min);
	m_controlSlider.SetPos(-1 * curVal);
	m_controlSlider.SetTicFreq(ticFreq);
	m_controlSlider.SetLineSize(lineSize);
	m_controlSlider.SetPageSize(pageSize);

	SliderValueUpdate();
}


void CSemantic::OnStnClickedLnaGainValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::LnaGain;
	ShowSlider(SW_SHOW);
	Invalidate();	//모든것을 다시 그리는 것은 비효율적이지만 제일 간단하다

	SetControlSlider(0, 7, m_strLnaGain, 1, 1, 10);
	GetDlgItem(IDC_LNA_GAIN_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedDutyCycleValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::DutyCycle;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 255, m_strDutyCycle, 10, 1, 10);
	GetDlgItem(IDC_DUTY_CYCLE_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedVcoOscFreqValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::VcoOsc;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 2047, m_strVcoOscFreq, 50, 1, 50);
	GetDlgItem(IDC_VCO_OSC_FREQ_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedVcoVddValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::VcoVdd;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strVcoVdd, 1, 1, 10);
	GetDlgItem(IDC_VCO_VDD_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedPaGainControl1ValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::PaGain1;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strPaGainControl1, 1, 1, 10);
	GetDlgItem(IDC_PA_GAIN_CONTROL1_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedPaGainControl2ValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::PaGain2;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strPaGainControl2, 1, 1, 10);
	GetDlgItem(IDC_PA_GAIN_CONTROL2_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedTestBufferCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::TestBuffer;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strTestBufferCurrent, 1, 1, 10);
	GetDlgItem(IDC_TEST_BUFFER_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedLna1BiasCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::Lna1;
	ShowSlider(SW_SHOW);
	Invalidate();
;
	SetControlSlider(0, 15, m_strLna1Current, 1, 1, 10);
	GetDlgItem(IDC_LNA1_BIAS_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedLna2BiasCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::Lna2;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strLna2Current, 1, 1, 10);
	GetDlgItem(IDC_LNA2_BIAS_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedLna3BiasCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::Lna3;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strLna3Current, 1, 1, 10);
	GetDlgItem(IDC_LNA3_BIAS_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedLna4BiasCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::Lna4;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strLna4Current, 1, 1, 10);
	GetDlgItem(IDC_LNA4_BIAS_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedLna5BiasCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::Lna5;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strLna5Current, 1, 1, 10);
	GetDlgItem(IDC_LNA5_BIAS_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedDemodRefStageCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::RefStage;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strDemodRefStageCurrent, 1, 1, 10);
	GetDlgItem(IDC_DEMOD_REF_STAGE_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedDemodIpStageCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::IpStage;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strDemodIPStageCurrent, 1, 1, 10);
	GetDlgItem(IDC_DEMOD_IP_STAGE_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedLaFbCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::Fb;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strLaFBCurrent, 1, 1, 10);
	GetDlgItem(IDC_LA_FB_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedLaCoreCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::Core;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strLaCoreCurrent, 1, 1, 10);
	GetDlgItem(IDC_LA_CORE_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedLaOpBufferCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::OP;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strLaOPBufferCurrent, 1, 1, 10);
	GetDlgItem(IDC_LA_OP_BUFFER_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedLaIpBufferCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::IP;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strLaIPBufferCurrent, 1, 1, 10);
	GetDlgItem(IDC_LA_IP_BUFFER_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedLaHlDataRateCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::HL;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strLaHLDataRateCurrent, 1, 1, 10);
	GetDlgItem(IDC_LA_HL_DATA_RATE_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedCmosGainStageCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::CMOS;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strCMOSGainStageCurrent, 1, 1, 10);
	GetDlgItem(IDC_CMOS_GAIN_STAGE_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedCmlInterfaceStageCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::CML;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 255, m_strCMLInterfaceStageCurrent, 10, 1, 10);
	GetDlgItem(IDC_CML_INTERFACE_STAGE_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedFdCoreCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::FdCore;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strFdCoreCur, 1, 1, 10);
	GetDlgItem(IDC_FD_CORE_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedFdBufferCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::FdBuf;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strFdBufCur, 1, 1, 10);
	GetDlgItem(IDC_FD_BUFFER_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
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


int CSemantic::SliderPos()
{
	return -1 * m_controlSlider.GetPos();
}


int CSemantic::SliderValueUpdate()
{
	int curPos = SliderPos();
	m_strSliderValue.Format(_T("Dec:%d"), curPos);
	m_strSliderValueHex.Format(_T("Hex:0x%02x"), curPos);
	m_strSliderValueBin = _T("Bin:");
	(curPos > 0xff) ? m_strSliderValueBin += DecToBin(curPos).Right(15) : m_strSliderValueBin += DecToBin(curPos).Right(10);
	UpdateData(FALSE);
	return curPos;
}


void CSemantic::ShowSlider(int nCmdShow)
{
	GetDlgItem(IDC_CONTROL_SLIDER)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_SLIDER_MAX_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_SLIDER_MIN_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_SLIDER_VALUE_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_SLIDER_VALUE_HEX_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_SLIDER_VALUE_BIN_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_SELECTED_STATIC)->ShowWindow(nCmdShow);
	if(nCmdShow==SW_SHOW) GetDlgItem(IDC_CONTROL_COMBO)->ShowWindow(SW_HIDE);
}


CString CSemantic::DecToBin(int dec)
{
	ASSERT(dec>=0 && dec <= 0xffff);	//2바이트 까지만 지원
	if (dec == 0) return _T("0");

	CString strBin;
	int byte = (dec & 0xff00) >> 8;
	for (int n = 0; n < 2; n++) {
		for (int i = 7; i >= 0; i--) {
			CString strBit;
			strBit.Format(_T("%d"), (byte >> i) & 1);
			strBin += strBit;
			if (i == 4) strBin += _T(" ");	//4비트 마다 공백
		}
		strBin += _T(" ");	//4비트 마다 공백
		byte = dec & 0xff;
	}
	TRACE(_T("DecToBin:")+strBin+_T("\n"));
	return strBin;
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
	m_selected = SelectStatic::RxData;
	ShowSlider(SW_HIDE);

	for (int i = m_controlCombo.GetCount() - 1; i >= 0; i--) m_controlCombo.DeleteString(i);
	m_controlCombo.AddString(_T("disable"));	//0
	m_controlCombo.AddString(_T("enable"));		//1

	CRegister reg;
	Parse(Parent()->m_pRaw, reg);
	m_controlCombo.SetCurSel(reg.m_nRxData);

	GetDlgItem(IDC_CONTROL_COMBO)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SELECTED_STATIC)->ShowWindow(SW_SHOW);
	Invalidate();

	GetDlgItem(IDC_RX_DATA_IF_ENABLE_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}



void CSemantic::OnStnClickedLimitingAmpEnableValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::LimAmp;
	ShowSlider(SW_HIDE);

	for (int i = m_controlCombo.GetCount() - 1; i >= 0; i--) m_controlCombo.DeleteString(i);
	m_controlCombo.AddString(_T("disable"));	//0
	m_controlCombo.AddString(_T("enable"));		//1

	CRegister reg;
	Parse(Parent()->m_pRaw, reg);
	m_controlCombo.SetCurSel(reg.m_nLimitAmp);

	GetDlgItem(IDC_CONTROL_COMBO)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SELECTED_STATIC)->ShowWindow(SW_SHOW);
	Invalidate();

	GetDlgItem(IDC_LIMITING_AMP_ENABLE_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedRegRefVoltValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::RegRef;
	ShowSlider(SW_HIDE);

	for (int i = m_controlCombo.GetCount() - 1; i >= 0; i--) m_controlCombo.DeleteString(i);
	m_controlCombo.AddString(_T("500mV"));	//0
	m_controlCombo.AddString(_T("400mV"));	//1

	CRegister reg;
	Parse(Parent()->m_pRaw, reg);
	m_controlCombo.SetCurSel(reg.m_nRegRef);

	GetDlgItem(IDC_CONTROL_COMBO)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SELECTED_STATIC)->ShowWindow(SW_SHOW);
	Invalidate();

	GetDlgItem(IDC_REG_REF_VOLT_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedVcoPowerValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::VcoPow;
	ShowSlider(SW_HIDE);

	for (int i = m_controlCombo.GetCount() - 1; i >= 0; i--) m_controlCombo.DeleteString(i);
	m_controlCombo.AddString(_T("VCO Off"));	//0
	m_controlCombo.AddString(_T("VCO On"));		//1

	CRegister reg;
	Parse(Parent()->m_pRaw, reg);
	m_controlCombo.SetCurSel(reg.m_nVcoPower);

	GetDlgItem(IDC_CONTROL_COMBO)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SELECTED_STATIC)->ShowWindow(SW_SHOW);
	Invalidate();

	GetDlgItem(IDC_VCO_POWER_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedModulatorPowerValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::ModPow;
	ShowSlider(SW_HIDE);

	for (int i = m_controlCombo.GetCount() - 1; i >= 0; i--) m_controlCombo.DeleteString(i);
	m_controlCombo.AddString(_T("Mod Off"));	//0
	m_controlCombo.AddString(_T("Mod On"));		//1

	CRegister reg;
	Parse(Parent()->m_pRaw, reg);
	m_controlCombo.SetCurSel(reg.m_nModPower);

	GetDlgItem(IDC_CONTROL_COMBO)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SELECTED_STATIC)->ShowWindow(SW_SHOW);
	Invalidate();

	GetDlgItem(IDC_MODULATOR_POWER_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedTestBufferPowerValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::TestBufPow;
	ShowSlider(SW_HIDE);

	for (int i = m_controlCombo.GetCount() - 1; i >= 0; i--) m_controlCombo.DeleteString(i);
	m_controlCombo.AddString(_T("Test Buff Off"));	//0
	m_controlCombo.AddString(_T("Test Buff On"));	//1

	CRegister reg;
	Parse(Parent()->m_pRaw, reg);
	m_controlCombo.SetCurSel(reg.m_nTestBufPower);

	GetDlgItem(IDC_CONTROL_COMBO)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SELECTED_STATIC)->ShowWindow(SW_SHOW);
	Invalidate();

	GetDlgItem(IDC_TEST_BUFFER_POWER_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedDataInputSelectValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::DataInp;
	ShowSlider(SW_HIDE);

	for (int i = m_controlCombo.GetCount() - 1; i >= 0; i--) m_controlCombo.DeleteString(i);
	m_controlCombo.AddString(_T("SER(Internal)"));			//0
	m_controlCombo.AddString(_T("Test Buff(External)"));	//1

	CRegister reg;
	Parse(Parent()->m_pRaw, reg);
	m_controlCombo.SetCurSel(reg.m_nDataInpSel);

	GetDlgItem(IDC_CONTROL_COMBO)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SELECTED_STATIC)->ShowWindow(SW_SHOW);
	Invalidate();

	GetDlgItem(IDC_DATA_INPUT_SELECT_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedPaPowerValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::PaPow;
	ShowSlider(SW_HIDE);

	for (int i = m_controlCombo.GetCount() - 1; i >= 0; i--) m_controlCombo.DeleteString(i);
	m_controlCombo.AddString(_T("PA Off"));	//0
	m_controlCombo.AddString(_T("PA On"));	//1

	CRegister reg;
	Parse(Parent()->m_pRaw, reg);
	m_controlCombo.SetCurSel(reg.m_nPaPower);

	GetDlgItem(IDC_CONTROL_COMBO)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SELECTED_STATIC)->ShowWindow(SW_SHOW);
	Invalidate();

	GetDlgItem(IDC_PA_POWER_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedBiasBlockEnableValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = SelectStatic::BiasBlock;
	ShowSlider(SW_HIDE);

	for (int i = m_controlCombo.GetCount() - 1; i >= 0; i--) m_controlCombo.DeleteString(i);
	m_controlCombo.AddString(_T("disable"));	//0
	m_controlCombo.AddString(_T("enable"));		//1

	CRegister reg;
	Parse(Parent()->m_pRaw, reg);
	m_controlCombo.SetCurSel(reg.m_nBiasBlock);

	GetDlgItem(IDC_CONTROL_COMBO)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SELECTED_STATIC)->ShowWindow(SW_SHOW);
	Invalidate();

	GetDlgItem(IDC_BIAS_BLOCK_ENABLE_STATIC)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
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


int CSemantic::ComboSel()
{
	return m_controlCombo.GetCurSel();
}


int CSemantic::OnNewRxData(int val, int newVal)
{
	return (val & 0xe0) | newVal << 4 | (val & 0x0f);
}


int CSemantic::OnNewLimAmp(int val, int newVal)
{
	return (val & 0xf0) | newVal << 3 | (val & 0x07);
}


int CSemantic::OnNewRegRef(int val, int newVal)
{
	return (val & 0xe0) | newVal << 4 | (val & 0x0f);
}


int CSemantic::OnNewVcoPow(int val, int newVal)
{
	return (val & 0xfe) | newVal;
}


int CSemantic::OnNewModPow(int val, int newVal)
{
	return (val & 0x7f) | newVal << 7;
}


int CSemantic::OnNewTestBufPow(int val, int newVal)
{
	return (val & 0x80) | newVal << 6 | (val & 0x3f);
}


int CSemantic::OnNewDataInp(int val, int newVal)
{
	return (val & 0xc0) | newVal << 5 | (val & 0x1f);
}


int CSemantic::OnNewPaPow(int val, int newVal)
{
	return (val & 0xe0) | newVal << 4 | (val & 0x0f);
}


int CSemantic::OnNewBiasBlock(int val, int newVal)
{
	return (val & 0xfe) | newVal;
}


int CSemantic::OnNewLnaGain(int val, int newVal)
{
	return (val & 0xf8) | newVal;
}


int CSemantic::OnNewDutyCycle(int val, int newVal)
{
	return newVal;
}


int CSemantic::OnNewVcoOscUp(int val, int newVal)
{
	return (newVal & 0x7f8) >> 3;
}


int CSemantic::OnNewVcoOscDown(int val, int newVal)
{
	return (newVal & 0x7) << 5 | (val & 0x1f);
}


int CSemantic::OnNewVcoVdd(int val, int newVal)
{
	return (val & 0xf0) | (newVal & 0x0f);
}


int CSemantic::OnNewPaGain1(int val, int newVal)
{
	return (newVal & 0x0f)<<4 | (val & 0x0f);
}


int CSemantic::OnNewPaGain2(int val, int newVal)
{
	return (val & 0xf0) | (newVal & 0x0f);
}


int CSemantic::OnNewTestBuffer(int val, int newVal)
{
	return (val & 0xf0) | (newVal & 0x0f);
}


int CSemantic::OnNewLna1(int val, int newVal)
{
	return (val & 0xf0) | (newVal & 0x0f);
}


int CSemantic::OnNewLna2(int val, int newVal)
{
	return OnNewLna1(val,newVal);
}


int CSemantic::OnNewLna3(int val, int newVal)
{
	return (newVal & 0x0f) << 4 | (val & 0x0f);
}


int CSemantic::OnNewLna4(int val, int newVal)
{
	return (val & 0xf0) | (newVal & 0x0f);
}


int CSemantic::OnNewLna5(int val, int newVal)
{
	return (newVal & 0x0f) << 4 | (val & 0x0f);
}


int CSemantic::OnNewRefStage(int val, int newVal)
{
	return (newVal & 0x0f) << 4 | (val & 0x0f);
}


int CSemantic::OnNewIpStage(int val, int newVal)
{
	return (val & 0xf0) | (newVal & 0x0f);
}


int CSemantic::OnNewFb(int val, int newVal)
{
	return (newVal & 0x0f) << 4 | (val & 0x0f);
}


int CSemantic::OnNewCore(int val, int newVal)
{
	return (val & 0xf0) | (newVal & 0x0f);
}


int CSemantic::OnNewOP(int val, int newVal)
{
	return (newVal & 0x0f) << 4 | (val & 0x0f);
}


int CSemantic::OnNewIP(int val, int newVal)
{
	return (val & 0xf0) | (newVal & 0x0f);
}


int CSemantic::OnNewHL(int val, int newVal)
{
	return (newVal & 0x0f) << 4 | (val & 0x0f);
}


int CSemantic::OnNewCMOS(int val, int newVal)
{
	return (val & 0xf0) | (newVal & 0x0f);
}


int CSemantic::OnNewCML(int val, int newVal)
{
	return newVal & 0xff;
}


int CSemantic::OnNewFdCore(int val, int newVal)
{
	return (newVal & 0x0f) << 4 | (val & 0x0f);
}


int CSemantic::OnNewFdBuf(int val, int newVal)
{
	return (val & 0xf0) | (newVal & 0x0f);
}


BOOL CSemantic::UpdateSemanticValue(int addr, int (CSemantic::* fpNewRegVal)(int, int), int newVal, void (CSemantic::* fpUpdateData)(CRegister&))
{
	int oldRegVal;
	char buffer[3];
	while (Parent()->m_pRaw->ReadRegister(addr, 2, buffer, MAX_LOOP) != ERROR_SUCCESS) Sleep(10);	//Blocking 함수

	oldRegVal = (int)strtol(buffer, NULL, 16);
	int newRegVal = (this->*fpNewRegVal)(oldRegVal, newVal);
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
		bRtn = UpdateSemanticValue(2, &CSemantic::OnNewRxData, updateValue, &CSemantic::UpdateRxData);
		break;
	case SelectStatic::LimAmp:
		bCommonControl ? updateValue = ComboSel() : updateValue = LimAmp();
		bRtn = UpdateSemanticValue(2, &CSemantic::OnNewLimAmp, updateValue, &CSemantic::UpdateLimitAmp);
		break;
	case SelectStatic::RegRef:
		if (Parent()->m_chip == _T("B0")) {
			bCommonControl ? updateValue = ComboSel() : updateValue = RegRef();
			bRtn = UpdateSemanticValue(5, &CSemantic::OnNewRegRef, updateValue, &CSemantic::UpdateRegRefVolt);
		}
		break;
	case SelectStatic::VcoPow:
		if (Parent()->m_chip == _T("B0")) {
			bCommonControl ? updateValue = ComboSel() : updateValue = VcoPow();
			bRtn = UpdateSemanticValue(13, &CSemantic::OnNewVcoPow, updateValue, &CSemantic::UpdateVcoPower);
		}
		break;
	case SelectStatic::ModPow:
		bCommonControl ? updateValue = ComboSel() : updateValue = ModPow();
		bRtn = UpdateSemanticValue(12, &CSemantic::OnNewModPow, updateValue, &CSemantic::UpdateModPower);
		break;
	case SelectStatic::TestBufPow:
		bCommonControl ? updateValue = ComboSel() : updateValue = TestBufPow();
		bRtn = UpdateSemanticValue(12, &CSemantic::OnNewTestBufPow, updateValue, &CSemantic::UpdateTestBufferPower);
		break;
	case SelectStatic::DataInp:
		bCommonControl ? updateValue = ComboSel() : updateValue = DataInp();
		bRtn = UpdateSemanticValue(12, &CSemantic::OnNewDataInp, updateValue, &CSemantic::UpdateDataInputSelect);
		break;
	case SelectStatic::PaPow:
		bCommonControl ? updateValue = ComboSel() : updateValue = PaPow();
		bRtn = UpdateSemanticValue(12, &CSemantic::OnNewPaPow, updateValue, &CSemantic::UpdateDataPaPower);
		break;
	case SelectStatic::BiasBlock:
		bCommonControl ? updateValue = ComboSel() : updateValue = BiasBlock();
		bRtn = UpdateSemanticValue(17, &CSemantic::OnNewBiasBlock, updateValue, &CSemantic::UpdateBiasBlockEnable);
		break;

		//ControlSlide
	case SelectStatic::LnaGain:
		bCommonControl ? updateValue = SliderPos() : updateValue = LnaGain();
		bRtn = UpdateSemanticValue(2, &CSemantic::OnNewLnaGain, updateValue, &CSemantic::UpdateLnaGain);
		break;
	case SelectStatic::DutyCycle:
		bCommonControl ? updateValue = SliderPos() : updateValue = DutyCycle();
		bRtn = UpdateSemanticValue(7, &CSemantic::OnNewDutyCycle, updateValue, &CSemantic::UpdateDutyCycle);
		break;
	case SelectStatic::VcoOsc:
		if (Parent()->m_chip == _T("B0")) {
			bCommonControl ? updateValue = SliderPos() : updateValue = VcoOsc();
			bRtn = UpdateSemanticValue(6, &CSemantic::OnNewVcoOscUp, updateValue, NULL);
			ASSERT(bRtn);
			bRtn = UpdateSemanticValue(5, &CSemantic::OnNewVcoOscDown, updateValue, &CSemantic::UpdateVcoOscFreq);
		}
		break;
	case SelectStatic::VcoVdd:
		if (Parent()->m_chip == _T("B0")) {
			bCommonControl ? updateValue = SliderPos() : updateValue = VcoVdd();
			bRtn = UpdateSemanticValue(5, &CSemantic::OnNewVcoVdd, updateValue, &CSemantic::UpdateVcoVdd);
		}
		break;
	case SelectStatic::PaGain1:
		bCommonControl ? updateValue = SliderPos() : updateValue = PaGain1();
		bRtn = UpdateSemanticValue(11, &CSemantic::OnNewPaGain1, updateValue, &CSemantic::UpdatePaGainControl1);
		break;
	case SelectStatic::PaGain2:
		bCommonControl ? updateValue = SliderPos() : updateValue = PaGain2();
		bRtn = UpdateSemanticValue(12, &CSemantic::OnNewPaGain2, updateValue, &CSemantic::UpdatePaGainControl2);
		break;
	case SelectStatic::TestBuffer:
		bCommonControl ? updateValue = SliderPos() : updateValue = TestBuffer();
		bRtn = UpdateSemanticValue(11, &CSemantic::OnNewTestBuffer, updateValue, &CSemantic::UpdateTestBufferCurrent);
		break;
	case SelectStatic::Lna1:
		bCommonControl ? updateValue = SliderPos() : updateValue = Lna1();
		bRtn = UpdateSemanticValue(18, &CSemantic::OnNewLna1, updateValue, &CSemantic::UpdateLna1Current);
		break;
	case SelectStatic::Lna2:
		bCommonControl ? updateValue = SliderPos() : updateValue = Lna2();
		bRtn = UpdateSemanticValue(18, &CSemantic::OnNewLna2, updateValue, &CSemantic::UpdateLna2Current);
		break;
	case SelectStatic::Lna3:
		bCommonControl ? updateValue = SliderPos() : updateValue = Lna3();
		bRtn = UpdateSemanticValue(18, &CSemantic::OnNewLna3, updateValue, &CSemantic::UpdateLna3Current);
		break;
	case SelectStatic::Lna4:
		bCommonControl ? updateValue = SliderPos() : updateValue = Lna4();
		bRtn = UpdateSemanticValue(19, &CSemantic::OnNewLna4, updateValue, &CSemantic::UpdateLna4Current);
		break;
	case SelectStatic::Lna5:
		bCommonControl ? updateValue = SliderPos() : updateValue = Lna5();
		bRtn = UpdateSemanticValue(19, &CSemantic::OnNewLna5, updateValue, &CSemantic::UpdateLna5Current);
		break;
	case SelectStatic::RefStage:
		bCommonControl ? updateValue = SliderPos() : updateValue = RefStage();
		bRtn = UpdateSemanticValue(20, &CSemantic::OnNewRefStage, updateValue, &CSemantic::UpdateDemodRefStageCurrent);
		break;
	case SelectStatic::IpStage:
		bCommonControl ? updateValue = SliderPos() : updateValue = IpStage();
		bRtn = UpdateSemanticValue(20, &CSemantic::OnNewIpStage, updateValue, &CSemantic::UpdateDemodIPStageCurrent);
		break;
	case SelectStatic::Fb:
		bCommonControl ? updateValue = SliderPos() : updateValue = Fb();
		bRtn = UpdateSemanticValue(21, &CSemantic::OnNewFb, updateValue, &CSemantic::UpdateLaFBCurrent);
		break;
	case SelectStatic::Core:
		bCommonControl ? updateValue = SliderPos() : updateValue = Core();
		bRtn = UpdateSemanticValue(21, &CSemantic::OnNewCore, updateValue, &CSemantic::UpdateLaCoreCurrent);
		break;
	case SelectStatic::OP:
		bCommonControl ? updateValue = SliderPos() : updateValue = OP();
		bRtn = UpdateSemanticValue(22, &CSemantic::OnNewOP, updateValue, &CSemantic::UpdateLaOPBufferCurrent);
		break;
	case SelectStatic::IP:
		bCommonControl ? updateValue = SliderPos() : updateValue = IP();
		bRtn = UpdateSemanticValue(22, &CSemantic::OnNewIP, updateValue, &CSemantic::UpdateLaIPBufferCurrent);
		break;
	case SelectStatic::HL:
		bCommonControl ? updateValue = SliderPos() : updateValue = HL();
		bRtn = UpdateSemanticValue(23, &CSemantic::OnNewHL, updateValue, &CSemantic::UpdateLaHLDataRateCurrent);
		break;
	case SelectStatic::CMOS:
		bCommonControl ? updateValue = SliderPos() : updateValue = CMOS();
		bRtn = UpdateSemanticValue(23, &CSemantic::OnNewCMOS, updateValue, &CSemantic::UpdateCMOSGainStageCurrent);
		break;
	case SelectStatic::CML:
		bCommonControl ? updateValue = SliderPos() : updateValue = CML();
		bRtn = UpdateSemanticValue(24, &CSemantic::OnNewCML, updateValue, &CSemantic::UpdateCMLInterfaceStageCurrent);
		break;
	case SelectStatic::FdCore:
		if (Parent()->m_chip == _T("A0")) {
			bCommonControl ? updateValue = SliderPos() : updateValue = FdCore();
			bRtn = UpdateSemanticValue(25, &CSemantic::OnNewFdCore, updateValue, &CSemantic::UpdateFdCoreCurrent);
		}
		break;
	case SelectStatic::FdBuf:
		if (Parent()->m_chip == _T("A0")) {
			bCommonControl ? updateValue = SliderPos() : updateValue = FdBuf();
			bRtn = UpdateSemanticValue(25, &CSemantic::OnNewFdBuf, updateValue, &CSemantic::UpdateFdBufferCurrent);
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


int CSemantic::Read4BitValue(CString str)
{
	int val = _tcstol(str.GetBuffer(), NULL, 16);
	ASSERT(val >= 0 && val <= 0xf);
	return val;
}


int CSemantic::Read8BitValue(CString str)
{
	int val = _tcstol(str.GetBuffer(), NULL, 16);
	ASSERT(val >= 0 && val <= 0xff);
	return val;
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

void CSemantic::OnBnClickedAutoWriteCheck()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bAutoWrite = !m_bAutoWrite;
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
