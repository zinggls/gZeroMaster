#pragma once

#include "CRawBase.h"

// CRawZing400T ��ȭ ����

class CRawZing400T : public CRawBase
{
	DECLARE_DYNAMIC(CRawZing400T)

public:
	CRawZing400T(CWnd* pParent = nullptr);   // ǥ�� �������Դϴ�.
	virtual ~CRawZing400T();

	// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RAW_ZING400T_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	virtual void OnHideRegisterButtons(CString strChosenRegister);
	virtual void OnChipConnect(CString chipModel);
	virtual afx_msg void OnBnClickedDefaultValueButton();
};
