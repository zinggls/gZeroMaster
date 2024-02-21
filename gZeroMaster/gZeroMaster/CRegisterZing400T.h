#pragma once

#include "CRegister.h"
#include "CBfBlock.h"

class CRegisterZing400T : public CRegister {
public:
	virtual ~CRegisterZing400T() {}

	int m_nVspsPa;
	int m_nVspsVga;
	int m_nVspsCs;
	CBfBlock m_block[4];
};