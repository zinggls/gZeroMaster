// CRawZing400T.cpp: 구현 파일
//

#include "pch.h"
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
}


BEGIN_MESSAGE_MAP(CRawZing400T, CDialogEx)
END_MESSAGE_MAP()


// CRawZing400T 메시지 처리기


BOOL CRawZing400T::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

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
}

void CRawZing400T::OnBnClickedDefaultValueButton()
{
	//IBase에서 선언된 순수가상함수 컴파일 오류를 막기 위해 내용이 없는 구현부를 제공
}