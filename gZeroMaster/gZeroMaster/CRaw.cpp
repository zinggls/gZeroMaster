// CRaw.cpp: 구현 파일
//

#include "pch.h"
#include "gZeroMaster.h"
#include "CRaw.h"
#include "afxdialogex.h"
#include "gZeroMasterDlg.h"
#include "CSemantic.h"
#include <list>


// CRaw 대화 상자

IMPLEMENT_DYNAMIC(CRaw, CRawBase)

CRaw::CRaw(CWnd* pParent /*=nullptr*/)
	: CRawBase(pParent)
	, m_strRxReg1(_T(""))
	, m_strTxReg1Top(_T(""))
	, m_strTxReg1Mid(_T(""))
	, m_strTxReg2Top(_T(""))
	, m_strTxReg2Mid(_T(""))
	, m_strTxReg2Bot(_T(""))
	, m_strBiasReg1(_T(""))
	, m_strBiasReg2(_T(""))
	, m_strBiasReg3(_T(""))
	, m_strBiasReg4(_T(""))
	, m_strBiasReg5(_T(""))
	, m_strBiasReg6(_T(""))
	, m_strBiasReg7(_T(""))
	, m_strBiasReg8(_T(""))
	, m_strBiasReg9(_T(""))
{
	m_strList.push_back(&m_strRxReg1);
	m_strList.push_back(&m_strTxReg1Top);
	m_strList.push_back(&m_strTxReg1Mid);
	m_strList.push_back(&m_strTxReg1Bot);
	m_strList.push_back(&m_strTxReg2Top);
	m_strList.push_back(&m_strTxReg2Mid);
	m_strList.push_back(&m_strTxReg2Bot);
	m_strList.push_back(&m_strBiasReg1);
	m_strList.push_back(&m_strBiasReg2);
	m_strList.push_back(&m_strBiasReg3);
	m_strList.push_back(&m_strBiasReg4);
	m_strList.push_back(&m_strBiasReg5);
	m_strList.push_back(&m_strBiasReg6);
	m_strList.push_back(&m_strBiasReg7);
	m_strList.push_back(&m_strBiasReg8);
	m_strList.push_back(&m_strBiasReg9);
}

CRaw::~CRaw()
{
}

void CRaw::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RX_REG1_STATIC, m_strRxReg1);
	DDX_Text(pDX, IDC_TX_REG1_TOP_STATIC, m_strTxReg1Top);
	DDX_Text(pDX, IDC_TX_REG1_MID_STATIC, m_strTxReg1Mid);
	DDX_Text(pDX, IDC_TX_REG1_BOT_STATIC, m_strTxReg1Bot);
	DDX_Text(pDX, IDC_TX_REG2_TOP_STATIC, m_strTxReg2Top);
	DDX_Text(pDX, IDC_TX_REG2_MID_STATIC, m_strTxReg2Mid);
	DDX_Text(pDX, IDC_TX_REG2_BOT_STATIC, m_strTxReg2Bot);
	DDX_Text(pDX, IDC_BIAS_REG1_STATIC, m_strBiasReg1);
	DDX_Text(pDX, IDC_BIAS_REG2_STATIC, m_strBiasReg2);
	DDX_Text(pDX, IDC_BIAS_REG3_STATIC, m_strBiasReg3);
	DDX_Text(pDX, IDC_BIAS_REG4_STATIC, m_strBiasReg4);
	DDX_Text(pDX, IDC_BIAS_REG5_STATIC, m_strBiasReg5);
	DDX_Text(pDX, IDC_BIAS_REG6_STATIC, m_strBiasReg6);
	DDX_Text(pDX, IDC_BIAS_REG7_STATIC, m_strBiasReg7);
	DDX_Text(pDX, IDC_BIAS_REG8_STATIC, m_strBiasReg8);
	DDX_Text(pDX, IDC_BIAS_REG9_STATIC, m_strBiasReg9);
	DDX_Control(pDX, IDC_BIT_EDIT7, m_bit7);
	DDX_Control(pDX, IDC_BIT_EDIT6, m_bit6);
	DDX_Control(pDX, IDC_BIT_EDIT5, m_bit5);
	DDX_Control(pDX, IDC_BIT_EDIT4, m_bit4);
	DDX_Control(pDX, IDC_BIT_EDIT3, m_bit3);
	DDX_Control(pDX, IDC_BIT_EDIT2, m_bit2);
	DDX_Control(pDX, IDC_BIT_EDIT1, m_bit1);
	DDX_Control(pDX, IDC_BIT_EDIT0, m_bit0);
	DDX_Text(pDX, IDC_CHOSEN_REGISTER_STATIC, m_strChosenRegister);
	DDX_Check(pDX, IDC_EDIT_CHECK, m_bEdit);
	DDX_Text(pDX, IDC_HEX_VALUE_STATIC, m_strHex);
}


