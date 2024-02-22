// CSemanticZing400T.cpp: 구현 파일
//

#include "pch.h"
#include "gZeroMaster.h"
#include "CSemanticZing400T.h"
#include "CRawZing400T.h"
#include "CRegisterZing400T.h"


// CSemanticZing400T 대화 상자

IMPLEMENT_DYNAMIC(CSemanticZing400T, CSemanticBase)

CSemanticZing400T::CSemanticZing400T(CWnd* pParent, CRawBase* pRawBase, CRegister* pReg)
	: CSemanticBase(pParent, pRawBase, pReg)
{
	ASSERT(pReg == m_pReg);

	m_staticMap.clear();
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::DutyCycle, CStaticElem(IDC_DUTY_CYCLE_VALUE_STATIC, &m_pReg->m_nDutyCycle, m_strDutyCycle)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::VcoOsc, CStaticElem(IDC_VCO_OSC_FREQ_VALUE_STATIC, &m_pReg->m_nVcoOsc, m_strVcoOscFreq)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::VcoVdd, CStaticElem(IDC_VCO_VDD_VALUE_STATIC, &m_pReg->m_nVcoVdd, m_strVcoVdd)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::PaGain1, CStaticElem(IDC_PA_GAIN_CONTROL1_VALUE_STATIC, &m_pReg->m_nPaGainCon1, m_strPaGainControl1)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::PaGain2, CStaticElem(IDC_PA_GAIN_CONTROL2_VALUE_STATIC, &m_pReg->m_nPaGainCon2, m_strPaGainControl2)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::TestBuffer, CStaticElem(IDC_TEST_BUFFER_CURRENT_VALUE_STATIC, &m_pReg->m_nTestBufCur, m_strTestBufferCurrent)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::RegRef, CStaticElem(IDC_REG_REF_VOLT_VALUE_STATIC, &m_pReg->m_nRegRef, m_strRegRefVolt)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::VcoPow, CStaticElem(IDC_VCO_POWER_VALUE_STATIC, &m_pReg->m_nVcoPower, m_strVcoPower)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::ModPow, CStaticElem(IDC_MODULATOR_POWER_VALUE_STATIC, &m_pReg->m_nModPower, m_strModPower)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::TestBufPow, CStaticElem(IDC_TEST_BUFFER_POWER_VALUE_STATIC, &m_pReg->m_nTestBufPower, m_strTestBufferPower)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::DataInp, CStaticElem(IDC_DATA_INPUT_SELECT_VALUE_STATIC, &m_pReg->m_nDataInpSel, m_strDataInputSelect)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::PaPow, CStaticElem(IDC_PA_POWER_VALUE_STATIC, &m_pReg->m_nPaPower, m_strPaPower)));

	CRegisterZing400T* pDerived = dynamic_cast<CRegisterZing400T*>(pReg);
	ASSERT(pDerived);
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::VspsPa, CStaticElem(IDC_TX_VSPS_PA_BIAS_VOLTAGE_VALUE_STATIC, &pDerived->m_nVspsPa, m_strVspsPaBiasVoltage)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::VspsVga, CStaticElem(IDC_TX_VSPS_VGA_BIAS_VOLTAGE_VALUE_STATIC, &pDerived->m_nVspsVga, m_strVspsVgaBiasVoltage)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::VspsCs, CStaticElem(IDC_TX_VSPS_CS_BIAS_VOLTAGE_VALUE_STATIC, &pDerived->m_nVspsCs, m_strVspsCsBiasVoltage)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch3Block, CStaticElem(IDC_TX_CH3_VSPS_BLOCK_ENABLE_VALUE_STATIC, &pDerived->m_block[3].m_nBlock, m_vspsBlock[3].m_strVspsBlockEnable)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch3_Q, CStaticElem(IDC_TX_CH3_Q_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, &pDerived->m_block[3].m_nQ, m_vspsBlock[3].m_strQ_PhaseControlBit)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch3_I, CStaticElem(IDC_TX_CH3_I_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, &pDerived->m_block[3].m_nI, m_vspsBlock[3].m_strI_PhaseControlBit)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch2Block, CStaticElem(IDC_TX_CH2_VSPS_BLOCK_ENABLE_VALUE_STATIC, &pDerived->m_block[2].m_nBlock, m_vspsBlock[2].m_strVspsBlockEnable)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch2_Q, CStaticElem(IDC_TX_CH2_Q_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, &pDerived->m_block[2].m_nQ, m_vspsBlock[2].m_strQ_PhaseControlBit)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch2_I, CStaticElem(IDC_TX_CH2_I_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, &pDerived->m_block[2].m_nI, m_vspsBlock[2].m_strI_PhaseControlBit)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch1Block, CStaticElem(IDC_TX_CH1_VSPS_BLOCK_ENABLE_VALUE_STATIC, &pDerived->m_block[1].m_nBlock, m_vspsBlock[1].m_strVspsBlockEnable)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch1_Q, CStaticElem(IDC_TX_CH1_Q_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, &pDerived->m_block[1].m_nQ, m_vspsBlock[1].m_strQ_PhaseControlBit)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch1_I, CStaticElem(IDC_TX_CH1_I_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, &pDerived->m_block[1].m_nI, m_vspsBlock[1].m_strI_PhaseControlBit)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch0Block, CStaticElem(IDC_TX_CH0_VSPS_BLOCK_ENABLE_VALUE_STATIC, &pDerived->m_block[0].m_nBlock, m_vspsBlock[0].m_strVspsBlockEnable)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch0_Q, CStaticElem(IDC_TX_CH0_Q_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, &pDerived->m_block[0].m_nQ, m_vspsBlock[0].m_strQ_PhaseControlBit)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch0_I, CStaticElem(IDC_TX_CH0_I_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, &pDerived->m_block[0].m_nI, m_vspsBlock[0].m_strI_PhaseControlBit)));
}

