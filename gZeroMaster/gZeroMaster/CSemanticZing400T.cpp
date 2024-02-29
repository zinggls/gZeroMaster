// CSemanticZing400T.cpp: 구현 파일
//

#include "pch.h"
#include "gZeroMaster.h"
#include "CSemanticZing400T.h"
#include "CRawZing400T.h"
#include "CRegisterZing400T.h"
#include "CPhaseTable.h"


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
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch3Phase, CStaticElem(IDC_TX_CH3_PHASE_VALUE_STATIC, &pDerived->m_block[3].m_nPhase, m_vspsBlock[3].m_strPhase)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch2Block, CStaticElem(IDC_TX_CH2_VSPS_BLOCK_ENABLE_VALUE_STATIC, &pDerived->m_block[2].m_nBlock, m_vspsBlock[2].m_strVspsBlockEnable)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch2Phase, CStaticElem(IDC_TX_CH2_PHASE_VALUE_STATIC, &pDerived->m_block[2].m_nPhase, m_vspsBlock[2].m_strPhase)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch1Block, CStaticElem(IDC_TX_CH1_VSPS_BLOCK_ENABLE_VALUE_STATIC, &pDerived->m_block[1].m_nBlock, m_vspsBlock[1].m_strVspsBlockEnable)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch1Phase, CStaticElem(IDC_TX_CH1_PHASE_VALUE_STATIC, &pDerived->m_block[1].m_nPhase, m_vspsBlock[1].m_strPhase)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch0Block, CStaticElem(IDC_TX_CH0_VSPS_BLOCK_ENABLE_VALUE_STATIC, &pDerived->m_block[0].m_nBlock, m_vspsBlock[0].m_strVspsBlockEnable)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch0Phase, CStaticElem(IDC_TX_CH0_PHASE_VALUE_STATIC, &pDerived->m_block[0].m_nPhase, m_vspsBlock[0].m_strPhase)));
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
	DDX_Text(pDX, IDC_TX_CH3_PHASE_VALUE_STATIC, m_vspsBlock[3].m_strPhase);
	DDX_Text(pDX, IDC_TX_CH2_VSPS_BLOCK_ENABLE_VALUE_STATIC, m_vspsBlock[2].m_strVspsBlockEnable);
	DDX_Text(pDX, IDC_TX_CH2_PHASE_VALUE_STATIC, m_vspsBlock[2].m_strPhase);
	DDX_Text(pDX, IDC_TX_CH1_VSPS_BLOCK_ENABLE_VALUE_STATIC, m_vspsBlock[1].m_strVspsBlockEnable);
	DDX_Text(pDX, IDC_TX_CH1_PHASE_VALUE_STATIC, m_vspsBlock[1].m_strPhase);
	DDX_Text(pDX, IDC_TX_CH0_VSPS_BLOCK_ENABLE_VALUE_STATIC, m_vspsBlock[0].m_strVspsBlockEnable);
	DDX_Text(pDX, IDC_TX_CH0_PHASE_VALUE_STATIC, m_vspsBlock[0].m_strPhase);
	DDX_Control(pDX, IDC_CONTROL_SLIDER, m_controlSlider);
	DDX_Check(pDX, IDC_SEMANTIC_EDIT_CHECK, m_bSemanticEdit);
	DDX_Text(pDX, IDC_SELECTED_STATIC, m_strSelectedStatic);
	DDX_Text(pDX, IDC_SLIDER_MIN_STATIC, m_strSliderMin);
	DDX_Text(pDX, IDC_SLIDER_MAX_STATIC, m_strSliderMax);
	DDX_Text(pDX, IDC_SLIDER_VALUE_STATIC, m_strSliderValue);
	DDX_Text(pDX, IDC_SLIDER_VALUE_HEX_STATIC, m_strSliderValueHex);
	DDX_Text(pDX, IDC_SLIDER_VALUE_BIN_STATIC, m_strSliderValueBin);
	DDX_Text(pDX, IDC_SLIDER_VALUE_PHASE_STATIC, m_strSliderValuePhase);
	DDX_Text(pDX, IDC_SLIDER_VALUE_I_STATIC, m_strSliderValueI);
	DDX_Text(pDX, IDC_SLIDER_VALUE_Q_STATIC, m_strSliderValueQ);
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
	ON_STN_CLICKED(IDC_TX_CH3_PHASE_VALUE_STATIC, &CSemanticZing400T::OnStnClickedTxCh3PhaseValueStatic)
	ON_STN_CLICKED(IDC_TX_CH2_VSPS_BLOCK_ENABLE_VALUE_STATIC, &CSemanticZing400T::OnStnClickedTxCh2VspsBlockEnableValueStatic)
	ON_STN_CLICKED(IDC_TX_CH2_PHASE_VALUE_STATIC, &CSemanticZing400T::OnStnClickedTxCh2PhaseValueStatic)
	ON_STN_CLICKED(IDC_TX_CH1_VSPS_BLOCK_ENABLE_VALUE_STATIC, &CSemanticZing400T::OnStnClickedTxCh1VspsBlockEnableValueStatic)
	ON_STN_CLICKED(IDC_TX_CH1_PHASE_VALUE_STATIC, &CSemanticZing400T::OnStnClickedTxCh1PhaseValueStatic)
	ON_STN_CLICKED(IDC_TX_CH0_VSPS_BLOCK_ENABLE_VALUE_STATIC, &CSemanticZing400T::OnStnClickedTxCh0VspsBlockEnableValueStatic)
	ON_STN_CLICKED(IDC_TX_CH0_PHASE_VALUE_STATIC, &CSemanticZing400T::OnStnClickedTxCh0PhaseValueStatic)
END_MESSAGE_MAP()


// CSemanticZing400T 메시지 처리기


