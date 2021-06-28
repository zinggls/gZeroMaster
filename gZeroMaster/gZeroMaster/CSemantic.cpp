// CSemantic.cpp: 구현 파일
//

#include "pch.h"
#include "gZeroMaster.h"
#include "CSemantic.h"
#include "afxdialogex.h"
#include "gZeroMasterDlg.h"
#include "CRaw.h"


// CSemantic 대화 상자

IMPLEMENT_DYNAMIC(CSemantic, CDialogEx)

CSemantic::CSemantic(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SEMANTIC_DIALOG, pParent)
	, m_bRxDataInterface(FALSE)
	, m_bLimitingAmplifier(FALSE)
	, m_strLnaGain(_T(""))
	, m_pParent(pParent)
{

}

CSemantic::~CSemantic()
{
}

void CSemantic::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_RX_DATA_IF_ENABLE_CHECK, m_bRxDataInterface);
	DDX_Check(pDX, IDC_LIMITING_AMP_ENABLE_CHECK, m_bLimitingAmplifier);
	DDX_Text(pDX, IDC_LNA_GAIN_VALUE_STATIC, m_strLnaGain);
}


BEGIN_MESSAGE_MAP(CSemantic, CDialogEx)
	ON_BN_CLICKED(IDC_RX_DATA_IF_ENABLE_CHECK, &CSemantic::OnBnClickedRxDataIfEnableCheck)
	ON_BN_CLICKED(IDC_LIMITING_AMP_ENABLE_CHECK, &CSemantic::OnBnClickedLimitingAmpEnableCheck)
END_MESSAGE_MAP()


CgZeroMasterDlg* CSemantic::Parent()
{
	return dynamic_cast<CgZeroMasterDlg*>(m_pParent);
}


// CSemantic 메시지 처리기


void CSemantic::OnBnClickedRxDataIfEnableCheck()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bRxDataInterface = !m_bRxDataInterface;
	UpdateData(FALSE);
}


void CSemantic::OnBnClickedLimitingAmpEnableCheck()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bLimitingAmplifier = !m_bLimitingAmplifier;
	UpdateData(FALSE);
}


BOOL CSemantic::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	ControlEnable(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CSemantic::UpdateRegisters()
{
	ASSERT(Parent());
	UpdateRxReg1(Parent()->m_pRaw->m_strRxReg1);
	UpdateData(FALSE);
}

void CSemantic::UpdateRxReg1(CString strRxReg1)
{
	int val = _tcstol(strRxReg1.GetBuffer(), NULL, 16) & 0xff;

	m_bRxDataInterface = (val & 0x10) >> 4;
	m_bLimitingAmplifier = (val & 0x08) >> 3;
	m_strLnaGain.Format(_T("0x%02x"), val & 0x07);
}


void CSemantic::ControlEnable(BOOL b)
{
	GetDlgItem(IDC_RX_DATA_IF_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LIMITING_AMP_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA_GAIN_STATIC)->EnableWindow(b);

	GetDlgItem(IDC_RX_DATA_IF_ENABLE_CHECK)->EnableWindow(b);
	GetDlgItem(IDC_LIMITING_AMP_ENABLE_CHECK)->EnableWindow(b);
	GetDlgItem(IDC_LNA_GAIN_VALUE_STATIC)->EnableWindow(b);
}