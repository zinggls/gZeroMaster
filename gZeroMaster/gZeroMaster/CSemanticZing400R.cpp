// CSemanticZing400R.cpp: ���� ����
//

#include "pch.h"
#include "gZeroMaster.h"
#include "CSemanticZing400R.h"
#include "CRawZing400R.h"
#include "CRegisterZing400R.h"
#include "CPhaseTable.h"


// CSemanticZing400R ��ȭ ����

IMPLEMENT_DYNAMIC(CSemanticZing400R, CSemanticBase)

CSemanticZing400R::CSemanticZing400R(CWnd* pParent, CRawBase* pRawBase, CRegister* pReg)
	: CSemanticBase(pParent, pRawBase, pReg)
{
	ASSERT(pReg == m_pReg);

	m_staticMap.clear();
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::RefStage, CStaticElem(IDC_DEMOD_REF_STAGE_CURRENT_VALUE_STATIC, &m_pReg->m_nDemodRefStageCur, m_strDemodRefStageCurrent)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::IpStage, CStaticElem(IDC_DEMOD_IP_STAGE_CURRENT_VALUE_STATIC, &m_pReg->m_nDemodIPStageCur, m_strDemodIPStageCurrent)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Fb, CStaticElem(IDC_LA_FB_CURRENT_VALUE_STATIC, &m_pReg->m_nLaFBCur, m_strLaFBCurrent)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Core, CStaticElem(IDC_LA_CORE_CURRENT_VALUE_STATIC, &m_pReg->m_nLaCoreCur, m_strLaCoreCurrent)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::OP, CStaticElem(IDC_LA_OP_BUFFER_CURRENT_VALUE_STATIC, &m_pReg->m_nLaOPBufCur, m_strLaOPBufferCurrent)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::IP, CStaticElem(IDC_LA_IP_BUFFER_CURRENT_VALUE_STATIC, &m_pReg->m_nLaIPBufCur, m_strLaIPBufferCurrent)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::HL, CStaticElem(IDC_LA_HL_DATA_RATE_CURRENT_VALUE_STATIC, &m_pReg->m_nLaHLDataRateCur, m_strLaHLDataRateCurrent)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::CMOS, CStaticElem(IDC_CMOS_GAIN_STAGE_CURRENT_VALUE_STATIC, &m_pReg->m_nCMOSGainStageCur, m_strCMOSGainStageCurrent)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::CML, CStaticElem(IDC_CML_INTERFACE_STAGE_CURRENT_VALUE_STATIC, &m_pReg->m_nCMLInterfaceStageCur, m_strCMLInterfaceStageCurrent)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::RxData, CStaticElem(IDC_RX_DATA_IF_ENABLE_VALUE_STATIC, &m_pReg->m_nRxData, m_strRxDataInterface)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::LimAmp, CStaticElem(IDC_LIMITING_AMP_ENABLE_VALUE_STATIC, &m_pReg->m_nLimitAmp, m_strLimitingAmplifier)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::BiasBlock, CStaticElem(IDC_BIAS_BLOCK_ENABLE_VALUE_STATIC, &m_pReg->m_nBiasBlock, m_strBiasBlockEnable)));

	CRegisterZing400R* pDerived = dynamic_cast<CRegisterZing400R*>(pReg);
	ASSERT(pDerived);
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch3Block, CStaticElem(IDC_RX_CH3_VSPS_BLOCK_ENABLE_VALUE_STATIC, &pDerived->m_block[3].m_nBlock, m_vspsBlock[3].m_strVspsBlockEnable)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch3Phase, CStaticElem(IDC_RX_CH3_PHASE_VALUE_STATIC, &pDerived->m_block[3].m_nPhase, m_vspsBlock[3].m_strPhase)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch2Block, CStaticElem(IDC_RX_CH2_VSPS_BLOCK_ENABLE_VALUE_STATIC, &pDerived->m_block[2].m_nBlock, m_vspsBlock[2].m_strVspsBlockEnable)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch2Phase, CStaticElem(IDC_RX_CH2_PHASE_VALUE_STATIC, &pDerived->m_block[2].m_nPhase, m_vspsBlock[2].m_strPhase)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch1Block, CStaticElem(IDC_RX_CH1_VSPS_BLOCK_ENABLE_VALUE_STATIC, &pDerived->m_block[1].m_nBlock, m_vspsBlock[1].m_strVspsBlockEnable)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch1Phase, CStaticElem(IDC_RX_CH1_PHASE_VALUE_STATIC, &pDerived->m_block[1].m_nPhase, m_vspsBlock[1].m_strPhase)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch0Block, CStaticElem(IDC_RX_CH0_VSPS_BLOCK_ENABLE_VALUE_STATIC, &pDerived->m_block[0].m_nBlock, m_vspsBlock[0].m_strVspsBlockEnable)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::Ch0Phase, CStaticElem(IDC_RX_CH0_PHASE_VALUE_STATIC, &pDerived->m_block[0].m_nPhase, m_vspsBlock[0].m_strPhase)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::VspsBias, CStaticElem(IDC_RX_VSPS_BIAS_CONTROL_BIT_VALUE_STATIC, &pDerived->m_nVspsBias, m_strVspsBiasControlBit)));
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::LnaBias, CStaticElem(IDC_RX_LNA_BIAS_CONTROL_BIT_VALUE_STATIC, &pDerived->m_nLnaBias, m_strLnaControlBit)));
}

