// CRawZing400T.cpp: ���� ����
//

#include "pch.h"
#include "CRawZing400T.h"


// CRawZing400T ��ȭ ����

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


// CRawZing400T �޽��� ó����


BOOL CRawZing400T::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
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
	//IBase���� ����� ���������Լ� ������ ������ ���� ���� ������ ���� �����θ� ����
}