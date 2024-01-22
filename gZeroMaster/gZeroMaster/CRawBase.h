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

// CRaw ��ȭ ����

class CRawBase : public CDialogEx
{
	DECLARE_DYNAMIC(CRawBase)

public:
	CRawBase(CWnd* pParent = nullptr);   // ǥ�� �������Դϴ�.
	virtual ~CRawBase();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	std::map<CString, CReg> m_regMap;

public:
	CgZeroMasterDlg* Parent();
	LONG SendReadCommand(int addr);
	LONG ReadRegister(int addr, DWORD sizeToRead, char* pBuffer, int maxLoop);
	BOOL ReadRegisters();
	void ReadRegister(int addr);
	void ReadRegister(int addr, CString name, CString* pValueStr);
	BOOL ReadRegister(int addr, CString name, CString* pValueStr, int maxLoop);
};
