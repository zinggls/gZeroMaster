﻿// CRaw.cpp: 구현 파일
//

#include "pch.h"
#include "gZeroMaster.h"
#include "CRaw.h"
#include "afxdialogex.h"
#include "gZeroMasterDlg.h"
#include "CSemantic.h"
#include <list>


// CRaw 대화 상자

IMPLEMENT_DYNAMIC(CRaw, CDialogEx)

CRaw::CRaw(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RAW_DIALOG, pParent)
	, m_pParent(pParent)
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
	, m_strChosenRegister(_T(""))
	, m_bEdit(FALSE)
	, m_strHex(_T(""))
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

	m_regMap.insert(std::pair<CString, CReg>(_T("RX_REG1 [4:0]"), CReg(2, &m_strRxReg1)));
	m_regMap.insert(std::pair<CString, CReg>(_T("TX_REG1 [23:16]"), CReg(7, &m_strTxReg1Top)));
	m_regMap.insert(std::pair<CString, CReg>(_T("TX_REG1 [15:8]"), CReg(6, &m_strTxReg1Mid)));
	m_regMap.insert(std::pair<CString, CReg>(_T("TX_REG1 [7:0]"), CReg(5, &m_strTxReg1Bot)));
	m_regMap.insert(std::pair<CString, CReg>(_T("TX_REG2 [16]"), CReg(13, &m_strTxReg2Top)));
	m_regMap.insert(std::pair<CString, CReg>(_T("TX_REG2 [15:8]"), CReg(12, &m_strTxReg2Mid)));
	m_regMap.insert(std::pair<CString, CReg>(_T("TX_REG2 [7:0]"), CReg(11, &m_strTxReg2Bot)));
	m_regMap.insert(std::pair<CString, CReg>(_T("BIAS_REG1 [0]"), CReg(17, &m_strBiasReg1)));
	m_regMap.insert(std::pair<CString, CReg>(_T("BIAS_REG2 [7:0]"), CReg(18, &m_strBiasReg2)));
	m_regMap.insert(std::pair<CString, CReg>(_T("BIAS_REG3 [7:0]"), CReg(19, &m_strBiasReg3)));
	m_regMap.insert(std::pair<CString, CReg>(_T("BIAS_REG4 [7:0]"), CReg(20, &m_strBiasReg4)));
	m_regMap.insert(std::pair<CString, CReg>(_T("BIAS_REG5 [7:0]"), CReg(21, &m_strBiasReg5)));
	m_regMap.insert(std::pair<CString, CReg>(_T("BIAS_REG6 [7:0]"), CReg(22, &m_strBiasReg6)));
	m_regMap.insert(std::pair<CString, CReg>(_T("BIAS_REG7 [7:0]"), CReg(23, &m_strBiasReg7)));
	m_regMap.insert(std::pair<CString, CReg>(_T("BIAS_REG8 [7:0]"), CReg(24, &m_strBiasReg8)));

	ShowBitWindow(SW_HIDE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

CgZeroMasterDlg* CRaw::Parent()
{
	return dynamic_cast<CgZeroMasterDlg*>(m_pParent);
}

LONG CRaw::ReadResister(int addr, int* value, int maxLoop)
{
	char buffer[4] = { 0, };
	sprintf_s(buffer, "%x", addr);

	size_t index = strlen(buffer);
	buffer[index] = 0xd;		//Enter
	buffer[index + 1] = 0x1;	//Read	0x1

	ASSERT(Parent());
	ASSERT(Parent()->m_serial.IsOpen());

	DWORD dwBytesWrite = 0;
	LONG lLastError = Parent()->m_serial.Write(buffer, index + 2, &dwBytesWrite);
	if (lLastError != ERROR_SUCCESS) {
		Parent()->ErrorMsg(Parent()->m_serial.GetLastError(), _T("Unable to send data"));
		return lLastError;
	}

#ifdef DEBUG_READ
	CString str;
	str.Format(_T("%d bytes written"), dwBytesWrite);
	L(str);
#endif // DEBUG_READ

	DWORD dwBytesReadSum, dwBytesRead;
	dwBytesReadSum = dwBytesRead = 0;

	int loop = 0;
	std::list<char> charList;
	do {
		char tmp[2];
		lLastError = Parent()->m_serial.Read(tmp, 2, &dwBytesRead);
		if (lLastError != ERROR_SUCCESS) {
			Parent()->ErrorMsg(Parent()->m_serial.GetLastError(), _T("Unable to receive data"));
			return lLastError;
		}
		if (dwBytesRead > 0) {
			dwBytesReadSum += dwBytesRead;
			for (DWORD i = 0; i < dwBytesRead; i++) charList.push_back(tmp[i]);
		}
		loop++;
	} while ((dwBytesReadSum < 2) && (loop < maxLoop));
	if (dwBytesReadSum != 2) return ERROR_TIMEOUT;	//데이터를 Limited기한내에 못찾았음

	int i = 0;
	for (std::list<char>::iterator it = charList.begin(); it != charList.end(); ++it) buffer[i++] = *it;

#ifdef DEBUG_READ
	str.Format(_T("%d bytes received"), dwBytesRead);
	L(str);
#endif // DEBUG_READ

	buffer[2] = 0;	//문자열 끝을 나타내기 위해서
	*value = (int)strtol(buffer, NULL, 16);

#ifdef DEBUG_READ
	str.Format(_T("Address:0x%02x Register:0x%02x"), addr, *value);
	L(str);
#endif // DEBUG_READ
	return ERROR_SUCCESS;
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

BOOL CRaw::PrintRegister(int addr, CString name, CString* pValueStr, int maxLoop)
{
	int value;
	LONG lLastError = ReadResister(addr, &value, maxLoop);
	if (lLastError != ERROR_SUCCESS) {
		Parent()->ErrorMsg(lLastError, _T("Error in ReadRegister"));
		return FALSE;
	}

	pValueStr->Format(_T("0x%02x"), value);

	CString str;
	str.Format(_T("Address:0x%02x %s 0x%02x"), addr, name.GetBuffer(), value);
	Parent()->L(str);

	UpdateData(FALSE);
	return TRUE;
}

BOOL CRaw::ReadResisters()
{
	for (std::map<CString, CReg>::iterator it = m_regMap.begin(); it != m_regMap.end(); it++)
		if(PrintRegister(it->second.m_nAddr, it->first, it->second.m_pStr, MAX_LOOP)!=TRUE) return FALSE;

	return TRUE;
}

void CRaw::ClearResisterValues()
{
	m_strRxReg1.Empty();
	m_strTxReg1Top.Empty();
	m_strTxReg1Mid.Empty();
	m_strTxReg1Bot.Empty();
	m_strTxReg2Top.Empty();
	m_strTxReg2Mid.Empty();
	m_strTxReg2Bot.Empty();
	m_strBiasReg1.Empty();
	m_strBiasReg2.Empty();
	m_strBiasReg3.Empty();
	m_strBiasReg4.Empty();
	m_strBiasReg5.Empty();
	m_strBiasReg6.Empty();
	m_strBiasReg7.Empty();
	m_strBiasReg8.Empty();
	UpdateData(FALSE);

	m_bit7.SetWindowText(_T(""));
	m_bit6.SetWindowText(_T(""));
	m_bit5.SetWindowText(_T(""));
	m_bit4.SetWindowText(_T(""));
	m_bit3.SetWindowText(_T(""));
	m_bit2.SetWindowText(_T(""));
	m_bit1.SetWindowText(_T(""));
	m_bit0.SetWindowText(_T(""));
}

CString CRaw::Bits(unsigned char byte)
{
	CString strBit;
	(byte & 0x80) ? strBit += "1" : strBit += "0";
	(byte & 0x40) ? strBit += "1" : strBit += "0";
	(byte & 0x20) ? strBit += "1" : strBit += "0";
	(byte & 0x10) ? strBit += "1" : strBit += "0";
	(byte & 0x08) ? strBit += "1" : strBit += "0";
	(byte & 0x04) ? strBit += "1" : strBit += "0";
	(byte & 0x02) ? strBit += "1" : strBit += "0";
	(byte & 0x01) ? strBit += "1" : strBit += "0";
	return strBit;
}

void CRaw::ShowBits(unsigned char byte)
{
	ShowBitWindow(SW_SHOW);
	(byte & 0x80) ? m_bit7.SetWindowText(_T("1")) : m_bit7.SetWindowText(_T("0"));
	(byte & 0x40) ? m_bit6.SetWindowText(_T("1")) : m_bit6.SetWindowText(_T("0"));
	(byte & 0x20) ? m_bit5.SetWindowText(_T("1")) : m_bit5.SetWindowText(_T("0"));
	(byte & 0x10) ? m_bit4.SetWindowText(_T("1")) : m_bit4.SetWindowText(_T("0"));
	(byte & 0x08) ? m_bit3.SetWindowText(_T("1")) : m_bit3.SetWindowText(_T("0"));
	(byte & 0x04) ? m_bit2.SetWindowText(_T("1")) : m_bit2.SetWindowText(_T("0"));
	(byte & 0x02) ? m_bit1.SetWindowText(_T("1")) : m_bit1.SetWindowText(_T("0"));
	(byte & 0x01) ? m_bit0.SetWindowText(_T("1")) : m_bit0.SetWindowText(_T("0"));
	ShowHexa();
}

void CRaw::OnStnClickedRxReg1Static()
{
	if (!Parent()->m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	Parent()->L(_T("RX_REG1[4:0]"));
	Parent()->L(_T("    [4]:RX Data Interface enable"));
	Parent()->L(_T("    [3]:Limiting Amplifier enable"));
	Parent()->L(_T("    [2:0]:Control the LNA gain"));
	ShowBits(_tcstol(m_strRxReg1.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_RX_REG1_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CRaw::OnStnClickedTxReg1TopStatic()
{
	if (!Parent()->m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	Parent()->L(_T("TX_REG1[23:16]"));
	Parent()->L(_T("    [7:0]:Duty cycle control"));
	ShowBits(_tcstol(m_strTxReg1Top.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_TX_REG1_TOP_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CRaw::OnStnClickedTxReg1MidStatic()
{
	if (!Parent()->m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	Parent()->L(_T("TX_REG1[15:8]"));
	Parent()->L(_T("    [7:0]:VCO oscillation frequency control(3:10)"));
	ShowBits(_tcstol(m_strTxReg1Mid.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_TX_REG1_MID_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CRaw::OnStnClickedTxReg1BotStatic()
{
	if (!Parent()->m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	Parent()->L(_T("TX_REG1[7:0]"));
	Parent()->L(_T("    [7:5]:VCO oscillation frequency control(0:2)"));
	Parent()->L(_T("    [4]:Regulator Reference Voltage  Control"));
	Parent()->L(_T("    [3:0]:VCO_VDD Control"));
	ShowBits(_tcstol(m_strTxReg1Bot.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_TX_REG1_BOT_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CRaw::OnStnClickedTxReg2TopStatic()
{
	if (!Parent()->m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	Parent()->L(_T("TX_REG2[16]"));
	Parent()->L(_T("    [0]:VCO power up/down 0: VCO off, 1: VCO on"));
	ShowBits(_tcstol(m_strTxReg2Top.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_TX_REG2_TOP_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CRaw::OnStnClickedTxReg2MidStatic()
{
	if (!Parent()->m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	Parent()->L(_T("TX_REG2[15:8]"));
	Parent()->L(_T("    [7]:Modulator power down --0: MOD off, 1: MOD on"));
	Parent()->L(_T("    [6]:Test buffer power down--0: test buff off, 1: test buff on"));
	Parent()->L(_T("    [5]:DATA Input Select --0: SER (Inside), 1: Test buff(Outside)"));
	Parent()->L(_T("    [4]:PA power down 0: PA off, 1: PA on"));
	Parent()->L(_T("    [3:0]:PA gain control 2"));
	ShowBits(_tcstol(m_strTxReg2Mid.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_TX_REG2_MID_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CRaw::OnStnClickedTxReg2BotStatic()
{
	if (!Parent()->m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	Parent()->L(_T("TX_REG2[7:0]"));
	Parent()->L(_T("    [7:4]:PA gain control 1"));
	Parent()->L(_T("    [3:0]:Test Buffer Current control"));
	ShowBits(_tcstol(m_strTxReg2Bot.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_TX_REG2_BOT_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CRaw::OnStnClickedBiasReg1Static()
{
	if (!Parent()->m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	Parent()->L(_T("BIAS_REG1[0]"));
	Parent()->L(_T("    [0]:BIAS block Enable"));
	ShowBits(_tcstol(m_strBiasReg1.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_BIAS_REG1_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CRaw::OnStnClickedBiasReg2Static()
{
	if (!Parent()->m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	Parent()->L(_T("BIAS_REG2[7:0]"));
	Parent()->L(_T("    [7:4]:Control LNA 3rd stage biasing current"));
	Parent()->L(_T("    [3:0]:Control LNA 1st & 2nd stages biasing current"));
	ShowBits(_tcstol(m_strBiasReg2.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_BIAS_REG2_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CRaw::OnStnClickedBiasReg3Static()
{
	if (!Parent()->m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	Parent()->L(_T("BIAS_REG3[7:0]"));
	Parent()->L(_T("    [7:4]:Control LNA 5th stage biasing current"));
	Parent()->L(_T("    [3:0]:Control LNA 4th stage biasing current"));
	ShowBits(_tcstol(m_strBiasReg3.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_BIAS_REG3_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CRaw::OnStnClickedBiasReg4Static()
{
	if (!Parent()->m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	Parent()->L(_T("BIAS_REG4[7:0]"));
	Parent()->L(_T("    [7:4]:Control the demodulator's current"));
	Parent()->L(_T("    [3:0]:Control the demodulator's current"));
	ShowBits(_tcstol(m_strBiasReg4.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_BIAS_REG4_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CRaw::OnStnClickedBiasReg5Static()
{
	if (!Parent()->m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	Parent()->L(_T("BIAS_REG5[7:0]"));
	Parent()->L(_T("    [7:4]:Control the biasing current for LA's FB"));
	Parent()->L(_T("    [3:0]:Control the biasing current for LA's core"));
	ShowBits(_tcstol(m_strBiasReg5.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_BIAS_REG5_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CRaw::OnStnClickedBiasReg6Static()
{
	if (!Parent()->m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	Parent()->L(_T("BIAS_REG6[7:0]"));
	Parent()->L(_T("    [7:4]:Control the biasing current for LA's O/P buffer"));
	Parent()->L(_T("    [3:0]:Control the biasing current for LA's I/P buffer"));
	ShowBits(_tcstol(m_strBiasReg6.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_BIAS_REG6_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CRaw::OnStnClickedBiasReg7Static()
{
	if (!Parent()->m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	Parent()->L(_T("BIAS_REG7[7:0]"));
	Parent()->L(_T("    [7:4]:Control the biasing current for LA's High/Low data rate"));
	Parent()->L(_T("    [3:0]:Control the biasing current for CMOS gain stage"));
	ShowBits(_tcstol(m_strBiasReg7.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_BIAS_REG7_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CRaw::OnStnClickedBiasReg8Static()
{
	if (!Parent()->m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	Parent()->L(_T("BIAS_REG8[7:0]"));
	Parent()->L(_T("    [7:0]:Control the biasing current for CML interface stage. It aso controls the duty cycle"));
	ShowBits(_tcstol(m_strBiasReg8.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_BIAS_REG8_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}

void CRaw::BitControlEnable(BOOL b)
{
	m_bit7.EnableWindow(b);
	m_bit6.EnableWindow(b);
	m_bit5.EnableWindow(b);
	m_bit4.EnableWindow(b);
	m_bit3.EnableWindow(b);
	m_bit2.EnableWindow(b);
	m_bit1.EnableWindow(b);
	m_bit0.EnableWindow(b);
}

void CRaw::OnBnClickedEditCheck()
{
	m_bEdit = !m_bEdit;
	if (m_bEdit) {
		ShowWriteButtons(SW_SHOW);
	}
	else {
		ShowWriteButtons(SW_HIDE);
	}
	UpdateData(FALSE);
}

void CRaw::ShowWriteButtons(int nCmdShow)
{
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT7_BUTTON)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT6_BUTTON)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT5_BUTTON)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT4_BUTTON)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT3_BUTTON)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT2_BUTTON)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT1_BUTTON)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT0_BUTTON)->ShowWindow(nCmdShow);
}

void CRaw::ToggleBit(CEdit& bit)
{
	CString strCurVal;
	bit.GetWindowText(strCurVal);
	(strCurVal == _T("0")) ? bit.SetWindowText(_T("1")) : bit.SetWindowText(_T("0"));
	ShowHexa();
}

void CRaw::OnBnClickedBit7Button()
{
	ToggleBit(m_bit7);
}


void CRaw::OnBnClickedBit6Button()
{
	ToggleBit(m_bit6);
}


void CRaw::OnBnClickedBit5Button()
{
	ToggleBit(m_bit5);
}


void CRaw::OnBnClickedBit4Button()
{
	ToggleBit(m_bit4);
}


void CRaw::OnBnClickedBit3Button()
{
	ToggleBit(m_bit3);
}


void CRaw::OnBnClickedBit2Button()
{
	ToggleBit(m_bit2);
}


void CRaw::OnBnClickedBit1Button()
{
	ToggleBit(m_bit1);
}


void CRaw::OnBnClickedBit0Button()
{
	ToggleBit(m_bit0);
}


void CRaw::OnBnClickedReadAllButton()
{
	m_strRxReg1.Empty();
	m_strTxReg1Top.Empty();
	m_strTxReg1Mid.Empty();
	m_strTxReg1Bot.Empty();
	m_strTxReg2Top.Empty();
	m_strTxReg2Mid.Empty();
	m_strTxReg2Bot.Empty();
	m_strBiasReg1.Empty();
	m_strBiasReg2.Empty();
	m_strBiasReg3.Empty();
	m_strBiasReg4.Empty();
	m_strBiasReg5.Empty();
	m_strBiasReg6.Empty();
	m_strBiasReg7.Empty();
	m_strBiasReg8.Empty();
	UpdateData(FALSE);

	ReadResisters();
}


int CRaw::GetValueFromBits()
{
	int value = 0;

	CString str;
	m_bit7.GetWindowText(str);
	if (str == _T("1")) value = 0x80;

	m_bit6.GetWindowText(str);
	if (str == _T("1")) value |= 0x40;

	m_bit5.GetWindowText(str);
	if (str == _T("1")) value |= 0x20;

	m_bit4.GetWindowText(str);
	if (str == _T("1")) value |= 0x10;

	m_bit3.GetWindowText(str);
	if (str == _T("1")) value |= 0x08;

	m_bit2.GetWindowText(str);
	if (str == _T("1")) value |= 0x04;

	m_bit1.GetWindowText(str);
	if (str == _T("1")) value |= 0x02;

	m_bit0.GetWindowText(str);
	if (str == _T("1")) value |= 0x01;

	str.Format(_T("0x%02x"), value);
	Parent()->L(_T("Value read from the Bits:") + str);
	return value;
}


BOOL CRaw::WriteRegister(int addr, int value)
{
	char buffer[12] = { 0, };
	sprintf_s(buffer, sizeof(buffer), "%x", addr);

	size_t index = strlen(buffer);
	buffer[index] = 0xd;            //Enter
	buffer[index + 1] = 0x0;        //Write    0x0

	sprintf_s(buffer + index + 2, sizeof(buffer) - index - 2, "%x", value);
	size_t valLen = strlen(buffer + index + 2);

	buffer[index + 2 + valLen] = 0xd;

	ASSERT(Parent());
	ASSERT(Parent()->m_serial.IsOpen());

	DWORD dwBytesWrite = 0;
	LONG lLastError = Parent()->m_serial.Write(buffer, index + valLen + 3, &dwBytesWrite);
	if (lLastError != ERROR_SUCCESS) {
		Parent()->ErrorMsg(Parent()->m_serial.GetLastError(), _T("Unable to send data"));
		return FALSE;
	}
	CString str;
	str.Format(_T("%d bytes sent"), dwBytesWrite);
	Parent()->L(str);
	return TRUE;
}


void CRaw::OnBnClickedWriteButton()
{
	ASSERT(m_strChosenRegister.IsEmpty() == FALSE);

	std::map<CString, CReg>::iterator it;

	it = m_regMap.find(m_strChosenRegister);
	ASSERT(it != m_regMap.end());

	BOOL b = WriteRegister(it->second.m_nAddr, GetValueFromBits());
	if (b) {
		Parent()->L(m_strChosenRegister + _T(" updated"));
	}
	else {
		Parent()->L(m_strChosenRegister + _T(" update failed"));
		return;
	}

	Sleep(100);	//주의! 여기서 Sleep이 없으면 PrintRegister과정의 Serial Read에서 Blocking된다.
	PrintRegister(it->second.m_nAddr, it->first, it->second.m_pStr, MAX_LOOP);
	Parent()->m_pSemantic->UpdateRegisters();
}

void CRaw::ShowHexa()
{
	m_strHex.Format(_T("0x%02x"), GetValueFromBits());
	UpdateData(FALSE);
}

void CRaw::ShowBitWindow(int nCmdShow)
{
	GetDlgItem(IDC_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT_EDIT7)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT_EDIT6)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT_EDIT5)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT_EDIT4)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT_EDIT3)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT_EDIT2)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT_EDIT1)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT_EDIT0)->ShowWindow(nCmdShow);

	GetDlgItem(IDC_STATIC7)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_STATIC6)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_STATIC5)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_STATIC4)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_STATIC3)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_STATIC2)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_STATIC1)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_STATIC0)->ShowWindow(nCmdShow);
}