CSemanticZing400R::~CSemanticZing400R()
{
	delete m_pReg;
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
	DDX_Text(pDX, IDC_RX_CH3_VSPS_BLOCK_ENABLE_VALUE_STATIC, m_vspsBlock[3].m_strVspsBlockEnable);
	DDX_Text(pDX, IDC_RX_CH3_PHASE_VALUE_STATIC, m_vspsBlock[3].m_strPhase);
	DDX_Text(pDX, IDC_CH3_VALUE_STATIC, m_vspsBlock[3].m_strPhase);
	DDX_Text(pDX, IDC_RX_CH2_VSPS_BLOCK_ENABLE_VALUE_STATIC, m_vspsBlock[2].m_strVspsBlockEnable);
	DDX_Text(pDX, IDC_RX_CH2_PHASE_VALUE_STATIC, m_vspsBlock[2].m_strPhase);
	DDX_Text(pDX, IDC_CH2_VALUE_STATIC, m_vspsBlock[2].m_strPhase);
	DDX_Text(pDX, IDC_RX_CH1_VSPS_BLOCK_ENABLE_VALUE_STATIC, m_vspsBlock[1].m_strVspsBlockEnable);
	DDX_Text(pDX, IDC_RX_CH1_PHASE_VALUE_STATIC, m_vspsBlock[1].m_strPhase);
	DDX_Text(pDX, IDC_CH1_VALUE_STATIC, m_vspsBlock[1].m_strPhase);
	DDX_Text(pDX, IDC_RX_CH0_VSPS_BLOCK_ENABLE_VALUE_STATIC, m_vspsBlock[0].m_strVspsBlockEnable);
	DDX_Text(pDX, IDC_RX_CH0_PHASE_VALUE_STATIC, m_vspsBlock[0].m_strPhase);
	DDX_Text(pDX, IDC_CH0_VALUE_STATIC, m_vspsBlock[0].m_strPhase);
	DDX_Text(pDX, IDC_RX_VSPS_BIAS_CONTROL_BIT_VALUE_STATIC, m_strVspsBiasControlBit);
	DDX_Text(pDX, IDC_RX_LNA_BIAS_CONTROL_BIT_VALUE_STATIC, m_strLnaControlBit);
	DDX_Control(pDX, IDC_CONTROL_SLIDER, m_controlSlider);
	DDX_Check(pDX, IDC_SEMANTIC_EDIT_CHECK, m_bSemanticEdit);
	DDX_Text(pDX, IDC_SELECTED_STATIC, m_strSelectedStatic);
	DDX_Text(pDX, IDC_SLIDER_MIN_STATIC, m_strSliderMin);
	DDX_Text(pDX, IDC_SLIDER_MAX_STATIC, m_strSliderMax);
	DDX_Text(pDX, IDC_SLIDER_VALUE_STATIC, m_strSliderValue);
	DDX_Text(pDX, IDC_SLIDER_VALUE_HEX_STATIC, m_strSliderValueHex);
	DDX_Text(pDX, IDC_SLIDER_VALUE_BIN_STATIC, m_strSliderValueBin);
	DDX_Text(pDX, IDC_RX_SLIDER_VALUE_PHASE_STATIC, m_strSliderValuePhase);
	DDX_Text(pDX, IDC_RX_SLIDER_VALUE_I_STATIC, m_strSliderValueI);
	DDX_Text(pDX, IDC_RX_SLIDER_VALUE_Q_STATIC, m_strSliderValueQ);
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
	ON_STN_CLICKED(IDC_RX_CH3_VSPS_BLOCK_ENABLE_VALUE_STATIC, &CSemanticZing400R::OnStnClickedRxCh3VspsBlockEnableValueStatic)
	ON_STN_CLICKED(IDC_RX_CH3_PHASE_VALUE_STATIC, &CSemanticZing400R::OnStnClickedRxCh3PhaseValueStatic)
	ON_STN_CLICKED(IDC_RX_CH2_VSPS_BLOCK_ENABLE_VALUE_STATIC, &CSemanticZing400R::OnStnClickedRxCh2VspsBlockEnableValueStatic)
	ON_STN_CLICKED(IDC_RX_CH2_PHASE_VALUE_STATIC, &CSemanticZing400R::OnStnClickedRxCh2PhaseValueStatic)
	ON_STN_CLICKED(IDC_RX_CH1_VSPS_BLOCK_ENABLE_VALUE_STATIC, &CSemanticZing400R::OnStnClickedRxCh1VspsBlockEnableValueStatic)
	ON_STN_CLICKED(IDC_RX_CH1_PHASE_VALUE_STATIC, &CSemanticZing400R::OnStnClickedRxCh1PhaseValueStatic)
	ON_STN_CLICKED(IDC_RX_CH0_VSPS_BLOCK_ENABLE_VALUE_STATIC, &CSemanticZing400R::OnStnClickedRxCh0VspsBlockEnableValueStatic)
	ON_STN_CLICKED(IDC_RX_CH0_PHASE_VALUE_STATIC, &CSemanticZing400R::OnStnClickedRxCh0PhaseValueStatic)
	ON_STN_CLICKED(IDC_RX_VSPS_BIAS_CONTROL_BIT_VALUE_STATIC, &OnStnClickedRxVspsBiasControlBitValueStatic)
	ON_STN_CLICKED(IDC_RX_LNA_BIAS_CONTROL_BIT_VALUE_STATIC, &OnStnClickedRxLnaBiasControlBitValueStatic)
	ON_MESSAGE(UDM_SEM_CH3_VSPS_BLOCK_ENABLE_CLICK, OnSemCh3VspsBlockEnableClick)
	ON_MESSAGE(UDM_SEM_CH3_PHASE_CLICK, OnSemCh3PhaseClick)
	ON_MESSAGE(UDM_SEM_CH2_VSPS_BLOCK_ENABLE_CLICK, OnSemCh2VspsBlockEnableClick)
	ON_MESSAGE(UDM_SEM_CH2_PHASE_CLICK, OnSemCh2PhaseClick)
	ON_MESSAGE(UDM_SEM_CH1_VSPS_BLOCK_ENABLE_CLICK, OnSemCh1VspsBlockEnableClick)
	ON_MESSAGE(UDM_SEM_CH1_PHASE_CLICK, OnSemCh1PhaseClick)
	ON_MESSAGE(UDM_SEM_CH0_VSPS_BLOCK_ENABLE_CLICK, OnSemCh0VspsBlockEnableClick)
	ON_MESSAGE(UDM_SEM_CH0_PHASE_CLICK, OnSemCh0PhaseClick)
	ON_MESSAGE(UDM_SEM_VSPS_BIAS_CONTROL_BIT_CLIC, OnSemVspsBiasControlBitClick)
	ON_MESSAGE(UDM_SEM_LNA_BIAS_CONTROL_BIT_CLICK, OnSemLnaBiasControlBitClick)
END_MESSAGE_MAP()


// CSemanticZing400R �޽��� ó����


BOOL CSemanticZing400R::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	InitialControlState();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
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
	GetDlgItem(IDC_RX_CH3_PHASE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH2_VSPS_BLOCK_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH2_PHASE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH1_VSPS_BLOCK_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH1_PHASE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH0_VSPS_BLOCK_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH0_PHASE_STATIC)->EnableWindow(b);
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
	GetDlgItem(IDC_RX_CH3_PHASE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH2_VSPS_BLOCK_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH2_PHASE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH1_VSPS_BLOCK_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH1_PHASE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH0_VSPS_BLOCK_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH0_PHASE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_VSPS_BIAS_CONTROL_BIT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_LNA_BIAS_CONTROL_BIT_VALUE_STATIC)->EnableWindow(b);
}

