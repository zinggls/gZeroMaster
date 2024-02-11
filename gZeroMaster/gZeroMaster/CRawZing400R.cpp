// CRawZing400R.cpp: 구현 파일
//

#include "pch.h"
#include "gZeroMaster.h"
#include "CRawZing400R.h"


// CRawZing400R 대화 상자

IMPLEMENT_DYNAMIC(CRawZing400R, CRawBase)

CRawZing400R::CRawZing400R(CWnd* pParent /*=nullptr*/)
	: CRawBase(pParent)
{
}

CRawZing400R::~CRawZing400R()
{
}

void CRawZing400R::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RX_REG1_STATIC, m_strRxReg1);
	DDX_Text(pDX, IDC_BIAS_REG1_STATIC, m_strBiasReg1);
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


BEGIN_MESSAGE_MAP(CRawZing400R, CDialogEx)
	ON_BN_CLICKED(IDC_READ_ALL_BUTTON, &CRawZing400R::OnBnClickedReadAllButton)
	ON_STN_CLICKED(IDC_RX_REG1_STATIC, &CRawZing400R::OnStnClickedRxReg1Static)
	ON_STN_CLICKED(IDC_BIAS_REG1_STATIC, &CRawZing400R::OnStnClickedBiasReg1Static)
	ON_STN_CLICKED(IDC_BIAS_REG4_STATIC, &CRawZing400R::OnStnClickedBiasReg4Static)
	ON_STN_CLICKED(IDC_BIAS_REG5_STATIC, &CRawZing400R::OnStnClickedBiasReg5Static)
	ON_STN_CLICKED(IDC_BIAS_REG6_STATIC, &CRawZing400R::OnStnClickedBiasReg6Static)
	ON_STN_CLICKED(IDC_BIAS_REG7_STATIC, &CRawZing400R::OnStnClickedBiasReg7Static)
	ON_STN_CLICKED(IDC_BIAS_REG8_STATIC, &CRawZing400R::OnStnClickedBiasReg8Static)
	ON_BN_CLICKED(IDC_EDIT_CHECK, &CRawZing400R::OnBnClickedEditCheck)
	ON_BN_CLICKED(IDC_BIT7_BUTTON, &CRawZing400R::OnBnClickedBit7Button)
	ON_BN_CLICKED(IDC_BIT6_BUTTON, &CRawZing400R::OnBnClickedBit6Button)
	ON_BN_CLICKED(IDC_BIT5_BUTTON, &CRawZing400R::OnBnClickedBit5Button)
	ON_BN_CLICKED(IDC_BIT4_BUTTON, &CRawZing400R::OnBnClickedBit4Button)
	ON_BN_CLICKED(IDC_BIT3_BUTTON, &CRawZing400R::OnBnClickedBit3Button)
	ON_BN_CLICKED(IDC_BIT2_BUTTON, &CRawZing400R::OnBnClickedBit2Button)
	ON_BN_CLICKED(IDC_BIT1_BUTTON, &CRawZing400R::OnBnClickedBit1Button)
	ON_BN_CLICKED(IDC_BIT0_BUTTON, &CRawZing400R::OnBnClickedBit0Button)
	ON_BN_CLICKED(IDC_WRITE_BUTTON, &CRawZing400R::OnBnClickedWriteButton)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CRawZing400R 메시지 처리기


BOOL CRawZing400R::OnInitDialog()
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

void CRawZing400R::OnHideRegisterButtons(CString strChosenRegister)
{
	if (strChosenRegister == _T("RX_REG1 [4:3]")) {
		GetDlgItem(IDC_BIT7_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT6_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT5_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT2_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT1_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BIT0_BUTTON)->ShowWindow(SW_HIDE);
	}
}

void CRawZing400R::OnChipConnect(CString chipModel)
{
	ASSERT(chipModel == _T("Zing400R"));

	m_regMap.clear();
	m_regMap.insert(std::pair<CString, CReg>(_T("RX_REG1 [4:3]"), CReg(2, &m_strRxReg1, IDC_RX_REG1_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("BIAS_REG1 [0]"), CReg(17, &m_strBiasReg1, IDC_BIAS_REG1_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("BIAS_REG4 [7:0]"), CReg(20, &m_strBiasReg4, IDC_BIAS_REG4_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("BIAS_REG5 [7:0]"), CReg(21, &m_strBiasReg5, IDC_BIAS_REG5_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("BIAS_REG6 [7:0]"), CReg(22, &m_strBiasReg6, IDC_BIAS_REG6_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("BIAS_REG7 [7:0]"), CReg(23, &m_strBiasReg7, IDC_BIAS_REG7_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("BIAS_REG8 [7:0]"), CReg(24, &m_strBiasReg8, IDC_BIAS_REG8_STATIC)));
}

void CRawZing400R::OnBnClickedDefaultValueButton()
{
	//IBase에서 선언된 순수가상함수 컴파일 오류를 막기 위해 내용이 없는 구현부를 제공
}

BOOL CRawZing400R::ReadRegisters()
{
	BOOL bRtn = CRawBase::ReadRegisters();
	if (!bRtn) return FALSE;

	/*
	Zing400R에서는 상위클래스에서 정의된 비트들 중에서 일부만 사용한다
		RX_REG1 [4:0] -> RX_REG1 [4:3]
	*/

	UpdateData(FALSE);
	return TRUE;
}

void CRawZing400R::OnBnClickedReadAllButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnBnClickedReadAllButton();
}


void CRawZing400R::OnStnClickedRxReg1Static()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CStringList msgList;
	msgList.AddTail(_T("RX_REG1[4:3]"));
	msgList.AddTail(_T("    [4]:RX Data Interface enable"));
	msgList.AddTail(_T("    [3]:Limiting Amplifier enable"));
	OnStnClicked(IDC_EDIT_CHECK, m_strRxReg1, IDC_RX_REG1_LABEL, msgList);
}


void CRawZing400R::OnStnClickedBiasReg1Static()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnStnClickedBiasReg1Static();
}


void CRawZing400R::OnStnClickedBiasReg4Static()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnStnClickedBiasReg4Static();
}


void CRawZing400R::OnStnClickedBiasReg5Static()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnStnClickedBiasReg5Static();
}


void CRawZing400R::OnStnClickedBiasReg6Static()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnStnClickedBiasReg6Static();
}


void CRawZing400R::OnStnClickedBiasReg7Static()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnStnClickedBiasReg7Static();
}


void CRawZing400R::OnStnClickedBiasReg8Static()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnStnClickedBiasReg8Static();
}


void CRawZing400R::OnBnClickedEditCheck()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnBnClickedEditCheck();
}


void CRawZing400R::OnBnClickedBit7Button()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnBnClickedBit7Button();
}


void CRawZing400R::OnBnClickedBit6Button()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnBnClickedBit6Button();
}


void CRawZing400R::OnBnClickedBit5Button()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnBnClickedBit5Button();
}


void CRawZing400R::OnBnClickedBit4Button()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnBnClickedBit4Button();
}


void CRawZing400R::OnBnClickedBit3Button()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnBnClickedBit3Button();
}


void CRawZing400R::OnBnClickedBit2Button()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnBnClickedBit2Button();
}


void CRawZing400R::OnBnClickedBit1Button()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnBnClickedBit1Button();
}


void CRawZing400R::OnBnClickedBit0Button()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnBnClickedBit0Button();
}


void CRawZing400R::OnBnClickedWriteButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRawBase::OnBnClickedWriteButton();
}
