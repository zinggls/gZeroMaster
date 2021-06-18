
// gZeroMasterDlg.h: 헤더 파일
//

#pragma once

#define MAX_LOG					1000
#define MAX_COMPORT				25

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
	CListBox m_log;
	CComboBox m_comPort;

	void L(const TCHAR* str, ...);
};
