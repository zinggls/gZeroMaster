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
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::BiasBlock, CStaticElem(IDC_TX_BIAS_BLOCK_ENABLE_VALUE_STATIC, &m_pReg->m_nBiasBlock, m_strBiasBlockEnable)));

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
	ON_STN_CLICKED(IDC_TX_BIAS_BLOCK_ENABLE_VALUE_STATIC, &CSemanticZing400T::OnStnClickedTxBiasBlockEnableValueStatic)
	ON_STN_CLICKED(IDC_TX_VSPS_PA_BIAS_VOLTAGE_VALUE_STATIC, &CSemanticZing400T::OnStnClickedTxVspsPaBiasVoltageValueStatic)
	ON_STN_CLICKED(IDC_TX_VSPS_VGA_BIAS_VOLTAGE_VALUE_STATIC, &CSemanticZing400T::OnStnClickedTxVspsVgaBiasVoltageValueStatic)
	ON_STN_CLICKED(IDC_TX_VSPS_CS_BIAS_VOLTAGE_VALUE_STATIC, &CSemanticZing400T::OnStnClickedTxVspsCsBiasVoltageValueStatic)
	ON_STN_CLICKED(IDC_TX_CH3_VSPS_BLOCK_ENABLE_VALUE_STATIC, &CSemanticZing400T::OnStnClickedTxCh3VspsBlockEnableValueStatic)
	ON_STN_CLICKED(IDC_TX_CH3_Q_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, &CSemanticZing400T::OnStnClickedTxCh3QVspsPhaseControlBitValueStatic)
	ON_STN_CLICKED(IDC_TX_CH3_I_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, &CSemanticZing400T::OnStnClickedTxCh3IVspsPhaseControlBitValueStatic)
	ON_STN_CLICKED(IDC_TX_CH2_VSPS_BLOCK_ENABLE_VALUE_STATIC, &CSemanticZing400T::OnStnClickedTxCh2VspsBlockEnableValueStatic)
	ON_STN_CLICKED(IDC_TX_CH2_Q_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, &CSemanticZing400T::OnStnClickedTxCh2QVspsPhaseControlBitValueStatic)
	ON_STN_CLICKED(IDC_TX_CH2_I_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, &CSemanticZing400T::OnStnClickedTxCh2IVspsPhaseControlBitValueStatic)
	ON_STN_CLICKED(IDC_TX_CH1_VSPS_BLOCK_ENABLE_VALUE_STATIC, &CSemanticZing400T::OnStnClickedTxCh1VspsBlockEnableValueStatic)
	ON_STN_CLICKED(IDC_TX_CH1_Q_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, &CSemanticZing400T::OnStnClickedTxCh1QVspsPhaseControlBitValueStatic)
	ON_STN_CLICKED(IDC_TX_CH1_I_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, &CSemanticZing400T::OnStnClickedTxCh1IVspsPhaseControlBitValueStatic)
	ON_STN_CLICKED(IDC_TX_CH0_VSPS_BLOCK_ENABLE_VALUE_STATIC, &CSemanticZing400T::OnStnClickedTxCh0VspsBlockEnableValueStatic)
	ON_STN_CLICKED(IDC_TX_CH0_Q_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, &CSemanticZing400T::OnStnClickedTxCh0QVspsPhaseControlBitValueStatic)
	ON_STN_CLICKED(IDC_TX_CH0_I_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC, &CSemanticZing400T::OnStnClickedTxCh0IVspsPhaseControlBitValueStatic)

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

	UpdateRegOut24(pDeriv->m_strRegOut24, *m_pReg);

	CRegisterZing400T& regDeriv = dynamic_cast<CRegisterZing400T&>(*m_pReg);
	UpdateRegOut25(pDeriv->m_strRegOut25, regDeriv);
	UpdateRegOut26(pDeriv->m_strRegOut26, regDeriv);
	UpdateRegOut27(pDeriv->m_strRegOut27, regDeriv);
	UpdateRegOut28(pDeriv->m_strRegOut28, regDeriv);
	UpdateRegOut29(pDeriv->m_strRegOut29, regDeriv);
	UpdateRegOut2A(pDeriv->m_strRegOut2A, regDeriv);
	UpdateRegOut2B(pDeriv->m_strRegOut2B, regDeriv);
	return *m_pReg;
}

