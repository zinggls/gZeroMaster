// CRaw.cpp: 구현 파일
//

#include "pch.h"
#include "gZeroMaster.h"
#include "CRaw.h"
#include "afxdialogex.h"


// CRaw 대화 상자

IMPLEMENT_DYNAMIC(CRaw, CDialogEx)

CRaw::CRaw(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RAW_DIALOG, pParent)
{

}

CRaw::~CRaw()
{
}

void CRaw::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRaw, CDialogEx)
END_MESSAGE_MAP()


// CRaw 메시지 처리기
