#pragma once


// CRaw 대화 상자

class CRaw : public CDialogEx
{
	DECLARE_DYNAMIC(CRaw)

public:
	CRaw(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CRaw();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RAW_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
