
// gZeroMasterDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "gZeroMaster.h"
#include "gZeroMasterDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CgZeroMasterDlg 대화 상자



CgZeroMasterDlg::CgZeroMasterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GZEROMASTER_DIALOG, pParent)
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
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CgZeroMasterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LOG_LIST, m_log);
	DDX_Control(pDX, IDC_COM_COMBO, m_comPort);
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
}

BEGIN_MESSAGE_MAP(CgZeroMasterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT_BUTTON, &CgZeroMasterDlg::OnBnClickedConnectButton)
	ON_STN_CLICKED(IDC_RX_REG1_STATIC, &CgZeroMasterDlg::OnStnClickedRxReg1Static)
	ON_STN_CLICKED(IDC_TX_REG1_TOP_STATIC, &CgZeroMasterDlg::OnStnClickedTxReg1TopStatic)
	ON_STN_CLICKED(IDC_TX_REG1_MID_STATIC, &CgZeroMasterDlg::OnStnClickedTxReg1MidStatic)
	ON_STN_CLICKED(IDC_TX_REG1_BOT_STATIC, &CgZeroMasterDlg::OnStnClickedTxReg1BotStatic)
	ON_STN_CLICKED(IDC_TX_REG2_TOP_STATIC, &CgZeroMasterDlg::OnStnClickedTxReg2TopStatic)
	ON_STN_CLICKED(IDC_TX_REG2_MID_STATIC, &CgZeroMasterDlg::OnStnClickedTxReg2MidStatic)
	ON_STN_CLICKED(IDC_TX_REG2_BOT_STATIC, &CgZeroMasterDlg::OnStnClickedTxReg2BotStatic)
	ON_STN_CLICKED(IDC_BIAS_REG1_STATIC, &CgZeroMasterDlg::OnStnClickedBiasReg1Static)
	ON_STN_CLICKED(IDC_BIAS_REG2_STATIC, &CgZeroMasterDlg::OnStnClickedBiasReg2Static)
	ON_STN_CLICKED(IDC_BIAS_REG3_STATIC, &CgZeroMasterDlg::OnStnClickedBiasReg3Static)
	ON_STN_CLICKED(IDC_BIAS_REG4_STATIC, &CgZeroMasterDlg::OnStnClickedBiasReg4Static)
	ON_STN_CLICKED(IDC_BIAS_REG5_STATIC, &CgZeroMasterDlg::OnStnClickedBiasReg5Static)
	ON_STN_CLICKED(IDC_BIAS_REG6_STATIC, &CgZeroMasterDlg::OnStnClickedBiasReg6Static)
	ON_STN_CLICKED(IDC_BIAS_REG7_STATIC, &CgZeroMasterDlg::OnStnClickedBiasReg7Static)
	ON_STN_CLICKED(IDC_BIAS_REG8_STATIC, &CgZeroMasterDlg::OnStnClickedBiasReg8Static)
	ON_BN_CLICKED(IDC_LOG_CLEAR_BUTTON, &CgZeroMasterDlg::OnBnClickedLogClearButton)
	ON_BN_CLICKED(IDC_EDIT_CHECK, &CgZeroMasterDlg::OnBnClickedEditCheck)
	ON_BN_CLICKED(IDC_BIT7_BUTTON, &CgZeroMasterDlg::OnBnClickedBit7Button)
	ON_BN_CLICKED(IDC_BIT6_BUTTON, &CgZeroMasterDlg::OnBnClickedBit6Button)
	ON_BN_CLICKED(IDC_BIT5_BUTTON, &CgZeroMasterDlg::OnBnClickedBit5Button)
	ON_BN_CLICKED(IDC_BIT4_BUTTON, &CgZeroMasterDlg::OnBnClickedBit4Button)
	ON_BN_CLICKED(IDC_BIT3_BUTTON, &CgZeroMasterDlg::OnBnClickedBit3Button)
	ON_BN_CLICKED(IDC_BIT2_BUTTON, &CgZeroMasterDlg::OnBnClickedBit2Button)
	ON_BN_CLICKED(IDC_BIT1_BUTTON, &CgZeroMasterDlg::OnBnClickedBit1Button)
	ON_BN_CLICKED(IDC_BIT0_BUTTON, &CgZeroMasterDlg::OnBnClickedBit0Button)
	ON_BN_CLICKED(IDC_READ_ALL_BUTTON, &CgZeroMasterDlg::OnBnClickedReadAllButton)
END_MESSAGE_MAP()


// CgZeroMasterDlg 메시지 처리기