BOOL CSemanticZing400T::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	InitialControlState();

	ASSERT(CPhaseTable::getState(0x0, 0x0) == -1);	//잘못된 값 테스트
	ASSERT(CPhaseTable::getState(0x1F, 0x10) == 1);
	ASSERT(CPhaseTable::getState(0x1D, 0x19) == 2);
	ASSERT(CPhaseTable::getState(0x1D, 0x1A) == 3);
	ASSERT(CPhaseTable::getState(0x1D, 0x1B) == 4);
	ASSERT(CPhaseTable::getState(0x1A, 0x1A) == 5);
	ASSERT(CPhaseTable::getState(0x1A, 0x1B) == 6);
	ASSERT(CPhaseTable::getState(0x18, 0x1B) == 7);
	ASSERT(CPhaseTable::getState(0x15, 0x1B) == 8);
	ASSERT(CPhaseTable::getState(0x8, 0x1C) == 9);
	ASSERT(CPhaseTable::getState(0x6, 0x1C) == 10);
	ASSERT(CPhaseTable::getState(0x5, 0x1C) == 11);
	ASSERT(CPhaseTable::getState(0x3, 0x1D) == 12);
	ASSERT(CPhaseTable::getState(0x2, 0x1C) == 13);
	ASSERT(CPhaseTable::getState(0x1, 0x1C) == 14);
	ASSERT(CPhaseTable::getState(0x1, 0x1B) == 15);
	ASSERT(CPhaseTable::getState(0x0, 0x1A) == 16);
	ASSERT(CPhaseTable::getState(0x0, 0xF) == 17);
	ASSERT(CPhaseTable::getState(0x0, 0x5) == 18);
	ASSERT(CPhaseTable::getState(0x2, 0x5) == 19);
	ASSERT(CPhaseTable::getState(0x2, 0x4) == 20);
	ASSERT(CPhaseTable::getState(0x4, 0x4) == 21);
	ASSERT(CPhaseTable::getState(0x6, 0x4) == 22);
	ASSERT(CPhaseTable::getState(0x6, 0x3) == 23);
	ASSERT(CPhaseTable::getState(0x8, 0x3) == 24);
	ASSERT(CPhaseTable::getState(0x18, 0x2) == 25);
	ASSERT(CPhaseTable::getState(0x1A, 0x2) == 26);
	ASSERT(CPhaseTable::getState(0x1B, 0x2) == 27);
	ASSERT(CPhaseTable::getState(0x1C, 0x2) == 28);
	ASSERT(CPhaseTable::getState(0x1D, 0x3) == 29);
	ASSERT(CPhaseTable::getState(0x1D, 0x4) == 30);
	ASSERT(CPhaseTable::getState(0x1E, 0x4) == 31);
	ASSERT(CPhaseTable::getState(0x1D, 0x6) == 32);

	ASSERT(CPhaseTable::getPhase(1)==CString(_T("0.00")));
	ASSERT(CPhaseTable::getPhase(2) == CString(_T("11.25")));
	ASSERT(CPhaseTable::getPhase(3) == CString(_T("22.50")));
	ASSERT(CPhaseTable::getPhase(4) == CString(_T("33.75")));
	ASSERT(CPhaseTable::getPhase(5) == CString(_T("45.00")));
	ASSERT(CPhaseTable::getPhase(6) == CString(_T("56.25")));
	ASSERT(CPhaseTable::getPhase(7) == CString(_T("67.50")));
	ASSERT(CPhaseTable::getPhase(8) == CString(_T("78.75")));
	ASSERT(CPhaseTable::getPhase(9) == CString(_T("90.00")));
	ASSERT(CPhaseTable::getPhase(10) == CString(_T("101.25")));
	ASSERT(CPhaseTable::getPhase(11) == CString(_T("112.50")));
	ASSERT(CPhaseTable::getPhase(12) == CString(_T("123.75")));
	ASSERT(CPhaseTable::getPhase(13) == CString(_T("135.00")));
	ASSERT(CPhaseTable::getPhase(14) == CString(_T("146.25")));
	ASSERT(CPhaseTable::getPhase(15) == CString(_T("157.50")));
	ASSERT(CPhaseTable::getPhase(16) == CString(_T("168.75")));
	ASSERT(CPhaseTable::getPhase(17) == CString(_T("180.00")));
	ASSERT(CPhaseTable::getPhase(18) == CString(_T("-168.75")));
	ASSERT(CPhaseTable::getPhase(19) == CString(_T("-157.50")));
	ASSERT(CPhaseTable::getPhase(20) == CString(_T("-146.25")));
	ASSERT(CPhaseTable::getPhase(21) == CString(_T("-135.00")));
	ASSERT(CPhaseTable::getPhase(22) == CString(_T("-123.75")));
	ASSERT(CPhaseTable::getPhase(23) == CString(_T("-112.50")));
	ASSERT(CPhaseTable::getPhase(24) == CString(_T("-101.25")));
	ASSERT(CPhaseTable::getPhase(25) == CString(_T("-90.00")));
	ASSERT(CPhaseTable::getPhase(26) == CString(_T("-78.75")));
	ASSERT(CPhaseTable::getPhase(27) == CString(_T("-67.50")));
	ASSERT(CPhaseTable::getPhase(28) == CString(_T("-56.25")));
	ASSERT(CPhaseTable::getPhase(29) == CString(_T("-45.00")));
	ASSERT(CPhaseTable::getPhase(30) == CString(_T("-33.75")));
	ASSERT(CPhaseTable::getPhase(31) == CString(_T("-22.50")));
	ASSERT(CPhaseTable::getPhase(32) == CString(_T("-11.25")));
	ASSERT(CPhaseTable::getPhase(-1) == CString(_T("undefined")));	//범위 밖의 값 입력시
	ASSERT(CPhaseTable::getPhase(33) == CString(_T("undefined")));	//범위 밖의 값 입력시

	ASSERT(CPhaseTable::byteBitReverse(0x1F) == 0xF8);		//0x1F(0001 1111) -> 0xF8(1111 1000)
	ASSERT(CPhaseTable::byteBitReverse(0x1A) == 0x58);		//0x1A(0001 1010) -> 0x58(0101 1000)
	ASSERT(CPhaseTable::byteBitReverse(0x9A) == 0x59);		//0x9A(1001 1010) -> 0x59(0101 1001)
	ASSERT(CPhaseTable::byteBitReverse(0x6B) == 0xD6);		//0x6B(0110 1011) -> 0xD6(0101 1001)

	ASSERT(CPhaseTable::reversePhaseBit(0x16) == 0xD);		//0x16(0001 0110) -> 0xD(0000 1101)
	ASSERT(CPhaseTable::reversePhaseBit(0x1F) == 0x1F);		//0x1F(0001 1111) -> 0x1F(0001 1111)
	ASSERT(CPhaseTable::reversePhaseBit(0x15) == 0x15);		//0x15(0001 0101) -> 0x15(0001 0101)
	ASSERT(CPhaseTable::reversePhaseBit(0xB) == 0x1A);		//0xB(0000 1011) -> 0x1A(0001 1010)
	ASSERT(CPhaseTable::reversePhaseBit(0x13) == 0x19);		//0x13(0001 0011) -> 0x19(0001 1001)

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
	GetDlgItem(IDC_TX_CH3_PHASE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH2_VSPS_BLOCK_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH2_PHASE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH1_VSPS_BLOCK_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH1_PHASE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH0_VSPS_BLOCK_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH0_PHASE_STATIC)->EnableWindow(b);
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
	GetDlgItem(IDC_TX_CH3_PHASE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH2_VSPS_BLOCK_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH2_PHASE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH1_VSPS_BLOCK_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH1_PHASE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH0_VSPS_BLOCK_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TX_CH0_PHASE_VALUE_STATIC)->EnableWindow(b);
}

