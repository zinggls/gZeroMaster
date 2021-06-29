#include "pch.h"
#include <tchar.h>
#include <windows.h>
#include <Serial.h>
#include <stdio.h>
#include <list>

TEST(Serial, open) {
	CSerial serial;

	LONG lLastError = serial.Open(_T("COM1"), 0, 0, false);
	EXPECT_EQ(lLastError, ERROR_SUCCESS);
	lLastError = serial.Close();
	EXPECT_EQ(lLastError, ERROR_SUCCESS);
}

TEST(Serial, nonBlocking) {
	CSerial serial;

	LONG lLastError = serial.Open(_T("COM5"), 0, 0, false);
	EXPECT_EQ(lLastError, ERROR_SUCCESS);

	lLastError = serial.Setup(CSerial::EBaud4800, CSerial::EData8, CSerial::EParNone, CSerial::EStop1);
	EXPECT_EQ(lLastError, ERROR_SUCCESS);

	lLastError = serial.SetupReadTimeouts(CSerial::EReadTimeoutNonblocking);	//Non Blocking�ɼ�
	EXPECT_EQ(lLastError, ERROR_SUCCESS);

	char buffer[2] = { 0, };
	DWORD dwBytesRead = 0;
	lLastError = serial.Read(buffer, 2, &dwBytesRead);	//EReadTimeoutBlocking�ɼ��� ��������� ���⼭ ��ϵȴ�
	EXPECT_EQ(lLastError, ERROR_SUCCESS);
	EXPECT_EQ(dwBytesRead, 0);

	lLastError = serial.Close();
	EXPECT_EQ(lLastError, ERROR_SUCCESS);
}

void ReadResister(CSerial &serial, int addr, int* value)
{
	char buffer[4] = { 0, };
	sprintf_s(buffer, "%x", addr);

	size_t index = strlen(buffer);
	buffer[index] = 0xd;		//Enter
	buffer[index + 1] = 0x1;	//Read	0x1

	EXPECT_EQ(serial.IsOpen(),TRUE);

	DWORD dwBytesWrite = 0;
	LONG lLastError = serial.Write(buffer, index + 2, &dwBytesWrite);
	EXPECT_EQ(lLastError, ERROR_SUCCESS);
	EXPECT_EQ(dwBytesWrite, index + 2);

	DWORD dwBytesReadSum,dwBytesRead;
	dwBytesReadSum = dwBytesRead = 0;

	std::list<char> charList;
	do {
		char tmp[2];
		lLastError = serial.Read(tmp, 2, &dwBytesRead);
		EXPECT_EQ(lLastError, ERROR_SUCCESS);
		if (dwBytesRead > 0) {
			dwBytesReadSum += dwBytesRead;
			for (DWORD i = 0; i < dwBytesRead; i++) charList.push_back(tmp[i]);
		}
	} while (dwBytesReadSum < 2);
	EXPECT_EQ(dwBytesReadSum, 2);
	EXPECT_EQ(charList.size(), 2);


	int i = 0;
	for (std::list<char>::iterator it = charList.begin(); it != charList.end(); ++it) buffer[i++] = *it;
		
	buffer[2] = 0;	//���ڿ� ���� ��Ÿ���� ���ؼ�
	*value = (int)strtol(buffer, NULL, 16);
}

TEST(Serial, NonBlockingRegisterRead) {
	CSerial serial;

	LONG lLastError = serial.Open(_T("COM5"), 0, 0, false);
	EXPECT_EQ(lLastError, ERROR_SUCCESS);

	lLastError = serial.Setup(CSerial::EBaud4800, CSerial::EData8, CSerial::EParNone, CSerial::EStop1);
	EXPECT_EQ(lLastError, ERROR_SUCCESS);

	lLastError = serial.SetupReadTimeouts(CSerial::EReadTimeoutNonblocking);	//Non Blocking�ɼ�
	EXPECT_EQ(lLastError, ERROR_SUCCESS);

	int addr[] = { 2,7,6,5,13,12,11,17,18,19,20,21,22,23,24 };
	EXPECT_EQ(sizeof(addr) / sizeof(int), 15);

	int value;
	for(int i=0;i<sizeof(addr)/sizeof(int);i++) {
		ReadResister(serial, addr[i], &value);
		printf("Address:0x%02x Register:0x%02x\n", addr[i], value);
	}

	lLastError = serial.Close();
	EXPECT_EQ(lLastError, ERROR_SUCCESS);
}

