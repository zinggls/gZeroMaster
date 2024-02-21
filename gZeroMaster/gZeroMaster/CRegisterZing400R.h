#pragma once

#include "CRegister.h"
#include "CBfBlock.h"

class CRegisterZing400R : public CRegister {
public:
	virtual ~CRegisterZing400R() {}

	CBfBlock m_block[4];
	int m_nVspsBias;
	int m_nLnaBias;
};