const CRegister& CSemanticZing400T::Parse()
{
	UpdateTxReg1(m_pRawBase->m_strTxReg1Top, m_pRawBase->m_strTxReg1Mid, m_pRawBase->m_strTxReg1Bot, *m_pReg);
	UpdateTxReg2(m_pRawBase->m_strTxReg2Top, m_pRawBase->m_strTxReg2Mid, m_pRawBase->m_strTxReg2Bot, *m_pReg);

	CRawZing400T* pDeriv = dynamic_cast<CRawZing400T*>(m_pRawBase);
	ASSERT(pDeriv);

	UpdateRegOut24(pDeriv->m_strRegOut24, *m_pReg);

	CRegisterZing400T& regDeriv = dynamic_cast<CRegisterZing400T&>(*m_pReg);

	//Register값을 채우기 전에 Phase값은 Invalid 값으로 초기화, 업데이트 후에는 Invalid값이 없음을 ASSERT하여 값이 정상적으로 세팅된 것을 확인
	for(int i=0;i<4;i++) regDeriv.m_block[i].m_nPhase = -1;

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
	UpdateCh3Phase(derived);
	UpdateCh2VspsBlockEnable(derived);
	UpdateCh2Phase(derived);
	UpdateCh1VspsBlockEnable(derived);
	UpdateCh1Phase(derived);
	UpdateCh0VspsBlockEnable(derived);
	UpdateCh0Phase(derived);
	UpdateData(FALSE);
}

void CSemanticZing400T::ResetValues()
{
	m_strBiasBlockEnable.Empty();
	m_strVspsPaBiasVoltage.Empty();
	m_strVspsVgaBiasVoltage.Empty();
	m_strVspsCsBiasVoltage.Empty();
	for (int i = 0; i < 4; i++) {
		m_vspsBlock[i].m_strVspsBlockEnable.Empty();
		m_vspsBlock[i].m_strPhase.Empty();
	}
	CSemanticBase::ResetValues();
}

void CSemanticZing400T::SetSliderGroup(UINT ss, int min, int max, CString strCurVal, int ticFreq, int lineSize, int pageSize, UINT idcStatic, void(CSemanticBase::* pControl)(int, int, CString, int, int, int))
{
	CSemanticBase::SetSliderGroup(ss, min, max, strCurVal, ticFreq, lineSize, pageSize, idcStatic, pControl);
}

void CSemanticZing400T::ShowSlider(int nCmdShow)
{
	CSemanticBase::ShowSlider(nCmdShow);

	GetDlgItem(IDC_SLIDER_VALUE_PHASE_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_SLIDER_VALUE_I_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_SLIDER_VALUE_Q_STATIC)->ShowWindow(nCmdShow);
}

int CSemanticZing400T::SliderValueUpdate()
{
	if (m_selected == CSelect::Ch3Phase || m_selected == CSelect::Ch2Phase || m_selected == CSelect::Ch1Phase || m_selected == CSelect::Ch0Phase) {
		m_strSliderValuePhase.Format(_T("Phase: "));
		int curPos = SliderPos();
		m_strSliderValuePhase += CPhaseTable::getPhase(curPos);
		m_strSliderValueI.Format(_T("I: "));
		m_strSliderValueI += PhaseBitsToString(CPhaseTable::getI(curPos));
		m_strSliderValueQ = _T("Q: ");
		m_strSliderValueQ += PhaseBitsToString(CPhaseTable::getQ(curPos));
	}
	else {
		m_strSliderValuePhase = m_strSliderValueI = m_strSliderValueQ = CString(_T(""));	//Phase 관련 변수가 선택되지 않는 경우는 아무값도 표시하지 않음
	}
	return CSemanticBase::SliderValueUpdate();
}

void CSemanticZing400T::ControlSliderCommon(int min, int max, CString strCurVal, int ticFreq, int lineSize, int pageSize)
{
	CSemanticBase::ControlSliderCommon(min, max, strCurVal, ticFreq, lineSize, pageSize);
}

