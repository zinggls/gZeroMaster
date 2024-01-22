#pragma once

class CgZeroMasterDlg;

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
	CgZeroMasterDlg* Parent();
};
