#include "pch.h"
#include "CSemanticBase.h"
#include "gZeroMasterDlg.h"

IMPLEMENT_DYNAMIC(CSemanticBase, CDialogEx)

CSemanticBase::CSemanticBase(CWnd* pParent /*=nullptr*/)
	: m_bSemanticEdit(FALSE)
	, m_bAutoWrite(FALSE)
	, m_selected(SelectStatic::None)
	, m_strSelectedStatic(_T(""))
	, m_strSliderMin(_T(""))
	, m_strSliderMax(_T(""))
	, m_strSliderValue(_T(""))
	, m_strSliderValueHex(_T(""))
	, m_strSliderValueBin(_T(""))
{
	m_pParentWnd = pParent;
}

CSemanticBase::~CSemanticBase()
{
}

CgZeroMasterDlg* CSemanticBase::Parent()
{
	return dynamic_cast<CgZeroMasterDlg*>(m_pParentWnd);
}