BEGIN_MESSAGE_MAP(CRaw, CDialogEx)
	ON_STN_CLICKED(IDC_RX_REG1_STATIC, &CRaw::OnStnClickedRxReg1Static)
	ON_STN_CLICKED(IDC_TX_REG1_TOP_STATIC, &CRaw::OnStnClickedTxReg1TopStatic)
	ON_STN_CLICKED(IDC_TX_REG1_MID_STATIC, &CRaw::OnStnClickedTxReg1MidStatic)
	ON_STN_CLICKED(IDC_TX_REG1_BOT_STATIC, &CRaw::OnStnClickedTxReg1BotStatic)
	ON_STN_CLICKED(IDC_TX_REG2_TOP_STATIC, &CRaw::OnStnClickedTxReg2TopStatic)
	ON_STN_CLICKED(IDC_TX_REG2_MID_STATIC, &CRaw::OnStnClickedTxReg2MidStatic)
	ON_STN_CLICKED(IDC_TX_REG2_BOT_STATIC, &CRaw::OnStnClickedTxReg2BotStatic)
	ON_STN_CLICKED(IDC_BIAS_REG1_STATIC, &CRaw::OnStnClickedBiasReg1Static)
	ON_STN_CLICKED(IDC_BIAS_REG2_STATIC, &CRaw::OnStnClickedBiasReg2Static)
	ON_STN_CLICKED(IDC_BIAS_REG3_STATIC, &CRaw::OnStnClickedBiasReg3Static)
	ON_STN_CLICKED(IDC_BIAS_REG4_STATIC, &CRaw::OnStnClickedBiasReg4Static)
	ON_STN_CLICKED(IDC_BIAS_REG5_STATIC, &CRaw::OnStnClickedBiasReg5Static)
	ON_STN_CLICKED(IDC_BIAS_REG6_STATIC, &CRaw::OnStnClickedBiasReg6Static)
	ON_STN_CLICKED(IDC_BIAS_REG7_STATIC, &CRaw::OnStnClickedBiasReg7Static)
	ON_STN_CLICKED(IDC_BIAS_REG8_STATIC, &CRaw::OnStnClickedBiasReg8Static)
	ON_STN_CLICKED(IDC_BIAS_REG9_STATIC, &CRaw::OnStnClickedBiasReg9Static)
	ON_BN_CLICKED(IDC_EDIT_CHECK, &CRaw::OnBnClickedEditCheck)
	ON_BN_CLICKED(IDC_BIT7_BUTTON, &CRaw::OnBnClickedBit7Button)
	ON_BN_CLICKED(IDC_BIT6_BUTTON, &CRaw::OnBnClickedBit6Button)
	ON_BN_CLICKED(IDC_BIT5_BUTTON, &CRaw::OnBnClickedBit5Button)
	ON_BN_CLICKED(IDC_BIT4_BUTTON, &CRaw::OnBnClickedBit4Button)
	ON_BN_CLICKED(IDC_BIT3_BUTTON, &CRaw::OnBnClickedBit3Button)
	ON_BN_CLICKED(IDC_BIT2_BUTTON, &CRaw::OnBnClickedBit2Button)
	ON_BN_CLICKED(IDC_BIT1_BUTTON, &CRaw::OnBnClickedBit1Button)
	ON_BN_CLICKED(IDC_BIT0_BUTTON, &CRaw::OnBnClickedBit0Button)
	ON_BN_CLICKED(IDC_READ_ALL_BUTTON, &CRaw::OnBnClickedReadAllButton)
	ON_BN_CLICKED(IDC_WRITE_BUTTON, &CRaw::OnBnClickedWriteButton)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CRaw 메시지 처리기