void CSemanticZing400T::SetControlSlider(int min, int max, CString strCurVal, int ticFreq, int lineSize, int pageSize)
{
	CSemanticBase::SetControlSlider(min, max, strCurVal, ticFreq, lineSize, pageSize);
}

void CSemanticZing400T::SetControlSliderForPhase(int min, int max, CString strCurVal, int ticFreq, int lineSize, int pageSize)
{
	CSemanticBase::SetControlSliderForPhase(min, max, strCurVal, ticFreq, lineSize, pageSize);
}

void CSemanticZing400T::OnBnClickedWriteButton()
{
	CSemanticBase::OnBnClickedWriteButton();
}

BOOL CSemanticZing400T::UpdateSelected(UINT selected, BOOL bCommonControl)
{
	BOOL bRtn = CSemanticBase::UpdateSelected(selected, bCommonControl);
	if (bRtn) return TRUE;

	int updateValue;
	switch (selected) {
		//ControlCombo
	case CSelect::BiasBlock:
		bCommonControl ? updateValue = ComboSel() : updateValue = BiasBlock();
		bRtn = UpdateSemanticValue(0x24, &OnNewBiasBlock, updateValue, &CSemanticBase::UpdateBiasBlockEnable);
		break;
	case CSelect::Ch3Block:
		bCommonControl ? updateValue = ComboSel() : updateValue = Ch3Block();
		bRtn = UpdateSemanticValue(0x26, &OnNewCh3Block, updateValue, reinterpret_cast<void (CSemanticBase::*)(const CRegister&)>(&CSemanticZing400T::UpdateCh3Block));
		break;
	case CSelect::Ch2Block:
		bCommonControl ? updateValue = ComboSel() : updateValue = Ch2Block();
		bRtn = UpdateSemanticValue(0x27, &OnNewCh2Block, updateValue, reinterpret_cast<void (CSemanticBase::*)(const CRegister&)>(&CSemanticZing400T::UpdateCh2Block));
		break;
	case CSelect::Ch1Block:
		bCommonControl ? updateValue = ComboSel() : updateValue = Ch1Block();
		bRtn = UpdateSemanticValue(0x29, &OnNewCh1Block, updateValue, reinterpret_cast<void (CSemanticBase::*)(const CRegister&)>(&CSemanticZing400T::UpdateCh1Block));
		break;
	case CSelect::Ch0Block:
		bCommonControl ? updateValue = ComboSel() : updateValue = Ch0Block();
		bRtn = UpdateSemanticValue(0x2A, &OnNewCh0Block, updateValue, reinterpret_cast<void (CSemanticBase::*)(const CRegister&)>(&CSemanticZing400T::UpdateCh0Block));
		break;

		//ControlSlide
	case CSelect::VspsPa:
		bCommonControl ? updateValue = SliderPos() : updateValue = VspsPa();
		bRtn = UpdateSemanticValue(0x25, &OnNewVspsPa, updateValue, reinterpret_cast<void (CSemanticBase::*)(const CRegister&)>(&CSemanticZing400T::UpdateVspsPa));
		break;
	case CSelect::VspsVga:
		bCommonControl ? updateValue = SliderPos() : updateValue = VspsVga();
		bRtn = UpdateSemanticValue(0x25, &OnNewVspsVga, updateValue, reinterpret_cast<void (CSemanticBase::*)(const CRegister&)>(&CSemanticZing400T::UpdateVspsVga));
		break;
	case CSelect::VspsCs:
		bCommonControl ? updateValue = SliderPos() : updateValue = VspsCs();
		bRtn = UpdateSemanticValue(0x26, &OnNewVspsCs, updateValue, reinterpret_cast<void (CSemanticBase::*)(const CRegister&)>(&CSemanticZing400T::UpdateVspsCs));
		break;
	case CSelect::Ch3Phase:
		bCommonControl ? updateValue = SliderPos() : updateValue = Ch3Phase();
		bRtn = UpdatePhaseValue(0x26, &OnNewCh3PhaseFirst, &OnNewCh3PhaseNext, updateValue, reinterpret_cast<void (CSemanticBase::*)(const CRegister&)>(&CSemanticZing400T::UpdateCh3PhaseIQ));
		break;
	case CSelect::Ch2Phase:
		bCommonControl ? updateValue = SliderPos() : updateValue = Ch2Phase();
		bRtn = UpdatePhaseValue(0x28, &OnNewCh2PhaseFirst, &OnNewCh2PhaseNext, updateValue, reinterpret_cast<void (CSemanticBase::*)(const CRegister&)>(&CSemanticZing400T::UpdateCh2PhaseIQ));
		break;
	case CSelect::Ch1Phase:
		bCommonControl ? updateValue = SliderPos() : updateValue = Ch1Phase();
		bRtn = UpdatePhaseValue(0x29, &OnNewCh1PhaseFirst, &OnNewCh1PhaseNext, updateValue, reinterpret_cast<void (CSemanticBase::*)(const CRegister&)>(&CSemanticZing400T::UpdateCh1PhaseIQ));
		break;
	case CSelect::Ch0Phase:
		bCommonControl ? updateValue = SliderPos() : updateValue = Ch0Phase();
		bRtn = UpdatePhaseValue(0x2A, &OnNewCh0PhaseFirst, &OnNewCh0PhaseNext, updateValue, reinterpret_cast<void (CSemanticBase::*)(const CRegister&)>(&CSemanticZing400T::UpdateCh0PhaseIQ));
		break;
	default:
		break;
	}
	return bRtn;
}

