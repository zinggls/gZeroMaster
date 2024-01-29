#pragma once

class CSemanticBase : public CDialogEx
{
	DECLARE_DYNAMIC(CSemanticBase)

public:
	CSemanticBase(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSemanticBase();
};