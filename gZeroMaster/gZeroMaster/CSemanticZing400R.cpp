// CSemanticZing400R.cpp: 구현 파일
//

#include "pch.h"
#include "gZeroMaster.h"
#include "CSemanticZing400R.h"
#include "CRawZing400R.h"
#include "CRegisterZing400R.h"
#include "CPhaseTable.h"


// CSemanticZing400R 대화 상자

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
	m_staticMap.insert(std::pair<UINT, CStaticElem>(CSelect::LnasBias, CStaticElem(IDC_RX_LNA_BIAS_CONTROL_BIT_VALUE_STATIC, &pDerived->m_nLnaBias, m_strLnaControlBit)));
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
	DDX_Text(pDX, IDC_RX_CH2_VSPS_BLOCK_ENABLE_VALUE_STATIC, m_vspsBlock[2].m_strVspsBlockEnable);
	DDX_Text(pDX, IDC_RX_CH2_PHASE_VALUE_STATIC, m_vspsBlock[2].m_strPhase);
	DDX_Text(pDX, IDC_RX_CH1_VSPS_BLOCK_ENABLE_VALUE_STATIC, m_vspsBlock[1].m_strVspsBlockEnable);
	DDX_Text(pDX, IDC_RX_CH1_PHASE_VALUE_STATIC, m_vspsBlock[1].m_strPhase);
	DDX_Text(pDX, IDC_RX_CH0_VSPS_BLOCK_ENABLE_VALUE_STATIC, m_vspsBlock[0].m_strVspsBlockEnable);
	DDX_Text(pDX, IDC_RX_CH0_PHASE_VALUE_STATIC, m_vspsBlock[0].m_strPhase);
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
	GetDlgItem(IDC_RX_CH2_VSPS_BLOCK_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH1_VSPS_BLOCK_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_RX_CH0_VSPS_BLOCK_ENABLE_VALUE_STATIC)->EnableWindow(b);
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
	UpdateRegOut29(pDeriv->m_strRegOut28, regDeriv);
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
	UpdateCh2VspsBlockEnable(derived);
	UpdateCh1VspsBlockEnable(derived);
	UpdateCh0VspsBlockEnable(derived);
	UpdateVspsBiasControlBit(derived);
	UpdateLnaControlBit(derived);
	UpdateData(FALSE);
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
	int high = CPhaseTable::byteBitReverse(phaseBits) >> 3;		//1110 0000 -> 1110 0
	int low = 0x00;		//Q_VGA4<3>,Q_VGA4<4>는 UpdateRegOut27에서 채워지는 공간으로 비워 놓는다
	reg.m_block[3].m_nQ = high | low;
}

void CSemanticZing400R::UpdateRegOut27(CString strRegOut27, CRegisterZing400R& reg)
{
	int hexa = _tcstol(strRegOut27.GetBuffer(), NULL, 16);

	int phaseBits = hexa & 0xc0;
	int low = CPhaseTable::byteBitReverse(phaseBits) & 0x3;	//0x3(0000 0011)연산을 할 필요는 없으나 명시적으로 마지막 두비트임을 나타내고자
	reg.m_block[3].m_nQ = reg.m_block[3].m_nQ | low;

	phaseBits = (hexa & 0x3e) >> 1;
	reg.m_block[3].m_nI = CPhaseTable::reversePhaseBit(phaseBits);
	reg.m_block[2].m_nBlock = hexa & 0x01;
}

void CSemanticZing400R::UpdateRegOut28(CString strRegOut28, CRegisterZing400R& reg)
{
	int hexa = _tcstol(strRegOut28.GetBuffer(), NULL, 16);

	int phaseBits = (hexa & 0xf8) >> 3;
	reg.m_block[2].m_nQ = CPhaseTable::reversePhaseBit(phaseBits);

	phaseBits = hexa & 0x7;
	int high = CPhaseTable::byteBitReverse(phaseBits) >> 3;
	int low = 0x00;		//I_VGA3<3>,I_VGA3<4>는 UpdateRegOut29에서 채워지는 공간으로 비워 놓는다
	reg.m_block[2].m_nI = high | low;
}

void CSemanticZing400R::UpdateRegOut29(CString strRegOut29, CRegisterZing400R& reg)
{
	int hexa = _tcstol(strRegOut29.GetBuffer(), NULL, 16);

	int phaseBits = (hexa & 0xc0) >> 6;
	int low = CPhaseTable::byteBitReverse(phaseBits) >> 6;
	reg.m_block[2].m_nI = reg.m_block[2].m_nI | low;

	reg.m_block[1].m_nBlock = (hexa & 0x20) >> 5;
	reg.m_block[1].m_nQ = CPhaseTable::reversePhaseBit(hexa & 0x1f);
}

void CSemanticZing400R::UpdateRegOut2A(CString strRegOut2A, CRegisterZing400R& reg)
{
	int hexa = _tcstol(strRegOut2A.GetBuffer(), NULL, 16);

	reg.m_block[1].m_nI = (hexa & 0xf8) >> 3;
	reg.m_block[0].m_nBlock = (hexa & 0x04) >> 2;

	int high = (hexa & 0x03) << 3;
	int low = reg.m_block[0].m_nQ & 0x07;
	reg.m_block[0].m_nQ = high | low;
}

void CSemanticZing400R::UpdateRegOut2B(CString strRegOut2B, CRegisterZing400R& reg)
{
	int hexa = _tcstol(strRegOut2B.GetBuffer(), NULL, 16);

	int high = (reg.m_block[0].m_nQ & 0x18);
	int low = (hexa & 0xe0) >> 5;
	reg.m_block[0].m_nQ = high | low;

	reg.m_block[0].m_nI = hexa & 0x1f;
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

void CSemanticZing400R::UpdateCh2VspsBlockEnable(const CRegisterZing400R& reg)
{
	(reg.m_block[2].m_nBlock) ? m_vspsBlock[2].m_strVspsBlockEnable.Format(_T("enable")) : m_vspsBlock[2].m_strVspsBlockEnable.Format(_T("disable"));
}

void CSemanticZing400R::UpdateCh1VspsBlockEnable(const CRegisterZing400R& reg)
{
	(reg.m_block[1].m_nBlock) ? m_vspsBlock[1].m_strVspsBlockEnable.Format(_T("enable")) : m_vspsBlock[1].m_strVspsBlockEnable.Format(_T("disable"));
}

void CSemanticZing400R::UpdateCh0VspsBlockEnable(const CRegisterZing400R& reg)
{
	(reg.m_block[0].m_nBlock) ? m_vspsBlock[0].m_strVspsBlockEnable.Format(_T("enable")) : m_vspsBlock[0].m_strVspsBlockEnable.Format(_T("disable"));
}

void CSemanticZing400R::UpdateVspsBiasControlBit(const CRegisterZing400R& reg)
{
	m_strVspsBiasControlBit.Format(_T("0x%02x"), reg.m_nVspsBias);
}

void CSemanticZing400R::UpdateLnaControlBit(const CRegisterZing400R& reg)
{
	m_strLnaControlBit.Format(_T("0x%02x"), reg.m_nLnaBias);
}