void CSemanticZing400T::OnBnClickedWriteAllButton()
{
	int errCnt = 0;
	CString str;
	for (std::map<UINT, CStaticElem>::iterator it = m_staticMap.begin(); it != m_staticMap.end(); ++it) {
		if (!UpdateSelected(it->first, FALSE)) {
			str.Format(_T("Update failed at SelectStatic:%d"), it->first);
			L(str);
			errCnt++;
		}
	}
	if (errCnt == 0)
		L(_T("All registers are updated"));
	else {
		str.Format(_T("%d Update failures"), errCnt);
		L(str);
	}
	OnBnClickedReadAllButton();
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

	unsigned int phaseBits = hexa & 0x07;
	unsigned int high = 0x00;	//Q_VGA3<3>,Q_VGA4<3>는 UpdateRegOut27에서 채워지는 공간으로 비워 놓는다
	unsigned int low = CPhaseTable::byteBitReverse(phaseBits) >> 5;

	reg.m_block[3].m_nQ = high | low;
}

void CSemanticZing400T::UpdateRegOut27(CString strRegOut27, CRegisterZing400T& reg)
{
	int hexa = _tcstol(strRegOut27.GetBuffer(), NULL, 16);

	unsigned int phaseBits = (hexa & 0xc0) >> 6;	//Q_VGA3<3>,Q_VGA4<3>
	reg.m_block[3].m_nQ = reg.m_block[3].m_nQ | (CPhaseTable::byteBitReverse(phaseBits) >> 3);

	phaseBits = (hexa & 0x3e) >> 1;
	reg.m_block[3].m_nI = CPhaseTable::reversePhaseBit(phaseBits);
	reg.m_block[2].m_nBlock = hexa & 0x1;
	reg.m_block[3].m_nPhase = CPhaseTable::getState((reg.m_block[3].m_nI) & 0x1f, (reg.m_block[3].m_nQ) & 0x1f);
}

void CSemanticZing400T::UpdateRegOut28(CString strRegOut28, CRegisterZing400T& reg)
{
	int hexa = _tcstol(strRegOut28.GetBuffer(), NULL, 16);

	unsigned int phaseBits = (hexa & 0xf8) >> 3;
	reg.m_block[2].m_nQ = CPhaseTable::reversePhaseBit(phaseBits);

	phaseBits = hexa & 0x07;
	int high = 0x00;	//I_VGA3<2>,I_VGA4<2>는 UpdateRegOut29에서 채워지는 공간으로 비워 놓는다
	int low = CPhaseTable::byteBitReverse(phaseBits) >> 5;
	reg.m_block[2].m_nI = high | low;
}

void CSemanticZing400T::UpdateRegOut29(CString strRegOut29, CRegisterZing400T& reg)
{
	int hexa = _tcstol(strRegOut29.GetBuffer(), NULL, 16);

	unsigned int phaseBits = (hexa & 0xc0) >> 6;
	int high = CPhaseTable::byteBitReverse(phaseBits) >> 3;
	reg.m_block[2].m_nI = high | reg.m_block[2].m_nI;

	reg.m_block[1].m_nQ = CPhaseTable::reversePhaseBit(hexa & 0x1f);
	reg.m_block[1].m_nBlock = (hexa & 0x20) >> 5;
	reg.m_block[2].m_nPhase = CPhaseTable::getState((reg.m_block[2].m_nI) & 0x1f, (reg.m_block[2].m_nQ) & 0x1f);
}

void CSemanticZing400T::UpdateRegOut2A(CString strRegOut2A, CRegisterZing400T& reg)
{
	int hexa = _tcstol(strRegOut2A.GetBuffer(), NULL, 16);

	unsigned int phaseBits = (hexa & 0xf8) >> 3;
	reg.m_block[1].m_nI = CPhaseTable::reversePhaseBit(phaseBits);

	reg.m_block[0].m_nBlock = (hexa & 0x04) >> 2;
	int high = 0x00;	//Q_VGA2<0>,Q_VGA3<0>,Q_VGA4<0>는 UpdateRegOut2B에서 채워지는 공간으로 비워 놓는다

	phaseBits = hexa & 0x3;
	int low = CPhaseTable::byteBitReverse(phaseBits) >> 6;
	reg.m_block[0].m_nQ = high | low;
	reg.m_block[1].m_nPhase = CPhaseTable::getState((reg.m_block[1].m_nI) & 0x1f, (reg.m_block[1].m_nQ) & 0x1f);
}

