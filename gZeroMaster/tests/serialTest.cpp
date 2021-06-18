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