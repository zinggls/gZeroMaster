// CRawZing400T.cpp: 구현 파일
//

#include "pch.h"
#include "gZeroMaster.h"
#include "CRawZing400T.h"


// CRawZing400T 대화 상자

IMPLEMENT_DYNAMIC(CRawZing400T, CRawBase)

CRawZing400T::CRawZing400T(CWnd* pParent /*=nullptr*/)
	: CRawBase(pParent)
{
}

CRawZing400T::~CRawZing400T()
{
}

void CRawZing400T::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TX_REG1_TOP_STATIC, m_strTxReg1Top);
	DDX_Text(pDX, IDC_TX_REG1_MID_STATIC, m_strTxReg1Mid);
	DDX_Text(pDX, IDC_TX_REG1_BOT_STATIC, m_strTxReg1Bot);
	DDX_Text(pDX, IDC_TX_REG2_TOP_STATIC, m_strTxReg2Top);
	DDX_Text(pDX, IDC_TX_REG2_MID_STATIC, m_strTxReg2Mid);
	DDX_Text(pDX, IDC_TX_REG2_BOT_STATIC, m_strTxReg2Bot);
	DDX_Text(pDX, IDC_TX_REG_OUT24_STATIC, m_strRegOut24);
	DDX_Text(pDX, IDC_TX_REG_OUT25_STATIC, m_strRegOut25);
	DDX_Text(pDX, IDC_TX_REG_OUT26_STATIC, m_strRegOut26);
	DDX_Text(pDX, IDC_TX_REG_OUT27_STATIC, m_strRegOut27);
	DDX_Text(pDX, IDC_TX_REG_OUT28_STATIC, m_strRegOut28);
	DDX_Text(pDX, IDC_TX_REG_OUT29_STATIC, m_strRegOut29);
	DDX_Text(pDX, IDC_TX_REG_OUT2A_STATIC, m_strRegOut2A);
	DDX_Text(pDX, IDC_TX_REG_OUT2B_STATIC, m_strRegOut2B);
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


BEGIN_MESSAGE_MAP(CRawZing400T, CDialogEx)
	ON_BN_CLICKED(IDC_READ_ALL_BUTTON, &CRawZing400T::OnBnClickedReadAllButton)
	ON_STN_CLICKED(IDC_TX_REG1_TOP_STATIC, &CRawZing400T::OnStnClickedTxReg1TopStatic)
	ON_STN_CLICKED(IDC_TX_REG1_MID_STATIC, &CRawZing400T::OnStnClickedTxReg1MidStatic)
	ON_STN_CLICKED(IDC_TX_REG1_BOT_STATIC, &CRawZing400T::OnStnClickedTxReg1BotStatic)
	ON_STN_CLICKED(IDC_TX_REG2_TOP_STATIC, &CRawZing400T::OnStnClickedTxReg2TopStatic)
	ON_STN_CLICKED(IDC_TX_REG2_MID_STATIC, &CRawZing400T::OnStnClickedTxReg2MidStatic)
	ON_STN_CLICKED(IDC_TX_REG2_BOT_STATIC, &CRawZing400T::OnStnClickedTxReg2BotStatic)
	ON_STN_CLICKED(IDC_TX_REG_OUT24_STATIC, &CRawZing400T::OnStnClickedTxRegOut24Static)
	ON_STN_CLICKED(IDC_TX_REG_OUT25_STATIC, &CRawZing400T::OnStnClickedTxRegOut25Static)
	ON_STN_CLICKED(IDC_TX_REG_OUT26_STATIC, &CRawZing400T::OnStnClickedTxRegOut26Static)
	ON_STN_CLICKED(IDC_TX_REG_OUT27_STATIC, &CRawZing400T::OnStnClickedTxRegOut27Static)
	ON_STN_CLICKED(IDC_TX_REG_OUT28_STATIC, &CRawZing400T::OnStnClickedTxRegOut28Static)
	ON_STN_CLICKED(IDC_TX_REG_OUT29_STATIC, &CRawZing400T::OnStnClickedTxRegOut29Static)
	ON_STN_CLICKED(IDC_TX_REG_OUT2A_STATIC, &CRawZing400T::OnStnClickedTxRegOut2AStatic)
	ON_STN_CLICKED(IDC_TX_REG_OUT2B_STATIC, &CRawZing400T::OnStnClickedTxRegOut2BStatic)
	ON_BN_CLICKED(IDC_EDIT_CHECK, &CRawZing400T::OnBnClickedEditCheck)
	ON_BN_CLICKED(IDC_BIT7_BUTTON, &CRawZing400T::OnBnClickedBit7Button)
	ON_BN_CLICKED(IDC_BIT6_BUTTON, &CRawZing400T::OnBnClickedBit6Button)
	ON_BN_CLICKED(IDC_BIT5_BUTTON, &CRawZing400T::OnBnClickedBit5Button)
	ON_BN_CLICKED(IDC_BIT4_BUTTON, &CRawZing400T::OnBnClickedBit4Button)
	ON_BN_CLICKED(IDC_BIT3_BUTTON, &CRawZing400T::OnBnClickedBit3Button)
	ON_BN_CLICKED(IDC_BIT2_BUTTON, &CRawZing400T::OnBnClickedBit2Button)
	ON_BN_CLICKED(IDC_BIT1_BUTTON, &CRawZing400T::OnBnClickedBit1Button)
	ON_BN_CLICKED(IDC_BIT0_BUTTON, &CRawZing400T::OnBnClickedBit0Button)
	ON_BN_CLICKED(IDC_WRITE_BUTTON, &CRawZing400T::OnBnClickedWriteButton)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CRawZing400T 메시지 처리기


