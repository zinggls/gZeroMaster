#pragma once

class CgZeroMasterDlg;

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
	CgZeroMasterDlg* Parent();
};
