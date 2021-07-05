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
	, m_strLnaGain(_T(""))
	, m_pParent(pParent)
	, m_strPaGainControl1(_T(""))
	, m_strPaGainControl2(_T(""))
	, m_strTestBufferCurrent(_T(""))
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
	, m_bSemanticEdit(FALSE)
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
	DDX_Control(pDX, IDC_RX_DATA_IF_ENABLE_VALUE_COMBO, m_RxDataInterface);
	DDX_Control(pDX, IDC_LIMITING_AMP_ENABLE_VALUE_COMBO, m_LimitingAmplifier);
	DDX_Text(pDX, IDC_LNA_GAIN_VALUE_STATIC, m_strLnaGain);
	DDX_Text(pDX, IDC_DUTY_CYCLE_VALUE_STATIC, m_strDutyCycle);
	DDX_Text(pDX, IDC_VCO_OSC_FREQ_VALUE_STATIC, m_strVcoOscFreq);
	DDX_Text(pDX, IDC_VCO_OSC_FREQ_VALUE_STATIC, m_strVcoOscFreq);
	DDX_Control(pDX, IDC_REG_REF_VOLT_VALUE_COMBO, m_regRefVolt);
	DDX_Text(pDX, IDC_VCO_VDD_VALUE_STATIC, m_strVcoVdd);
	DDX_Control(pDX, IDC_VCO_POWER_VALUE_COMBO, m_vcoPower);
	DDX_Control(pDX, IDC_MODULATOR_POWER_VALUE_COMBO, m_modPower);
	DDX_Control(pDX, IDC_TEST_BUFFER_POWER_VALUE_COMBO, m_testBufferPower);
	DDX_Control(pDX, IDC_DATA_INPUT_SELECT_VALUE_COMBO, m_dataInputSelect);
	DDX_Control(pDX, IDC_PA_POWER_VALUE_COMBO, m_paPower);
	DDX_Text(pDX, IDC_PA_GAIN_CONTROL1_VALUE_STATIC, m_strPaGainControl1);
	DDX_Text(pDX, IDC_PA_GAIN_CONTROL2_VALUE_STATIC, m_strPaGainControl2);
	DDX_Text(pDX, IDC_TEST_BUFFER_CURRENT_VALUE_STATIC, m_strTestBufferCurrent);
	DDX_Control(pDX, IDC_BIAS_BLOCK_ENABLE_VALUE_COMBO, m_BiasBlockEnable);
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
	DDX_Control(pDX, IDC_CONTROL_SLIDER, m_controlSlider);
	DDX_Check(pDX, IDC_SEMANTIC_EDIT_CHECK, m_bSemanticEdit);
	DDX_Text(pDX, IDC_SELECTED_STATIC, m_strSelectedStatic);
	DDX_Text(pDX, IDC_SLIDER_MIN_STATIC, m_strSliderMin);
	DDX_Text(pDX, IDC_SLIDER_MAX_STATIC, m_strSliderMax);
	DDX_Text(pDX, IDC_SLIDER_VALUE_STATIC, m_strSliderValue);
	DDX_Text(pDX, IDC_SLIDER_VALUE_HEX_STATIC, m_strSliderValueHex);
	DDX_Text(pDX, IDC_SLIDER_VALUE_BIN_STATIC, m_strSliderValueBin);
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

	m_RxDataInterface.AddString(_T("disable"));	//0
	m_RxDataInterface.AddString(_T("enable"));	//1

	m_LimitingAmplifier.AddString(_T("disable"));	//0
	m_LimitingAmplifier.AddString(_T("enable"));	//1

	m_BiasBlockEnable.AddString(_T("disable"));	//0
	m_BiasBlockEnable.AddString(_T("enable"));	//1

	m_regRefVolt.AddString(_T("500mV"));	//0
	m_regRefVolt.AddString(_T("400mV"));	//1

	m_vcoPower.AddString(_T("VCO Off"));	//0
	m_vcoPower.AddString(_T("VCO On"));		//1

	m_modPower.AddString(_T("MOD Off"));	//0
	m_modPower.AddString(_T("MOD On"));		//1

	m_testBufferPower.AddString(_T("Test Buff Off"));	//0
	m_testBufferPower.AddString(_T("Test Buff On"));	//1

	m_dataInputSelect.AddString(_T("SER(Int)"));		//0
	m_dataInputSelect.AddString(_T("Test Buff(Ext)"));	//1

	m_paPower.AddString(_T("PA Off"));		//0
	m_paPower.AddString(_T("PA On"));		//1

	ShowSlider(SW_HIDE);
	m_selected = None;

	GetDlgItem(IDC_READ_ALL_BUTTON)->ShowWindow(SW_HIDE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CSemantic::UpdateRegisters()
{
	ASSERT(Parent());
	CRegister reg;
	UpdateRxReg1(Parent()->m_pRaw->m_strRxReg1,reg);
	UpdateTxReg1(Parent()->m_pRaw->m_strTxReg1Top, Parent()->m_pRaw->m_strTxReg1Mid, Parent()->m_pRaw->m_strTxReg1Bot,reg);
	UpdateTxReg2(Parent()->m_pRaw->m_strTxReg2Top, Parent()->m_pRaw->m_strTxReg2Mid, Parent()->m_pRaw->m_strTxReg2Bot);
	UpdateBiasReg1(Parent()->m_pRaw->m_strBiasReg1);
	UpdateBiasReg2(Parent()->m_pRaw->m_strBiasReg2);
	UpdateBiasReg3(Parent()->m_pRaw->m_strBiasReg3);
	UpdateBiasReg4(Parent()->m_pRaw->m_strBiasReg4);
	UpdateBiasReg5(Parent()->m_pRaw->m_strBiasReg5);
	UpdateBiasReg6(Parent()->m_pRaw->m_strBiasReg6);
	UpdateBiasReg7(Parent()->m_pRaw->m_strBiasReg7);
	UpdateBiasReg8(Parent()->m_pRaw->m_strBiasReg8);

	m_RxDataInterface.SetCurSel(reg.m_nRxData);
	m_LimitingAmplifier.SetCurSel(reg.m_nLimitAmp);
	m_strLnaGain.Format(_T("0x%02x"), reg.m_nLnaGain);

	m_strDutyCycle.Format(_T("0x%02x"), reg.m_nDutyCycle);
	m_strVcoOscFreq.Format(_T("0x%02x"),reg.m_nVcoOsc);
	m_regRefVolt.SetCurSel(reg.m_nRegRef);
	m_strVcoVdd.Format(_T("0x%02x"), reg.m_nVcoVdd);
	UpdateData(FALSE);
}

void CSemantic::UpdateRxReg1(CString strRxReg1, CRegister &reg)
{
	int val = _tcstol(strRxReg1.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nRxData = (val & 0x10) >> 4;
	reg.m_nLimitAmp = (val & 0x08) >> 3;
	reg.m_nLnaGain = val & 0x07;
}

void CSemantic::UpdateTxReg1(CString strTxReg1Top, CString strTxReg1Mid, CString strTxReg1Bot, CRegister& reg)
{
	int mid = _tcstol(strTxReg1Mid.GetBuffer(), NULL, 16) & 0xff;
	int bot = _tcstol(strTxReg1Bot.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nDutyCycle = _tcstol(strTxReg1Top.GetBuffer(), NULL, 16) & 0xff;
	reg.m_nVcoOsc = (bot & 0xe0) >> 5 | (mid << 3);
	reg.m_nRegRef = (bot & 0x10) >> 4;
	reg.m_nVcoVdd = bot & 0x0f;
}

void CSemantic::UpdateTxReg2(CString strTxReg2Top, CString strTxReg2Mid, CString strTxReg2Bot)
{
	int top = _tcstol(strTxReg2Top.GetBuffer(), NULL, 16) & 0x01;
	int mid = _tcstol(strTxReg2Mid.GetBuffer(), NULL, 16) & 0xff;
	int bot = _tcstol(strTxReg2Bot.GetBuffer(), NULL, 16) & 0xff;

	m_vcoPower.SetCurSel(top);
	m_modPower.SetCurSel((mid & 0x80) >> 7);
	m_testBufferPower.SetCurSel((mid & 0x40) >> 6);
	m_dataInputSelect.SetCurSel((mid & 0x20) >> 5);
	m_paPower.SetCurSel((mid & 0x10) >> 4);

	m_strPaGainControl2.Format(_T("0x%02x"),mid&0x0f);
	m_strPaGainControl1.Format(_T("0x%02x"), (bot&0xf0)>>4 );
	m_strTestBufferCurrent.Format(_T("0x%02x"),bot&0x0f);
}

void CSemantic::UpdateBiasReg1(CString strBiasReg1)
{
	m_BiasBlockEnable.SetCurSel(_tcstol(strBiasReg1.GetBuffer(), NULL, 16) & 0x01);
}

void CSemantic::UpdateBiasReg2(CString strBiasReg2)
{
	int reg2 = _tcstol(strBiasReg2.GetBuffer(), NULL, 16) & 0xff;

	m_strLna3Current.Format(_T("0x%02x"),(reg2&0xf0)>>4);
	m_strLna1Current.Format(_T("0x%02x"), reg2 & 0x0f);
	m_strLna2Current = m_strLna1Current;
}

void CSemantic::UpdateBiasReg3(CString strBiasReg3)
{
	int reg3 = _tcstol(strBiasReg3.GetBuffer(), NULL, 16) & 0xff;

	m_strLna5Current.Format(_T("0x%02x"), (reg3 & 0xf0) >> 4);
	m_strLna4Current.Format(_T("0x%02x"), reg3 & 0x0f);
}

void CSemantic::UpdateBiasReg4(CString strBiasReg4)
{
	int reg4 = _tcstol(strBiasReg4.GetBuffer(), NULL, 16) & 0xff;

	m_strDemodRefStageCurrent.Format(_T("0x%02x"), (reg4 & 0xf0) >> 4);
	m_strDemodIPStageCurrent.Format(_T("0x%02x"), reg4 & 0x0f);
}

void CSemantic::UpdateBiasReg5(CString strBiasReg5)
{
	int reg5 = _tcstol(strBiasReg5.GetBuffer(), NULL, 16) & 0xff;

	m_strLaFBCurrent.Format(_T("0x%02x"), (reg5 & 0xf0) >> 4);
	m_strLaCoreCurrent.Format(_T("0x%02x"), reg5 & 0x0f);
}

void CSemantic::UpdateBiasReg6(CString strBiasReg6)
{
	int reg6 = _tcstol(strBiasReg6.GetBuffer(), NULL, 16) & 0xff;

	m_strLaOPBufferCurrent.Format(_T("0x%02x"), (reg6 & 0xf0) >> 4);
	m_strLaIPBufferCurrent.Format(_T("0x%02x"), reg6 & 0x0f);
}

void CSemantic::UpdateBiasReg7(CString strBiasReg7)
{
	int reg7 = _tcstol(strBiasReg7.GetBuffer(), NULL, 16) & 0xff;

	m_strLaHLDataRateCurrent.Format(_T("0x%02x"), (reg7 & 0xf0) >> 4);
	m_strCMOSGainStageCurrent.Format(_T("0x%02x"), reg7 & 0x0f);
}

void CSemantic::UpdateBiasReg8(CString strBiasReg8)
{
	m_strCMLInterfaceStageCurrent = strBiasReg8;
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
}

void CSemantic::ControlValueEnable(BOOL b)
{
	GetDlgItem(IDC_RX_DATA_IF_ENABLE_VALUE_COMBO)->EnableWindow(b);
	GetDlgItem(IDC_LIMITING_AMP_ENABLE_VALUE_COMBO)->EnableWindow(b);
	GetDlgItem(IDC_LNA_GAIN_VALUE_STATIC)->EnableWindow(b);

	GetDlgItem(IDC_DUTY_CYCLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_VCO_OSC_FREQ_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_REG_REF_VOLT_VALUE_COMBO)->EnableWindow(b);
	GetDlgItem(IDC_VCO_VDD_VALUE_STATIC)->EnableWindow(b);

	GetDlgItem(IDC_VCO_POWER_VALUE_COMBO)->EnableWindow(b);
	GetDlgItem(IDC_MODULATOR_POWER_VALUE_COMBO)->EnableWindow(b);
	GetDlgItem(IDC_TEST_BUFFER_POWER_VALUE_COMBO)->EnableWindow(b);
	GetDlgItem(IDC_DATA_INPUT_SELECT_VALUE_COMBO)->EnableWindow(b);
	GetDlgItem(IDC_PA_POWER_VALUE_COMBO)->EnableWindow(b);
	GetDlgItem(IDC_PA_GAIN_CONTROL1_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_PA_GAIN_CONTROL2_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TEST_BUFFER_CURRENT_VALUE_STATIC)->EnableWindow(b);

	GetDlgItem(IDC_BIAS_BLOCK_ENABLE_VALUE_COMBO)->EnableWindow(b);
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
}

void CSemantic::OnBnClickedSemanticEditCheck()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bSemanticEdit = !m_bSemanticEdit;
	if (m_bSemanticEdit) {
		m_selected = None;
		ControlValueEnable(TRUE);
	}
	else {
		ControlValueEnable(FALSE);
		ShowSlider(SW_HIDE);
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
		SetColor(pDC, LnaGain);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_DUTY_CYCLE_VALUE_STATIC) {
		SetColor(pDC, DutyCycle);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_VCO_OSC_FREQ_VALUE_STATIC) {
		SetColor(pDC, VcoOsc);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_VCO_VDD_VALUE_STATIC) {
		SetColor(pDC, VcoVdd);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_PA_GAIN_CONTROL1_VALUE_STATIC) {
		SetColor(pDC, PaGain1);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_PA_GAIN_CONTROL2_VALUE_STATIC) {
		SetColor(pDC, PaGain2);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_TEST_BUFFER_CURRENT_VALUE_STATIC) {
		SetColor(pDC, TestBuffer);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_LNA1_BIAS_CURRENT_VALUE_STATIC) {
		SetColor(pDC, Lna1);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_LNA2_BIAS_CURRENT_VALUE_STATIC) {
		SetColor(pDC, Lna2);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_LNA3_BIAS_CURRENT_VALUE_STATIC) {
		SetColor(pDC, Lna3);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_LNA4_BIAS_CURRENT_VALUE_STATIC) {
		SetColor(pDC, Lna4);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_LNA5_BIAS_CURRENT_VALUE_STATIC) {
		SetColor(pDC, Lna5);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_DEMOD_REF_STAGE_CURRENT_VALUE_STATIC) {
		SetColor(pDC, RefStage);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_DEMOD_IP_STAGE_CURRENT_VALUE_STATIC) {
		SetColor(pDC, IpStage);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_LA_FB_CURRENT_VALUE_STATIC) {
		SetColor(pDC, Fb);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_LA_CORE_CURRENT_VALUE_STATIC) {
		SetColor(pDC, Core);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_LA_OP_BUFFER_CURRENT_VALUE_STATIC) {
		SetColor(pDC, OP);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_LA_IP_BUFFER_CURRENT_VALUE_STATIC) {
		SetColor(pDC, IP);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_LA_HL_DATA_RATE_CURRENT_VALUE_STATIC) {
		SetColor(pDC, HL);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_CMOS_GAIN_STAGE_CURRENT_VALUE_STATIC) {
		SetColor(pDC, CMOS);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_CML_INTERFACE_STAGE_CURRENT_VALUE_STATIC) {
		SetColor(pDC, CML);
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
		m_strSliderMin += DecToBin(min);
		m_strSliderMin += _T(")");
	}

	m_strSliderMax.Format(_T("Max:%d"), max);
	m_strSliderMax += _T("(");
	m_strSliderMax += DecToBin(max);
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
	m_selected = LnaGain;
	ShowSlider(SW_SHOW);
	Invalidate();	//모든것을 다시 그리는 것은 비효율적이지만 제일 간단하다

	SetControlSlider(0, 7, m_strLnaGain, 1, 1, 10);
	GetDlgItem(IDC_LNA_GAIN_STATIC)->GetWindowText(m_strSelectedStatic);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedDutyCycleValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = DutyCycle;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 255, m_strDutyCycle, 10, 1, 10);
	GetDlgItem(IDC_DUTY_CYCLE_STATIC)->GetWindowText(m_strSelectedStatic);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedVcoOscFreqValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = VcoOsc;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 2047, m_strVcoOscFreq, 50, 1, 50);
	GetDlgItem(IDC_VCO_OSC_FREQ_STATIC)->GetWindowText(m_strSelectedStatic);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedVcoVddValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = VcoVdd;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strVcoVdd, 1, 1, 10);
	GetDlgItem(IDC_VCO_VDD_STATIC)->GetWindowText(m_strSelectedStatic);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedPaGainControl1ValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = PaGain1;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strPaGainControl1, 1, 1, 10);
	GetDlgItem(IDC_PA_GAIN_CONTROL1_STATIC)->GetWindowText(m_strSelectedStatic);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedPaGainControl2ValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = PaGain2;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strPaGainControl2, 1, 1, 10);
	GetDlgItem(IDC_PA_GAIN_CONTROL2_STATIC)->GetWindowText(m_strSelectedStatic);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedTestBufferCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = TestBuffer;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strTestBufferCurrent, 1, 1, 10);
	GetDlgItem(IDC_TEST_BUFFER_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedLna1BiasCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = Lna1;
	ShowSlider(SW_SHOW);
	Invalidate();
;
	SetControlSlider(0, 15, m_strLna1Current, 1, 1, 10);
	GetDlgItem(IDC_LNA1_BIAS_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedLna2BiasCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = Lna2;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strLna2Current, 1, 1, 10);
	GetDlgItem(IDC_LNA2_BIAS_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedLna3BiasCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = Lna3;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strLna3Current, 1, 1, 10);
	GetDlgItem(IDC_LNA3_BIAS_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedLna4BiasCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = Lna4;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strLna4Current, 1, 1, 10);
	GetDlgItem(IDC_LNA4_BIAS_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedLna5BiasCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = Lna5;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strLna5Current, 1, 1, 10);
	GetDlgItem(IDC_LNA5_BIAS_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedDemodRefStageCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = RefStage;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strDemodRefStageCurrent, 1, 1, 10);
	GetDlgItem(IDC_DEMOD_REF_STAGE_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedDemodIpStageCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = IpStage;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strDemodIPStageCurrent, 1, 1, 10);
	GetDlgItem(IDC_DEMOD_IP_STAGE_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedLaFbCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = Fb;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strLaFBCurrent, 1, 1, 10);
	GetDlgItem(IDC_LA_FB_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedLaCoreCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = Core;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strLaCoreCurrent, 1, 1, 10);
	GetDlgItem(IDC_LA_CORE_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedLaOpBufferCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = OP;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strLaOPBufferCurrent, 1, 1, 10);
	GetDlgItem(IDC_LA_OP_BUFFER_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedLaIpBufferCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = IP;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strLaIPBufferCurrent, 1, 1, 10);
	GetDlgItem(IDC_LA_IP_BUFFER_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedLaHlDataRateCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = HL;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strLaHLDataRateCurrent, 1, 1, 10);
	GetDlgItem(IDC_LA_HL_DATA_RATE_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedCmosGainStageCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = CMOS;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 15, m_strCMOSGainStageCurrent, 1, 1, 10);
	GetDlgItem(IDC_CMOS_GAIN_STAGE_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	UpdateData(FALSE);
}


void CSemantic::OnStnClickedCmlInterfaceStageCurrentValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selected = CML;
	ShowSlider(SW_SHOW);
	Invalidate();

	SetControlSlider(0, 255, m_strCMLInterfaceStageCurrent, 10, 1, 10);
	GetDlgItem(IDC_CML_INTERFACE_STAGE_CURRENT_STATIC)->GetWindowText(m_strSelectedStatic);
	UpdateData(FALSE);
}


void CSemantic::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (pScrollBar == (CScrollBar*)&m_controlSlider) {
		SliderValueUpdate();
	}

	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CSemantic::SliderValueUpdate()
{
	int curPos = -1*m_controlSlider.GetPos();
	m_strSliderValue.Format(_T("Dec:%d"), curPos);
	m_strSliderValueHex.Format(_T("Hex:0x%02x"), curPos);
	m_strSliderValueBin = _T("Bin:");
	m_strSliderValueBin+=DecToBin(curPos);
	UpdateData(FALSE);
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
}


CString CSemantic::DecToBin(int dec)
{
	if (dec == 0) return _T("0");

	CString strBin;
	int byte = dec & 0xff;
	while (byte > 0) {
		for (int i = 7; i >= 0; i--) {
			CString strBit;
			strBit.Format(_T("%d"), (byte >> i) & 1);
			strBin += strBit;
		}
		byte = (byte >> 8) & 0xff;
	}
	return strBin;
}

void CSemantic::OnBnClickedReadAllButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Parent()->m_pRaw->OnBnClickedReadAllButton();
	UpdateRegisters();
}
