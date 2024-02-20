// CSemanticZing400R.cpp: 구현 파일
//

#include "pch.h"
#include "gZeroMaster.h"
#include "CSemanticZing400R.h"
#include "CRawBase.h"


// CSemanticZing400R 대화 상자

IMPLEMENT_DYNAMIC(CSemanticZing400R, CSemanticBase)

CSemanticZing400R::CSemanticZing400R(CWnd* pParent, CRawBase* pRawBase)
	: CSemanticBase(pParent, pRawBase)
{
	m_staticMap.clear();
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::RefStage, CStaticElem(IDC_DEMOD_REF_STAGE_CURRENT_VALUE_STATIC, &m_reg.m_nDemodRefStageCur, m_strDemodRefStageCurrent)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::IpStage, CStaticElem(IDC_DEMOD_IP_STAGE_CURRENT_VALUE_STATIC, &m_reg.m_nDemodIPStageCur, m_strDemodIPStageCurrent)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::Fb, CStaticElem(IDC_LA_FB_CURRENT_VALUE_STATIC, &m_reg.m_nLaFBCur, m_strLaFBCurrent)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::Core, CStaticElem(IDC_LA_CORE_CURRENT_VALUE_STATIC, &m_reg.m_nLaCoreCur, m_strLaCoreCurrent)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::OP, CStaticElem(IDC_LA_OP_BUFFER_CURRENT_VALUE_STATIC, &m_reg.m_nLaOPBufCur, m_strLaOPBufferCurrent)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::IP, CStaticElem(IDC_LA_IP_BUFFER_CURRENT_VALUE_STATIC, &m_reg.m_nLaIPBufCur, m_strLaIPBufferCurrent)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::HL, CStaticElem(IDC_LA_HL_DATA_RATE_CURRENT_VALUE_STATIC, &m_reg.m_nLaHLDataRateCur, m_strLaHLDataRateCurrent)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::CMOS, CStaticElem(IDC_CMOS_GAIN_STAGE_CURRENT_VALUE_STATIC, &m_reg.m_nCMOSGainStageCur, m_strCMOSGainStageCurrent)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::CML, CStaticElem(IDC_CML_INTERFACE_STAGE_CURRENT_VALUE_STATIC, &m_reg.m_nCMLInterfaceStageCur, m_strCMLInterfaceStageCurrent)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::RxData, CStaticElem(IDC_RX_DATA_IF_ENABLE_VALUE_STATIC, &m_reg.m_nRxData, m_strRxDataInterface)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::LimAmp, CStaticElem(IDC_LIMITING_AMP_ENABLE_VALUE_STATIC, &m_reg.m_nLimitAmp, m_strLimitingAmplifier)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::BiasBlock, CStaticElem(IDC_BIAS_BLOCK_ENABLE_VALUE_STATIC, &m_reg.m_nBiasBlock, m_strBiasBlockEnable)));
}

CSemanticZing400R::~CSemanticZing400R()
{
}

void CSemanticZing400R::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RX_DATA_IF_ENABLE_VALUE_STATIC, m_strRxDataInterface);
	DDX_Text(pDX, IDC_LIMITING_AMP_ENABLE_VALUE_STATIC, m_strLimitingAmplifier);
	DDX_Text(pDX, IDC_BIAS_BLOCK_ENABLE_VALUE_STATIC, m_strBiasBlockEnable);
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
	DDX_Control(pDX, IDC_CONTROL_COMBO, m_controlCombo);
	DDX_Check(pDX, IDC_AUTO_WRITE_CHECK, m_bAutoWrite);
}


BEGIN_MESSAGE_MAP(CSemanticZing400R, CSemanticBase)
	ON_BN_CLICKED(IDC_SEMANTIC_EDIT_CHECK, &OnBnClickedSemanticEditCheck)
	ON_WM_CTLCOLOR()
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_READ_ALL_BUTTON, &OnBnClickedReadAllButton)
	ON_CBN_SELCHANGE(IDC_CONTROL_COMBO, &OnCbnSelchangeControlCombo)
	ON_BN_CLICKED(IDC_WRITE_BUTTON, &OnBnClickedWriteButton)
	ON_BN_CLICKED(IDC_DEFAULT_VALUE_BUTTON, &OnBnClickedDefaultValueButton)
	ON_BN_CLICKED(IDC_WRITE_ALL_BUTTON, &OnBnClickedWriteAllButton)
	ON_BN_CLICKED(IDC_AUTO_WRITE_CHECK, &OnBnClickedAutoWriteCheck)
	ON_STN_CLICKED(IDC_LNA_GAIN_VALUE_STATIC, &OnStnClickedLnaGainValueStatic)
	ON_STN_CLICKED(IDC_DEMOD_REF_STAGE_CURRENT_VALUE_STATIC, &OnStnClickedDemodRefStageCurrentValueStatic)
	ON_STN_CLICKED(IDC_DEMOD_IP_STAGE_CURRENT_VALUE_STATIC, &OnStnClickedDemodIpStageCurrentValueStatic)
	ON_STN_CLICKED(IDC_LA_FB_CURRENT_VALUE_STATIC, &OnStnClickedLaFbCurrentValueStatic)
	ON_STN_CLICKED(IDC_LA_CORE_CURRENT_VALUE_STATIC, &OnStnClickedLaCoreCurrentValueStatic)
	ON_STN_CLICKED(IDC_LA_OP_BUFFER_CURRENT_VALUE_STATIC, &OnStnClickedLaOpBufferCurrentValueStatic)
	ON_STN_CLICKED(IDC_LA_IP_BUFFER_CURRENT_VALUE_STATIC, &OnStnClickedLaIpBufferCurrentValueStatic)
	ON_STN_CLICKED(IDC_LA_HL_DATA_RATE_CURRENT_VALUE_STATIC, &OnStnClickedLaHlDataRateCurrentValueStatic)
	ON_STN_CLICKED(IDC_CMOS_GAIN_STAGE_CURRENT_VALUE_STATIC, &OnStnClickedCmosGainStageCurrentValueStatic)
	ON_STN_CLICKED(IDC_CML_INTERFACE_STAGE_CURRENT_VALUE_STATIC, &OnStnClickedCmlInterfaceStageCurrentValueStatic)
	ON_STN_CLICKED(IDC_RX_DATA_IF_ENABLE_VALUE_STATIC, &OnStnClickedRxDataIfEnableValueStatic)
	ON_STN_CLICKED(IDC_LIMITING_AMP_ENABLE_VALUE_STATIC, &OnStnClickedLimitingAmpEnableValueStatic)
	ON_STN_CLICKED(IDC_BIAS_BLOCK_ENABLE_VALUE_STATIC, &OnStnClickedBiasBlockEnableValueStatic)
