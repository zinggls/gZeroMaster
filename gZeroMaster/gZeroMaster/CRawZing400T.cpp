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
	ON_BN_CLICKED(IDC_EDIT_CHECK, &CRawZing400T::OnBnClickedEditCheck)
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
}

void CRawZing400T::OnBnClickedDefaultValueButton()
{
	//IBase에서 선언된 순수가상함수 컴파일 오류를 막기 위해 내용이 없는 구현부를 제공
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

	CString str;

	CReg reg = m_regMap.at(_T("TX_REG2 [15:13]"));
	int nOrgVal = _tcstoul(*reg.m_pStr, NULL, 16);
	int nNewVal = (nOrgVal & 0xe0) >> 5;
	reg.m_pStr->Format(_T("0x%02x"), nNewVal);
	str.Format(_T("Address:0x%02x %s 0x%02x->%s modified for Zing400T"), reg.m_nAddr, _T("TX_REG2 [15:13]"), nOrgVal, reg.m_pStr->GetBuffer());
	L(str);

	reg = m_regMap.at(_T("TX_REG2 [3:0]"));
	nOrgVal = _tcstoul(*reg.m_pStr, NULL, 16);
	nNewVal = nOrgVal & 0x0f;
	reg.m_pStr->Format(_T("0x%02x"), nNewVal);
	str.Format(_T("Address:0x%02x %s 0x%02x->%s modified for Zing400T"), reg.m_nAddr, _T("TX_REG2 [3:0]"), nOrgVal, reg.m_pStr->GetBuffer());
	L(str);

	UpdateData(FALSE);
	return TRUE;
}

void CRawZing400T::OnBnClickedReadAllButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ResetValues();
	if (!ReadRegisters()) L(_T("Error occured in reading registers"));
}


void CRawZing400T::OnStnClickedTxReg1TopStatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CStringList msgList;
	msgList.AddTail(_T("TX_REG1[23:16]"));
	msgList.AddTail(_T("    [7:0]:Duty cycle control"));
	OnStnClicked(IDC_EDIT_CHECK, m_strTxReg1Top, IDC_TX_REG1_TOP_LABEL, msgList);
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
	CStringList msgList;
	msgList.AddTail(_T("TX_REG2[16]"));
	msgList.AddTail(_T("    [0]:VCO power up/down 0: VCO off, 1: VCO on"));
	OnStnClicked(IDC_EDIT_CHECK, m_strTxReg2Top, IDC_TX_REG2_TOP_LABEL, msgList);
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


void CRawZing400T::OnBnClickedEditCheck()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnBnClickedEditCheck();
}