CSemanticZing400T::~CSemanticZing400T()
{
	delete m_pReg;
}

void CSemanticZing400T::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
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
	DDX_Text(pDX, IDC_TX_BIAS_BLOCK_ENABLE_VALUE_STATIC, m_strBiasBlockEnable);
	DDX_Text(pDX, IDC_TX_VSPS_PA_BIAS_VOLTAGE_VALUE_STATIC, m_strVspsPaBiasVoltage);
	DDX_Text(pDX, IDC_TX_VSPS_VGA_BIAS_VOLTAGE_VALUE_STATIC, m_strVspsVgaBiasVoltage);
	DDX_Text(pDX, IDC_TX_VSPS_CS_BIAS_VOLTAGE_VALUE_STATIC, m_strVspsCsBiasVoltage);
	DDX_Text(pDX, IDC_TX_CH3_VSPS_BLOCK_ENABLE_VALUE_STATIC, m_vspsBlock[3].m_strVspsBlockEnable);
	DDX_Text(pDX, IDC_TX_CH3_Q_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, m_vspsBlock[3].m_strQ_PhaseControlBit);
	DDX_Text(pDX, IDC_TX_CH3_I_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, m_vspsBlock[3].m_strI_PhaseControlBit);
	DDX_Text(pDX, IDC_TX_CH2_VSPS_BLOCK_ENABLE_VALUE_STATIC, m_vspsBlock[2].m_strVspsBlockEnable);
	DDX_Text(pDX, IDC_TX_CH2_Q_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, m_vspsBlock[2].m_strQ_PhaseControlBit);
	DDX_Text(pDX, IDC_TX_CH2_I_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, m_vspsBlock[2].m_strI_PhaseControlBit);
	DDX_Text(pDX, IDC_TX_CH1_VSPS_BLOCK_ENABLE_VALUE_STATIC, m_vspsBlock[1].m_strVspsBlockEnable);
	DDX_Text(pDX, IDC_TX_CH1_Q_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, m_vspsBlock[1].m_strQ_PhaseControlBit);
	DDX_Text(pDX, IDC_TX_CH1_I_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, m_vspsBlock[1].m_strI_PhaseControlBit);
	DDX_Text(pDX, IDC_TX_CH0_VSPS_BLOCK_ENABLE_VALUE_STATIC, m_vspsBlock[0].m_strVspsBlockEnable);
	DDX_Text(pDX, IDC_TX_CH0_Q_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, m_vspsBlock[0].m_strQ_PhaseControlBit);
	DDX_Text(pDX, IDC_TX_CH0_I_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, m_vspsBlock[0].m_strI_PhaseControlBit);
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


