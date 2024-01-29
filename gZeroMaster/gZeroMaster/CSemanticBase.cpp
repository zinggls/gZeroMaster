#include "pch.h"
#include "CSemanticBase.h"

IMPLEMENT_DYNAMIC(CSemanticBase, CDialogEx)

CSemanticBase::CSemanticBase(CWnd* pParent /*=nullptr*/)
{
	m_pParentWnd = pParent;
}

CSemanticBase::~CSemanticBase()
{
}