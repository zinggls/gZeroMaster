// CSemantic.cpp: 구현 파일
//

#include "pch.h"
#include "gZeroMaster.h"
#include "CSemantic.h"
#include "afxdialogex.h"


// CSemantic 대화 상자

IMPLEMENT_DYNAMIC(CSemantic, CDialogEx)

CSemantic::CSemantic(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SEMANTIC_DIALOG, pParent)
	, m_bRxDataInterface(FALSE)
	, m_bLimitingAmplifier(FALSE)
	, m_strLnaGain(_T(""))
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
	m_bLimitingAmplifier = TRUE;
	m_bRxDataInterface = FALSE;

	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
