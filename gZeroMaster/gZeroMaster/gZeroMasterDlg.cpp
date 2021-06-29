﻿
// gZeroMasterDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "gZeroMaster.h"
#include "gZeroMasterDlg.h"
#include "afxdialogex.h"
#include "CSemantic.h"
#include "CRaw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CgZeroMasterDlg 대화 상자



CgZeroMasterDlg::CgZeroMasterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GZEROMASTER_DIALOG, pParent)
	, m_pSemantic(NULL)
	, m_pRaw(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CgZeroMasterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LOG_LIST, m_log);
	DDX_Control(pDX, IDC_COM_COMBO, m_comPort);
	DDX_Control(pDX, IDC_TAB, m_tab);
}

BEGIN_MESSAGE_MAP(CgZeroMasterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT_BUTTON, &CgZeroMasterDlg::OnBnClickedConnectButton)
	ON_BN_CLICKED(IDC_LOG_CLEAR_BUTTON, &CgZeroMasterDlg::OnBnClickedLogClearButton)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CgZeroMasterDlg::OnTcnSelchangeTab)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CgZeroMasterDlg 메시지 처리기

BOOL CgZeroMasterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	for (int i = 1; i <= MAX_COMPORT; i++) {
		CString strVal;
		strVal.Format(_T("COM%d"), i);
		m_comPort.AddString(strVal);
	}
	m_comPort.SetCurSel(0);

	m_tab.InsertItem(0, _T("Semantic"));
	m_tab.InsertItem(1, _T("Raw"));

	m_tab.SetCurSel(0);

	CRect rect;
	m_tab.GetWindowRect(rect);

	m_pSemantic = new CSemantic(this);
	m_pSemantic->Create(IDD_SEMANTIC_DIALOG, &m_tab);
	m_pSemantic->MoveWindow(0, 20, rect.Width(), rect.Height());
	m_pSemantic->ShowWindow(SW_SHOW);

	m_pRaw = new CRaw(this);
	m_pRaw->Create(IDD_RAW_DIALOG, &m_tab);
	m_pRaw->MoveWindow(0, 20, rect.Width(), rect.Height());
	m_pRaw->ShowWindow(SW_HIDE);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CgZeroMasterDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CgZeroMasterDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CgZeroMasterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CgZeroMasterDlg::L(const TCHAR* str, ...)
{
	if (m_log.GetCount() >= MAX_LOG) {
		m_log.AddString(_T("Log >= MAX_LOG, Reset log"));
		m_log.ResetContent();
	}

	va_list args;
	va_start(args, str);

	int len = _vsctprintf(str, args) + 1;	//_vscprintf doesn't count terminating '\0'
	TCHAR* buffer = new TCHAR[len];
	_vstprintf(buffer, len, str, args);
	va_end(args);

	m_log.AddString(buffer);
	delete[](buffer);

	m_log.SetTopIndex(m_log.GetCount() - 1);
}

void CgZeroMasterDlg::ErrorMsg(LONG lError, LPCTSTR lptszMessage)
{
	CString str;
	str.Format(_T("%s(error code:%d)"), lptszMessage, lError);
	L(str);
}

void CgZeroMasterDlg::SerialClose(CString& str)
{
	LONG lLastError = m_serial.Close();
	if (lLastError == ERROR_SUCCESS) {
		GetDlgItem(IDC_COM_COMBO)->EnableWindow(TRUE);
		GetDlgItem(IDC_CONNECT_BUTTON)->SetWindowTextW(_T("connect"));
		L(str + _T(" closed"));
	}
	else {
		L(str + _T(" close failed"));
	}
	GetDlgItem(IDC_COM_COMBO)->EnableWindow(TRUE);
	m_pSemantic->ControlLabelEnable(FALSE);
	m_pSemantic->ControlValueEnable(FALSE);
	m_pRaw->GetDlgItem(IDC_READ_ALL_BUTTON)->ShowWindow(SW_HIDE);
}

void CgZeroMasterDlg::OnBnClickedConnectButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_COM_COMBO)->EnableWindow(FALSE);

	CString str;
	m_comPort.GetLBText(m_comPort.GetCurSel(), str);
	if (!m_serial.IsOpen()) {
		L(_T("Connecting to ") + str+_T("..."));

		LONG lLastError = m_serial.Open(str, 0, 0, false);
		if (lLastError == ERROR_SUCCESS) {
			GetDlgItem(IDC_CONNECT_BUTTON)->SetWindowTextW(_T("Disconnect"));
			L(str + _T(" opened"));

			lLastError = m_serial.Setup(CSerial::EBaud4800, CSerial::EData8, CSerial::EParNone, CSerial::EStop1);
			if (lLastError != ERROR_SUCCESS) return ErrorMsg(m_serial.GetLastError(), _T("Unable to set COM-port setting"));
			L(_T("setup ok"));

			lLastError = m_serial.SetupReadTimeouts(CSerial::EReadTimeoutNonblocking);
			if (lLastError != ERROR_SUCCESS) return ErrorMsg(m_serial.GetLastError(), _T("Unable to set COM-port read timeout"));

			if(m_pRaw->ReadResisters()) {
				m_pSemantic->UpdateRegisters();
				m_pSemantic->ControlLabelEnable(TRUE);
				m_pSemantic->ControlValueEnable(FALSE);
				m_pRaw->GetDlgItem(IDC_READ_ALL_BUTTON)->ShowWindow(SW_SHOW);
			}
			else {
				L(_T("Can't read resgisters"));
				SerialClose(str);
			}
		}
		else {
			GetDlgItem(IDC_COM_COMBO)->EnableWindow(TRUE);
			L(str + _T(" open failed"));
		}
	}
	else {
		SerialClose(str);
	}
}

void CgZeroMasterDlg::OnBnClickedLogClearButton()
{
	m_log.ResetContent();
	UpdateData(FALSE);
}

void CgZeroMasterDlg::OnTcnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (IDC_TAB == pNMHDR->idFrom) {
		int iSelect = m_tab.GetCurSel();
		switch (iSelect)
		{
		case 0:
			m_pSemantic->ShowWindow(SW_SHOW);
			m_pRaw->ShowWindow(SW_HIDE);
			break;
		case 1:
			m_pSemantic->ShowWindow(SW_HIDE);
			m_pRaw->ShowWindow(SW_SHOW);
			break;
		}
	}
	*pResult = 0;
}


void CgZeroMasterDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	delete m_pSemantic;
	delete m_pRaw;
}
