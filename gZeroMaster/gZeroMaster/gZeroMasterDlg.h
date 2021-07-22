
// gZeroMasterDlg.h: 헤더 파일
//

#pragma once

#include <Serial.h>

#define MAX_LOG					1000
#define MAX_COMPORT				25

class CSemantic;
class CRaw;

// CgZeroMasterDlg 대화 상자
class CgZeroMasterDlg : public CDialogEx
{
// 생성입니다.
public:
	CgZeroMasterDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GZEROMASTER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CSerial m_serial;
	CListBox m_log;
	CComboBox m_comPort;
	CTabCtrl m_tab;
	CSemantic *m_pSemantic;
	CRaw *m_pRaw;
	CString m_chip;

	void L(const TCHAR* str, ...);
	void Reset();
	void SerialClose(CString& str);
	afx_msg void OnBnClickedConnectButton();
	afx_msg void OnBnClickedLogClearButton();
	void ErrorMsg(LONG lError, LPCTSTR lptszMessage);
	afx_msg void OnTcnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDestroy();
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnMainmenuClearlog();
	afx_msg void OnMainmenuSave();
	void SaveRegisterA0(CString fileName);
	void SaveRegisterB0(CString fileName);
	void SaveRegisters(CString fileName);
	afx_msg void OnMainmenuLoad();
	BOOL LoadValue(TCHAR *regTagName, CString *pTargetStr, CString fileName);
	void CheckRxReg1(CString strRxReg1);
	void CheckTxReg2Top(CString strTxReg2Top);
	void CheckBiasReg1(CString strBiasReg1);
	BOOL LoadRegisters(CString fileName);
	afx_msg void OnStnDblclickLogoStatic();
};