void CSemanticZing400T::UpdateRegisters()
{
	CSemanticBase::UpdateRegisters();

	const CRegisterZing400T & derived = dynamic_cast<const CRegisterZing400T&>(Parse());
	UpdateBiasBlockEnable(derived);
	UpdateVspsPaBiasVoltage(derived);
	UpdateVspsVgaBiasVoltage(derived);
	UpdateVspsCsBiasVoltage(derived);
	UpdateCh3VspsBlockEnable(derived);
	UpdateCh3VspsPhaseControlBitQ(derived);
	UpdateCh3VspsPhaseControlBitI(derived);
	UpdateCh2VspsBlockEnable(derived);
	UpdateCh2VspsPhaseControlBitQ(derived);
	UpdateCh2VspsPhaseControlBitI(derived);
	UpdateCh1VspsBlockEnable(derived);
	UpdateCh1VspsPhaseControlBitQ(derived);
	UpdateCh1VspsPhaseControlBitI(derived);
	UpdateCh0VspsBlockEnable(derived);
	UpdateCh0VspsPhaseControlBitQ(derived);
	UpdateCh0VspsPhaseControlBitI(derived);
	UpdateData(FALSE);
}

void CSemanticZing400T::ResetValues()
{
	m_strBiasBlockEnable.Empty();
	m_strVspsPaBiasVoltage.Empty();
	m_strVspsVgaBiasVoltage.Empty();
	m_strVspsCsBiasVoltage.Empty();
	for (int i = 0; i < 4; i++) {
		m_vspsBlock[i].m_strI_PhaseControlBit.Empty();
		m_vspsBlock[i].m_strQ_PhaseControlBit.Empty();
		m_vspsBlock[i].m_strVspsBlockEnable.Empty();
	}
	CSemanticBase::ResetValues();
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

void CSemanticZing400T::UpdateRegOut24(CString strRegOut24, CRegister& reg)
{
	reg.m_nBiasBlock = _tcstol(strRegOut24.GetBuffer(), NULL, 16) & 0x01;
}

void CSemanticZing400T::UpdateRegOut25(CString strRegOut25, CRegisterZing400T& reg)
{
	int hexa = _tcstol(strRegOut25.GetBuffer(), NULL, 16);
	reg.m_nVspsPa = (hexa & 0xf0)>>4;
	reg.m_nVspsVga = hexa & 0x0f;
}

void CSemanticZing400T::UpdateRegOut26(CString strRegOut26, CRegisterZing400T& reg)
{
	int hexa = _tcstol(strRegOut26.GetBuffer(), NULL, 16);

	reg.m_nVspsCs = (hexa & 0xf0) >> 4;
	reg.m_block[3].m_nBlock = (hexa & 0x08) >> 3;

	int high = (hexa & 0x07)<<2;
	int low = reg.m_block[3].m_nQ & 0x03;
	reg.m_block[3].m_nQ = high | low;
}

void CSemanticZing400T::UpdateRegOut27(CString strRegOut27, CRegisterZing400T& reg)
{
	int hexa = _tcstol(strRegOut27.GetBuffer(), NULL, 16);

	int high = (reg.m_block[3].m_nQ) & 0x1c;
	int low = (hexa & 0xc0) >> 6;
	reg.m_block[3].m_nQ = high | low;
	reg.m_block[3].m_nI = (hexa & 0x3e) >> 1;
	reg.m_block[2].m_nBlock = hexa & 0x1;
}

void CSemanticZing400T::UpdateRegOut28(CString strRegOut28, CRegisterZing400T& reg)
{
	int hexa = _tcstol(strRegOut28.GetBuffer(), NULL, 16);

	reg.m_block[2].m_nQ = (hexa & 0xf8) >> 3;

	int high = (hexa & 0x7) << 2;
	int low = reg.m_block[2].m_nI & 0x03;
	reg.m_block[2].m_nI = high | low;
}

void CSemanticZing400T::UpdateRegOut29(CString strRegOut29, CRegisterZing400T& reg)
{
	int hexa = _tcstol(strRegOut29.GetBuffer(), NULL, 16);

	int high = (reg.m_block[2].m_nI) & 0x1c;
	int low = (hexa & 0xc0) >> 6;
	reg.m_block[2].m_nI = high | low;
	reg.m_block[1].m_nQ = hexa & 0x1f;
	reg.m_block[1].m_nBlock = (hexa & 0x20) >> 5;
}

void CSemanticZing400T::UpdateRegOut2A(CString strRegOut2A, CRegisterZing400T& reg)
{
	int hexa = _tcstol(strRegOut2A.GetBuffer(), NULL, 16);

	reg.m_block[1].m_nI = (hexa & 0xf8) >> 3;
	reg.m_block[0].m_nBlock = (hexa & 0x04) >> 2;
	int high = (hexa & 0x3) << 3;
	int low = (reg.m_block[0].m_nQ) & 0x7;
	reg.m_block[0].m_nQ = high | low;
}

void CSemanticZing400T::UpdateRegOut2B(CString strRegOut2B, CRegisterZing400T& reg)
{
	int hexa = _tcstol(strRegOut2B.GetBuffer(), NULL, 16);

	reg.m_block[0].m_nI = hexa & 0x1f;
	int high = (reg.m_block[0].m_nQ) & 0x18;
	int low = (hexa & 0xe0) >> 5;
	reg.m_block[0].m_nQ = high | low;
}

void CSemanticZing400T::UpdateBiasBlockEnable(const CRegisterZing400T & reg)
{
	(reg.m_nBiasBlock) ? m_strBiasBlockEnable.Format(_T("enable")) : m_strBiasBlockEnable.Format(_T("disable"));
}

void CSemanticZing400T::UpdateVspsPaBiasVoltage(const CRegisterZing400T& reg)
{
	m_strVspsPaBiasVoltage.Format(_T("0x%02x"), reg.m_nVspsPa);
}

void CSemanticZing400T::UpdateVspsVgaBiasVoltage(const CRegisterZing400T& reg)
{
	m_strVspsVgaBiasVoltage.Format(_T("0x%02x"), reg.m_nVspsVga);
}

void CSemanticZing400T::UpdateVspsCsBiasVoltage(const CRegisterZing400T& reg)
{
	m_strVspsCsBiasVoltage.Format(_T("0x%02x"), reg.m_nVspsCs);
}

void CSemanticZing400T::UpdateCh3VspsBlockEnable(const CRegisterZing400T& reg)
{
	(reg.m_block[3].m_nBlock) ? m_vspsBlock[3].m_strVspsBlockEnable.Format(_T("enable")) : m_vspsBlock[3].m_strVspsBlockEnable.Format(_T("disable"));
}

void CSemanticZing400T::UpdateCh3VspsPhaseControlBitQ(const CRegisterZing400T& reg)
{
	m_vspsBlock[3].m_strQ_PhaseControlBit.Format(_T("0x%02x"), reg.m_block[3].m_nQ);
}

void CSemanticZing400T::UpdateCh3VspsPhaseControlBitI(const CRegisterZing400T& reg)
{
	m_vspsBlock[3].m_strI_PhaseControlBit.Format(_T("0x%02x"), reg.m_block[3].m_nI);
}

void CSemanticZing400T::UpdateCh2VspsBlockEnable(const CRegisterZing400T& reg)
{
	(reg.m_block[2].m_nBlock) ? m_vspsBlock[2].m_strVspsBlockEnable.Format(_T("enable")) : m_vspsBlock[2].m_strVspsBlockEnable.Format(_T("disable"));
}

void CSemanticZing400T::UpdateCh2VspsPhaseControlBitQ(const CRegisterZing400T& reg)
{
	m_vspsBlock[2].m_strQ_PhaseControlBit.Format(_T("0x%02x"), reg.m_block[2].m_nQ);
}

void CSemanticZing400T::UpdateCh2VspsPhaseControlBitI(const CRegisterZing400T& reg)
{
	m_vspsBlock[2].m_strI_PhaseControlBit.Format(_T("0x%02x"), reg.m_block[2].m_nI);
}

void CSemanticZing400T::UpdateCh1VspsBlockEnable(const CRegisterZing400T& reg)
{
	(reg.m_block[1].m_nBlock) ? m_vspsBlock[1].m_strVspsBlockEnable.Format(_T("enable")) : m_vspsBlock[1].m_strVspsBlockEnable.Format(_T("disable"));
}

void CSemanticZing400T::UpdateCh1VspsPhaseControlBitQ(const CRegisterZing400T& reg)
{
	m_vspsBlock[1].m_strQ_PhaseControlBit.Format(_T("0x%02x"), reg.m_block[1].m_nQ);
}

void CSemanticZing400T::UpdateCh1VspsPhaseControlBitI(const CRegisterZing400T& reg)
{
	m_vspsBlock[1].m_strI_PhaseControlBit.Format(_T("0x%02x"), reg.m_block[1].m_nI);
}

void CSemanticZing400T::UpdateCh0VspsBlockEnable(const CRegisterZing400T& reg)
{
	(reg.m_block[0].m_nBlock) ? m_vspsBlock[0].m_strVspsBlockEnable.Format(_T("enable")) : m_vspsBlock[0].m_strVspsBlockEnable.Format(_T("disable"));
}

void CSemanticZing400T::UpdateCh0VspsPhaseControlBitQ(const CRegisterZing400T& reg)
{
	m_vspsBlock[0].m_strQ_PhaseControlBit.Format(_T("0x%02x"), reg.m_block[0].m_nQ);
}

void CSemanticZing400T::UpdateCh0VspsPhaseControlBitI(const CRegisterZing400T& reg)
{
	m_vspsBlock[0].m_strI_PhaseControlBit.Format(_T("0x%02x"), reg.m_block[0].m_nI);
}

void CSemanticZing400T::OnStnClickedTxBiasBlockEnableValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetComboGroup(CSelect::BiasBlock, _T("disable"), _T("enable"), getRegister().m_nBiasBlock, IDC_TX_BIAS_BLOCK_ENABLE_VALUE_STATIC);
}

