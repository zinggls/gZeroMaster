// CSemanticZing400T.cpp: ���� ����
//

#include "pch.h"
#include "CSemanticZing400T.h"


// CSemanticZing400T ��ȭ ����

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


// CSemanticZing400T �޽��� ó����


BOOL CSemanticZing400T::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CSemanticZing400T::OnChipConnect(CString chipModel)
{
	ASSERT(chipModel == _T("Zing400T"));
}


void CSemanticZing400T::OnBnClickedDefaultValueButton()
{
}