const CRegister& CSemanticZing400R::Parse()
{
	UpdateRxReg1(m_pRawBase->m_strRxReg1, *m_pReg);
	UpdateBiasReg1(m_pRawBase->m_strBiasReg1, *m_pReg);
	UpdateBiasReg2(m_pRawBase->m_strBiasReg2, *m_pReg);
	UpdateBiasReg3(m_pRawBase->m_strBiasReg3, *m_pReg);
	UpdateBiasReg4(m_pRawBase->m_strBiasReg4, *m_pReg);
	UpdateBiasReg5(m_pRawBase->m_strBiasReg5, *m_pReg);
	UpdateBiasReg6(m_pRawBase->m_strBiasReg6, *m_pReg);
	UpdateBiasReg7(m_pRawBase->m_strBiasReg7, *m_pReg);
	UpdateBiasReg8(m_pRawBase->m_strBiasReg8, *m_pReg);

	CRawZing400R* pDeriv = dynamic_cast<CRawZing400R*>(m_pRawBase);
	ASSERT(pDeriv);

	CRegisterZing400R& regDeriv = dynamic_cast<CRegisterZing400R&>(*m_pReg);
	UpdateRegOut26(pDeriv->m_strRegOut26, regDeriv);
	UpdateRegOut27(pDeriv->m_strRegOut27, regDeriv);
	UpdateRegOut28(pDeriv->m_strRegOut28, regDeriv);
	UpdateRegOut29(pDeriv->m_strRegOut29, regDeriv);
	UpdateRegOut2A(pDeriv->m_strRegOut2A, regDeriv);
	UpdateRegOut2B(pDeriv->m_strRegOut2B, regDeriv);
	UpdateRegOut2C(pDeriv->m_strRegOut2C, regDeriv);
	return *m_pReg;
}

void CSemanticZing400R::UpdateRegisters()
{
	CSemanticBase::UpdateRegisters();

	const CRegisterZing400R& derived = dynamic_cast<const CRegisterZing400R&>(Parse());
	UpdateCh3VspsBlockEnable(derived);
	UpdateCh3Phase(derived);
	UpdateCh2VspsBlockEnable(derived);
	UpdateCh2Phase(derived);
	UpdateCh1VspsBlockEnable(derived);
	UpdateCh1Phase(derived);
	UpdateCh0VspsBlockEnable(derived);
	UpdateCh0Phase(derived);
	UpdateVspsBiasControlBit(derived);
	UpdateLnaControlBit(derived);
	UpdateData(FALSE);
}

void CSemanticZing400R::ResetValues()
{
	m_strVspsBiasControlBit.Empty();
	m_strLnaControlBit.Empty();
	for (int i = 0; i < 4; i++) {
		m_vspsBlock[i].m_strVspsBlockEnable.Empty();
		m_vspsBlock[i].m_strPhase.Empty();
	}
	CSemanticBase::ResetValues();
}

void CSemanticZing400R::ShowChipPic(int nCmdShow)
{
	GetDlgItem(IDC_ZING400_PIC_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_CH0_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_CH1_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_CH2_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_CH3_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_CH0_VALUE_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_CH1_VALUE_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_CH2_VALUE_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_CH3_VALUE_STATIC)->ShowWindow(nCmdShow);
}

void CSemanticZing400R::ShowPhaseSync(int nCmdShow)
{
	GetDlgItem(IDC_CH_PHASE_SYNCH_BUTTON)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_CH_PHASE_DIFF_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_CH_PHASE_DIFF_COMBO)->ShowWindow(nCmdShow);

	ShowChipPic(nCmdShow);
}

void CSemanticZing400R::ShowSlider(int nCmdShow)
{
	CSemanticBase::ShowSlider(nCmdShow);

	GetDlgItem(IDC_RX_SLIDER_VALUE_PHASE_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_RX_SLIDER_VALUE_I_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_RX_SLIDER_VALUE_Q_STATIC)->ShowWindow(nCmdShow);
	ShowPhaseSync(nCmdShow);

	if (m_selected != CSelect::Ch3Phase && m_selected != CSelect::Ch2Phase && m_selected != CSelect::Ch1Phase && m_selected != CSelect::Ch0Phase) ShowPhaseSync(SW_HIDE);
}

int CSemanticZing400R::SliderValueUpdate()
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
		m_strSliderValuePhase = m_strSliderValueI = m_strSliderValueQ = CString(_T(""));	//Phase ���� ������ ���õ��� �ʴ� ���� �ƹ����� ǥ������ ����
	}
	return CSemanticBase::SliderValueUpdate();
}

void CSemanticZing400R::OnBnClickedWriteButton()
{
	CSemanticBase::OnBnClickedWriteButton();
}

