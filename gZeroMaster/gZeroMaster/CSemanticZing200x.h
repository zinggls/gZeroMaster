#pragma once

#include "CSemanticBase.h"

// CSemantic 대화 상자

class CSemanticZing200x : public CSemanticBase
{
	DECLARE_DYNAMIC(CSemanticZing200x)

public:
	CSemanticZing200x(CWnd* pParent, CRawBase* pRawBase, CRegister* pRegister);   // 표준 생성자입니다.
	virtual ~CSemanticZing200x();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEMANTIC_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	virtual void OnChipConnect(CString chipModel);
	virtual const CRegister& Parse();
	virtual void UpdateRegisters();
};
