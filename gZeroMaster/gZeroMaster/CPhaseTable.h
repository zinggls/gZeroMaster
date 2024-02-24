#pragma once

#include <afx.h>

class CPhaseTable {
public:
	static int getState(unsigned char I, unsigned char Q);
	static CString getPhase(int state);
};