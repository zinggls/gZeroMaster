#pragma once

#include <map>
#include <list>
#define MAX_LOOP	100000

class CgZeroMasterDlg;

class CReg {
	CReg();
public:
	CReg(int addr, CString* pStr, UINT idc) :m_nAddr(addr), m_pStr(pStr), m_uIdcStatic(idc) {}
	int m_nAddr;
	CString* m_pStr;
	UINT m_uIdcStatic;
};

// CRaw 대화 상자

class CRawBase : public CDialogEx
{
	DECLARE_DYNAMIC(CRawBase)

public:
	CRawBase(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CRawBase();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	std::map<CString, CReg> m_regMap;
	CEdit m_bit7;
	CEdit m_bit6;
	CEdit m_bit5;
	CEdit m_bit4;
	CEdit m_bit3;
	CEdit m_bit2;
	CEdit m_bit1;
	CEdit m_bit0;
	CString m_strHex;
	CString m_strChosenRegister;
	BOOL m_bEdit;
	std::list<CString*> m_strList;

public:
	CgZeroMasterDlg* Parent();
	LONG SendReadCommand(int addr);
	LONG ReadRegister(int addr, DWORD sizeToRead, char* pBuffer, int maxLoop);
	BOOL ReadRegisters();
	void ReadRegister(int addr);
	void ReadRegister(int addr, CString name, CString* pValueStr);
	BOOL ReadRegister(int addr, CString name, CString* pValueStr, int maxLoop);
	CString RegisterName(int addr);
	void ShowBits(unsigned char byte);
	void ShowBitWindow(int nCmdShow);
	void ShowHexa();
	int GetValueFromBits();
	void BitControlEnable(BOOL b);
	void ShowWriteButtons(int nCmdShow);
	BOOL WriteRegister(int addr, int value);
	void ToggleBit(CEdit& bit);
	COLORREF SetColor(CDC* pDC, CString given);
	afx_msg void OnBnClickedBit7Button();
	afx_msg void OnBnClickedBit6Button();
	afx_msg void OnBnClickedBit5Button();
	afx_msg void OnBnClickedBit4Button();
	afx_msg void OnBnClickedBit3Button();
	afx_msg void OnBnClickedBit2Button();
	afx_msg void OnBnClickedBit1Button();
	afx_msg void OnBnClickedBit0Button();
	afx_msg void OnBnClickedEditCheck();
	virtual afx_msg void OnBnClickedReadAllButton();
	virtual afx_msg void OnBnClickedWriteButton();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	void RegisterButtons();
	virtual void OnHideRegisterButtons(CString strChosenRegister)=0;
	void ResetValues();
	void OnStnClicked(UINT idcEdit, CString& strReg, UINT idcReg, CStringList& msgList);
};