void CSemanticZing400T::OnStnClickedTxVspsPaBiasVoltageValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(CSelect::VspsPa, 0, 15, m_strVspsPaBiasVoltage, 1, 1, 10, IDC_TX_VSPS_PA_BIAS_VOLTAGE_VALUE_STATIC);
}


void CSemanticZing400T::OnStnClickedTxVspsVgaBiasVoltageValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(CSelect::VspsVga, 0, 15, m_strVspsVgaBiasVoltage, 1, 1, 10, IDC_TX_VSPS_VGA_BIAS_VOLTAGE_VALUE_STATIC);
}


void CSemanticZing400T::OnStnClickedTxVspsCsBiasVoltageValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(CSelect::VspsCs, 0, 15, m_strVspsCsBiasVoltage, 1, 1, 10, IDC_TX_VSPS_CS_BIAS_VOLTAGE_VALUE_STATIC);
}


void CSemanticZing400T::OnStnClickedTxCh3VspsBlockEnableValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	const CRegisterZing400T& derived = dynamic_cast<const CRegisterZing400T&>(getRegister());
	SetComboGroup(CSelect::Ch3Block, _T("disable"), _T("enable"), derived.m_block[3].m_nBlock, IDC_TX_CH3_VSPS_BLOCK_ENABLE_VALUE_STATIC);
}


