// CSemantic.cpp: 구현 파일
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


BEGIN_MESSAGE_MAP(CSemantic, CDialogEx)
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

	if (CSemanticBase::OnCbnSelchangeControlCombo() && m_bAutoWrite) OnBnClickedWriteButton();
}


BOOL CSemantic::UpdateSemanticValue(int addr, int (* fpNewRegVal)(int, int), int newVal, void (CSemantic::* fpUpdateData)(const CRegister&))
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
			(this->*fpUpdateData)(getRegister());
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