BOOL CgZeroMasterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	for (int i = 1; i <= MAX_COMPORT; i++) {
		CString strVal;
		strVal.Format(_T("COM%d"), i);
		m_comPort.AddString(strVal);
	}
	m_comPort.SetCurSel(0);

	BitControlEnable(FALSE);
	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_HIDE);
	ShowWriteButtons(SW_HIDE);
	GetDlgItem(IDC_READ_ALL_BUTTON)->ShowWindow(SW_HIDE);

	m_regMap.insert( std::pair<CString,int>(_T("RX_REG1 [4:0]"), 2) );
	m_regMap.insert( std::pair<CString, int>(_T("TX_REG1 [23:16]"), 7) );
	m_regMap.insert( std::pair<CString, int>(_T("TX_REG1 [15:8]"), 6) );
	m_regMap.insert( std::pair<CString, int>(_T("TX_REG1 [7:0]"), 5) );
	m_regMap.insert( std::pair<CString, int>(_T("TX_REG2 [16]"), 13) );
	m_regMap.insert( std::pair<CString, int>(_T("TX_REG2 [15:8]"), 12) );
	m_regMap.insert( std::pair<CString, int>(_T("TX_REG2 [7:0]"), 11) );
	m_regMap.insert( std::pair<CString, int>(_T("BIAS_REG1 [0]"), 17) );
	m_regMap.insert( std::pair<CString, int>(_T("BIAS_REG2 [7:0]"), 18) );
	m_regMap.insert( std::pair<CString, int>(_T("BIAS_REG3 [7:0]"), 19) );
	m_regMap.insert( std::pair<CString, int>(_T("BIAS_REG4 [7:0]"), 20) );
	m_regMap.insert( std::pair<CString, int>(_T("BIAS_REG5 [7:0]"), 21) );
	m_regMap.insert( std::pair<CString, int>(_T("BIAS_REG6 [7:0]"), 22) );
	m_regMap.insert( std::pair<CString, int>(_T("BIAS_REG7 [7:0]"), 23) );
	m_regMap.insert( std::pair<CString, int>(_T("BIAS_REG8 [7:0]"), 24) );
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CgZeroMasterDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CgZeroMasterDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CgZeroMasterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CgZeroMasterDlg::L(const TCHAR* str, ...)
{
	if (m_log.GetCount() >= MAX_LOG) {
		m_log.AddString(_T("Log >= MAX_LOG, Reset log"));
		m_log.ResetContent();
	}

	va_list args;
	va_start(args, str);

	int len = _vsctprintf(str, args) + 1;	//_vscprintf doesn't count terminating '\0'
	TCHAR* buffer = new TCHAR[len];
	_vstprintf(buffer, len, str, args);
	va_end(args);

	m_log.AddString(buffer);
	delete[](buffer);

	m_log.SetTopIndex(m_log.GetCount() - 1);
}

void CgZeroMasterDlg::ErrorMsg(LONG lError, LPCTSTR lptszMessage)
{
	CString str;
	str.Format(_T("%s(error code:%d)"), lptszMessage, lError);
	L(str);
}