BOOL CSemanticZing400R::UpdateSelected(UINT selected, BOOL bCommonControl)
{
	BOOL bRtn = CSemanticBase::UpdateSelected(selected, bCommonControl);
	if (bRtn) return TRUE;

	int updateValue;
	switch (selected) {
		//ControlCombo
	case CSelect::Ch3Block:
		bCommonControl ? updateValue = ComboSel() : updateValue = Ch3Block();
		bRtn = UpdateSemanticValue(0x26, &OnNewCh3Block, updateValue, reinterpret_cast<void (CSemanticBase::*)(const CRegister&)>(&CSemanticZing400R::UpdateCh3Block));
		break;
	case CSelect::Ch2Block:
		bCommonControl ? updateValue = ComboSel() : updateValue = Ch2Block();
		bRtn = UpdateSemanticValue(0x27, &OnNewCh2Block, updateValue, reinterpret_cast<void (CSemanticBase::*)(const CRegister&)>(&CSemanticZing400R::UpdateCh2Block));
		break;
	case CSelect::Ch1Block:
		bCommonControl ? updateValue = ComboSel() : updateValue = Ch1Block();
		bRtn = UpdateSemanticValue(0x29, &OnNewCh1Block, updateValue, reinterpret_cast<void (CSemanticBase::*)(const CRegister&)>(&CSemanticZing400R::UpdateCh1Block));
		break;
	case CSelect::Ch0Block:
		bCommonControl ? updateValue = ComboSel() : updateValue = Ch0Block();
		bRtn = UpdateSemanticValue(0x2A, &OnNewCh0Block, updateValue, reinterpret_cast<void (CSemanticBase::*)(const CRegister&)>(&CSemanticZing400R::UpdateCh0Block));
		break;

		//ControlSlide
	case CSelect::VspsBias:
		bCommonControl ? updateValue = SliderPos() : updateValue = VspsBias();
		bRtn = UpdateSemanticValue(0x2C, &OnNewVspsBias, updateValue, reinterpret_cast<void (CSemanticBase::*)(const CRegister&)>(&CSemanticZing400R::UpdateVspsBias));
		break;
	case CSelect::LnaBias:
		bCommonControl ? updateValue = SliderPos() : updateValue = LnaBias();
		bRtn = UpdateSemanticValue(0x2C, &OnNewLnaBias, updateValue, reinterpret_cast<void (CSemanticBase::*)(const CRegister&)>(&CSemanticZing400R::UpdateLnaBias));
		break;
	case CSelect::Ch3Phase:
		bCommonControl ? updateValue = SliderPos() : updateValue = Ch3Phase();
		bRtn = UpdatePhaseValue(0x26, &OnNewCh3PhaseFirst, &OnNewCh3PhaseNext, updateValue, reinterpret_cast<void (CSemanticBase::*)(const CRegister&)>(&CSemanticZing400R::UpdateCh3PhaseIQ));
		break;
	case CSelect::Ch2Phase:
		bCommonControl ? updateValue = SliderPos() : updateValue = Ch2Phase();
		bRtn = UpdatePhaseValue(0x28, &OnNewCh2PhaseFirst, &OnNewCh2PhaseNext, updateValue, reinterpret_cast<void (CSemanticBase::*)(const CRegister&)>(&CSemanticZing400R::UpdateCh2PhaseIQ));
		break;
	case CSelect::Ch1Phase:
		bCommonControl ? updateValue = SliderPos() : updateValue = Ch1Phase();
		bRtn = UpdatePhaseValue(0x29, &OnNewCh1PhaseFirst, &OnNewCh1PhaseNext, updateValue, reinterpret_cast<void (CSemanticBase::*)(const CRegister&)>(&CSemanticZing400R::UpdateCh1PhaseIQ));
		break;
	case CSelect::Ch0Phase:
		bCommonControl ? updateValue = SliderPos() : updateValue = Ch0Phase();
		bRtn = UpdatePhaseValue(0x2A, &OnNewCh0PhaseFirst, &OnNewCh0PhaseNext, updateValue, reinterpret_cast<void (CSemanticBase::*)(const CRegister&)>(&CSemanticZing400R::UpdateCh0PhaseIQ));
		break;
	default:
		break;
	}
	return bRtn;
}

void CSemanticZing400R::OnBnClickedWriteAllButton()
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