END_MESSAGE_MAP()


// CSemanticZing400R 메시지 처리기


BOOL CSemanticZing400R::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	InitialControlState();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CSemanticZing400R::OnChipConnect(CString chipModel)
{
	ASSERT(chipModel == _T("Zing400R"));
}


void CSemanticZing400R::ControlLabelEnable(BOOL b)
{
	GetDlgItem(IDC_RX_DATA_IF_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LIMITING_AMP_ENABLE_STATIC)->EnableWindow(b);

	GetDlgItem(IDC_BIAS_BLOCK_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_DEMOD_REF_STAGE_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_DEMOD_IP_STAGE_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_FB_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_CORE_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_OP_BUFFER_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_IP_BUFFER_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_HL_DATA_RATE_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_CMOS_GAIN_STAGE_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_CML_INTERFACE_STAGE_CURRENT_STATIC)->EnableWindow(b);

	GetDlgItem(IDC_RX_CH3_VSPS_BLOCK_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH3_Q_VSPS_PHASE_CONTROL_BIT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH3_I_VSPS_PHASE_CONTROL_BIT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH2_VSPS_BLOCK_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH2_Q_VSPS_PHASE_CONTROL_BIT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH2_I_VSPS_PHASE_CONTROL_BIT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH1_VSPS_BLOCK_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH1_Q_VSPS_PHASE_CONTROL_BIT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH1_I_VSPS_PHASE_CONTROL_BIT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH0_VSPS_BLOCK_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH0_Q_VSPS_PHASE_CONTROL_BIT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH0_I_VSPS_PHASE_CONTROL_BIT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_VSPS_BIAS_CONTROL_BIT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_LNA_BIAS_CONTROL_BIT_STATIC)->EnableWindow(b);
}

void CSemanticZing400R::ControlValueEnable(BOOL b)
{
	GetDlgItem(IDC_RX_DATA_IF_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LIMITING_AMP_ENABLE_VALUE_STATIC)->EnableWindow(b);

	GetDlgItem(IDC_BIAS_BLOCK_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_DEMOD_REF_STAGE_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_DEMOD_IP_STAGE_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_FB_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_CORE_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_OP_BUFFER_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_IP_BUFFER_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_HL_DATA_RATE_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_CMOS_GAIN_STAGE_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_CML_INTERFACE_STAGE_CURRENT_VALUE_STATIC)->EnableWindow(b);

	GetDlgItem(IDC_RX_CH3_VSPS_BLOCK_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH3_Q_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH3_I_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH2_VSPS_BLOCK_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH2_Q_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH2_I_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH1_VSPS_BLOCK_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH1_Q_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH1_I_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH0_VSPS_BLOCK_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH0_Q_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH0_I_VSPS_PHASE_CONTROL_BIT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_VSPS_BIAS_CONTROL_BIT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_LNA_BIAS_CONTROL_BIT_VALUE_STATIC)->EnableWindow(b);
}

const CRegister& CSemanticZing400R::Parse()
{
	UpdateRxReg1(m_pRawBase->m_strRxReg1, m_reg);
	UpdateBiasReg1(m_pRawBase->m_strBiasReg1, m_reg);
	UpdateBiasReg2(m_pRawBase->m_strBiasReg2, m_reg);
	UpdateBiasReg3(m_pRawBase->m_strBiasReg3, m_reg);
	UpdateBiasReg4(m_pRawBase->m_strBiasReg4, m_reg);
	UpdateBiasReg5(m_pRawBase->m_strBiasReg5, m_reg);
	UpdateBiasReg6(m_pRawBase->m_strBiasReg6, m_reg);
	UpdateBiasReg7(m_pRawBase->m_strBiasReg7, m_reg);
	UpdateBiasReg8(m_pRawBase->m_strBiasReg8, m_reg);
	return m_reg;
}

void CSemanticZing400R::UpdateRegisters()
{
	CSemanticBase::UpdateRegisters();
}

void CSemanticZing400R::UpdateRxReg1(CString strRxReg1, CRegister& reg)
{
	int val = _tcstol(strRxReg1.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nRxData = (val & 0x10) >> 4;
	reg.m_nLimitAmp = (val & 0x08) >> 3;
}