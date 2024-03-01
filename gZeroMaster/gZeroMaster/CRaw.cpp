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
{
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
	ON_STN_CLICKED(IDC_RX_REG1_STATIC, &OnStnClickedRxReg1Static)
	ON_STN_CLICKED(IDC_TX_REG1_TOP_STATIC, &OnStnClickedTxReg1TopStatic)
	ON_STN_CLICKED(IDC_TX_REG1_MID_STATIC, &OnStnClickedTxReg1MidStatic)
	ON_STN_CLICKED(IDC_TX_REG1_BOT_STATIC, &OnStnClickedTxReg1BotStatic)
	ON_STN_CLICKED(IDC_TX_REG2_TOP_STATIC, &OnStnClickedTxReg2TopStatic)
	ON_STN_CLICKED(IDC_TX_REG2_MID_STATIC, &OnStnClickedTxReg2MidStatic)
	ON_STN_CLICKED(IDC_TX_REG2_BOT_STATIC, &OnStnClickedTxReg2BotStatic)
	ON_STN_CLICKED(IDC_BIAS_REG1_STATIC, &OnStnClickedBiasReg1Static)
	ON_STN_CLICKED(IDC_BIAS_REG2_STATIC, &OnStnClickedBiasReg2Static)
	ON_STN_CLICKED(IDC_BIAS_REG3_STATIC, &OnStnClickedBiasReg3Static)
	ON_STN_CLICKED(IDC_BIAS_REG4_STATIC, &OnStnClickedBiasReg4Static)
	ON_STN_CLICKED(IDC_BIAS_REG5_STATIC, &OnStnClickedBiasReg5Static)
	ON_STN_CLICKED(IDC_BIAS_REG6_STATIC, &OnStnClickedBiasReg6Static)
	ON_STN_CLICKED(IDC_BIAS_REG7_STATIC, &OnStnClickedBiasReg7Static)
	ON_STN_CLICKED(IDC_BIAS_REG8_STATIC, &OnStnClickedBiasReg8Static)
	ON_STN_CLICKED(IDC_BIAS_REG9_STATIC, &OnStnClickedBiasReg9Static)
	ON_BN_CLICKED(IDC_EDIT_CHECK, &OnBnClickedEditCheck)
	ON_BN_CLICKED(IDC_BIT7_BUTTON, &OnBnClickedBit7Button)
	ON_BN_CLICKED(IDC_BIT6_BUTTON, &OnBnClickedBit6Button)
	ON_BN_CLICKED(IDC_BIT5_BUTTON, &OnBnClickedBit5Button)
	ON_BN_CLICKED(IDC_BIT4_BUTTON, &OnBnClickedBit4Button)
	ON_BN_CLICKED(IDC_BIT3_BUTTON, &OnBnClickedBit3Button)
	ON_BN_CLICKED(IDC_BIT2_BUTTON, &OnBnClickedBit2Button)
	ON_BN_CLICKED(IDC_BIT1_BUTTON, &OnBnClickedBit1Button)
	ON_BN_CLICKED(IDC_BIT0_BUTTON, &OnBnClickedBit0Button)
	ON_BN_CLICKED(IDC_READ_ALL_BUTTON, &OnBnClickedReadAllButton)
	ON_BN_CLICKED(IDC_WRITE_BUTTON, &OnBnClickedWriteButton)
	ON_BN_CLICKED(IDC_DEFAULT_VALUE_BUTTON, &CRaw::OnBnClickedDefaultValueButton)
	ON_BN_CLICKED(IDC_WRITE_ALL_BUTTON, &CRaw::OnBnClickedWriteAllButton)
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
	GetDlgItem(IDC_WRITE_ALL_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_DEFAULT_VALUE_BUTTON)->ShowWindow(SW_HIDE);

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

void CRaw::OnChipConnect(CString chipModel)
{
	ASSERT(chipModel == _T("A0") || chipModel == _T("Zing200x"));

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

	if (chipModel == _T("Zing200x")) {
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

void CRaw::DefaultValues(CString strChip)
{
	ASSERT(strChip == _T("A0") || strChip == _T("Zing200x"));

	m_strRxReg1 = _T("0x18");
	m_strTxReg1Top = _T("0x00");
	m_strBiasReg1 = _T("0x01");
	m_strBiasReg2 = _T("0x99");
	m_strBiasReg3 = _T("0x99");
	m_strBiasReg4 = _T("0x96");
	m_strBiasReg5 = _T("0x66");
	m_strBiasReg6 = _T("0x66");
	m_strBiasReg7 = _T("0x06");

	if (strChip == _T("A0")) {
		m_strTxReg1Mid = _T("0xf7");
		m_strTxReg1Bot = _T("0xb7");
		m_strBiasReg8 = _T("0x06");
		m_strBiasReg9 = _T("0x99");
	}
	else if (strChip == _T("Zing200x")) {
		m_strTxReg1Mid = _T("0x10");
		m_strTxReg1Bot = _T("0x10");
		m_strTxReg2Top = _T("0x01");
		m_strTxReg2Mid = _T("0xf7");
		m_strTxReg2Bot = _T("0xb7");

		m_strBiasReg8 = _T("0x50");
	}
	UpdateData(FALSE);
}