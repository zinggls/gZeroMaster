#pragma once

class IBase : public CDialogEx {
public:
	virtual ~IBase() {};
	virtual void OnChipConnect(CString chipModel)=0;
};