BEGIN_MESSAGE_MAP(CSemanticZing400T, CSemanticBase)
	ON_BN_CLICKED(IDC_SEMANTIC_EDIT_CHECK, &OnBnClickedSemanticEditCheck)
	ON_WM_CTLCOLOR()
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_READ_ALL_BUTTON, &OnBnClickedReadAllButton)
	ON_CBN_SELCHANGE(IDC_CONTROL_COMBO, &OnCbnSelchangeControlCombo)
	ON_BN_CLICKED(IDC_WRITE_BUTTON, &OnBnClickedWriteButton)
	ON_BN_CLICKED(IDC_DEFAULT_VALUE_BUTTON, &OnBnClickedDefaultValueButton)
	ON_BN_CLICKED(IDC_WRITE_ALL_BUTTON, &OnBnClickedWriteAllButton)
	ON_BN_CLICKED(IDC_AUTO_WRITE_CHECK, &OnBnClickedAutoWriteCheck)
	ON_STN_CLICKED(IDC_DUTY_CYCLE_VALUE_STATIC, &OnStnClickedDutyCycleValueStatic)
	ON_STN_CLICKED(IDC_VCO_OSC_FREQ_VALUE_STATIC, &OnStnClickedVcoOscFreqValueStatic)
	ON_STN_CLICKED(IDC_VCO_VDD_VALUE_STATIC, &OnStnClickedVcoVddValueStatic)
	ON_STN_CLICKED(IDC_PA_GAIN_CONTROL1_VALUE_STATIC, &OnStnClickedPaGainControl1ValueStatic)
	ON_STN_CLICKED(IDC_PA_GAIN_CONTROL2_VALUE_STATIC, &OnStnClickedPaGainControl2ValueStatic)
	ON_STN_CLICKED(IDC_TEST_BUFFER_CURRENT_VALUE_STATIC, &OnStnClickedTestBufferCurrentValueStatic)
	ON_STN_CLICKED(IDC_REG_REF_VOLT_VALUE_STATIC, &OnStnClickedRegRefVoltValueStatic)
	ON_STN_CLICKED(IDC_VCO_POWER_VALUE_STATIC, &OnStnClickedVcoPowerValueStatic)
	ON_STN_CLICKED(IDC_MODULATOR_POWER_VALUE_STATIC, &OnStnClickedModulatorPowerValueStatic)
	ON_STN_CLICKED(IDC_TEST_BUFFER_POWER_VALUE_STATIC, &OnStnClickedTestBufferPowerValueStatic)
	ON_STN_CLICKED(IDC_DATA_INPUT_SELECT_VALUE_STATIC, &OnStnClickedDataInputSelectValueStatic)
	ON_STN_CLICKED(IDC_PA_POWER_VALUE_STATIC, &OnStnClickedPaPowerValueStatic)
END_MESSAGE_MAP()


// CSemanticZing400T 메시지 처리기


BOOL CSemanticZing400T::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	InitialControlState();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CSemanticZing400T::OnChipConnect(CString chipModel)
{
	ASSERT(chipModel == _T("Zing400T"));
}


void CSemanticZing400T::ControlLabelEnable(BOOL b)
{
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

	GetDlgItem(IDC_TX_BIAS_BLOCK_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_VSPS_PA_BIAS_VOLTAGE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_VSPS_VGA_BIAS_VOLTAGE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_VSPS_CS_BIAS_VOLTAGE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH3_VSPS_BLOCK_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH3_Q_VSPS_PHASE_CONTROL_BIT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH3_I_VSPS_PHASE_CONTROL_BIT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH2_VSPS_BLOCK_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH2_Q_VSPS_PHASE_CONTROL_BIT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH2_I_VSPS_PHASE_CONTROL_BIT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH1_VSPS_BLOCK_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH1_Q_VSPS_PHASE_CONTROL_BIT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH1_I_VSPS_PHASE_CONTROL_BIT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH0_VSPS_BLOCK_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH0_Q_VSPS_PHASE_CONTROL_BIT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH0_I_VSPS_PHASE_CONTROL_BIT_STATIC)->EnableWindow(b);
}

void CSemanticZing400T::ControlValueEnable(BOOL b)
{
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

	GetDlgItem(IDC_TX_BIAS_BLOCK_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_VSPS_PA_BIAS_VOLTAGE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_VSPS_VGA_BIAS_VOLTAGE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_VSPS_CS_BIAS_VOLTAGE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH3_VSPS_BLOCK_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH3_Q_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH3_I_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH2_VSPS_BLOCK_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH2_Q_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH2_I_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH1_VSPS_BLOCK_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH1_Q_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH1_I_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH0_VSPS_BLOCK_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH0_Q_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH0_I_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC)->EnableWindow(b);
}

const CRegister& CSemanticZing400T::Parse()
{
	UpdateTxReg1(m_pRawBase->m_strTxReg1Top, m_pRawBase->m_strTxReg1Mid, m_pRawBase->m_strTxReg1Bot, *m_pReg);
	UpdateTxReg2(m_pRawBase->m_strTxReg2Top, m_pRawBase->m_strTxReg2Mid, m_pRawBase->m_strTxReg2Bot, *m_pReg);

	CRawZing400T* pDeriv = dynamic_cast<CRawZing400T*>(m_pRawBase);
	ASSERT(pDeriv);

	return *m_pReg;
}

void CSemanticZing400T::UpdateRegisters()
{
	CSemanticBase::UpdateRegisters();
}

void CSemanticZing400T::UpdateTxReg1(CString strTxRegTop, CString strTxRegMid, CString strTxRegBot, CRegister& reg)
{
	int mid = _tcstol(strTxRegMid.GetBuffer(), NULL, 16) & 0xff;
	int bot = _tcstol(strTxRegBot.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nDutyCycle = _tcstol(strTxRegTop.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nVcoOsc = (bot & 0xe0) >> 5 | (mid << 3);
	reg.m_nRegRef = (bot & 0x10) >> 4;
	reg.m_nVcoVdd = bot & 0x0f;
}