void CSemanticZing400T::UpdateRegOut2B(CString strRegOut2B, CRegisterZing400T& reg)
{
	int hexa = _tcstol(strRegOut2B.GetBuffer(), NULL, 16);

	unsigned int phaseBits = hexa & 0x1f;
	reg.m_block[0].m_nI = CPhaseTable::reversePhaseBit(phaseBits);

	phaseBits = (hexa & 0xe0) >> 5;
	int high = CPhaseTable::byteBitReverse(phaseBits) >> 3;
	reg.m_block[0].m_nQ = high | reg.m_block[0].m_nQ;
	reg.m_block[0].m_nPhase = CPhaseTable::getState((reg.m_block[0].m_nI) & 0x1f, (reg.m_block[0].m_nQ) & 0x1f);
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

void CSemanticZing400T::UpdateCh3Phase(const CRegisterZing400T& reg)
{
	if (reg.m_block[3].m_nPhase == -1) {
		m_vspsBlock[3].m_strPhase = CString(_T("undefined"));
	}
	else {
		m_vspsBlock[3].m_strPhase.Format(_T("%d / "), reg.m_block[3].m_nPhase);
		m_vspsBlock[3].m_strPhase += CPhaseTable::getPhase(reg.m_block[3].m_nPhase);
	}
}

void CSemanticZing400T::UpdateCh2VspsBlockEnable(const CRegisterZing400T& reg)
{
	(reg.m_block[2].m_nBlock) ? m_vspsBlock[2].m_strVspsBlockEnable.Format(_T("enable")) : m_vspsBlock[2].m_strVspsBlockEnable.Format(_T("disable"));
}

void CSemanticZing400T::UpdateCh2Phase(const CRegisterZing400T& reg)
{
	if (reg.m_block[2].m_nPhase == -1) {
		m_vspsBlock[2].m_strPhase = CString(_T("undefined"));
	}
	else {
		m_vspsBlock[2].m_strPhase.Format(_T("%d / "), reg.m_block[2].m_nPhase);
		m_vspsBlock[2].m_strPhase += CPhaseTable::getPhase(reg.m_block[2].m_nPhase);
	}
}

void CSemanticZing400T::UpdateCh1VspsBlockEnable(const CRegisterZing400T& reg)
{
	(reg.m_block[1].m_nBlock) ? m_vspsBlock[1].m_strVspsBlockEnable.Format(_T("enable")) : m_vspsBlock[1].m_strVspsBlockEnable.Format(_T("disable"));
}

void CSemanticZing400T::UpdateCh1Phase(const CRegisterZing400T& reg)
{
	if (reg.m_block[1].m_nPhase == -1) {
		m_vspsBlock[1].m_strPhase = CString(_T("undefined"));
	}
	else {
		m_vspsBlock[1].m_strPhase.Format(_T("%d / "), reg.m_block[1].m_nPhase);
		m_vspsBlock[1].m_strPhase += CPhaseTable::getPhase(reg.m_block[1].m_nPhase);
	}
}

void CSemanticZing400T::UpdateCh0VspsBlockEnable(const CRegisterZing400T& reg)
{
	(reg.m_block[0].m_nBlock) ? m_vspsBlock[0].m_strVspsBlockEnable.Format(_T("enable")) : m_vspsBlock[0].m_strVspsBlockEnable.Format(_T("disable"));
}

void CSemanticZing400T::UpdateCh0Phase(const CRegisterZing400T& reg)
{
	if (reg.m_block[0].m_nPhase == -1) {
		m_vspsBlock[0].m_strPhase = CString(_T("undefined"));
	}
	else {
		m_vspsBlock[0].m_strPhase.Format(_T("%d / "), reg.m_block[0].m_nPhase);
		m_vspsBlock[0].m_strPhase += CPhaseTable::getPhase(reg.m_block[0].m_nPhase);
	}
}

void CSemanticZing400T::OnStnClickedTxBiasBlockEnableValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetComboGroup(CSelect::BiasBlock, _T("disable"), _T("enable"), getRegister().m_nBiasBlock, IDC_TX_BIAS_BLOCK_ENABLE_STATIC);
}

void CSemanticZing400T::OnStnClickedTxVspsPaBiasVoltageValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(CSelect::VspsPa, 0, 15, m_strVspsPaBiasVoltage, 1, 1, 10, IDC_TX_VSPS_PA_BIAS_VOLTAGE_STATIC);
}


void CSemanticZing400T::OnStnClickedTxVspsVgaBiasVoltageValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(CSelect::VspsVga, 0, 15, m_strVspsVgaBiasVoltage, 1, 1, 10, IDC_TX_VSPS_VGA_BIAS_VOLTAGE_STATIC);
}


void CSemanticZing400T::OnStnClickedTxVspsCsBiasVoltageValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(CSelect::VspsCs, 0, 15, m_strVspsCsBiasVoltage, 1, 1, 10, IDC_TX_VSPS_CS_BIAS_VOLTAGE_STATIC);
}


void CSemanticZing400T::OnStnClickedTxCh3VspsBlockEnableValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	const CRegisterZing400T& derived = dynamic_cast<const CRegisterZing400T&>(getRegister());
	SetComboGroup(CSelect::Ch3Block, _T("disable"), _T("enable"), derived.m_block[3].m_nBlock, IDC_TX_CH3_VSPS_BLOCK_ENABLE_STATIC);
}


void CSemanticZing400T::OnStnClickedTxCh3PhaseValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(CSelect::Ch3Phase, 1, 32, m_vspsBlock[3].m_strPhase, 1, 1, 10, IDC_TX_CH3_PHASE_STATIC, &CSemanticBase::SetControlSliderForPhase);
}


void CSemanticZing400T::OnStnClickedTxCh2VspsBlockEnableValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	const CRegisterZing400T& derived = dynamic_cast<const CRegisterZing400T&>(getRegister());
	SetComboGroup(CSelect::Ch2Block, _T("disable"), _T("enable"), derived.m_block[2].m_nBlock, IDC_TX_CH2_VSPS_BLOCK_ENABLE_STATIC);
}


void CSemanticZing400T::OnStnClickedTxCh2PhaseValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(CSelect::Ch2Phase, 1, 32, m_vspsBlock[2].m_strPhase, 1, 1, 10, IDC_TX_CH2_PHASE_STATIC, &CSemanticBase::SetControlSliderForPhase);
}


void CSemanticZing400T::OnStnClickedTxCh1VspsBlockEnableValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	const CRegisterZing400T& derived = dynamic_cast<const CRegisterZing400T&>(getRegister());
	SetComboGroup(CSelect::Ch1Block, _T("disable"), _T("enable"), derived.m_block[1].m_nBlock, IDC_TX_CH1_VSPS_BLOCK_ENABLE_STATIC);
}


void CSemanticZing400T::OnStnClickedTxCh1PhaseValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(CSelect::Ch1Phase, 1, 32, m_vspsBlock[1].m_strPhase, 1, 1, 10, IDC_TX_CH1_PHASE_STATIC, &CSemanticBase::SetControlSliderForPhase);
}


void CSemanticZing400T::OnStnClickedTxCh0VspsBlockEnableValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	const CRegisterZing400T& derived = dynamic_cast<const CRegisterZing400T&>(getRegister());
	SetComboGroup(CSelect::Ch0Block, _T("disable"), _T("enable"), derived.m_block[0].m_nBlock, IDC_TX_CH0_VSPS_BLOCK_ENABLE_STATIC);
}


