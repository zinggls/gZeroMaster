#pragma once

#include <afx.h>

class CPhaseTable {
public:
	static int getState(unsigned char I, unsigned char Q);
	static int getPhase100Number(int state);
	static CString getPhase(int state);
	static unsigned int byteBitReverse(unsigned int num);
	static unsigned int reversePhaseBit(unsigned int num);
	static unsigned char CPhaseTable::getI(int state);
};