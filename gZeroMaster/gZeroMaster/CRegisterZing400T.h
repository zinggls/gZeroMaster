#pragma once

#include "CRegister.h"

class CBfBlock {
	int m_nBlock;
	int m_nQ;
	int m_nI;
};

class CRegisterZing400T : public CRegister {
public:
	int m_nVspsPa;
	int m_nVspsVga;
	int m_nVspsCs;
	CBfBlock m_block[4];
};