void CSemanticZing400R::UpdateRxReg1(CString strRxReg1, CRegister& reg)
{
	int val = _tcstol(strRxReg1.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nRxData = (val & 0x10) >> 4;
	reg.m_nLimitAmp = (val & 0x08) >> 3;
}

void CSemanticZing400R::UpdateRegOut26(CString strRegOut26, CRegisterZing400R& reg)
{
	int hexa = _tcstol(strRegOut26.GetBuffer(), NULL, 16);
	reg.m_block[3].m_nBlock = (hexa & 0x08) >> 3;

	int phaseBits = hexa & 0x7;	//0x7 (0000 0111)
	int high = 0x00;			//Q_VGA4<3>,Q_VGA4<4>�� UpdateRegOut27���� ä������ �������� ��� ���´�
	int low = CPhaseTable::byteBitReverse(phaseBits) >> 5;
	reg.m_block[3].m_nQ = high | low;
}

void CSemanticZing400R::UpdateRegOut27(CString strRegOut27, CRegisterZing400R& reg)
{
	int hexa = _tcstol(strRegOut27.GetBuffer(), NULL, 16);

	int phaseBits = (hexa & 0xc0) >> 6;
	int high = CPhaseTable::byteBitReverse(phaseBits) >> 3;
	reg.m_block[3].m_nQ = high | reg.m_block[3].m_nQ;

	phaseBits = (hexa & 0x3e) >> 1;
	reg.m_block[3].m_nI = CPhaseTable::reversePhaseBit(phaseBits);
	reg.m_block[3].m_nPhase = CPhaseTable::getState((reg.m_block[3].m_nI) & 0x1f, (reg.m_block[3].m_nQ) & 0x1f);
	reg.m_block[2].m_nBlock = hexa & 0x01;
}

void CSemanticZing400R::UpdateRegOut28(CString strRegOut28, CRegisterZing400R& reg)
{
	int hexa = _tcstol(strRegOut28.GetBuffer(), NULL, 16);

	int phaseBits = (hexa & 0xf8) >> 3;
	reg.m_block[2].m_nQ = CPhaseTable::reversePhaseBit(phaseBits);

	phaseBits = hexa & 0x7;
	int high = 0x00;	//I_VGA3<3>,I_VGA3<4>�� UpdateRegOut29���� ä������ �������� ��� ���´�
	int low = CPhaseTable::byteBitReverse(phaseBits) >> 5;
	reg.m_block[2].m_nI = high | low;
}

void CSemanticZing400R::UpdateRegOut29(CString strRegOut29, CRegisterZing400R& reg)
{
	int hexa = _tcstol(strRegOut29.GetBuffer(), NULL, 16);

	int phaseBits = (hexa & 0xc0) >> 6;
	int high = CPhaseTable::byteBitReverse(phaseBits) >> 3;
	reg.m_block[2].m_nI = high | reg.m_block[2].m_nI;
	reg.m_block[2].m_nPhase = CPhaseTable::getState((reg.m_block[2].m_nI) & 0x1f, (reg.m_block[2].m_nQ) & 0x1f);

	reg.m_block[1].m_nBlock = (hexa & 0x20) >> 5;
	reg.m_block[1].m_nQ = CPhaseTable::reversePhaseBit(hexa & 0x1f);
}

void CSemanticZing400R::UpdateRegOut2A(CString strRegOut2A, CRegisterZing400R& reg)
{
	int hexa = _tcstol(strRegOut2A.GetBuffer(), NULL, 16);

	int phaseBits = (hexa & 0xf8) >> 3;
	reg.m_block[1].m_nI = CPhaseTable::reversePhaseBit(phaseBits);
	reg.m_block[1].m_nPhase = CPhaseTable::getState((reg.m_block[1].m_nI) & 0x1f, (reg.m_block[1].m_nQ) & 0x1f);
	reg.m_block[0].m_nBlock = (hexa & 0x04) >> 2;

	phaseBits = hexa & 0x03;
	int high = 0X00;		//Q_VGA1<2>,Q_VGA1<3>,Q_VGA1<4>�� UpdateRegOut2B���� ä������ �������� ��� ���´�
	int low = CPhaseTable::byteBitReverse(phaseBits) >> 6;
	reg.m_block[0].m_nQ = high | low;
}

void CSemanticZing400R::UpdateRegOut2B(CString strRegOut2B, CRegisterZing400R& reg)
{
	int hexa = _tcstol(strRegOut2B.GetBuffer(), NULL, 16);

	int phaseBits = (hexa & 0xe0) >> 5;
	int high = CPhaseTable::byteBitReverse(phaseBits) >> 3;
	reg.m_block[0].m_nQ = high | reg.m_block[0].m_nQ;

	phaseBits = hexa & 0x1f;
	reg.m_block[0].m_nI = CPhaseTable::reversePhaseBit(phaseBits);
	reg.m_block[0].m_nPhase = CPhaseTable::getState((reg.m_block[0].m_nI) & 0x1f, (reg.m_block[0].m_nQ) & 0x1f);
}

void CSemanticZing400R::UpdateRegOut2C(CString strRegOut2C, CRegisterZing400R& reg)
{
	int hexa = _tcstol(strRegOut2C.GetBuffer(), NULL, 16);

	reg.m_nVspsBias = (hexa & 0xf0) >> 4;
	reg.m_nLnaBias = hexa & 0x0f;
}

void CSemanticZing400R::UpdateCh3VspsBlockEnable(const CRegisterZing400R& reg)
{
	(reg.m_block[3].m_nBlock) ? m_vspsBlock[3].m_strVspsBlockEnable.Format(_T("enable")) : m_vspsBlock[3].m_strVspsBlockEnable.Format(_T("disable"));
}

void CSemanticZing400R::UpdateCh3Phase(const CRegisterZing400R& reg)
{
	if (reg.m_block[3].m_nPhase == -1) {
		m_vspsBlock[3].m_strPhase = CString(_T("undefined"));
	}
	else {
		m_vspsBlock[3].m_strPhase.Format(_T("%d / "), reg.m_block[3].m_nPhase);
		m_vspsBlock[3].m_strPhase += CPhaseTable::getPhase(reg.m_block[3].m_nPhase);
	}
}

void CSemanticZing400R::UpdateCh2VspsBlockEnable(const CRegisterZing400R& reg)
{
	(reg.m_block[2].m_nBlock) ? m_vspsBlock[2].m_strVspsBlockEnable.Format(_T("enable")) : m_vspsBlock[2].m_strVspsBlockEnable.Format(_T("disable"));
}

void CSemanticZing400R::UpdateCh2Phase(const CRegisterZing400R& reg)
{
	if (reg.m_block[2].m_nPhase == -1) {
		m_vspsBlock[2].m_strPhase = CString(_T("undefined"));
	}
	else {
		m_vspsBlock[2].m_strPhase.Format(_T("%d / "), reg.m_block[2].m_nPhase);
		m_vspsBlock[2].m_strPhase += CPhaseTable::getPhase(reg.m_block[2].m_nPhase);
	}
}

void CSemanticZing400R::UpdateCh1VspsBlockEnable(const CRegisterZing400R& reg)
{
	(reg.m_block[1].m_nBlock) ? m_vspsBlock[1].m_strVspsBlockEnable.Format(_T("enable")) : m_vspsBlock[1].m_strVspsBlockEnable.Format(_T("disable"));
}

void CSemanticZing400R::UpdateCh1Phase(const CRegisterZing400R& reg)
{
	if (reg.m_block[1].m_nPhase == -1) {
		m_vspsBlock[1].m_strPhase = CString(_T("undefined"));
	}
	else {
		m_vspsBlock[1].m_strPhase.Format(_T("%d / "), reg.m_block[1].m_nPhase);
		m_vspsBlock[1].m_strPhase += CPhaseTable::getPhase(reg.m_block[1].m_nPhase);
	}
}

void CSemanticZing400R::UpdateCh0VspsBlockEnable(const CRegisterZing400R& reg)
{
	(reg.m_block[0].m_nBlock) ? m_vspsBlock[0].m_strVspsBlockEnable.Format(_T("enable")) : m_vspsBlock[0].m_strVspsBlockEnable.Format(_T("disable"));
}

void CSemanticZing400R::UpdateCh0Phase(const CRegisterZing400R& reg)
{
	if (reg.m_block[0].m_nPhase == -1) {
		m_vspsBlock[0].m_strPhase = CString(_T("undefined"));
	}
	else {
		m_vspsBlock[0].m_strPhase.Format(_T("%d / "), reg.m_block[0].m_nPhase);
		m_vspsBlock[0].m_strPhase += CPhaseTable::getPhase(reg.m_block[0].m_nPhase);
	}
}

void CSemanticZing400R::UpdateVspsBiasControlBit(const CRegisterZing400R& reg)
{
	m_strVspsBiasControlBit.Format(_T("0x%02x"), reg.m_nVspsBias);
}

void CSemanticZing400R::UpdateLnaControlBit(const CRegisterZing400R& reg)
{
	m_strLnaControlBit.Format(_T("0x%02x"), reg.m_nLnaBias);
}

void CSemanticZing400R::OnStnClickedRxCh3VspsBlockEnableValueStatic()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	const CRegisterZing400R& derived = dynamic_cast<const CRegisterZing400R&>(getRegister());
	SetComboGroup(CSelect::Ch3Block, _T("disable"), _T("enable"), derived.m_block[3].m_nBlock, IDC_RX_CH3_VSPS_BLOCK_ENABLE_STATIC);
	ShowChipPic(SW_SHOW);
}