BOOL CRaw::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	BitControlEnable(FALSE);
	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_HIDE);
	ShowWriteButtons(SW_HIDE);
	GetDlgItem(IDC_READ_ALL_BUTTON)->ShowWindow(SW_HIDE);

	ShowBitWindow(SW_HIDE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

/*
*   address(Dec)	address(Hex)	Register		: DefaultValue
	2				2				RX_REG1[4:0]	: 18
	7				7				TX_REG1[23:16]	: 00
	6				6				TX_REG1[15:8]	: 10
	5				5				TX_REG1[7:0]	: 10
	13				D				TX_REG216		: 01
	12				C				TX_REG2[15:8]	: F7
	11				B				TX_REG2[7:0]	: B7
	17				11				BIAS_REG10		: 01
	18				12				BIAS_REG2[7:0]	: 99
	19				13				BIAS_REG3[7:0]	: 99
	20				14				BIAS_REG4[7:0]	: 96
	21				15				BIAS_REG5[7:0]	: 66
	22				16				BIAS_REG6[7:0]	: 66
	23				17				BIAS_REG7[7:0]	: 06
	24				18				BIAS_REG8[7:0]	: 50
*/

void CRaw::OnStnClickedRxReg1Static()
{
	CStringList msgList;
	msgList.AddTail(_T("RX_REG1[4:0]"));
	msgList.AddTail(_T("    [4]:RX Data Interface enable"));
	msgList.AddTail(_T("    [3]:Limiting Amplifier enable"));
	msgList.AddTail(_T("    [2:0]:Control the LNA gain"));
	OnStnClicked(IDC_EDIT_CHECK, m_strRxReg1, IDC_RX_REG1_LABEL, msgList);
}


void CRaw::OnStnClickedTxReg1TopStatic()
{
	CStringList msgList;
	msgList.AddTail(_T("TX_REG1[23:16]"));
	msgList.AddTail(_T("    [7:0]:Duty cycle control"));
	OnStnClicked(IDC_EDIT_CHECK, m_strTxReg1Top, IDC_TX_REG1_TOP_LABEL, msgList);
}


void CRaw::OnStnClickedTxReg1MidStatic()
{
	CStringList msgList;
	msgList.AddTail(_T("TX_REG1[15:8]"));
	ASSERT(Parent()->m_chip == _T("A0") || Parent()->m_chip == _T("B0"));
	if (Parent()->m_chip == _T("A0")) {
		msgList.AddTail(_T("    [7]:Modulator power down 0: MOD off, 1: MOD on"));
		msgList.AddTail(_T("    [6]:Test buffer power down 0: test buff off, 1: test buff on"));
		msgList.AddTail(_T("    [5]:DATA Input Select 0: SER (Inside), 1: Test buff(Outside)"));
		msgList.AddTail(_T("    [4]:PA power down 0: PA off, 1: PA on"));
		msgList.AddTail(_T("    [3:0]:PA gain control 2"));
	}
	else {
		msgList.AddTail(_T("    [7:0]:VCO oscillation frequency control(3:10)"));
	}
	OnStnClicked(IDC_EDIT_CHECK, m_strTxReg1Mid, IDC_TX_REG1_MID_LABEL, msgList);
}


void CRaw::OnStnClickedTxReg1BotStatic()
{
	CStringList msgList;
	msgList.AddTail(_T("TX_REG1[7:0]"));
	ASSERT(Parent()->m_chip == _T("A0") || Parent()->m_chip == _T("B0"));
	if (Parent()->m_chip == _T("A0")) {
		msgList.AddTail(_T("    [7:4]:PA gain control 1"));
		msgList.AddTail(_T("    [3:0]:Test Buffer Current control"));
	}
	else {
		msgList.AddTail(_T("    [7:5]:VCO oscillation frequency control(0:2)"));
		msgList.AddTail(_T("    [4]:Regulator Reference Voltage  Control"));
		msgList.AddTail(_T("    [3:0]:VCO_VDD Control"));
	}
	OnStnClicked(IDC_EDIT_CHECK, m_strTxReg1Bot, IDC_TX_REG1_BOT_LABEL, msgList);
}


void CRaw::OnStnClickedTxReg2TopStatic()
{
	CStringList msgList;
	msgList.AddTail(_T("TX_REG2[16]"));
	msgList.AddTail(_T("    [0]:VCO power up/down 0: VCO off, 1: VCO on"));
	OnStnClicked(IDC_EDIT_CHECK, m_strTxReg2Top, IDC_TX_REG2_TOP_LABEL, msgList);
}


void CRaw::OnStnClickedTxReg2MidStatic()
{
	CStringList msgList;
	msgList.AddTail(_T("TX_REG2[15:8]"));
	msgList.AddTail(_T("    [7]:Modulator power down 0: MOD off, 1: MOD on"));
	msgList.AddTail(_T("    [6]:Test buffer power down 0: test buff off, 1: test buff on"));
	msgList.AddTail(_T("    [5]:DATA Input Select 0: SER (Inside), 1: Test buff(Outside)"));
	msgList.AddTail(_T("    [4]:PA power down 0: PA off, 1: PA on"));
	msgList.AddTail(_T("    [3:0]:PA gain control 2"));
	OnStnClicked(IDC_EDIT_CHECK, m_strTxReg2Mid, IDC_TX_REG2_MID_LABEL, msgList);
}


void CRaw::OnStnClickedTxReg2BotStatic()
{
	CStringList msgList;
	msgList.AddTail(_T("TX_REG2[7:0]"));
	msgList.AddTail(_T("    [7:4]:PA gain control 1"));
	msgList.AddTail(_T("    [3:0]:Test Buffer Current control"));
	OnStnClicked(IDC_EDIT_CHECK, m_strTxReg2Bot, IDC_TX_REG2_BOT_LABEL, msgList);
}


void CRaw::OnStnClickedBiasReg1Static()
{
	CStringList msgList;
	msgList.AddTail(_T("BIAS_REG1[0]"));
	msgList.AddTail(_T("    [0]:BIAS block Enable"));
	OnStnClicked(IDC_EDIT_CHECK, m_strBiasReg1, IDC_BIAS_REG1_LABEL, msgList);
}


void CRaw::OnStnClickedBiasReg2Static()
{
	CStringList msgList;
	msgList.AddTail(_T("BIAS_REG2[7:0]"));
	msgList.AddTail(_T("    [7:4]:Control LNA 3rd stage biasing current"));
	msgList.AddTail(_T("    [3:0]:Control LNA 1st & 2nd stages biasing current"));
	OnStnClicked(IDC_EDIT_CHECK, m_strBiasReg2, IDC_BIAS_REG2_LABEL, msgList);
}


void CRaw::OnStnClickedBiasReg3Static()
{
	CStringList msgList;
	msgList.AddTail(_T("BIAS_REG3[7:0]"));
	msgList.AddTail(_T("    [7:4]:Control LNA 5th stage biasing current"));
	msgList.AddTail(_T("    [3:0]:Control LNA 4th stage biasing current"));
	OnStnClicked(IDC_EDIT_CHECK, m_strBiasReg3, IDC_BIAS_REG3_LABEL, msgList);
}


void CRaw::OnStnClickedBiasReg4Static()
{
	CStringList msgList;
	msgList.AddTail(_T("BIAS_REG4[7:0]"));
	msgList.AddTail(_T("    [7:4]:Control the demodulator's current"));
	msgList.AddTail(_T("    [3:0]:Control the demodulator's current"));
	OnStnClicked(IDC_EDIT_CHECK, m_strBiasReg4, IDC_BIAS_REG4_LABEL, msgList);
}


void CRaw::OnStnClickedBiasReg5Static()
{
	CStringList msgList;
	msgList.AddTail(_T("BIAS_REG5[7:0]"));
	msgList.AddTail(_T("    [7:4]:Control the biasing current for LA's FB"));
	msgList.AddTail(_T("    [3:0]:Control the biasing current for LA's core"));
	OnStnClicked(IDC_EDIT_CHECK, m_strBiasReg5, IDC_BIAS_REG5_LABEL, msgList);
}


void CRaw::OnStnClickedBiasReg6Static()
{
	CStringList msgList;
	msgList.AddTail(_T("BIAS_REG6[7:0]"));
	msgList.AddTail(_T("    [7:4]:Control the biasing current for LA's O/P buffer"));
	msgList.AddTail(_T("    [3:0]:Control the biasing current for LA's I/P buffer"));
	OnStnClicked(IDC_EDIT_CHECK, m_strBiasReg6, IDC_BIAS_REG6_LABEL, msgList);
}


void CRaw::OnStnClickedBiasReg7Static()
{
	CStringList msgList;
	msgList.AddTail(_T("BIAS_REG7[7:0]"));
	msgList.AddTail(_T("    [7:4]:Control the biasing current for LA's High/Low data rate"));
	msgList.AddTail(_T("    [3:0]:Control the biasing current for CMOS gain stage"));
	OnStnClicked(IDC_EDIT_CHECK, m_strBiasReg7, IDC_BIAS_REG7_LABEL, msgList);
}


void CRaw::OnStnClickedBiasReg8Static()
{
	CStringList msgList;
	msgList.AddTail(_T("BIAS_REG8[7:0]"));
	msgList.AddTail(_T("    [7:0]:Control the biasing current for CML interface stage. It aso controls the duty cycle"));
	OnStnClicked(IDC_EDIT_CHECK, m_strBiasReg8, IDC_BIAS_REG8_LABEL, msgList);
}


void CRaw::OnStnClickedBiasReg9Static()
{
	CStringList msgList;
	msgList.AddTail(_T("BIAS_REG9[7:0]"));
	msgList.AddTail(_T("    [7:4]:Control FD cores of stg1 & stg2 biasing current"));
	msgList.AddTail(_T("    [3:0]:Control FD buffers of stg1 & stg2 biasing current"));
	OnStnClicked(IDC_EDIT_CHECK, m_strBiasReg9, IDC_BIAS_REG9_LABEL, msgList);
}

void CRaw::OnHideRegisterButtons(CString strChosenRegister)
{
	if (strChosenRegister == _T("RX_REG1 [4:0]")) {
		GetDlgItem(IDC_BIT7_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT6_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT5_BUTTON)->ShowWindow(SW_HIDE);
	}
	else if (strChosenRegister == _T("TX_REG2 [16]") | strChosenRegister == _T("BIAS_REG1 [0]")) {
		GetDlgItem(IDC_BIT7_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT6_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT5_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT4_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT3_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT2_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT1_BUTTON)->ShowWindow(SW_HIDE);
	}
}

void CRaw::OnBnClickedReadAllButton()
{
	CRawBase::OnBnClickedReadAllButton();
	Parent()->m_pSemantic->UpdateRegisters();
}

void CRaw::OnBnClickedWriteButton()
{
	CRawBase::OnBnClickedWriteButton();
	Parent()->m_pSemantic->UpdateRegisters();
}

void CRaw::ResetValues()
{
	CRawBase::ResetValues();
	UpdateData(FALSE);
}

void CRaw::OnChipConnect(CString chipModel)
{
	ASSERT(chipModel == _T("A0") || chipModel == _T("B0"));

	m_regMap.clear();
	m_regMap.insert(std::pair<CString, CReg>(_T("RX_REG1 [4:0]"), CReg(2, &m_strRxReg1, IDC_RX_REG1_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("TX_REG1 [23:16]"), CReg(7, &m_strTxReg1Top, IDC_TX_REG1_TOP_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("TX_REG1 [15:8]"), CReg(6, &m_strTxReg1Mid, IDC_TX_REG1_MID_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("TX_REG1 [7:0]"), CReg(5, &m_strTxReg1Bot, IDC_TX_REG1_BOT_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("BIAS_REG1 [0]"), CReg(17, &m_strBiasReg1, IDC_BIAS_REG1_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("BIAS_REG2 [7:0]"), CReg(18, &m_strBiasReg2, IDC_BIAS_REG2_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("BIAS_REG3 [7:0]"), CReg(19, &m_strBiasReg3, IDC_BIAS_REG3_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("BIAS_REG4 [7:0]"), CReg(20, &m_strBiasReg4, IDC_BIAS_REG4_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("BIAS_REG5 [7:0]"), CReg(21, &m_strBiasReg5, IDC_BIAS_REG5_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("BIAS_REG6 [7:0]"), CReg(22, &m_strBiasReg6, IDC_BIAS_REG6_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("BIAS_REG7 [7:0]"), CReg(23, &m_strBiasReg7, IDC_BIAS_REG7_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("BIAS_REG8 [7:0]"), CReg(24, &m_strBiasReg8, IDC_BIAS_REG8_STATIC)));

	if (chipModel == _T("B0")) {
		m_regMap.insert(std::pair<CString, CReg>(_T("TX_REG2 [16]"), CReg(13, &m_strTxReg2Top, IDC_TX_REG2_TOP_STATIC)));
		m_regMap.insert(std::pair<CString, CReg>(_T("TX_REG2 [15:8]"), CReg(12, &m_strTxReg2Mid, IDC_TX_REG2_MID_STATIC)));
		m_regMap.insert(std::pair<CString, CReg>(_T("TX_REG2 [7:0]"), CReg(11, &m_strTxReg2Bot, IDC_TX_REG2_BOT_STATIC)));

		GetDlgItem(IDC_TX_REG2_TOP_LABEL)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_TX_REG2_MID_LABEL)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_TX_REG2_BOT_LABEL)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_TX_REG2_TOP_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_TX_REG2_MID_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_TX_REG2_BOT_STATIC)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_BIAS_REG9_LABEL)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIAS_REG9_STATIC)->ShowWindow(SW_HIDE);
	}
	else if (chipModel == _T("A0")) {
		m_regMap.insert(std::pair<CString, CReg>(_T("BIAS_REG9 [7:0]"), CReg(25, &m_strBiasReg9, IDC_BIAS_REG9_STATIC)));

		GetDlgItem(IDC_TX_REG2_TOP_LABEL)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_TX_REG2_MID_LABEL)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_TX_REG2_BOT_LABEL)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_TX_REG2_TOP_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_TX_REG2_MID_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_TX_REG2_BOT_STATIC)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_BIAS_REG9_LABEL)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BIAS_REG9_STATIC)->ShowWindow(SW_SHOW);
	}
}