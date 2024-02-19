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
	m_strList.push_back(&m_strRegOut26);
	m_strList.push_back(&m_strRegOut27);
	m_strList.push_back(&m_strRegOut28);
	m_strList.push_back(&m_strRegOut29);
	m_strList.push_back(&m_strRegOut2A);
	m_strList.push_back(&m_strRegOut2B);
	m_strList.push_back(&m_strRegOut2C);
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
	DDX_Text(pDX, IDC_RX_REG_OUT26_STATIC, m_strRegOut26);
	DDX_Text(pDX, IDC_RX_REG_OUT27_STATIC, m_strRegOut27);
	DDX_Text(pDX, IDC_RX_REG_OUT28_STATIC, m_strRegOut28);
	DDX_Text(pDX, IDC_RX_REG_OUT29_STATIC, m_strRegOut29);
	DDX_Text(pDX, IDC_RX_REG_OUT2A_STATIC, m_strRegOut2A);
	DDX_Text(pDX, IDC_RX_REG_OUT2B_STATIC, m_strRegOut2B);
	DDX_Text(pDX, IDC_RX_REG_OUT2C_STATIC, m_strRegOut2C);
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
	ON_STN_CLICKED(IDC_RX_REG_OUT26_STATIC, &CRawZing400R::OnStnClickedRxRegOut26Static)
	ON_STN_CLICKED(IDC_RX_REG_OUT27_STATIC, &CRawZing400R::OnStnClickedRxRegOut27Static)
	ON_STN_CLICKED(IDC_RX_REG_OUT28_STATIC, &CRawZing400R::OnStnClickedRxRegOut28Static)
	ON_STN_CLICKED(IDC_RX_REG_OUT29_STATIC, &CRawZing400R::OnStnClickedRxRegOut29Static)
	ON_STN_CLICKED(IDC_RX_REG_OUT2A_STATIC, &CRawZing400R::OnStnClickedRxRegOut2AStatic)
	ON_STN_CLICKED(IDC_RX_REG_OUT2B_STATIC, &CRawZing400R::OnStnClickedRxRegOut2BStatic)
	ON_STN_CLICKED(IDC_RX_REG_OUT2C_STATIC, &CRawZing400R::OnStnClickedRxRegOut2CStatic)
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
	m_regMap.insert(std::pair<CString, CReg>(_T("RegOut26 [3:0]"), CReg(38, &m_strRegOut26, IDC_RX_REG_OUT26_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("RegOut27 [7:0]"), CReg(39, &m_strRegOut27, IDC_RX_REG_OUT27_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("RegOut28 [7:0]"), CReg(40, &m_strRegOut28, IDC_RX_REG_OUT28_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("RegOut29 [7:0]"), CReg(41, &m_strRegOut29, IDC_RX_REG_OUT29_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("RegOut2A [7:0]"), CReg(42, &m_strRegOut2A, IDC_RX_REG_OUT2A_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("RegOut2B [7:0]"), CReg(43, &m_strRegOut2B, IDC_RX_REG_OUT2B_STATIC)));
	m_regMap.insert(std::pair<CString, CReg>(_T("RegOut2C [7:0]"), CReg(44, &m_strRegOut2C, IDC_RX_REG_OUT2C_STATIC)));
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


void CRawZing400R::OnStnClickedRxRegOut26Static()
{
	CStringList msgList;
	msgList.AddTail(_T("RegOut26[3:0]"));
	msgList.AddTail(_T("    [3]:CH.3 VSPS Block Enable"));
	msgList.AddTail(_T("    [2:0]:Q-CH.3 VSPS Phase Control Bit (Ref.Phase Table)"));
	OnStnClicked(IDC_EDIT_CHECK, m_strRegOut26, IDC_REG_OUT26_LABEL, msgList);
}


void CRawZing400R::OnStnClickedRxRegOut27Static()
{
	CStringList msgList;
	msgList.AddTail(_T("RegOut27[7:0]"));
	msgList.AddTail(_T("    [7:6]:Q-CH.3 VSPS Phase Control Bit (Ref.Phase Table)"));
	msgList.AddTail(_T("    [5:1]:I-CH.3 VSPS Phase Control Bit (Ref.Phase Table)"));
	msgList.AddTail(_T("    [0]:CH.2 VSPS Block Enable"));
	OnStnClicked(IDC_EDIT_CHECK, m_strRegOut27, IDC_REG_OUT27_LABEL, msgList);
}


void CRawZing400R::OnStnClickedRxRegOut28Static()
{
	CStringList msgList;
	msgList.AddTail(_T("RegOut28[7:0]"));
	msgList.AddTail(_T("    [7:3]:Q-CH.2 VSPS Phase Control Bit (Ref.Phase Table)"));
	msgList.AddTail(_T("    [2:0]:I-CH.2 VSPS Phase Control Bit (Ref.Phase Table)"));
	OnStnClicked(IDC_EDIT_CHECK, m_strRegOut28, IDC_REG_OUT28_LABEL, msgList);
}


void CRawZing400R::OnStnClickedRxRegOut29Static()
{
	CStringList msgList;
	msgList.AddTail(_T("RegOut29[7:0]"));
	msgList.AddTail(_T("    [7:6]:I-CH.2 VSPS Phase Control Bit (Ref.Phase Table)"));
	msgList.AddTail(_T("    [5]:CH.1 VSPS Block Enable"));
	msgList.AddTail(_T("    [4:0]:Q-CH.1 VSPS Phase Control Bit (Ref.Phase Table)"));
	OnStnClicked(IDC_EDIT_CHECK, m_strRegOut29, IDC_REG_OUT29_LABEL, msgList);
}


void CRawZing400R::OnStnClickedRxRegOut2AStatic()
{
	CStringList msgList;
	msgList.AddTail(_T("RegOut2A[7:0]"));
	msgList.AddTail(_T("    [7:3]:I-CH.1 VSPS Phase Control Bit (Ref.Phase Table)"));
	msgList.AddTail(_T("    [2]:CH.0 VSPS Block Enable"));
	msgList.AddTail(_T("    [1:0]:Q-CH.0 VSPS Phase Control Bit (Ref.Phase Table)"));
	OnStnClicked(IDC_EDIT_CHECK, m_strRegOut2A, IDC_REG_OUT2A_LABEL, msgList);
}


void CRawZing400R::OnStnClickedRxRegOut2BStatic()
{
	CStringList msgList;
	msgList.AddTail(_T("RegOut2B[7:0]"));
	msgList.AddTail(_T("    [7:5]:Q-CH.0 VSPS Phase Control Bit (Ref.Phase Table)"));
	msgList.AddTail(_T("    [4:0]:I-CH.0 VSPS Phase Control Bit (Ref.Phase Table)"));
	OnStnClicked(IDC_EDIT_CHECK, m_strRegOut2B, IDC_REG_OUT2B_LABEL, msgList);
}


void CRawZing400R::OnStnClickedRxRegOut2CStatic()
{
	CStringList msgList;
	msgList.AddTail(_T("RegOut2C[7:0]"));
	msgList.AddTail(_T("    [7:4]:VSPS Bias Control Bit (0001: 0.5104V)"));
	msgList.AddTail(_T("    [3:0]:LNA Bias Control Bit (0000: 0.5342V)"));
	OnStnClicked(IDC_EDIT_CHECK, m_strRegOut2C, IDC_REG_OUT2C_LABEL, msgList);
}


void CRawZing400R::DefaultValues(CString strChip)
{
	ASSERT(strChip == _T("Zing400R"));

	m_strRxReg1 = _T("0x18");
	m_strBiasReg1 = _T("0x01");
	m_strBiasReg4 = _T("0x96");
	m_strBiasReg5 = _T("0x66");
	m_strBiasReg6 = _T("0x66");
	m_strBiasReg7 = _T("0x06");
	m_strBiasReg8 = _T("0x06");
	UpdateData(FALSE);
}