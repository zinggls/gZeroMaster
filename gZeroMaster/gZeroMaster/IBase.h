#pragma once

class IBase : public CDialogEx {
public:
	virtual ~IBase() {};
	virtual void OnChipConnect(CString chipModel)=0;
	virtual afx_msg void OnBnClickedDefaultValueButton() = 0;
	virtual afx_msg void OnBnClickedWriteButton()=0;
	virtual afx_msg void OnBnClickedReadAllButton()=0;
	virtual afx_msg void OnBnClickedWriteAllButton()=0;
};