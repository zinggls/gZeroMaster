#pragma once

#include "CRegister.h"

class CBfBlock {
public:
	int m_nBlock;
	int m_nQ;
	int m_nI;
};

class CRegisterZing400T : public CRegister {
public:
	virtual ~CRegisterZing400T() {}

	int m_nVspsPa;
	int m_nVspsVga;
	int m_nVspsCs;
	CBfBlock m_block[4];
};