bool LimitedReadResister(CSerial& serial, int addr, int* value, int maxLoop)
{
	char buffer[4] = { 0, };
	sprintf_s(buffer, "%x", addr);

	size_t index = strlen(buffer);
	buffer[index] = 0xd;		//Enter
	buffer[index + 1] = 0x1;	//Read	0x1

	EXPECT_EQ(serial.IsOpen(), TRUE);

	DWORD dwBytesWrite = 0;
	LONG lLastError = serial.Write(buffer, index + 2, &dwBytesWrite);
	EXPECT_EQ(lLastError, ERROR_SUCCESS);
	EXPECT_EQ(dwBytesWrite, index + 2);

	DWORD dwBytesReadSum, dwBytesRead;
	dwBytesReadSum = dwBytesRead = 0;

	int loop = 0;
	std::list<char> charList;
	do {
		char tmp[2];
		lLastError = serial.Read(tmp, 2, &dwBytesRead);
		EXPECT_EQ(lLastError, ERROR_SUCCESS);
		if (dwBytesRead > 0) {
			dwBytesReadSum += dwBytesRead;
			for (DWORD i = 0; i < dwBytesRead; i++) charList.push_back(tmp[i]);
		}
		loop++;
	} while ( (dwBytesReadSum<2) && (loop<maxLoop));

	if (dwBytesReadSum != 2) return false;	//�����͸� Limited���ѳ��� ��ã����

	int i = 0;
	for (std::list<char>::iterator it = charList.begin(); it != charList.end(); ++it) buffer[i++] = *it;

	buffer[2] = 0;	//���ڿ� ���� ��Ÿ���� ���ؼ�
	*value = (int)strtol(buffer, NULL, 16);
	return true;
}

void regReadTest(const TCHAR *comPort,int maxLoop)
{
	CSerial serial;

	LONG lLastError = serial.Open(comPort, 0, 0, false);		//COM1�� �����ϴ� ��Ʈ�̳� �Ʒ��� ���������� �������� �ʴ� ��Ʈ�� ���� �����͸� ������ �� ���� ��Ʈ��
	EXPECT_EQ(lLastError, ERROR_SUCCESS);

	lLastError = serial.Setup(CSerial::EBaud4800, CSerial::EData8, CSerial::EParNone, CSerial::EStop1);
	EXPECT_EQ(lLastError, ERROR_SUCCESS);

	lLastError = serial.SetupReadTimeouts(CSerial::EReadTimeoutNonblocking);	//Non Blocking�ɼ�
	EXPECT_EQ(lLastError, ERROR_SUCCESS);

	int addr[] = { 2,7,6,5,13,12,11,17,18,19,20,21,22,23,24 };
	EXPECT_EQ(sizeof(addr) / sizeof(int), 15);

	int value;
	for (int i = 0; i < sizeof(addr) / sizeof(int); i++) {
		if (LimitedReadResister(serial, addr[i], &value, maxLoop)) {
			printf("Address:0x%02x Register:0x%02x\n", addr[i], value);
		}
	}

	lLastError = serial.Close();
	EXPECT_EQ(lLastError, ERROR_SUCCESS);
}

TEST(Serial, NonBlockingLimitedRegisterRead_NoRespondingComPort) {
	regReadTest(_T("COM1"), 50000);	//COM1�� �����ϴ� ��Ʈ�̳� �Ʒ��� ���������� �������� �ʴ� ��Ʈ�� ���� �����͸� ������ �� ���� ��Ʈ��
}

TEST(Serial, NonBlockingLimitedRegisterRead_RespondingComPort) {
	regReadTest(_T("COM5"),50000);	//COM5�� B0 SPI�� ����ϸ� ��û�� �ּ��� �������Ͱ��� ��ȯ�ϴ� ��Ʈ��
}