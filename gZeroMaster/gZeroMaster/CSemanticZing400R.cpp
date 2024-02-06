// CSemanticZing400R.cpp: 구현 파일
//

#include "pch.h"
#include "CSemanticZing400R.h"


// CSemanticZing400R 대화 상자

IMPLEMENT_DYNAMIC(CSemanticZing400R, CSemanticBase)

CSemanticZing400R::CSemanticZing400R(CWnd* pParent /*=nullptr*/)
	: CSemanticBase(pParent)
{
}

CSemanticZing400R::~CSemanticZing400R()
{
}

void CSemanticZing400R::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSemanticZing400R, CSemanticBase)
END_MESSAGE_MAP()


// CSemanticZing400R 메시지 처리기


BOOL CSemanticZing400R::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CSemanticZing400R::OnChipConnect(CString chipModel)
{
	ASSERT(chipModel == _T("Zing400R"));
}


void CSemanticZing400R::OnBnClickedDefaultValueButton()
{
}