#pragma once

#include "CSemanticBase.h"

// CSemanticZing400R ��ȭ ����

class CSemanticZing400R : public CSemanticBase
{
	DECLARE_DYNAMIC(CSemanticZing400R)

public:
	CSemanticZing400R(CWnd* pParent = nullptr);   // ǥ�� �������Դϴ�.
	virtual ~CSemanticZing400R();

	// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEMANTIC_ZING400T_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	virtual void OnChipConnect(CString chipModel);
	virtual afx_msg void OnBnClickedDefaultValueButton();
	virtual void ControlLabelEnable(BOOL b);
};
