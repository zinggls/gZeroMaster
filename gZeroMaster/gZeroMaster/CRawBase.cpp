// CRawBase.cpp: 구현 파일
//

#include "pch.h"
#include "CRawBase.h"
#include "gZeroMasterDlg.h"

// CRaw 대화 상자

IMPLEMENT_DYNAMIC(CRawBase, CDialogEx)

CRawBase::CRawBase(CWnd* pParent /*=nullptr*/)
{
	m_pParentWnd = pParent;
}

CRawBase::~CRawBase()
{
}

void CRawBase::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRawBase, CDialogEx)

END_MESSAGE_MAP()


// CRawBase 메시지 처리기


CgZeroMasterDlg* CRawBase::Parent()
{
	return dynamic_cast<CgZeroMasterDlg*>(m_pParentWnd);
}