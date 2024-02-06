
// gZeroMasterDlg.h: 헤더 파일
//

#pragma once

#include <Serial.h>
#include <nlohmann/json.hpp>
#include "CRegister.h"

#define MAX_LOG					1000
#define MAX_COMPORT				25
#define ZMQ_TIMER				1

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
	CComboBox m_chipSelect;
	std::list<std::pair<std::string, int>> m_combos;
	std::list<std::pair<std::string, int>> m_sliders;
	void* m_context;
	void* m_responder;
	CString m_strTcpBindPort;
	BOOL m_bTcpBind;

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
	afx_msg void OnCbnSelchangeChipCombo();
	afx_msg void OnFileLoad();
	afx_msg void OnFileSavetofile();
	afx_msg void OnLogClear();
	afx_msg void OnUpdateFileLoad(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileSavetofile(CCmdUI* pCmdUI);
	afx_msg void OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu);
	afx_msg void OnEepromLoad();
	afx_msg void OnEepromSave();
	afx_msg void OnUpdateEepromLoad(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEepromSave(CCmdUI* pCmdUI);
	BOOL iterateJson(nlohmann::json j, CString& strErr);
	static int strBool2int(std::string strBool);
	static CString str2CStr(std::string str);
	void setCombos();
	void setSliders();
	int findCombos(std::string key);
	int findSliders(std::string key);
	void handleCombo(int nUserDefinedMessage, std::string key, int nCurSel);
	CString handleSlider(int nUserDefinedMessage, std::string key, int nVal);
	afx_msg void OnFileLoadjson();
	afx_msg void OnUpdateFileLoadjson(CCmdUI* pCmdUI);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	LRESULT OnDeviceChange(WPARAM wParam, LPARAM lParam);
	afx_msg void OnBnClickedTcpBindPortButton();
	void UpdateRegisters();
	void Parse(CRegister& reg);
};
