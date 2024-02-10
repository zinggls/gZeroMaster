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
END_MESSAGE_MAP()


// CRawZing400R 메시지 처리기


BOOL CRawZing400R::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CRawZing400R::OnHideRegisterButtons(CString strChosenRegister)
{
}

void CRawZing400R::OnChipConnect(CString chipModel)
{
	ASSERT(chipModel == _T("Zing400R"));

	m_regMap.clear();
}

void CRawZing400R::OnBnClickedDefaultValueButton()
{
	//IBase에서 선언된 순수가상함수 컴파일 오류를 막기 위해 내용이 없는 구현부를 제공
}