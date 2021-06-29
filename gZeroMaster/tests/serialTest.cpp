#include "pch.h"
#include <tchar.h>
#include <windows.h>
#include <Serial.h>

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

	lLastError = serial.SetupReadTimeouts(CSerial::EReadTimeoutNonblocking);	//Non Blocking옵션
	EXPECT_EQ(lLastError, ERROR_SUCCESS);

	char buffer[2] = { 0, };
	DWORD dwBytesRead = 0;
	lLastError = serial.Read(buffer, 2, &dwBytesRead);	//EReadTimeoutBlocking옵션을 사용했으면 여기서 블록된다
	EXPECT_EQ(lLastError, ERROR_SUCCESS);
	EXPECT_EQ(dwBytesRead, 0);

	lLastError = serial.Close();
	EXPECT_EQ(lLastError, ERROR_SUCCESS);
}