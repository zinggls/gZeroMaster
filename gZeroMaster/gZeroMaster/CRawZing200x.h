#pragma once

#include "CRawBase.h"

// CRawZing200x 대화 상자

class CRawZing200x : public CRawBase
{
	DECLARE_DYNAMIC(CRawZing200x)

public:
	CRawZing200x(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CRawZing200x();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RAW_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	virtual void OnHideRegisterButtons(CString strChosenRegister);
	virtual void OnChipConnect(CString chipModel);
	virtual void DefaultValues(CString strChip);
};