void CSemanticZing400T::OnStnClickedTxCh0PhaseValueStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetSliderGroup(CSelect::Ch0Phase, 1, 32, m_vspsBlock[0].m_strPhase, 1, 1, 10, IDC_TX_CH0_PHASE_STATIC, &CSemanticBase::SetControlSliderForPhase);
}

int CSemanticZing400T::Ch3Block()
{
	return disableOrEnable(m_vspsBlock[3].m_strVspsBlockEnable);
}

int CSemanticZing400T::OnNewCh3Block(int val, int newVal)
{
	return (val & 0xf7) | newVal << 3;
}

void CSemanticZing400T::UpdateCh3Block(const CRegister& reg)
{
	const CRegisterZing400T& derived = dynamic_cast<const CRegisterZing400T&>(reg);
	(derived.m_block[3].m_nBlock) ? m_vspsBlock[3].m_strVspsBlockEnable.Format(_T("enable")) : m_vspsBlock[3].m_strVspsBlockEnable.Format(_T("disable"));
}

int CSemanticZing400T::Ch2Block()
{
	return disableOrEnable(m_vspsBlock[2].m_strVspsBlockEnable);
}

int CSemanticZing400T::OnNewCh2Block(int val, int newVal)
{
	return (val & 0xfe) | (newVal&0x1);
}

void CSemanticZing400T::UpdateCh2Block(const CRegister& reg)
{
	const CRegisterZing400T& derived = dynamic_cast<const CRegisterZing400T&>(reg);
	(derived.m_block[2].m_nBlock) ? m_vspsBlock[2].m_strVspsBlockEnable.Format(_T("enable")) : m_vspsBlock[2].m_strVspsBlockEnable.Format(_T("disable"));
}

int CSemanticZing400T::Ch1Block()
{
	return disableOrEnable(m_vspsBlock[1].m_strVspsBlockEnable);
}

int CSemanticZing400T::OnNewCh1Block(int val, int newVal)
{
	return (val & 0xdf) | ((newVal & 0x1) << 5);
}

void CSemanticZing400T::UpdateCh1Block(const CRegister& reg)
{
	const CRegisterZing400T& derived = dynamic_cast<const CRegisterZing400T&>(reg);
	(derived.m_block[1].m_nBlock) ? m_vspsBlock[1].m_strVspsBlockEnable.Format(_T("enable")) : m_vspsBlock[1].m_strVspsBlockEnable.Format(_T("disable"));
}

int CSemanticZing400T::Ch0Block()
{
	return disableOrEnable(m_vspsBlock[0].m_strVspsBlockEnable);
}

int CSemanticZing400T::OnNewCh0Block(int val, int newVal)
{
	return (val & 0xfb) | ((newVal & 0x1) << 2);
}

void CSemanticZing400T::UpdateCh0Block(const CRegister& reg)
{
	const CRegisterZing400T& derived = dynamic_cast<const CRegisterZing400T&>(reg);
	(derived.m_block[0].m_nBlock) ? m_vspsBlock[0].m_strVspsBlockEnable.Format(_T("enable")) : m_vspsBlock[0].m_strVspsBlockEnable.Format(_T("disable"));
}

int CSemanticZing400T::VspsPa()
{
	int val = _tcstol(m_strVspsPaBiasVoltage.GetBuffer(), NULL, 16);
	ASSERT(val >= 0 && val <= 0xf);
	return val;
}

int CSemanticZing400T::OnNewVspsPa(int val, int newVal)
{
	return (val & 0x0f) | ((newVal & 0x0f) << 4);
}

void CSemanticZing400T::UpdateVspsPa(const CRegister& reg)
{
	const CRegisterZing400T& derived = dynamic_cast<const CRegisterZing400T&>(reg);
	m_strVspsPaBiasVoltage.Format(_T("0x%02x"), derived.m_nVspsPa);
}

int CSemanticZing400T::VspsVga()
{
	int val = _tcstol(m_strVspsVgaBiasVoltage.GetBuffer(), NULL, 16);
	ASSERT(val >= 0 && val <= 0xf);
	return val;
}

int CSemanticZing400T::OnNewVspsVga(int val, int newVal)
{
	return (val & 0xf0) | (newVal & 0x0f);
}

void CSemanticZing400T::UpdateVspsVga(const CRegister& reg)
{
	const CRegisterZing400T& derived = dynamic_cast<const CRegisterZing400T&>(reg);
	m_strVspsVgaBiasVoltage.Format(_T("0x%02x"), derived.m_nVspsVga);
}

int CSemanticZing400T::VspsCs()
{
	int val = _tcstol(m_strVspsCsBiasVoltage.GetBuffer(), NULL, 16);
	ASSERT(val >= 0 && val <= 0xf);
	return val;
}

int CSemanticZing400T::OnNewVspsCs(int val, int newVal)
{
	return (val & 0x0f) | ((newVal & 0x0f) << 4);
}

void CSemanticZing400T::UpdateVspsCs(const CRegister& reg)
{
	const CRegisterZing400T& derived = dynamic_cast<const CRegisterZing400T&>(reg);
	m_strVspsCsBiasVoltage.Format(_T("0x%02x"), derived.m_nVspsCs);
}

int CSemanticZing400T::Ch3Phase()
{
	CString strPhaseState;
	AfxExtractSubString(strPhaseState, m_vspsBlock[3].m_strPhase, 0, '/');
	int val = _tcstol(strPhaseState.GetBuffer(), NULL, 10);	//"undefined"인 경우 val값은 0
	return val;
}

int CSemanticZing400T::OnNewCh3PhaseFirst(int val, int newVal)
{
	unsigned char q = CPhaseTable::reversePhaseBit(CPhaseTable::getQ(newVal));
	ASSERT((q & 0xe0) == 0);	//Q Phase비트는 반드시 5비트이어야 함
	return (val & 0xf8) | ((q & 0x1c) >> 2);
}

