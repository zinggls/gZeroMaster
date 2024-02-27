#include "pch.h"
#include "CPhaseTable.h"

int CPhaseTable::getState(unsigned char I, unsigned char Q)
{
	int hexa = ((I & 0x1F) << 5) | (Q & 0x1F);
	
	if (hexa == 0x3F0) return 1;
	else if (hexa == 0x3B9) return 2;
	else if (hexa == 0x3BA) return 3;
	else if (hexa == 0x3BB) return 4;
	else if (hexa == 0x35A) return 5;
	else if (hexa == 0x35B) return 6;
	else if (hexa == 0x31B) return 7;
	else if (hexa == 0x2BB) return 8;
	else if (hexa == 0x11C) return 9;
	else if (hexa == 0xDC) return 10;
	else if (hexa == 0xBC) return 11;
	else if (hexa == 0x7D) return 12;
	else if (hexa == 0x5C) return 13;
	else if (hexa == 0x3C) return 14;
	else if (hexa == 0x3B) return 15;
	else if (hexa == 0x1A) return 16;
	else if (hexa == 0xF) return 17;
	else if (hexa == 0x5) return 18;
	else if (hexa == 0x45) return 19;
	else if (hexa == 0x44) return 20;
	else if (hexa == 0x84) return 21;
	else if (hexa == 0xC4) return 22;
	else if (hexa == 0xC3) return 23;
	else if (hexa == 0x103) return 24;
	else if (hexa == 0x302) return 25;
	else if (hexa == 0x342) return 26;
	else if (hexa == 0x362) return 27;
	else if (hexa == 0x382) return 28;
	else if (hexa == 0x3A3) return 29;
	else if (hexa == 0x3A4) return 30;
	else if (hexa == 0x3C4) return 31;
	else if (hexa == 0x3A6) return 32;

	return -1;
}

int CPhaseTable::getPhase100Number(int state)
{
	int nPhase100;
	if (state >= 1 && state <= 17) {
		nPhase100 = (state - 1) * 1125;
	}
	else if (state >= 18 && state <= 32) {
		nPhase100 = -18000 + (state - 17) * 1125;
	}
	else {
		nPhase100 = -1;
	}
	return nPhase100;
}

CString CPhaseTable::getPhase(int state)
{
	if (state < 1 || state > 32) return CString(_T("undefined"));

	int nPhase100 = getPhase100Number(state);
	if (nPhase100 == -1) return CString(_T("undefined"));

	CString str;
	str.Format(_T("%.2f"),(float)nPhase100/100);
	return str;
}

unsigned int CPhaseTable::byteBitReverse(unsigned int num)
{
	const unsigned int NO_OF_BITS = 8;
	unsigned int reverse_num = 0;
	for (unsigned int i = 0; i < NO_OF_BITS; i++) {
		if ((num & (1 << i)))
			reverse_num |= 1 << ((NO_OF_BITS - 1) - i);
	}
	return reverse_num;
}

unsigned int CPhaseTable::reversePhaseBit(unsigned int num)
{
	return byteBitReverse(num) >> 3;
}

unsigned char CPhaseTable::getI(int state)
{
	ASSERT(state >= 1 && state <= 32);

	unsigned char val;
	switch (state) {
	case 1:
		val = 0x1f;
		break;
	case 2:
		val = 0x1d;
		break;
	case 3:
		val = 0x1d;
		break;
	case 4:
		val = 0x1d;
		break;
	case 5:
		val = 0x1a;
		break;
	case 6:
		val = 0x1a;
		break;
	case 7:
		val = 0x18;
		break;
	case 8:
		val = 0x15;
		break;
	case 9:
		val = 0x08;
		break;
	case 10:
		val = 0x06;
		break;
	case 11:
		val = 0x05;
		break;
	case 12:
		val = 0x03;
		break;
	case 13:
		val = 0x02;
		break;
	case 14:
		val = 0x01;
		break;
	case 15:
		val = 0x01;
		break;
	case 16:
		val = 0x00;
		break;
	case 17:
		val = 0x00;
		break;
	case 18:
		val = 0x00;
		break;
	case 19:
		val = 0x02;
		break;
	case 20:
		val = 0x02;
		break;
	case 21:
		val = 0x04;
		break;
	case 22:
		val = 0x06;
		break;
	case 23:
		val = 0x06;
		break;
	case 24:
		val = 0x08;
		break;
	case 25:
		val = 0x18;
		break;
	case 26:
		val = 0x1a;
		break;
	case 27:
		val = 0x1b;
		break;
	case 28:
		val = 0x1c;
		break;
	case 29:
		val = 0x1d;
		break;
	case 30:
		val = 0x1d;
		break;
	case 31:
		val = 0x1e;
		break;
	case 32:
		val = 0x1d;
		break;
	default:
		ASSERT(FALSE);	//이곳에 도달하면 안됨
		break;
	}
	return val;
}

unsigned char CPhaseTable::getQ(int state)
{
	ASSERT(state >= 1 && state <= 32);

	unsigned char val;
	switch (state) {
	case 1:
		val = 0x10;
		break;
	case 2:
		val = 0x19;
		break;
	case 3:
		val = 0x1a;
		break;
	case 4:
		val = 0x1b;
		break;
	case 5:
		val = 0x1a;
		break;
	case 6:
		val = 0x1b;
		break;
	case 7:
		val = 0x1b;
		break;
	case 8:
		val = 0x1b;
		break;
	case 9:
		val = 0x1c;
		break;
	case 10:
		val = 0x1c;
		break;
	case 11:
		val = 0x1c;
		break;
	case 12:
		val = 0x1d;
		break;
	case 13:
		val = 0x1c;
		break;
	case 14:
		val = 0x1c;
		break;
	case 15:
		val = 0x1b;
		break;
	case 16:
		val = 0x1a;
		break;
	case 17:
		val = 0x0f;
		break;
	case 18:
		val = 0x05;
		break;
	case 19:
		val = 0x05;
		break;
	case 20:
		val = 0x04;
		break;
	case 21:
		val = 0x04;
		break;
	case 22:
		val = 0x04;
		break;
	case 23:
		val = 0x03;
		break;
	case 24:
		val = 0x03;
		break;
	case 25:
		val = 0x02;
		break;
	case 26:
		val = 0x02;
		break;
	case 27:
		val = 0x02;
		break;
	case 28:
		val = 0x02;
		break;
	case 29:
		val = 0x03;
		break;
	case 30:
		val = 0x04;
		break;
	case 31:
		val = 0x04;
		break;
	case 32:
		val = 0x06;
		break;
	default:
		ASSERT(FALSE);	//이곳에 도달하면 안됨
		break;
	}
	return val;
}