void CSemanticZing400T::OnStnClickedTxCh3QVspsPhaseControlBitValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(CSelect::Ch3_Q, 0, 31, m_vspsBlock[3].m_strQ_PhaseControlBit, 1, 1, 10, IDC_TX_CH3_Q_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC);
}


void CSemanticZing400T::OnStnClickedTxCh3IVspsPhaseControlBitValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(CSelect::Ch3_I, 0, 31, m_vspsBlock[3].m_strI_PhaseControlBit, 1, 1, 10, IDC_TX_CH3_I_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC);
}


void CSemanticZing400T::OnStnClickedTxCh2VspsBlockEnableValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	const CRegisterZing400T& derived = dynamic_cast<const CRegisterZing400T&>(getRegister());
	SetComboGroup(CSelect::Ch2Block, _T("disable"), _T("enable"), derived.m_block[2].m_nBlock, IDC_TX_CH2_VSPS_BLOCK_ENABLE_VALUE_STATIC);
}


void CSemanticZing400T::OnStnClickedTxCh2QVspsPhaseControlBitValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(CSelect::Ch2_Q, 0, 31, m_vspsBlock[2].m_strQ_PhaseControlBit, 1, 1, 10, IDC_TX_CH2_Q_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC);
}


void CSemanticZing400T::OnStnClickedTxCh2IVspsPhaseControlBitValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(CSelect::Ch2_I, 0, 31, m_vspsBlock[2].m_strI_PhaseControlBit, 1, 1, 10, IDC_TX_CH2_I_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC);
}


void CSemanticZing400T::OnStnClickedTxCh1VspsBlockEnableValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	const CRegisterZing400T& derived = dynamic_cast<const CRegisterZing400T&>(getRegister());
	SetComboGroup(CSelect::Ch1Block, _T("disable"), _T("enable"), derived.m_block[1].m_nBlock, IDC_TX_CH1_VSPS_BLOCK_ENABLE_VALUE_STATIC);
}


void CSemanticZing400T::OnStnClickedTxCh1QVspsPhaseControlBitValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(CSelect::Ch1_Q, 0, 31, m_vspsBlock[1].m_strQ_PhaseControlBit, 1, 1, 10, IDC_TX_CH1_Q_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC);
}


void CSemanticZing400T::OnStnClickedTxCh1IVspsPhaseControlBitValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(CSelect::Ch1_I, 0, 31, m_vspsBlock[1].m_strI_PhaseControlBit, 1, 1, 10, IDC_TX_CH1_I_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC);
}


void CSemanticZing400T::OnStnClickedTxCh0VspsBlockEnableValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	const CRegisterZing400T& derived = dynamic_cast<const CRegisterZing400T&>(getRegister());
	SetComboGroup(CSelect::Ch0Block, _T("disable"), _T("enable"), derived.m_block[0].m_nBlock, IDC_TX_CH0_VSPS_BLOCK_ENABLE_VALUE_STATIC);
}


void CSemanticZing400T::OnStnClickedTxCh0QVspsPhaseControlBitValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CSemanticZing400T::OnStnClickedTxCh0IVspsPhaseControlBitValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}