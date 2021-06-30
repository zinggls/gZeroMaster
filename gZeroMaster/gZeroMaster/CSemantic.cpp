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
	, m_bRxDataInterface(FALSE)
	, m_bLimitingAmplifier(FALSE)
	, m_strLnaGain(_T(""))
	, m_pParent(pParent)
	, m_strPaGainControl1(_T(""))
	, m_strPaGainControl2(_T(""))
	, m_strTestBufferCurrent(_T(""))
	, m_bBiasBlockEnable(FALSE)
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
{

}

CSemantic::~CSemantic()
{
}

void CSemantic::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_RX_DATA_IF_ENABLE_CHECK, m_bRxDataInterface);
	DDX_Check(pDX, IDC_LIMITING_AMP_ENABLE_CHECK, m_bLimitingAmplifier);
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
	DDX_Check(pDX, IDC_BIAS_BLOCK_ENABLE_CHECK, m_bBiasBlockEnable);
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
}


BEGIN_MESSAGE_MAP(CSemantic, CDialogEx)
	ON_BN_CLICKED(IDC_RX_DATA_IF_ENABLE_CHECK, &CSemantic::OnBnClickedRxDataIfEnableCheck)
	ON_BN_CLICKED(IDC_LIMITING_AMP_ENABLE_CHECK, &CSemantic::OnBnClickedLimitingAmpEnableCheck)
END_MESSAGE_MAP()


CgZeroMasterDlg* CSemantic::Parent()
{
	return dynamic_cast<CgZeroMasterDlg*>(m_pParent);
}


// CSemantic 메시지 처리기


void CSemantic::OnBnClickedRxDataIfEnableCheck()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bRxDataInterface = !m_bRxDataInterface;
	UpdateData(FALSE);
}


void CSemantic::OnBnClickedLimitingAmpEnableCheck()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bLimitingAmplifier = !m_bLimitingAmplifier;
	UpdateData(FALSE);
}


BOOL CSemantic::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	ControlLabelEnable(FALSE);
	ControlValueEnable(FALSE);

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
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CSemantic::UpdateRegisters()
{
	ASSERT(Parent());
	UpdateRxReg1(Parent()->m_pRaw->m_strRxReg1);
	UpdateTxReg1(Parent()->m_pRaw->m_strTxReg1Top, Parent()->m_pRaw->m_strTxReg1Mid, Parent()->m_pRaw->m_strTxReg1Bot);
	UpdateTxReg2(Parent()->m_pRaw->m_strTxReg2Top, Parent()->m_pRaw->m_strTxReg2Mid, Parent()->m_pRaw->m_strTxReg2Bot);
	UpdateBiasReg1(Parent()->m_pRaw->m_strBiasReg1);
	UpdateBiasReg2(Parent()->m_pRaw->m_strBiasReg2);
	UpdateData(FALSE);
}

void CSemantic::UpdateRxReg1(CString strRxReg1)
{
	int val = _tcstol(strRxReg1.GetBuffer(), NULL, 16) & 0xff;

	m_bRxDataInterface = (val & 0x10) >> 4;
	m_bLimitingAmplifier = (val & 0x08) >> 3;
	m_strLnaGain.Format(_T("0x%02x"), val & 0x07);
}

void CSemantic::UpdateTxReg1(CString strTxReg1Top, CString strTxReg1Mid, CString strTxReg1Bot)
{
	m_strDutyCycle = strTxReg1Top;

	int mid = _tcstol(strTxReg1Mid.GetBuffer(), NULL, 16) & 0xff;
	int bot = _tcstol(strTxReg1Bot.GetBuffer(), NULL, 16) & 0xff;

	int nVcoOscFreq = (bot & 0xe0) >> 5 | (mid << 3);
	int nRefVolt = (bot & 0x10) >> 4;
	int nVcoVdd = bot & 0x0f;

	m_strVcoOscFreq.Format(_T("0x%02x"), nVcoOscFreq);
	m_regRefVolt.SetCurSel(nRefVolt);
	m_strVcoVdd.Format(_T("0x%02x"), nVcoVdd);
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
	m_bBiasBlockEnable = _tcstol(strBiasReg1.GetBuffer(), NULL, 16) & 0x01;
}

void CSemantic::UpdateBiasReg2(CString strBiasReg2)
{
	int reg2 = _tcstol(strBiasReg2.GetBuffer(), NULL, 16) & 0xff;

	m_strLna3Current.Format(_T("0x%02x"),(reg2&0xf0)>>4);
	m_strLna1Current.Format(_T("0x%02x"), reg2 & 0x0f);
	m_strLna2Current = m_strLna1Current;
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
	GetDlgItem(IDC_RX_DATA_IF_ENABLE_CHECK)->EnableWindow(b);
	GetDlgItem(IDC_LIMITING_AMP_ENABLE_CHECK)->EnableWindow(b);
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

	GetDlgItem(IDC_BIAS_BLOCK_ENABLE_CHECK)->EnableWindow(b);
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