void CSemanticZing400R::OnStnClickedRxCh3PhaseValueStatic()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SetSliderGroup(CSelect::Ch3Phase, 1, 32, m_vspsBlock[3].m_strPhase, 1, 1, 10, IDC_RX_CH3_PHASE_STATIC, &CSemanticBase::SetControlSliderForPhase);
}


void CSemanticZing400R::OnStnClickedRxCh2VspsBlockEnableValueStatic()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	const CRegisterZing400R& derived = dynamic_cast<const CRegisterZing400R&>(getRegister());
	SetComboGroup(CSelect::Ch2Block, _T("disable"), _T("enable"), derived.m_block[2].m_nBlock, IDC_RX_CH2_VSPS_BLOCK_ENABLE_STATIC);
	ShowChipPic(SW_SHOW);
}


void CSemanticZing400R::OnStnClickedRxCh2PhaseValueStatic()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SetSliderGroup(CSelect::Ch2Phase, 1, 32, m_vspsBlock[2].m_strPhase, 1, 1, 10, IDC_RX_CH2_PHASE_STATIC, &CSemanticBase::SetControlSliderForPhase);
}


void CSemanticZing400R::OnStnClickedRxCh1VspsBlockEnableValueStatic()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	const CRegisterZing400R& derived = dynamic_cast<const CRegisterZing400R&>(getRegister());
	SetComboGroup(CSelect::Ch1Block, _T("disable"), _T("enable"), derived.m_block[1].m_nBlock, IDC_RX_CH1_VSPS_BLOCK_ENABLE_STATIC);
	ShowChipPic(SW_SHOW);
}


void CSemanticZing400R::OnStnClickedRxCh1PhaseValueStatic()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SetSliderGroup(CSelect::Ch1Phase, 1, 32, m_vspsBlock[1].m_strPhase, 1, 1, 10, IDC_RX_CH1_PHASE_STATIC, &CSemanticBase::SetControlSliderForPhase);
}


void CSemanticZing400R::OnStnClickedRxCh0VspsBlockEnableValueStatic()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	const CRegisterZing400R& derived = dynamic_cast<const CRegisterZing400R&>(getRegister());
	SetComboGroup(CSelect::Ch0Block, _T("disable"), _T("enable"), derived.m_block[0].m_nBlock, IDC_RX_CH0_VSPS_BLOCK_ENABLE_STATIC);
	ShowChipPic(SW_SHOW);
}


void CSemanticZing400R::OnStnClickedRxCh0PhaseValueStatic()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SetSliderGroup(CSelect::Ch0Phase, 1, 32, m_vspsBlock[0].m_strPhase, 1, 1, 10, IDC_RX_CH0_PHASE_STATIC, &CSemanticBase::SetControlSliderForPhase);
}

void CSemanticZing400R::OnStnClickedRxVspsBiasControlBitValueStatic()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SetSliderGroup(CSelect::VspsBias, 0, 15, m_strVspsBiasControlBit, 0, 1, 10, IDC_RX_VSPS_BIAS_CONTROL_BIT_STATIC);
}

void CSemanticZing400R::OnStnClickedRxLnaBiasControlBitValueStatic()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SetSliderGroup(CSelect::LnaBias, 0, 15, m_strLnaControlBit, 0, 1, 10, IDC_RX_LNA_BIAS_CONTROL_BIT_STATIC);
}

LRESULT CSemanticZing400R::OnSemCh3VspsBlockEnableClick(WPARAM w, LPARAM l)
{
	OnStnClickedRxCh3VspsBlockEnableValueStatic();
	return 0;
}

LRESULT CSemanticZing400R::OnSemCh3PhaseClick(WPARAM w, LPARAM l)
{
	OnStnClickedRxCh3PhaseValueStatic();
	return 0;
}

LRESULT CSemanticZing400R::OnSemCh2VspsBlockEnableClick(WPARAM w, LPARAM l)
{
	OnStnClickedRxCh2VspsBlockEnableValueStatic();
	return 0;
}

LRESULT CSemanticZing400R::OnSemCh2PhaseClick(WPARAM w, LPARAM l)
{
	OnStnClickedRxCh2PhaseValueStatic();
	return 0;
}

LRESULT CSemanticZing400R::OnSemCh1VspsBlockEnableClick(WPARAM w, LPARAM l)
{
	OnStnClickedRxCh1VspsBlockEnableValueStatic();
	return 0;
}

LRESULT CSemanticZing400R::OnSemCh1PhaseClick(WPARAM w, LPARAM l)
{
	OnStnClickedRxCh1PhaseValueStatic();
	return 0;
}

