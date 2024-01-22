// CRawBase.cpp: 구현 파일
//

#include "pch.h"
#include "CRawBase.h"
#include "gZeroMasterDlg.h"
#include "gZeroMaster.h"

// CRaw 대화 상자

IMPLEMENT_DYNAMIC(CRawBase, CDialogEx)

CRawBase::CRawBase(CWnd* pParent /*=nullptr*/)
	: m_strHex(_T(""))
	, m_strChosenRegister(_T(""))
	, m_bEdit(FALSE)
{
	m_pParentWnd = pParent;
}

CRawBase::~CRawBase()
{
}

void CRawBase::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRawBase, CDialogEx)

END_MESSAGE_MAP()


// CRawBase 메시지 처리기


CgZeroMasterDlg* CRawBase::Parent()
{
	return dynamic_cast<CgZeroMasterDlg*>(m_pParentWnd);
}

LONG CRawBase::SendReadCommand(int addr)
{
	char buffer[4] = { 0, };
	sprintf_s(buffer, "%x", addr);

	size_t index = strlen(buffer);
	buffer[index] = 0xd;		//Enter
	buffer[index + 1] = 0x1;	//Read	0x1

	ASSERT(Parent());
	ASSERT(Parent()->m_serial.IsOpen());

	DWORD dwBytesWrite = 0;
	return Parent()->m_serial.Write(buffer, index + 2, &dwBytesWrite);
}

LONG CRawBase::ReadRegister(int addr, DWORD sizeToRead, char* pBuffer, int maxLoop)
{
	LONG lLastError = SendReadCommand(addr);
	if (lLastError != ERROR_SUCCESS) {
		Parent()->ErrorMsg(Parent()->m_serial.GetLastError(), _T("Unable to send data"));
		return lLastError;
	}

#ifdef DEBUG_READ
	CString str;
	str.Format(_T("%d bytes written"), dwBytesWrite);
	L(str);
#endif // DEBUG_READ

	DWORD dwBytesReadSum, dwBytesRead;
	dwBytesReadSum = dwBytesRead = 0;

	int loop = 0;
	std::list<char> charList;
	do {
		char* tmp = new char[sizeToRead];
		lLastError = Parent()->m_serial.Read(tmp, sizeToRead, &dwBytesRead);
		if (lLastError != ERROR_SUCCESS) {
			Parent()->ErrorMsg(Parent()->m_serial.GetLastError(), _T("Unable to receive data"));
			delete[] tmp;
			return lLastError;
		}
		if (dwBytesRead > 0) {
			dwBytesReadSum += dwBytesRead;
			for (DWORD i = 0; i < dwBytesRead; i++) charList.push_back(tmp[i]);
		}
		delete[] tmp;
		loop++;
	} while ((dwBytesReadSum < sizeToRead) && (loop < maxLoop));
	if (dwBytesReadSum != sizeToRead) return ERROR_TIMEOUT;	//데이터를 Limited기한내에 못찾았음

	int i = 0;
	for (std::list<char>::iterator it = charList.begin(); it != charList.end(); ++it) pBuffer[i++] = *it;

#ifdef DEBUG_READ
	str.Format(_T("%d bytes received"), dwBytesRead);
	L(str);
#endif // DEBUG_READ

	pBuffer[sizeToRead] = 0;	//문자열 끝을 나타내기 위해서

#ifdef DEBUG_READ
	str.Format(_T("Address:0x%02x Register:0x%02x"), addr, *value);
	L(str);
#endif // DEBUG_READ
	return ERROR_SUCCESS;
}

BOOL CRawBase::ReadRegisters()
{
	for (std::map<CString, CReg>::iterator it = m_regMap.begin(); it != m_regMap.end(); it++) {
		if (ReadRegister(it->second.m_nAddr, it->first, it->second.m_pStr, MAX_LOOP) != TRUE) return FALSE;
		CString str;
		str.Format(_T("Address:0x%02x %s %s"), it->second.m_nAddr, it->first, it->second.m_pStr->GetBuffer());
		Parent()->L(str);
	}
	return TRUE;
}

