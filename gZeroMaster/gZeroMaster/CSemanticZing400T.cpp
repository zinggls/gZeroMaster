// CSemanticZing400T.cpp: 구현 파일
//

#include "pch.h"
#include "CSemanticZing400T.h"


// CSemanticZing400T 대화 상자

IMPLEMENT_DYNAMIC(CSemanticZing400T, CSemanticBase)

CSemanticZing400T::CSemanticZing400T(CWnd* pParent /*=nullptr*/)
	: CSemanticBase(pParent)
{
}

CSemanticZing400T::~CSemanticZing400T()
{
}

void CSemanticZing400T::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSemanticZing400T, CSemanticBase)
END_MESSAGE_MAP()


// CSemanticZing400T 메시지 처리기


BOOL CSemanticZing400T::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CSemanticZing400T::OnChipConnect(CString chipModel)
{
	ASSERT(chipModel == _T("Zing400T"));
}


void CSemanticZing400T::OnBnClickedDefaultValueButton()
{
}