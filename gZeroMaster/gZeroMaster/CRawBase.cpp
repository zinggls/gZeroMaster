// CRawBase.cpp: ���� ����
//

#include "pch.h"
#include "CRawBase.h"
#include "gZeroMasterDlg.h"
#include "gZeroMaster.h"

// CRaw ��ȭ ����

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


// CRawBase �޽��� ó����


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
	if (dwBytesReadSum != sizeToRead) return ERROR_TIMEOUT;	//�����͸� Limited���ѳ��� ��ã����

	int i = 0;
	for (std::list<char>::iterator it = charList.begin(); it != charList.end(); ++it) pBuffer[i++] = *it;

#ifdef DEBUG_READ
	str.Format(_T("%d bytes received"), dwBytesRead);
	L(str);
#endif // DEBUG_READ

	pBuffer[sizeToRead] = 0;	//���ڿ� ���� ��Ÿ���� ���ؼ�

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
	while (ReadRegister(addr, 2, buffer, MAX_LOOP) != ERROR_SUCCESS) Sleep(10);	//Blocking �Լ�
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

void CRawBase::BitControlEnable(BOOL b)
{
	m_bit7.EnableWindow(b);
	m_bit6.EnableWindow(b);
	m_bit5.EnableWindow(b);
	m_bit4.EnableWindow(b);
	m_bit3.EnableWindow(b);
	m_bit2.EnableWindow(b);
	m_bit1.EnableWindow(b);
	m_bit0.EnableWindow(b);
}

void CRawBase::ShowWriteButtons(int nCmdShow)
{
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT7_BUTTON)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT6_BUTTON)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT5_BUTTON)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT4_BUTTON)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT3_BUTTON)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT2_BUTTON)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT1_BUTTON)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BIT0_BUTTON)->ShowWindow(nCmdShow);
}

BOOL CRawBase::WriteRegister(int addr, int value)
{
	char buffer[12] = { 0, };
	sprintf_s(buffer, sizeof(buffer), "%x", addr);

	size_t index = strlen(buffer);
	buffer[index] = 0xd;            //Enter
	buffer[index + 1] = 0x0;        //Write    0x0

	sprintf_s(buffer + index + 2, sizeof(buffer) - index - 2, "%x", value);
	size_t valLen = strlen(buffer + index + 2);

	buffer[index + 2 + valLen] = 0xd;

	ASSERT(Parent());
	ASSERT(Parent()->m_serial.IsOpen());

	DWORD dwBytesWrite = 0;
	LONG lLastError = Parent()->m_serial.Write(buffer, index + valLen + 3, &dwBytesWrite);
	if (lLastError != ERROR_SUCCESS) {
		Parent()->ErrorMsg(Parent()->m_serial.GetLastError(), _T("Unable to send data"));
		return FALSE;
	}
#ifdef DEBUG_WRITE
	CString str;
	str.Format(_T("%d bytes sent"), dwBytesWrite);
	Parent()->L(str);
#endif
	return TRUE;
}

void CRawBase::ToggleBit(CEdit& bit)
{
	CString strCurVal;
	bit.GetWindowText(strCurVal);
	(strCurVal == _T("0")) ? bit.SetWindowText(_T("1")) : bit.SetWindowText(_T("0"));
	ShowHexa();
}

COLORREF CRawBase::SetColor(CDC* pDC, CString given)
{
	if (m_strChosenRegister == given)
		return pDC->SetTextColor(RGB(255, 0, 0));
	else
		return pDC->SetTextColor(RGB(0, 0, 0));
}

void CRawBase::OnBnClickedBit7Button()
{
	ToggleBit(m_bit7);
}


void CRawBase::OnBnClickedBit6Button()
{
	ToggleBit(m_bit6);
}


void CRawBase::OnBnClickedBit5Button()
{
	ToggleBit(m_bit5);
}


void CRawBase::OnBnClickedBit4Button()
{
	ToggleBit(m_bit4);
}


void CRawBase::OnBnClickedBit3Button()
{
	ToggleBit(m_bit3);
}


void CRawBase::OnBnClickedBit2Button()
{
	ToggleBit(m_bit2);
}


void CRawBase::OnBnClickedBit1Button()
{
	ToggleBit(m_bit1);
}


void CRawBase::OnBnClickedBit0Button()
{
	ToggleBit(m_bit0);
}

void CRawBase::OnBnClickedEditCheck()
{
	m_bEdit = !m_bEdit;
	RegisterButtons();
	UpdateData(FALSE);
}

void CRawBase::OnBnClickedReadAllButton()
{
	ResetValues();
	if (!ReadRegisters()) Parent()->L(_T("Error occured in reading registers"));
}