// CRawZing400R.cpp: ���� ����
//

#include "pch.h"
#include "CRawZing400R.h"


// CRawZing400R ��ȭ ����

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
}


BEGIN_MESSAGE_MAP(CRawZing400R, CDialogEx)
END_MESSAGE_MAP()


// CRawZing400R �޽��� ó����


BOOL CRawZing400R::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
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
	//IBase���� ����� ���������Լ� ������ ������ ���� ���� ������ ���� �����θ� ����
}