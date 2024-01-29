#pragma once

class CSemanticBase : public CDialogEx
{
	DECLARE_DYNAMIC(CSemanticBase)

public:
	CSemanticBase(CWnd* pParent = nullptr);   // ǥ�� �������Դϴ�.
	virtual ~CSemanticBase();

public:
	CSliderCtrl m_controlSlider;
	BOOL m_bSemanticEdit;
	BOOL m_bAutoWrite;

	enum class SelectStatic {
		None = 0, RxData, LimAmp, LnaGain, DutyCycle, VcoOsc, RegRef, VcoVdd, VcoPow, ModPow, TestBufPow,
		DataInp, PaPow, PaGain1, PaGain2, TestBuffer, BiasBlock, Lna1, Lna2, Lna3, Lna4, Lna5, RefStage, IpStage, Fb, Core, OP, IP, HL, CMOS, CML, FdCore, FdBuf
	};
	SelectStatic m_selected;

	CString m_strSelectedStatic;
	CString m_strSliderMin;
	CString m_strSliderMax;
	CString m_strSliderValue;
	CString m_strSliderValueHex;
	CString m_strSliderValueBin;
	CComboBox m_controlCombo;
};