BOOL CgZeroMasterDlg::ReadResister(int addr,int *value)
{
	char buffer[4] = { 0, };
	sprintf_s(buffer, "%x", addr);

	size_t index = strlen(buffer);
	buffer[index] = 0xd;		//Enter
	buffer[index + 1] = 0x1;	//Read	0x1

	CString str;

	DWORD dwBytesWrite = 0;
	LONG lLastError = m_serial.Write(buffer, index+2,&dwBytesWrite);
	if (lLastError != ERROR_SUCCESS) {
		ErrorMsg(m_serial.GetLastError(), _T("Unable to send data"));
		return FALSE;
	}

#ifdef DEBUG_READ
	str.Format(_T("%d bytes written"), dwBytesWrite);
	L(str);
#endif // DEBUG_READ

	DWORD dwBytesRead = 0;
	if (m_serial.Read(buffer, 4, &dwBytesRead) != ERROR_SUCCESS) {
	//if (m_serial.Read(buffer, 4, &dwBytesRead, 0, INFINITE) != ERROR_SUCCESS) {
		ErrorMsg(m_serial.GetLastError(), _T("Unable to receive data"));
		return FALSE;
	}
#ifdef DEBUG_READ
	str.Format(_T("%d bytes received"), dwBytesRead);
	L(str);
#endif // DEBUG_READ

	//spiProxy는 아래의 반응을 보이도록 정의되었음
	//ASSERT(buffer[0] == 1);		//Read(0x1) 명령을 처리했음을 의미
	//ASSERT(buffer[3] == 'R');	//Read가 끝났음을 의미

	buffer[3] = 0;	//문자열 끝을 나타내기 위해서
	*value = (int)strtol(buffer + 1, NULL, 16);

#ifdef DEBUG_READ
	str.Format(_T("Address:0x%02x Register:0x%02x"), addr,*value);
	L(str);
#endif // DEBUG_READ
	return TRUE;
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

BOOL CgZeroMasterDlg::PrintRegister(int addr,CString name, CString& valueStr)
{
	int value;
	if (ReadResister(addr,&value) == FALSE) return FALSE;

	valueStr.Format(_T("0x%02x"), value);

	CString str;
	str.Format(_T("Address:0x%02x %s 0x%02x"), addr,name.GetBuffer(),value);
	L(str);

	UpdateData(FALSE);
	return TRUE;
}

void CgZeroMasterDlg::ReadResisters()
{
	PrintRegister(2, _T("RX_REG1[4:0]"), m_strRxReg1);
	PrintRegister(7, _T("TX_REG1[23:16]"), m_strTxReg1Top);
	PrintRegister(6, _T("TX_REG1[15:8]"), m_strTxReg1Mid);
	PrintRegister(5, _T("TX_REG1[7:0]"), m_strTxReg1Bot);
	PrintRegister(13, _T("TX_REG216"), m_strTxReg2Top);
	PrintRegister(12, _T("TX_REG2[15:8]"), m_strTxReg2Mid);
	PrintRegister(11, _T("TX_REG2[7:0]"), m_strTxReg2Bot);
	PrintRegister(17, _T("BIAS_REG10"), m_strBiasReg1);
	PrintRegister(18, _T("BIAS_REG2[7:0]"), m_strBiasReg2);
	PrintRegister(19, _T("BIAS_REG3[7:0]"), m_strBiasReg3);
	PrintRegister(20, _T("BIAS_REG4[7:0]"), m_strBiasReg4);
	PrintRegister(21, _T("BIAS_REG5[7:0]"), m_strBiasReg5);
	PrintRegister(22, _T("BIAS_REG6[7:0]"), m_strBiasReg6);
	PrintRegister(23, _T("BIAS_REG7[7:0]"), m_strBiasReg7);
	PrintRegister(24, _T("BIAS_REG8[7:0]"), m_strBiasReg8);
}

void CgZeroMasterDlg::ClearResisterValues()
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

void CgZeroMasterDlg::OnBnClickedConnectButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_COM_COMBO)->EnableWindow(FALSE);

	CString str;
	m_comPort.GetLBText(m_comPort.GetCurSel(), str);
	if (!m_serial.IsOpen()) {
		L(_T("Connecting to ") + str+_T("..."));

		LONG lLastError = m_serial.Open(str, 0, 0, false);
		if (lLastError == ERROR_SUCCESS) {
			GetDlgItem(IDC_CONNECT_BUTTON)->SetWindowTextW(_T("Disconnect"));
			L(str + _T(" opened"));

			lLastError = m_serial.Setup(CSerial::EBaud4800, CSerial::EData8, CSerial::EParNone, CSerial::EStop1);
			if (lLastError != ERROR_SUCCESS) return ErrorMsg(m_serial.GetLastError(), _T("Unable to set COM-port setting"));
			L(_T("setup ok"));

			lLastError = m_serial.SetupReadTimeouts(CSerial::EReadTimeoutBlocking);
			if (lLastError != ERROR_SUCCESS) return ErrorMsg(m_serial.GetLastError(), _T("Unable to set COM-port read timeout"));

			ReadResisters();
			GetDlgItem(IDC_READ_ALL_BUTTON)->ShowWindow(SW_SHOW);
		}
		else {
			GetDlgItem(IDC_COM_COMBO)->EnableWindow(TRUE);
			L(str + _T(" open failed"));
		}
	}
	else {
		LONG lLastError = m_serial.Close();
		if (lLastError == ERROR_SUCCESS) {
			GetDlgItem(IDC_COM_COMBO)->EnableWindow(TRUE);
			GetDlgItem(IDC_CONNECT_BUTTON)->SetWindowTextW(_T("connect"));
			L(str + _T(" closed"));
		}
		else {
			L(str + _T(" close failed"));
		}
		ClearResisterValues();
		GetDlgItem(IDC_COM_COMBO)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_HIDE);
		ShowWriteButtons(SW_HIDE);
		GetDlgItem(IDC_READ_ALL_BUTTON)->ShowWindow(SW_HIDE);
	}
}

