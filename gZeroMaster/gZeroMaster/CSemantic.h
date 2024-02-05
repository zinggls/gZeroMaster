#pragma once

#include "CSemanticBase.h"

// CSemantic 대화 상자

class CSemantic : public CSemanticBase
{
	DECLARE_DYNAMIC(CSemantic)

public:
	CSemantic(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSemantic();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEMANTIC_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedReadAllButton();
	afx_msg void OnCbnSelchangeControlCombo();
	BOOL UpdateSemanticValue(int addr, int (* fpNewRegVal)(int, int), int newVal, void (CSemantic::* fpUpdateData)(const CRegister&));
	afx_msg void OnBnClickedWriteButton();
	afx_msg void OnBnClickedWriteAllButton();
	BOOL UpdateSelected(SelectStatic selected, BOOL bCommonControl);
	void OnChipConnect(CString chipModel);
	afx_msg void OnBnClickedDefaultValueButton();
};