BOOL CRawZing400T::OnInitDialog()
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

void CRawZing400T::OnHideRegisterButtons(CString strChosenRegister)
{
	if (strChosenRegister == _T("TX_REG2 [16]")) {
		GetDlgItem(IDC_BIT7_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT6_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT5_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT4_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT3_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT2_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT1_BUTTON)->ShowWindow(SW_HIDE);
	}
	else if (strChosenRegister == _T("TX_REG2 [15:13]")) {
		GetDlgItem(IDC_BIT4_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT3_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT2_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT1_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT0_BUTTON)->ShowWindow(SW_HIDE);
	}
	else if (strChosenRegister == _T("TX_REG2 [3:0]")) {
		GetDlgItem(IDC_BIT7_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT6_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT5_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT4_BUTTON)->ShowWindow(SW_HIDE);
	}
}

void CRawZing400T::OnChipConnect(CString chipModel)
{
	ASSERT(chipModel == _T("Zing400T"));

	m_regMap.clear();
	m_regMap.insert(std::pair<CString, CReg>(_T("TX_REG1 [23:16]"), CReg(7, &m_strTxReg1Top, IDC_TX_REG1_TOP_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("TX_REG1 [15:8]"), CReg(6, &m_strTxReg1Mid, IDC_TX_REG1_MID_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("TX_REG1 [7:0]"), CReg(5, &m_strTxReg1Bot, IDC_TX_REG1_BOT_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("TX_REG2 [16]"), CReg(13, &m_strTxReg2Top, IDC_TX_REG2_TOP_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("TX_REG2 [15:13]"), CReg(12, &m_strTxReg2Mid, IDC_TX_REG2_MID_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("TX_REG2 [3:0]"), CReg(11, &m_strTxReg2Bot, IDC_TX_REG2_BOT_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("RegOut24 [7:0]"), CReg(36, &m_strRegOut24, IDC_TX_REG_OUT24_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("RegOut25 [7:0]"), CReg(37, &m_strRegOut25, IDC_TX_REG_OUT25_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("RegOut26 [7:0]"), CReg(38, &m_strRegOut26, IDC_TX_REG_OUT26_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("RegOut27 [7:0]"), CReg(39, &m_strRegOut27, IDC_TX_REG_OUT27_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("RegOut28 [7:0]"), CReg(40, &m_strRegOut28, IDC_TX_REG_OUT28_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("RegOut29 [7:0]"), CReg(41, &m_strRegOut29, IDC_TX_REG_OUT29_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("RegOut2A [7:0]"), CReg(42, &m_strRegOut2A, IDC_TX_REG_OUT2A_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("RegOut2B [7:0]"), CReg(43, &m_strRegOut2B, IDC_TX_REG_OUT2B_STATIC)));
}

BOOL CRawZing400T::ReadRegisters()
{
	BOOL bRtn = CRawBase::ReadRegisters();
	if (!bRtn) return FALSE;

	/*
	Zing400T에서는 상위클래스에서 정의된 비트들 중에서 일부만 사용한다
		TX_REG2[15:8] -> TX_REG2[15:13]
		TX_REG2[7:0] -> TX_REG2[3:0]
	*/

	UpdateData(FALSE);
	return TRUE;
}

void CRawZing400T::OnBnClickedReadAllButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnBnClickedReadAllButton();
}


void CRawZing400T::OnStnClickedTxReg1TopStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnStnClickedTxReg1TopStatic();
}


void CRawZing400T::OnStnClickedTxReg1MidStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CStringList msgList;
	msgList.AddTail(_T("TX_REG1[15:8]"));
	msgList.AddTail(_T("    [7:0]:VCO oscillation frequency control(3:10)"));
	OnStnClicked(IDC_EDIT_CHECK, m_strTxReg1Mid, IDC_TX_REG1_MID_LABEL, msgList);
}


void CRawZing400T::OnStnClickedTxReg1BotStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CStringList msgList;
	msgList.AddTail(_T("TX_REG1[7:0]"));
	msgList.AddTail(_T("    [7:5]:VCO oscillation frequency control(0:2)"));
	msgList.AddTail(_T("    [4]:Regulator Reference Voltage  Control"));
	msgList.AddTail(_T("    [3:0]:VCO_VDD Control"));
	OnStnClicked(IDC_EDIT_CHECK, m_strTxReg1Bot, IDC_TX_REG1_BOT_LABEL, msgList);
}


void CRawZing400T::OnStnClickedTxReg2TopStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnStnClickedTxReg2TopStatic();
}


void CRawZing400T::OnStnClickedTxReg2MidStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CStringList msgList;
	msgList.AddTail(_T("TX_REG2[15:13]"));
	msgList.AddTail(_T("    [7]:Modulator power down 0: MOD off, 1: MOD on"));
	msgList.AddTail(_T("    [6]:Test buffer power down 0: test buff off, 1: test buff on"));
	msgList.AddTail(_T("    [5]:DATA Input Select 0: SER (Inside), 1: Test buff(Outside)"));
	OnStnClicked(IDC_EDIT_CHECK, m_strTxReg2Mid, IDC_TX_REG2_MID_LABEL, msgList);
}


void CRawZing400T::OnStnClickedTxReg2BotStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CStringList msgList;
	msgList.AddTail(_T("TX_REG2[3:0]"));
	msgList.AddTail(_T("    [3:0]:Test Buffer Current control"));
	OnStnClicked(IDC_EDIT_CHECK, m_strTxReg2Bot, IDC_TX_REG2_BOT_LABEL, msgList);
}

void CRawZing400T::OnStnClickedTxRegOut24Static()
{
	CStringList msgList;
	msgList.AddTail(_T("RegOut24[0]"));
	msgList.AddTail(_T("    [0]:BIAS Block Enable"));
	OnStnClicked(IDC_EDIT_CHECK, m_strRegOut24, IDC_REG_OUT24_LABEL, msgList);
}

void CRawZing400T::OnStnClickedTxRegOut25Static()
{
	CStringList msgList;
	msgList.AddTail(_T("RegOut25[7:0]"));
	msgList.AddTail(_T("    [7:4]:VSPS PA Bias Voltage (0111: 0.55V)"));
	msgList.AddTail(_T("    [3:0]:VSPS VGA Bias Voltage (1000: 0.56V)"));
	OnStnClicked(IDC_EDIT_CHECK, m_strRegOut25, IDC_REG_OUT25_LABEL, msgList);
}

void CRawZing400T::OnStnClickedTxRegOut26Static()
{
	CStringList msgList;
	msgList.AddTail(_T("RegOut26[7:0]"));
	msgList.AddTail(_T("    [7:4]:VSPS CS Bias Voltage (1000: 0.5V)"));
	msgList.AddTail(_T("    [3]:CH.3 VSPS Block Enable"));
	msgList.AddTail(_T("    [2:0]:Q-CH.3 VSPS Phase Control Bit (Ref.Phase Table)"));
	OnStnClicked(IDC_EDIT_CHECK, m_strRegOut26, IDC_REG_OUT26_LABEL, msgList);
}

void CRawZing400T::OnStnClickedTxRegOut27Static()
{
	CStringList msgList;
	msgList.AddTail(_T("RegOut27[7:0]"));
	msgList.AddTail(_T("    [7:6]:Q-CH.3 VSPS Phase Control Bit (Ref.Phase Table)"));
	msgList.AddTail(_T("    [5:1]:I-CH.3 VSPS Phase Control Bit (Ref.Phase Table)"));
	msgList.AddTail(_T("    [0]:CH.2 VSPS Block Enable"));
	OnStnClicked(IDC_EDIT_CHECK, m_strRegOut27, IDC_REG_OUT27_LABEL, msgList);
}

void CRawZing400T::OnStnClickedTxRegOut28Static()
{
	CStringList msgList;
	msgList.AddTail(_T("RegOut28[7:0]"));
	msgList.AddTail(_T("    [7:3]:Q-CH.2 VSPS Phase Control Bit (Ref.Phase Table)"));
	msgList.AddTail(_T("    [2:0]:I-CH.2 VSPS Phase Control Bit (Ref.Phase Table)"));
	OnStnClicked(IDC_EDIT_CHECK, m_strRegOut28, IDC_REG_OUT28_LABEL, msgList);
}

void CRawZing400T::OnStnClickedTxRegOut29Static()
{
	CStringList msgList;
	msgList.AddTail(_T("RegOut29[7:0]"));
	msgList.AddTail(_T("    [7:6]:I-CH.2 VSPS Phase Control Bit (Ref.Phase Table)"));
	msgList.AddTail(_T("    [5]:CH.1 VSPS Block Enable"));
	msgList.AddTail(_T("    [4:0]:Q-CH.1 VSPS Phase Control Bit (Ref.Phase Table)"));
	OnStnClicked(IDC_EDIT_CHECK, m_strRegOut29, IDC_REG_OUT29_LABEL, msgList);
}

void CRawZing400T::OnStnClickedTxRegOut2AStatic()
{
	CStringList msgList;
	msgList.AddTail(_T("RegOut2A[7:0]"));
	msgList.AddTail(_T("    [7:3]:I-CH.1 VSPS Phase Control Bit (Ref.Phase Table)"));
	msgList.AddTail(_T("    [2]:CH.0 VSPS Block Enable"));
	msgList.AddTail(_T("    [1:0]:Q-CH.0 VSPS Phase Control Bit (Ref.Phase Table)"));
	OnStnClicked(IDC_EDIT_CHECK, m_strRegOut2A, IDC_REG_OUT2A_LABEL, msgList);
}

void CRawZing400T::OnStnClickedTxRegOut2BStatic()
{
	CStringList msgList;
	msgList.AddTail(_T("RegOut2B[7:0]"));
	msgList.AddTail(_T("    [7:5]:Q-CH.0 VSPS Phase Control Bit (Ref.Phase Table)"));
	msgList.AddTail(_T("    [4:0]:I-CH.0 VSPS Phase Control Bit (Ref.Phase Table)"));
	OnStnClicked(IDC_EDIT_CHECK, m_strRegOut2B, IDC_REG_OUT2B_LABEL, msgList);
}

void CRawZing400T::OnBnClickedEditCheck()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnBnClickedEditCheck();
}


void CRawZing400T::OnBnClickedBit7Button()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnBnClickedBit7Button();
}


void CRawZing400T::OnBnClickedBit6Button()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnBnClickedBit6Button();
}


void CRawZing400T::OnBnClickedBit5Button()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnBnClickedBit5Button();
}


void CRawZing400T::OnBnClickedBit4Button()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnBnClickedBit4Button();
}


void CRawZing400T::OnBnClickedBit3Button()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnBnClickedBit3Button();
}


void CRawZing400T::OnBnClickedBit2Button()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnBnClickedBit2Button();
}


void CRawZing400T::OnBnClickedBit1Button()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnBnClickedBit1Button();
}


void CRawZing400T::OnBnClickedBit0Button()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnBnClickedBit0Button();
}


void CRawZing400T::OnBnClickedWriteButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnBnClickedWriteButton();
}

void CRawZing400T::DefaultValues(CString strChip)
{
	ASSERT(strChip == _T("Zing400T"));

	m_strTxReg1Top = _T("0x00");
	m_strTxReg1Mid = _T("0x10");
	m_strTxReg1Bot = _T("0x10");
	m_strTxReg2Top = _T("0x01");
	m_strTxReg2Mid = _T("0xE0");
	m_strTxReg2Bot = _T("0x07");
	UpdateData(FALSE);
}