LRESULT CSemanticZing400R::OnSemCh0VspsBlockEnableClick(WPARAM w, LPARAM l)
{
	OnStnClickedRxCh0VspsBlockEnableValueStatic();
	return 0;
}

LRESULT CSemanticZing400R::OnSemCh0PhaseClick(WPARAM w, LPARAM l)
{
	OnStnClickedRxCh0PhaseValueStatic();
	return 0;
}

LRESULT CSemanticZing400R::OnSemVspsBiasControlBitClick(WPARAM w, LPARAM l)
{
	OnStnClickedRxVspsBiasControlBitValueStatic();
	return 0;
}

LRESULT CSemanticZing400R::OnSemLnaBiasControlBitClick(WPARAM w, LPARAM l)
{
	OnStnClickedRxLnaBiasControlBitValueStatic();
	return 0;
}

int CSemanticZing400R::Ch3Block()
{
	return disableOrEnable(m_vspsBlock[3].m_strVspsBlockEnable);
}

int CSemanticZing400R::OnNewCh3Block(int val, int newVal)
{
	return (val & 0x7) | ((newVal & 0x1) << 3);
}

void CSemanticZing400R::UpdateCh3Block(const CRegister& reg)
{
	const CRegisterZing400R& derived = dynamic_cast<const CRegisterZing400R&>(reg);
	(derived.m_block[3].m_nBlock) ? m_vspsBlock[3].m_strVspsBlockEnable.Format(_T("enable")) : m_vspsBlock[3].m_strVspsBlockEnable.Format(_T("disable"));
}

int CSemanticZing400R::Ch2Block()
{
	return disableOrEnable(m_vspsBlock[2].m_strVspsBlockEnable);
}

int CSemanticZing400R::OnNewCh2Block(int val, int newVal)
{
	return (val & 0xfe) | (newVal & 0x1);
}

void CSemanticZing400R::UpdateCh2Block(const CRegister& reg)
{
	const CRegisterZing400R& derived = dynamic_cast<const CRegisterZing400R&>(reg);
	(derived.m_block[2].m_nBlock) ? m_vspsBlock[2].m_strVspsBlockEnable.Format(_T("enable")) : m_vspsBlock[2].m_strVspsBlockEnable.Format(_T("disable"));
}

int CSemanticZing400R::Ch1Block()
{
	return disableOrEnable(m_vspsBlock[1].m_strVspsBlockEnable);
}

int CSemanticZing400R::OnNewCh1Block(int val, int newVal)
{
	return (val & 0xdf) | ((newVal & 0x1) << 5);
}

void CSemanticZing400R::UpdateCh1Block(const CRegister& reg)
{
	const CRegisterZing400R& derived = dynamic_cast<const CRegisterZing400R&>(reg);
	(derived.m_block[1].m_nBlock) ? m_vspsBlock[1].m_strVspsBlockEnable.Format(_T("enable")) : m_vspsBlock[1].m_strVspsBlockEnable.Format(_T("disable"));
}

int CSemanticZing400R::Ch0Block()
{
	return disableOrEnable(m_vspsBlock[0].m_strVspsBlockEnable);
}

int CSemanticZing400R::OnNewCh0Block(int val, int newVal)
{
	return (val & 0xfb) | ((newVal & 0x1) << 2);
}

void CSemanticZing400R::UpdateCh0Block(const CRegister& reg)
{
	const CRegisterZing400R& derived = dynamic_cast<const CRegisterZing400R&>(reg);
	(derived.m_block[0].m_nBlock) ? m_vspsBlock[0].m_strVspsBlockEnable.Format(_T("enable")) : m_vspsBlock[0].m_strVspsBlockEnable.Format(_T("disable"));
}

int CSemanticZing400R::VspsBias()
{
	int val = _tcstol(m_strVspsBiasControlBit.GetBuffer(), NULL, 16);
	ASSERT(val >= 0 && val <= 0xf);
	return val;
}

int CSemanticZing400R::OnNewVspsBias(int val, int newVal)
{
	return (val & 0x0f) | ((newVal & 0x0f) << 4);
}

void CSemanticZing400R::UpdateVspsBias(const CRegister& reg)
{
	const CRegisterZing400R& derived = dynamic_cast<const CRegisterZing400R&>(reg);
	m_strVspsBiasControlBit.Format(_T("0x%02x"), derived.m_nVspsBias);
}

int CSemanticZing400R::LnaBias()
{
	int val = _tcstol(m_strLnaControlBit.GetBuffer(), NULL, 16);
	ASSERT(val >= 0 && val <= 0xf);
	return val;
}

int CSemanticZing400R::OnNewLnaBias(int val, int newVal)
{
	return (val & 0xf0) | (newVal & 0x0f);
}

void CSemanticZing400R::UpdateLnaBias(const CRegister& reg)
{
	const CRegisterZing400R& derived = dynamic_cast<const CRegisterZing400R&>(reg);
	m_strLnaControlBit.Format(_T("0x%02x"), derived.m_nLnaBias);
}

int CSemanticZing400R::Ch3Phase()
{
	CString strPhaseState;
	AfxExtractSubString(strPhaseState, m_vspsBlock[3].m_strPhase, 0, '/');
	int val = _tcstol(strPhaseState.GetBuffer(), NULL, 10);	//"undefined"�� ��� val���� 0
	return val;
}

int CSemanticZing400R::OnNewCh3PhaseFirst(int val, int newVal)
{
	unsigned char q = CPhaseTable::reversePhaseBit(CPhaseTable::getQ(newVal));
	ASSERT((q & 0xe0) == 0);	//Q Phase��Ʈ�� �ݵ�� 5��Ʈ�̾�� ��
	return (val & 0xf8) | ((q & 0x1c) >> 2);
}