CString CgZeroMasterDlg::Bits(unsigned char byte)
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

void CgZeroMasterDlg::ShowBits(unsigned char byte)
{
	(byte & 0x80) ? m_bit7.SetWindowText(_T("1")) : m_bit7.SetWindowText(_T("0"));
	(byte & 0x40) ? m_bit6.SetWindowText(_T("1")) : m_bit6.SetWindowText(_T("0"));
	(byte & 0x20) ? m_bit5.SetWindowText(_T("1")) : m_bit5.SetWindowText(_T("0"));
	(byte & 0x10) ? m_bit4.SetWindowText(_T("1")) : m_bit4.SetWindowText(_T("0"));
	(byte & 0x08) ? m_bit3.SetWindowText(_T("1")) : m_bit3.SetWindowText(_T("0"));
	(byte & 0x04) ? m_bit2.SetWindowText(_T("1")) : m_bit2.SetWindowText(_T("0"));
	(byte & 0x02) ? m_bit1.SetWindowText(_T("1")) : m_bit1.SetWindowText(_T("0"));
	(byte & 0x01) ? m_bit0.SetWindowText(_T("1")) : m_bit0.SetWindowText(_T("0"));
}

void CgZeroMasterDlg::OnStnClickedRxReg1Static()
{
	if (!m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	L(_T("RX_REG1[4:0]"));
	L(_T("    [4]:RX Data Interface enable"));
	L(_T("    [3]:Limiting Amplifier enable"));
	L(_T("    [2:0]:Control the LNA gain"));
	ShowBits(_tcstol(m_strRxReg1.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_RX_REG1_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CgZeroMasterDlg::OnStnClickedTxReg1TopStatic()
{
	if (!m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	L(_T("TX_REG1[23:16]"));
	L(_T("    [7:0]:Duty cycle control"));
	ShowBits(_tcstol(m_strTxReg1Top.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_TX_REG1_TOP_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CgZeroMasterDlg::OnStnClickedTxReg1MidStatic()
{
	if (!m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	L(_T("TX_REG1[15:8]"));
	L(_T("    [7:0]:VCO oscillation frequency control(3:10)"));
	ShowBits(_tcstol(m_strTxReg1Mid.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_TX_REG1_MID_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CgZeroMasterDlg::OnStnClickedTxReg1BotStatic()
{
	if (!m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	L(_T("TX_REG1[7:0]"));
	L(_T("    [7:5]:VCO oscillation frequency control(0:2)"));
	L(_T("    [4]:Regulator Reference Voltage  Control"));
	L(_T("    [3:0]:VCO_VDD Control"));
	ShowBits(_tcstol(m_strTxReg1Bot.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_TX_REG1_BOT_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CgZeroMasterDlg::OnStnClickedTxReg2TopStatic()
{
	if (!m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	L(_T("TX_REG2[16]"));
	L(_T("    [0]:VCO power up/down 0: VCO off, 1: VCO on"));
	ShowBits(_tcstol(m_strTxReg2Top.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_TX_REG2_TOP_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CgZeroMasterDlg::OnStnClickedTxReg2MidStatic()
{
	if (!m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	L(_T("TX_REG2[15:8]"));
	L(_T("    [7]:Modulator power down --0: MOD off, 1: MOD on"));
	L(_T("    [6]:Test buffer power down--0: test buff off, 1: test buff on"));
	L(_T("    [5]:DATA Input Select --0: SER (Inside), 1: Test buff(Outside)"));
	L(_T("    [4]:PA power down 0: PA off, 1: PA on"));
	L(_T("    [3:0]:PA gain control 2"));
	ShowBits(_tcstol(m_strTxReg2Mid.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_TX_REG2_MID_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CgZeroMasterDlg::OnStnClickedTxReg2BotStatic()
{
	if (!m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	L(_T("TX_REG2[7:0]"));
	L(_T("    [7:4]:PA gain control 1"));
	L(_T("    [3:0]:Test Buffer Current control"));
	ShowBits(_tcstol(m_strTxReg2Bot.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_TX_REG2_BOT_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CgZeroMasterDlg::OnStnClickedBiasReg1Static()
{
	if (!m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	L(_T("BIAS_REG1[0]"));
	L(_T("    [0]:BIAS block Enable"));
	ShowBits(_tcstol(m_strBiasReg1.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_BIAS_REG1_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CgZeroMasterDlg::OnStnClickedBiasReg2Static()
{
	if (!m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	L(_T("BIAS_REG2[7:0]"));
	L(_T("    [7:4]:Control LNA 3rd stage biasing current"));
	L(_T("    [3:0]:Control LNA 1st & 2nd stages biasing current"));
	ShowBits(_tcstol(m_strBiasReg2.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_BIAS_REG2_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CgZeroMasterDlg::OnStnClickedBiasReg3Static()
{
	if (!m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	L(_T("BIAS_REG3[7:0]"));
	L(_T("    [7:4]:Control LNA 5th stage biasing current"));
	L(_T("    [3:0]:Control LNA 4th stage biasing current"));
	ShowBits(_tcstol(m_strBiasReg3.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_BIAS_REG3_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CgZeroMasterDlg::OnStnClickedBiasReg4Static()
{
	if (!m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	L(_T("BIAS_REG4[7:0]"));
	L(_T("    [7:4]:Control the demodulator's current"));
	L(_T("    [3:0]:Control the demodulator's current"));
	ShowBits(_tcstol(m_strBiasReg4.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_BIAS_REG4_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CgZeroMasterDlg::OnStnClickedBiasReg5Static()
{
	if (!m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	L(_T("BIAS_REG5[7:0]"));
	L(_T("    [7:4]:Control the biasing current for LA's FB"));
	L(_T("    [3:0]:Control the biasing current for LA's core"));
	ShowBits(_tcstol(m_strBiasReg5.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_BIAS_REG5_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CgZeroMasterDlg::OnStnClickedBiasReg6Static()
{
	if (!m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	L(_T("BIAS_REG6[7:0]"));
	L(_T("    [7:4]:Control the biasing current for LA's O/P buffer"));
	L(_T("    [3:0]:Control the biasing current for LA's I/P buffer"));
	ShowBits(_tcstol(m_strBiasReg6.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_BIAS_REG6_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CgZeroMasterDlg::OnStnClickedBiasReg7Static()
{
	if (!m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	L(_T("BIAS_REG7[7:0]"));
	L(_T("    [7:4]:Control the biasing current for LA's High/Low data rate"));
	L(_T("    [3:0]:Control the biasing current for CMOS gain stage"));
	ShowBits(_tcstol(m_strBiasReg7.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_BIAS_REG7_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CgZeroMasterDlg::OnStnClickedBiasReg8Static()
{
	if (!m_serial.IsOpen()) return;

	GetDlgItem(IDC_EDIT_CHECK)->ShowWindow(SW_SHOW);
	L(_T("BIAS_REG8[7:0]"));
	L(_T("    [7:0]:Control the biasing current for CML interface stage. It aso controls the duty cycle"));
	ShowBits(_tcstol(m_strBiasReg8.GetBuffer(), NULL, 16) & 0xff);
	GetDlgItem(IDC_BIAS_REG8_LABEL)->GetWindowText(m_strChosenRegister);
	UpdateData(FALSE);
}


void CgZeroMasterDlg::OnBnClickedLogClearButton()
{
	m_log.ResetContent();
	UpdateData(FALSE);
}

void CgZeroMasterDlg::BitControlEnable(BOOL b)
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

void CgZeroMasterDlg::OnBnClickedEditCheck()
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

void CgZeroMasterDlg::ShowWriteButtons(int nCmdShow)
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

void CgZeroMasterDlg::ToggleBit(CEdit& bit)
{
	CString strCurVal;
	bit.GetWindowText(strCurVal);
	(strCurVal == _T("0")) ? bit.SetWindowText(_T("1")) : bit.SetWindowText(_T("0"));
}

void CgZeroMasterDlg::OnBnClickedBit7Button()
{
	ToggleBit(m_bit7);
}


void CgZeroMasterDlg::OnBnClickedBit6Button()
{
	ToggleBit(m_bit6);
}


void CgZeroMasterDlg::OnBnClickedBit5Button()
{
	ToggleBit(m_bit5);
}


void CgZeroMasterDlg::OnBnClickedBit4Button()
{
	ToggleBit(m_bit4);
}


void CgZeroMasterDlg::OnBnClickedBit3Button()
{
	ToggleBit(m_bit3);
}


void CgZeroMasterDlg::OnBnClickedBit2Button()
{
	ToggleBit(m_bit2);
}


void CgZeroMasterDlg::OnBnClickedBit1Button()
{
	ToggleBit(m_bit1);
}


void CgZeroMasterDlg::OnBnClickedBit0Button()
{
	ToggleBit(m_bit0);
}


void CgZeroMasterDlg::OnBnClickedReadAllButton()
{
	ClearResisterValues();
	ReadResisters();
}