void CRawBase::ReadRegister(int addr, CString name, CString* pValueStr)
{
	char buffer[3];
	while (ReadRegister(addr, 2, buffer, MAX_LOOP) != ERROR_SUCCESS) Sleep(10);	//Blocking 함수
	pValueStr->Format(_T("0x%02x"), (int)strtol(buffer, NULL, 16));
	UpdateData(FALSE);
}

BOOL CRawBase::ReadRegister(int addr, CString name, CString* pValueStr, int maxLoop)
{
	char buffer[3];
	LONG lLastError = ReadRegister(addr, 2, buffer, maxLoop);
	if (lLastError != ERROR_SUCCESS) {
		Parent()->ErrorMsg(lLastError, _T("CRawBase::PrintRegister Error in ReadRegister"));
		return FALSE;
	}
	pValueStr->Format(_T("0x%02x"), (int)strtol(buffer, NULL, 16));
	UpdateData(FALSE);
	return TRUE;
}

void CRawBase::ReadRegister(int addr)
{
	for (std::map<CString, CReg>::iterator it = m_regMap.begin(); it != m_regMap.end(); it++) {
		if (addr == it->second.m_nAddr) {
			ReadRegister(it->second.m_nAddr, it->first, it->second.m_pStr);
			return;
		}
	}
}

CString CRawBase::RegisterName(int addr)
{
	for (std::map<CString, CReg>::iterator it = m_regMap.begin(); it != m_regMap.end(); it++) {
		if (addr == it->second.m_nAddr) {
			return it->first;
		}
	}
	return _T("");
}

void CRawBase::ShowBits(unsigned char byte)
{
	ShowBitWindow(SW_SHOW);
	(byte & 0x80) ? m_bit7.SetWindowText(_T("1")) : m_bit7.SetWindowText(_T("0"));
	(byte & 0x40) ? m_bit6.SetWindowText(_T("1")) : m_bit6.SetWindowText(_T("0"));
	(byte & 0x20) ? m_bit5.SetWindowText(_T("1")) : m_bit5.SetWindowText(_T("0"));
	(byte & 0x10) ? m_bit4.SetWindowText(_T("1")) : m_bit4.SetWindowText(_T("0"));
	(byte & 0x08) ? m_bit3.SetWindowText(_T("1")) : m_bit3.SetWindowText(_T("0"));
	(byte & 0x04) ? m_bit2.SetWindowText(_T("1")) : m_bit2.SetWindowText(_T("0"));
	(byte & 0x02) ? m_bit1.SetWindowText(_T("1")) : m_bit1.SetWindowText(_T("0"));
	(byte & 0x01) ? m_bit0.SetWindowText(_T("1")) : m_bit0.SetWindowText(_T("0"));
	ShowHexa();
}

void CRawBase::ShowBitWindow(int nCmdShow)
{
	GetDlgItem(IDC_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT_EDIT7)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT_EDIT6)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT_EDIT5)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT_EDIT4)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT_EDIT3)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT_EDIT2)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT_EDIT1)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT_EDIT0)->ShowWindow(nCmdShow);

	GetDlgItem(IDC_STATIC7)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_STATIC6)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_STATIC5)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_STATIC4)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_STATIC3)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_STATIC2)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_STATIC1)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_STATIC0)->ShowWindow(nCmdShow);
}

void CRawBase::ShowHexa()
{
	m_strHex.Format(_T("0x%02x"), GetValueFromBits());
	UpdateData(FALSE);
}

int CRawBase::GetValueFromBits()
{
	int value = 0;

	CString str;
	m_bit7.GetWindowText(str);
	if (str == _T("1")) value = 0x80;

	m_bit6.GetWindowText(str);
	if (str == _T("1")) value |= 0x40;

	m_bit5.GetWindowText(str);
	if (str == _T("1")) value |= 0x20;

	m_bit4.GetWindowText(str);
	if (str == _T("1")) value |= 0x10;

	m_bit3.GetWindowText(str);
	if (str == _T("1")) value |= 0x08;

	m_bit2.GetWindowText(str);
	if (str == _T("1")) value |= 0x04;

	m_bit1.GetWindowText(str);
	if (str == _T("1")) value |= 0x02;

	m_bit0.GetWindowText(str);
	if (str == _T("1")) value |= 0x01;

	str.Format(_T("0x%02x"), value);
	Parent()->L(_T("Value read from the Bits:") + str);
	return value;
}