int CSemanticZing400R::OnNewCh3PhaseNext(int val, int newVal)
{
	unsigned char q = CPhaseTable::reversePhaseBit(CPhaseTable::getQ(newVal));
	unsigned char i = CPhaseTable::reversePhaseBit(CPhaseTable::getI(newVal));
	ASSERT((q & 0xe0) == 0);	//Q Phase��Ʈ�� �ݵ�� 5��Ʈ�̾�� ��
	ASSERT((i & 0xe0) == 0);	//I Phase��Ʈ�� �ݵ�� 5��Ʈ�̾�� ��
	return (val & 0x01) | ((q & 0x3) << 6) | (i << 1);
}

void CSemanticZing400R::UpdateCh3PhaseIQ(const CRegister& reg)
{
	const CRegisterZing400R& derived = dynamic_cast<const CRegisterZing400R&>(reg);
	m_vspsBlock[3].m_strPhase.Format(_T("%d / "), derived.m_block[3].m_nPhase);
	m_vspsBlock[3].m_strPhase += CPhaseTable::getPhase(derived.m_block[3].m_nPhase);
}

int CSemanticZing400R::Ch2Phase()
{
	CString strPhaseState;
	AfxExtractSubString(strPhaseState, m_vspsBlock[2].m_strPhase, 0, '/');
	int val = _tcstol(strPhaseState.GetBuffer(), NULL, 10);	//"undefined"�� ��� val���� 0
	return val;
}

int CSemanticZing400R::OnNewCh2PhaseFirst(int val, int newVal)
{
	unsigned char q = CPhaseTable::reversePhaseBit(CPhaseTable::getQ(newVal));
	unsigned char i = CPhaseTable::reversePhaseBit(CPhaseTable::getI(newVal));
	ASSERT((q & 0xe0) == 0);	//Q Phase��Ʈ�� �ݵ�� 5��Ʈ�̾�� ��
	ASSERT((i & 0xe0) == 0);	//I Phase��Ʈ�� �ݵ�� 5��Ʈ�̾�� ��
	return (q << 3) | ((i & 0x1c) >> 2);
}

int CSemanticZing400R::OnNewCh2PhaseNext(int val, int newVal)
{
	unsigned char i = CPhaseTable::reversePhaseBit(CPhaseTable::getI(newVal));
	ASSERT((i & 0xe0) == 0);	//I Phase��Ʈ�� �ݵ�� 5��Ʈ�̾�� ��
	return (val & 0x3f) | ((i & 0x3) << 6);
}

void CSemanticZing400R::UpdateCh2PhaseIQ(const CRegister& reg)
{
	const CRegisterZing400R& derived = dynamic_cast<const CRegisterZing400R&>(reg);
	m_vspsBlock[2].m_strPhase.Format(_T("%d / "), derived.m_block[2].m_nPhase);
	m_vspsBlock[2].m_strPhase += CPhaseTable::getPhase(derived.m_block[2].m_nPhase);
}

int CSemanticZing400R::Ch1Phase()
{
	CString strPhaseState;
	AfxExtractSubString(strPhaseState, m_vspsBlock[1].m_strPhase, 0, '/');
	int val = _tcstol(strPhaseState.GetBuffer(), NULL, 10);	//"undefined"�� ��� val���� 0
	return val;
}

int CSemanticZing400R::OnNewCh1PhaseFirst(int val, int newVal)
{
	unsigned char q = CPhaseTable::reversePhaseBit(CPhaseTable::getQ(newVal));
	ASSERT((q & 0xe0) == 0);	//Q Phase��Ʈ�� �ݵ�� 5��Ʈ�̾�� ��
	return (val & 0xe0) | q;
}

int CSemanticZing400R::OnNewCh1PhaseNext(int val, int newVal)
{
	unsigned char i = CPhaseTable::reversePhaseBit(CPhaseTable::getI(newVal));
	ASSERT((i & 0xe0) == 0);	//I Phase��Ʈ�� �ݵ�� 5��Ʈ�̾�� ��
	return (val & 0x7) | (i << 3);
}

void CSemanticZing400R::UpdateCh1PhaseIQ(const CRegister& reg)
{
	const CRegisterZing400R& derived = dynamic_cast<const CRegisterZing400R&>(reg);
	m_vspsBlock[1].m_strPhase.Format(_T("%d / "), derived.m_block[1].m_nPhase);
	m_vspsBlock[1].m_strPhase += CPhaseTable::getPhase(derived.m_block[1].m_nPhase);
}

int CSemanticZing400R::Ch0Phase()
{
	CString strPhaseState;
	AfxExtractSubString(strPhaseState, m_vspsBlock[0].m_strPhase, 0, '/');
	int val = _tcstol(strPhaseState.GetBuffer(), NULL, 10);	//"undefined"�� ��� val���� 0
	return val;
}

int CSemanticZing400R::OnNewCh0PhaseFirst(int val, int newVal)
{
	unsigned char q = CPhaseTable::reversePhaseBit(CPhaseTable::getQ(newVal));
	ASSERT((q & 0xe0) == 0);	//Q Phase��Ʈ�� �ݵ�� 5��Ʈ�̾�� ��
	return (val & 0xfc) | ((q & 0x18) >> 3);
}

int CSemanticZing400R::OnNewCh0PhaseNext(int val, int newVal)
{
	unsigned char q = CPhaseTable::reversePhaseBit(CPhaseTable::getQ(newVal));
	unsigned char i = CPhaseTable::reversePhaseBit(CPhaseTable::getI(newVal));
	ASSERT((q & 0xe0) == 0);	//Q Phase��Ʈ�� �ݵ�� 5��Ʈ�̾�� ��
	ASSERT((i & 0xe0) == 0);	//I Phase��Ʈ�� �ݵ�� 5��Ʈ�̾�� ��
	return ((q & 0x7) << 5) | i;
}

void CSemanticZing400R::UpdateCh0PhaseIQ(const CRegister& reg)
{
	const CRegisterZing400R& derived = dynamic_cast<const CRegisterZing400R&>(reg);
	m_vspsBlock[0].m_strPhase.Format(_T("%d / "), derived.m_block[0].m_nPhase);
	m_vspsBlock[0].m_strPhase += CPhaseTable::getPhase(derived.m_block[0].m_nPhase);
}