#pragma once

#include <map>
#define MAX_LOOP	100000

class CgZeroMasterDlg;

class CReg {
	CReg();
public:
	CReg(int addr, CString* pStr) :m_nAddr(addr), m_pStr(pStr) {}
	int m_nAddr;
	CString* m_pStr;
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
};