int CSemanticZing400T::OnNewCh3PhaseNext(int val, int newVal)
{
	unsigned char q = CPhaseTable::reversePhaseBit(CPhaseTable::getQ(newVal));
	unsigned char i = CPhaseTable::reversePhaseBit(CPhaseTable::getI(newVal));
	ASSERT((q & 0xe0) == 0);	//Q Phase비트는 반드시 5비트이어야 함
	ASSERT((i & 0xe0) == 0);	//I Phase비트는 반드시 5비트이어야 함
	return (val & 0x01) | ((q & 0x3) << 6) | (i << 1);
}

void CSemanticZing400T::UpdateCh3PhaseIQ(const CRegister& reg)
{
	const CRegisterZing400T& derived = dynamic_cast<const CRegisterZing400T&>(reg);
	m_vspsBlock[3].m_strPhase.Format(_T("%d / "), derived.m_block[3].m_nPhase);
	m_vspsBlock[3].m_strPhase += CPhaseTable::getPhase(derived.m_block[3].m_nPhase);
}

int CSemanticZing400T::Ch2Phase()
{
	CString strPhaseState;
	AfxExtractSubString(strPhaseState, m_vspsBlock[2].m_strPhase, 0, '/');
	int val = _tcstol(strPhaseState.GetBuffer(), NULL, 10);	//"undefined"인 경우 val값은 0
	return val;
}

int CSemanticZing400T::OnNewCh2PhaseFirst(int val, int newVal)
{
	unsigned char q = CPhaseTable::reversePhaseBit(CPhaseTable::getQ(newVal));
	unsigned char i = CPhaseTable::reversePhaseBit(CPhaseTable::getI(newVal));
	ASSERT((q & 0xe0) == 0);	//Q Phase비트는 반드시 5비트이어야 함
	ASSERT((i & 0xe0) == 0);	//I Phase비트는 반드시 5비트이어야 함
	return (q << 3) | ((i & 0x1c) >> 2);
}

int CSemanticZing400T::OnNewCh2PhaseNext(int val, int newVal)
{
	unsigned char i = CPhaseTable::reversePhaseBit(CPhaseTable::getI(newVal));
	ASSERT((i & 0xe0) == 0);	//I Phase비트는 반드시 5비트이어야 함
	return (val & 0x3f) | ((i & 0x3) << 6);
}

void CSemanticZing400T::UpdateCh2PhaseIQ(const CRegister& reg)
{
	const CRegisterZing400T& derived = dynamic_cast<const CRegisterZing400T&>(reg);
	m_vspsBlock[2].m_strPhase.Format(_T("%d / "), derived.m_block[2].m_nPhase);
	m_vspsBlock[2].m_strPhase += CPhaseTable::getPhase(derived.m_block[2].m_nPhase);
}

int CSemanticZing400T::Ch1Phase()
{
	CString strPhaseState;
	AfxExtractSubString(strPhaseState, m_vspsBlock[1].m_strPhase, 0, '/');
	int val = _tcstol(strPhaseState.GetBuffer(), NULL, 10);	//"undefined"인 경우 val값은 0
	return val;
}

int CSemanticZing400T::OnNewCh1PhaseFirst(int val, int newVal)
{
	unsigned char q = CPhaseTable::reversePhaseBit(CPhaseTable::getQ(newVal));
	ASSERT((q & 0xe0) == 0);	//Q Phase비트는 반드시 5비트이어야 함
	return (val & 0xe0) | q;
}

int CSemanticZing400T::OnNewCh1PhaseNext(int val, int newVal)
{
	unsigned char i = CPhaseTable::reversePhaseBit(CPhaseTable::getI(newVal));
	ASSERT((i & 0xe0) == 0);	//I Phase비트는 반드시 5비트이어야 함
	return (val & 0x7) | (i << 3);
}

void CSemanticZing400T::UpdateCh1PhaseIQ(const CRegister& reg)
{
	const CRegisterZing400T& derived = dynamic_cast<const CRegisterZing400T&>(reg);
	m_vspsBlock[1].m_strPhase.Format(_T("%d / "), derived.m_block[1].m_nPhase);
	m_vspsBlock[1].m_strPhase += CPhaseTable::getPhase(derived.m_block[1].m_nPhase);
}

int CSemanticZing400T::Ch0Phase()
{
	CString strPhaseState;
	AfxExtractSubString(strPhaseState, m_vspsBlock[0].m_strPhase, 0, '/');
	int val = _tcstol(strPhaseState.GetBuffer(), NULL, 10);	//"undefined"인 경우 val값은 0
	return val;
}

int CSemanticZing400T::OnNewCh0PhaseFirst(int val, int newVal)
{
	unsigned char q = CPhaseTable::reversePhaseBit(CPhaseTable::getQ(newVal));
	ASSERT((q & 0xe0) == 0);	//Q Phase비트는 반드시 5비트이어야 함
	return (val & 0xfc) | ((q & 0x18) >> 3);
}

int CSemanticZing400T::OnNewCh0PhaseNext(int val, int newVal)
{
	unsigned char q = CPhaseTable::reversePhaseBit(CPhaseTable::getQ(newVal));
	unsigned char i = CPhaseTable::reversePhaseBit(CPhaseTable::getI(newVal));
	ASSERT((q & 0xe0) == 0);	//Q Phase비트는 반드시 5비트이어야 함
	ASSERT((i & 0xe0) == 0);	//I Phase비트는 반드시 5비트이어야 함
	return ((q & 0x7) << 5) | i;
}

void CSemanticZing400T::UpdateCh0PhaseIQ(const CRegister& reg)
{
	const CRegisterZing400T& derived = dynamic_cast<const CRegisterZing400T&>(reg);
	m_vspsBlock[0].m_strPhase.Format(_T("%d / "), derived.m_block[0].m_nPhase);
	m_vspsBlock[0].m_strPhase += CPhaseTable::getPhase(derived.m_block[0].m_nPhase);
}