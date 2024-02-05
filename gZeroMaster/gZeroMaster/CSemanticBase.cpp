#include "pch.h"
#include "gZeroMaster.h"
#include "CSemanticBase.h"
#include "gZeroMasterDlg.h"
#include "CRaw.h"

IMPLEMENT_DYNAMIC(CSemanticBase, CDialogEx)

CSemanticBase::CSemanticBase(CWnd* pParent /*=nullptr*/)
	: m_bSemanticEdit(FALSE)
	, m_bAutoWrite(FALSE)
	, m_selected(SelectStatic::None)
	, m_strSelectedStatic(_T(""))
	, m_strSliderMin(_T(""))
	, m_strSliderMax(_T(""))
	, m_strSliderValue(_T(""))
	, m_strSliderValueHex(_T(""))
	, m_strSliderValueBin(_T(""))
	, m_strRxDataInterface(_T(""))
	, m_strLimitingAmplifier(_T(""))
	, m_strLnaGain(_T(""))
	, m_strRegRefVolt(_T(""))
	, m_strVcoPower(_T(""))
	, m_strModPower(_T(""))
	, m_strTestBufferPower(_T(""))
	, m_strDataInputSelect(_T(""))
	, m_strPaPower(_T(""))
	, m_strPaGainControl1(_T(""))
	, m_strPaGainControl2(_T(""))
	, m_strTestBufferCurrent(_T(""))
	, m_strBiasBlockEnable(_T(""))
	, m_strLna1Current(_T(""))
	, m_strLna2Current(_T(""))
	, m_strLna3Current(_T(""))
	, m_strLna4Current(_T(""))
	, m_strLna5Current(_T(""))
	, m_strDemodRefStageCurrent(_T(""))
	, m_strDemodIPStageCurrent(_T(""))
	, m_strLaCoreCurrent(_T(""))
	, m_strLaOPBufferCurrent(_T(""))
	, m_strLaIPBufferCurrent(_T(""))
	, m_strLaHLDataRateCurrent(_T(""))
	, m_strCMOSGainStageCurrent(_T(""))
	, m_strCMLInterfaceStageCurrent(_T(""))
	, m_strFdCoreCur(_T(""))
	, m_strFdBufCur(_T(""))
{
	m_pParentWnd = pParent;

	m_staticMap.clear();
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::LnaGain, CStaticElem(IDC_LNA_GAIN_VALUE_STATIC, &m_reg.m_nLnaGain)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::DutyCycle, CStaticElem(IDC_DUTY_CYCLE_VALUE_STATIC, &m_reg.m_nDutyCycle)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::VcoOsc, CStaticElem(IDC_VCO_OSC_FREQ_VALUE_STATIC, &m_reg.m_nVcoOsc)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::VcoVdd, CStaticElem(IDC_VCO_VDD_VALUE_STATIC, &m_reg.m_nVcoVdd)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::PaGain1, CStaticElem(IDC_PA_GAIN_CONTROL1_VALUE_STATIC, &m_reg.m_nPaGainCon1)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::PaGain2, CStaticElem(IDC_PA_GAIN_CONTROL2_VALUE_STATIC, &m_reg.m_nPaGainCon2)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::TestBuffer, CStaticElem(IDC_TEST_BUFFER_CURRENT_VALUE_STATIC, &m_reg.m_nTestBufCur)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::Lna1, CStaticElem(IDC_LNA1_BIAS_CURRENT_VALUE_STATIC, &m_reg.m_nLna1Cur)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::Lna2, CStaticElem(IDC_LNA2_BIAS_CURRENT_VALUE_STATIC, &m_reg.m_nLna2Cur)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::Lna3, CStaticElem(IDC_LNA3_BIAS_CURRENT_VALUE_STATIC, &m_reg.m_nLna3Cur)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::Lna4, CStaticElem(IDC_LNA4_BIAS_CURRENT_VALUE_STATIC, &m_reg.m_nLna4Cur)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::Lna5, CStaticElem(IDC_LNA5_BIAS_CURRENT_VALUE_STATIC, &m_reg.m_nLna5Cur)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::RefStage, CStaticElem(IDC_DEMOD_REF_STAGE_CURRENT_VALUE_STATIC, &m_reg.m_nDemodRefStageCur)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::IpStage, CStaticElem(IDC_DEMOD_IP_STAGE_CURRENT_VALUE_STATIC, &m_reg.m_nDemodIPStageCur)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::Fb, CStaticElem(IDC_LA_FB_CURRENT_VALUE_STATIC, &m_reg.m_nLaFBCur)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::Core, CStaticElem(IDC_LA_CORE_CURRENT_VALUE_STATIC, &m_reg.m_nLaCoreCur)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::OP, CStaticElem(IDC_LA_OP_BUFFER_CURRENT_VALUE_STATIC, &m_reg.m_nLaOPBufCur)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::IP, CStaticElem(IDC_LA_IP_BUFFER_CURRENT_VALUE_STATIC, &m_reg.m_nLaIPBufCur)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::HL, CStaticElem(IDC_LA_HL_DATA_RATE_CURRENT_VALUE_STATIC, &m_reg.m_nLaHLDataRateCur)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::CMOS, CStaticElem(IDC_CMOS_GAIN_STAGE_CURRENT_VALUE_STATIC, &m_reg.m_nCMOSGainStageCur)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::CML, CStaticElem(IDC_CML_INTERFACE_STAGE_CURRENT_VALUE_STATIC, &m_reg.m_nCMLInterfaceStageCur)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::RxData, CStaticElem(IDC_RX_DATA_IF_ENABLE_VALUE_STATIC, &m_reg.m_nRxData)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::LimAmp, CStaticElem(IDC_LIMITING_AMP_ENABLE_VALUE_STATIC, &m_reg.m_nLimitAmp)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::RegRef, CStaticElem(IDC_REG_REF_VOLT_VALUE_STATIC, &m_reg.m_nRegRef)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::VcoPow, CStaticElem(IDC_VCO_POWER_VALUE_STATIC, &m_reg.m_nVcoPower)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::ModPow, CStaticElem(IDC_MODULATOR_POWER_VALUE_STATIC, &m_reg.m_nModPower)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::TestBufPow, CStaticElem(IDC_TEST_BUFFER_POWER_VALUE_STATIC, &m_reg.m_nTestBufPower)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::DataInp, CStaticElem(IDC_DATA_INPUT_SELECT_VALUE_STATIC, &m_reg.m_nDataInpSel)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::PaPow, CStaticElem(IDC_PA_POWER_VALUE_STATIC, &m_reg.m_nPaPower)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::BiasBlock, CStaticElem(IDC_BIAS_BLOCK_ENABLE_VALUE_STATIC, &m_reg.m_nBiasBlock)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::FdCore, CStaticElem(IDC_FD_CORE_CURRENT_VALUE_STATIC, &m_reg.m_nFdCoreCur)));
	m_staticMap.insert(std::pair<SelectStatic, CStaticElem>(SelectStatic::FdBuf, CStaticElem(IDC_FD_BUFFER_CURRENT_VALUE_STATIC, &m_reg.m_nFdBufCur)));
}

CSemanticBase::~CSemanticBase()
{
}

CgZeroMasterDlg* CSemanticBase::Parent()
{
	return dynamic_cast<CgZeroMasterDlg*>(m_pParentWnd);
}

const CRegister& CSemanticBase::getRegister()
{
	Parse(Parent()->m_pRaw, m_reg);
	return m_reg;
}

void CSemanticBase::Parse(CRaw* pRaw, CRegister& reg)
{
	ASSERT(pRaw->Parent()->m_chip == _T("A0") || pRaw->Parent()->m_chip == _T("B0"));

	UpdateRxReg1(pRaw->m_strRxReg1, reg);
	UpdateTxReg1(pRaw->m_strTxReg1Top, pRaw->m_strTxReg1Mid, pRaw->m_strTxReg1Bot, reg, pRaw->Parent()->m_chip);
	if (pRaw->Parent()->m_chip == _T("B0"))
		UpdateTxReg2(pRaw->m_strTxReg2Top, pRaw->m_strTxReg2Mid, pRaw->m_strTxReg2Bot, reg);

	UpdateBiasReg1(pRaw->m_strBiasReg1, reg);
	UpdateBiasReg2(pRaw->m_strBiasReg2, reg);
	UpdateBiasReg3(pRaw->m_strBiasReg3, reg);
	UpdateBiasReg4(pRaw->m_strBiasReg4, reg);
	UpdateBiasReg5(pRaw->m_strBiasReg5, reg);
	UpdateBiasReg6(pRaw->m_strBiasReg6, reg);
	UpdateBiasReg7(pRaw->m_strBiasReg7, reg);
	UpdateBiasReg8(pRaw->m_strBiasReg8, reg);
	if (pRaw->Parent()->m_chip == _T("A0"))
		UpdateBiasReg9(pRaw->m_strBiasReg9, reg);
}

void CSemanticBase::UpdateRxReg1(CString strRxReg1, CRegister& reg)
{
	int val = _tcstol(strRxReg1.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nRxData = (val & 0x10) >> 4;
	reg.m_nLimitAmp = (val & 0x08) >> 3;
	reg.m_nLnaGain = val & 0x07;
}

void CSemanticBase::UpdateTxReg1(CString strTxRegTop, CString strTxRegMid, CString strTxRegBot, CRegister& reg, CString chip)
{
	ASSERT(chip == _T("A0") || chip == _T("B0"));
	int mid = _tcstol(strTxRegMid.GetBuffer(), NULL, 16) & 0xff;
	int bot = _tcstol(strTxRegBot.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nDutyCycle = _tcstol(strTxRegTop.GetBuffer(), NULL, 16) & 0xff;
	if (chip == _T("A0")) {
		reg.m_nModPower = (mid & 0x80) >> 7;
		reg.m_nTestBufPower = (mid & 0x40) >> 6;
		reg.m_nDataInpSel = (mid & 0x20) >> 5;
		reg.m_nPaPower = (mid & 0x10) >> 4;
		reg.m_nPaGainCon2 = mid & 0x0f;
		reg.m_nPaGainCon1 = (bot & 0xf0) >> 4;
		reg.m_nTestBufCur = bot & 0x0f;
	}
	else if (chip == _T("B0")) {
		reg.m_nVcoOsc = (bot & 0xe0) >> 5 | (mid << 3);
		reg.m_nRegRef = (bot & 0x10) >> 4;
		reg.m_nVcoVdd = bot & 0x0f;
	}
}

void CSemanticBase::UpdateTxReg2(CString strTxRegTop, CString strTxRegMid, CString strTxRegBot, CRegister& reg)
{
	int top = _tcstol(strTxRegTop.GetBuffer(), NULL, 16) & 0x01;
	int mid = _tcstol(strTxRegMid.GetBuffer(), NULL, 16) & 0xff;
	int bot = _tcstol(strTxRegBot.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nVcoPower = top;
	reg.m_nModPower = (mid & 0x80) >> 7;
	reg.m_nTestBufPower = (mid & 0x40) >> 6;
	reg.m_nDataInpSel = (mid & 0x20) >> 5;
	reg.m_nPaPower = (mid & 0x10) >> 4;
	reg.m_nPaGainCon2 = mid & 0x0f;
	reg.m_nPaGainCon1 = (bot & 0xf0) >> 4;
	reg.m_nTestBufCur = bot & 0x0f;
}

void CSemanticBase::UpdateBiasReg1(CString strBiasReg1, CRegister& reg)
{
	reg.m_nBiasBlock = _tcstol(strBiasReg1.GetBuffer(), NULL, 16) & 0x01;
}

void CSemanticBase::UpdateBiasReg2(CString strBiasReg2, CRegister& reg)
{
	int reg2 = _tcstol(strBiasReg2.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nLna3Cur = (reg2 & 0xf0) >> 4;
	reg.m_nLna1Cur = reg2 & 0x0f;
	reg.m_nLna2Cur = reg.m_nLna1Cur;
}

void CSemanticBase::UpdateBiasReg3(CString strBiasReg3, CRegister& reg)
{
	int reg3 = _tcstol(strBiasReg3.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nLna5Cur = (reg3 & 0xf0) >> 4;
	reg.m_nLna4Cur = reg3 & 0x0f;
}

void CSemanticBase::UpdateBiasReg4(CString strBiasReg4, CRegister& reg)
{
	int reg4 = _tcstol(strBiasReg4.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nDemodRefStageCur = (reg4 & 0xf0) >> 4;
	reg.m_nDemodIPStageCur = reg4 & 0x0f;
}

void CSemanticBase::UpdateBiasReg5(CString strBiasReg5, CRegister& reg)
{
	int reg5 = _tcstol(strBiasReg5.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nLaFBCur = (reg5 & 0xf0) >> 4;
	reg.m_nLaCoreCur = reg5 & 0x0f;
}

void CSemanticBase::UpdateBiasReg6(CString strBiasReg6, CRegister& reg)
{
	int reg6 = _tcstol(strBiasReg6.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nLaOPBufCur = (reg6 & 0xf0) >> 4;
	reg.m_nLaIPBufCur = reg6 & 0x0f;
}

void CSemanticBase::UpdateBiasReg7(CString strBiasReg7, CRegister& reg)
{
	int reg7 = _tcstol(strBiasReg7.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nLaHLDataRateCur = (reg7 & 0xf0) >> 4;
	reg.m_nCMOSGainStageCur = reg7 & 0x0f;
}

void CSemanticBase::UpdateBiasReg8(CString strBiasReg8, CRegister& reg)
{
	reg.m_nCMLInterfaceStageCur = _tcstol(strBiasReg8.GetBuffer(), NULL, 16) & 0xff;
}

void CSemanticBase::UpdateBiasReg9(CString strBiasReg9, CRegister& reg)
{
	int reg9 = _tcstol(strBiasReg9.GetBuffer(), NULL, 16) & 0xff;

	reg.m_nFdCoreCur = (reg9 & 0xf0) >> 4;
	reg.m_nFdBufCur = reg9 & 0x0f;
}

int CSemanticBase::SliderPos()
{
	return -1 * m_controlSlider.GetPos();
}

void CSemanticBase::ShowSlider(int nCmdShow)
{
	GetDlgItem(IDC_CONTROL_SLIDER)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_SLIDER_MAX_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_SLIDER_MIN_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_SLIDER_VALUE_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_SLIDER_VALUE_HEX_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_SLIDER_VALUE_BIN_STATIC)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_SELECTED_STATIC)->ShowWindow(nCmdShow);
	if (nCmdShow == SW_SHOW) GetDlgItem(IDC_CONTROL_COMBO)->ShowWindow(SW_HIDE);
}

void CSemanticBase::ControlValueEnable(BOOL b)
{
	GetDlgItem(IDC_RX_DATA_IF_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LIMITING_AMP_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA_GAIN_VALUE_STATIC)->EnableWindow(b);

	GetDlgItem(IDC_DUTY_CYCLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_VCO_OSC_FREQ_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_REG_REF_VOLT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_VCO_VDD_VALUE_STATIC)->EnableWindow(b);

	GetDlgItem(IDC_VCO_POWER_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_MODULATOR_POWER_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TEST_BUFFER_POWER_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_DATA_INPUT_SELECT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_PA_POWER_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_PA_GAIN_CONTROL1_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_PA_GAIN_CONTROL2_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TEST_BUFFER_CURRENT_VALUE_STATIC)->EnableWindow(b);

	GetDlgItem(IDC_BIAS_BLOCK_ENABLE_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA1_BIAS_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA2_BIAS_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA3_BIAS_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA4_BIAS_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA5_BIAS_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_DEMOD_REF_STAGE_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_DEMOD_IP_STAGE_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_FB_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_CORE_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_OP_BUFFER_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_IP_BUFFER_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_HL_DATA_RATE_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_CMOS_GAIN_STAGE_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_CML_INTERFACE_STAGE_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_FD_CORE_CURRENT_VALUE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_FD_BUFFER_CURRENT_VALUE_STATIC)->EnableWindow(b);
}

void CSemanticBase::OnBnClickedSemanticEditCheck()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bSemanticEdit = !m_bSemanticEdit;
	if (m_bSemanticEdit) {
		m_selected = SelectStatic::None;
		ControlValueEnable(TRUE);
		GetDlgItem(IDC_AUTO_WRITE_CHECK)->ShowWindow(SW_SHOW);
	}
	else {
		ControlValueEnable(FALSE);
		ShowSlider(SW_HIDE);
		GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CONTROL_COMBO)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_AUTO_WRITE_CHECK)->ShowWindow(SW_HIDE);
	}
	UpdateData(FALSE);
}

void CSemanticBase::OnBnClickedAutoWriteCheck()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bAutoWrite = !m_bAutoWrite;
}

COLORREF CSemanticBase::SetColor(CDC* pDC, SelectStatic given)
{
	if (m_selected == given)
		return pDC->SetTextColor(RGB(255, 0, 0));
	else
		return pDC->SetTextColor(RGB(0, 0, 0));
}

CString CSemanticBase::DecToBin(int dec)
{
	ASSERT(dec >= 0 && dec <= 0xffff);	//2바이트 까지만 지원
	if (dec == 0) return _T("0");

	CString strBin;
	int byte = (dec & 0xff00) >> 8;
	for (int n = 0; n < 2; n++) {
		for (int i = 7; i >= 0; i--) {
			CString strBit;
			strBit.Format(_T("%d"), (byte >> i) & 1);
			strBin += strBit;
			if (i == 4) strBin += _T(" ");	//4비트 마다 공백
		}
		strBin += _T(" ");	//4비트 마다 공백
		byte = dec & 0xff;
	}
	TRACE(_T("DecToBin:") + strBin + _T("\n"));
	return strBin;
}

int CSemanticBase::SliderValueUpdate()
{
	int curPos = SliderPos();
	m_strSliderValue.Format(_T("Dec:%d"), curPos);
	m_strSliderValueHex.Format(_T("Hex:0x%02x"), curPos);
	m_strSliderValueBin = _T("Bin:");
	(curPos > 0xff) ? m_strSliderValueBin += DecToBin(curPos).Right(15) : m_strSliderValueBin += DecToBin(curPos).Right(10);
	UpdateData(FALSE);
	return curPos;
}

void CSemanticBase::SetControlSlider(int min, int max, CString strCurVal, int ticFreq, int lineSize, int pageSize)
{
	int curVal = _tcstol(strCurVal.GetBuffer(), NULL, 16);

	m_strSliderMin.Format(_T("Min:%d"), min);
	if (min != 0) {
		m_strSliderMin += _T("(");
		m_strSliderMin += DecToBin(min).TrimLeft(_T('0')).TrimLeft();
		m_strSliderMin += _T(")");
	}

	m_strSliderMax.Format(_T("Max:%d"), max);
	m_strSliderMax += _T("(");
	(max > 0xff) ? m_strSliderMax += DecToBin(max).Right(15) : m_strSliderMax += DecToBin(max).Right(10);
	m_strSliderMax += _T(")");

	//슬라이더 컨트롤이 최대값이 아래로 표시되기때문에 최대값을 -1을 곱하여 최소갑인것 처럼 표시
	m_controlSlider.SetRange(-1 * max, -1 * min);
	m_controlSlider.SetRangeMin(-1 * max);
	m_controlSlider.SetRangeMax(-1 * min);
	m_controlSlider.SetPos(-1 * curVal);
	m_controlSlider.SetTicFreq(ticFreq);
	m_controlSlider.SetLineSize(lineSize);
	m_controlSlider.SetPageSize(pageSize);

	SliderValueUpdate();
}

void CSemanticBase::SetSliderGroup(SelectStatic ss, int min, int max, CString strCurVal, int ticFreq, int lineSize, int pageSize, UINT idcStatic)
{
	m_selected = ss;
	ShowSlider(SW_SHOW);
	Invalidate();	//모든것을 다시 그리는 것은 비효율적이지만 제일 간단하다

	SetControlSlider(min, max, strCurVal, ticFreq, lineSize, pageSize);
	GetDlgItem(idcStatic)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}

void CSemanticBase::SetComboGroup(SelectStatic ss, CString strVal0,CString strVal1, int nVal, UINT idcStatic)
{
	m_selected = ss;
	ShowSlider(SW_HIDE);

	for (int i = m_controlCombo.GetCount() - 1; i >= 0; i--) m_controlCombo.DeleteString(i);
	m_controlCombo.AddString(strVal0);	//0
	m_controlCombo.AddString(strVal1);	//1

	m_controlCombo.SetCurSel(nVal);

	GetDlgItem(IDC_CONTROL_COMBO)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SELECTED_STATIC)->ShowWindow(SW_SHOW);
	Invalidate();

	GetDlgItem(idcStatic)->GetWindowText(m_strSelectedStatic);
	GetDlgItem(IDC_WRITE_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE);
	UpdateData(FALSE);
}

void CSemanticBase::ControlLabelEnable(BOOL b)
{
	GetDlgItem(IDC_RX_DATA_IF_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LIMITING_AMP_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA_GAIN_STATIC)->EnableWindow(b);

	GetDlgItem(IDC_DUTY_CYCLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_VCO_OSC_FREQ_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_REG_REF_VOLT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_VCO_VDD_STATIC)->EnableWindow(b);

	GetDlgItem(IDC_VCO_POWER_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_MODULATOR_POWER_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TEST_BUFFER_POWER_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_DATA_INPUT_SELECT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_PA_POWER_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_PA_GAIN_CONTROL1_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_PA_GAIN_CONTROL2_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_TEST_BUFFER_CURRENT_STATIC)->EnableWindow(b);

	GetDlgItem(IDC_BIAS_BLOCK_ENABLE_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA1_BIAS_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA2_BIAS_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA3_BIAS_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA4_BIAS_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LNA5_BIAS_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_DEMOD_REF_STAGE_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_DEMOD_IP_STAGE_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_FB_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_CORE_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_OP_BUFFER_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_IP_BUFFER_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_LA_HL_DATA_RATE_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_CMOS_GAIN_STAGE_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_CML_INTERFACE_STAGE_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_FD_CORE_CURRENT_STATIC)->EnableWindow(b);
	GetDlgItem(IDC_FD_BUFFER_CURRENT_STATIC)->EnableWindow(b);
}

int CSemanticBase::ComboSel()
{
	return m_controlCombo.GetCurSel();
}

int CSemanticBase::Read4BitValue(CString str)
{
	int val = _tcstol(str.GetBuffer(), NULL, 16);
	ASSERT(val >= 0 && val <= 0xf);
	return val;
}


int CSemanticBase::Read8BitValue(CString str)
{
	int val = _tcstol(str.GetBuffer(), NULL, 16);
	ASSERT(val >= 0 && val <= 0xff);
	return val;
}

int CSemanticBase::OnNewRxData(int val, int newVal)
{
	return (val & 0xe0) | newVal << 4 | (val & 0x0f);
}


int CSemanticBase::OnNewLimAmp(int val, int newVal)
{
	return (val & 0xf0) | newVal << 3 | (val & 0x07);
}


int CSemanticBase::OnNewRegRef(int val, int newVal)
{
	return (val & 0xe0) | newVal << 4 | (val & 0x0f);
}


int CSemanticBase::OnNewVcoPow(int val, int newVal)
{
	return (val & 0xfe) | newVal;
}


int CSemanticBase::OnNewModPow(int val, int newVal)
{
	return (val & 0x7f) | newVal << 7;
}


int CSemanticBase::OnNewTestBufPow(int val, int newVal)
{
	return (val & 0x80) | newVal << 6 | (val & 0x3f);
}


int CSemanticBase::OnNewDataInp(int val, int newVal)
{
	return (val & 0xc0) | newVal << 5 | (val & 0x1f);
}


int CSemanticBase::OnNewPaPow(int val, int newVal)
{
	return (val & 0xe0) | newVal << 4 | (val & 0x0f);
}


int CSemanticBase::OnNewBiasBlock(int val, int newVal)
{
	return (val & 0xfe) | newVal;
}


int CSemanticBase::OnNewLnaGain(int val, int newVal)
{
	return (val & 0xf8) | newVal;
}


int CSemanticBase::OnNewDutyCycle(int val, int newVal)
{
	return newVal;
}


int CSemanticBase::OnNewVcoOscUp(int val, int newVal)
{
	return (newVal & 0x7f8) >> 3;
}


int CSemanticBase::OnNewVcoOscDown(int val, int newVal)
{
	return (newVal & 0x7) << 5 | (val & 0x1f);
}


int CSemanticBase::OnNewVcoVdd(int val, int newVal)
{
	return (val & 0xf0) | (newVal & 0x0f);
}


int CSemanticBase::OnNewPaGain1(int val, int newVal)
{
	return (newVal & 0x0f) << 4 | (val & 0x0f);
}


int CSemanticBase::OnNewPaGain2(int val, int newVal)
{
	return (val & 0xf0) | (newVal & 0x0f);
}


int CSemanticBase::OnNewTestBuffer(int val, int newVal)
{
	return (val & 0xf0) | (newVal & 0x0f);
}


int CSemanticBase::OnNewLna1(int val, int newVal)
{
	return (val & 0xf0) | (newVal & 0x0f);
}


int CSemanticBase::OnNewLna2(int val, int newVal)
{
	return OnNewLna1(val, newVal);
}


int CSemanticBase::OnNewLna3(int val, int newVal)
{
	return (newVal & 0x0f) << 4 | (val & 0x0f);
}


int CSemanticBase::OnNewLna4(int val, int newVal)
{
	return (val & 0xf0) | (newVal & 0x0f);
}


int CSemanticBase::OnNewLna5(int val, int newVal)
{
	return (newVal & 0x0f) << 4 | (val & 0x0f);
}


int CSemanticBase::OnNewRefStage(int val, int newVal)
{
	return (newVal & 0x0f) << 4 | (val & 0x0f);
}


int CSemanticBase::OnNewIpStage(int val, int newVal)
{
	return (val & 0xf0) | (newVal & 0x0f);
}


int CSemanticBase::OnNewFb(int val, int newVal)
{
	return (newVal & 0x0f) << 4 | (val & 0x0f);
}


int CSemanticBase::OnNewCore(int val, int newVal)
{
	return (val & 0xf0) | (newVal & 0x0f);
}


int CSemanticBase::OnNewOP(int val, int newVal)
{
	return (newVal & 0x0f) << 4 | (val & 0x0f);
}


int CSemanticBase::OnNewIP(int val, int newVal)
{
	return (val & 0xf0) | (newVal & 0x0f);
}


int CSemanticBase::OnNewHL(int val, int newVal)
{
	return (newVal & 0x0f) << 4 | (val & 0x0f);
}


int CSemanticBase::OnNewCMOS(int val, int newVal)
{
	return (val & 0xf0) | (newVal & 0x0f);
}


int CSemanticBase::OnNewCML(int val, int newVal)
{
	return newVal & 0xff;
}


int CSemanticBase::OnNewFdCore(int val, int newVal)
{
	return (newVal & 0x0f) << 4 | (val & 0x0f);
}


int CSemanticBase::OnNewFdBuf(int val, int newVal)
{
	return (val & 0xf0) | (newVal & 0x0f);
}

int CSemanticBase::disableOrEnable(CString str)
{
	return strToInt(_T("disable"), _T("enable"), str);
}


int CSemanticBase::strToInt(CString zero, CString one, CString str)
{
	ASSERT(str == zero || str == one);

	if (str == zero) return 0;
	ASSERT(str == one);
	return 1;
}

HBRUSH CSemanticBase::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	for (std::map<SelectStatic, CStaticElem>::iterator it = m_staticMap.begin(); it != m_staticMap.end(); ++it) {
		if (pWnd->GetDlgCtrlID() == it->second.m_uIdc)
			SetColor(pDC, it->first);
	}

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}

BOOL CSemanticBase::OnCbnSelchangeControlCombo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	BOOL bProcessed = FALSE;
	for (std::map<SelectStatic, CStaticElem>::iterator it = m_staticMap.begin(); it != m_staticMap.end(); ++it) {
		if (m_selected == it->first) {
			(ComboSel() == (*it->second.m_pRegVal)) ? GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(FALSE) : GetDlgItem(IDC_WRITE_BUTTON)->EnableWindow(TRUE);
			bProcessed = TRUE;
			break;
		}
	}

	return bProcessed;
}

void CSemanticBase::UpdateRxData(const CRegister& reg)
{
	(reg.m_nRxData) ? m_strRxDataInterface.Format(_T("enable")) : m_strRxDataInterface.Format(_T("disable"));
}


void CSemanticBase::UpdateLimitAmp(const CRegister& reg)
{
	(reg.m_nLimitAmp) ? m_strLimitingAmplifier.Format(_T("enable")) : m_strLimitingAmplifier.Format(_T("disable"));
}


void CSemanticBase::UpdateLnaGain(const CRegister& reg)
{
	m_strLnaGain.Format(_T("0x%02x"), reg.m_nLnaGain);
}


void CSemanticBase::UpdateDutyCycle(const CRegister& reg)
{
	m_strDutyCycle.Format(_T("0x%02x"), reg.m_nDutyCycle);
}


void CSemanticBase::UpdateVcoOscFreq(const CRegister& reg)
{
	m_strVcoOscFreq.Format(_T("0x%02x"), reg.m_nVcoOsc);
}


void CSemanticBase::UpdateRegRefVolt(const CRegister& reg)
{
	(reg.m_nRegRef) ? m_strRegRefVolt.Format(_T("400mV")) : m_strRegRefVolt.Format(_T("500mV"));
}


void CSemanticBase::UpdateVcoVdd(const CRegister& reg)
{
	m_strVcoVdd.Format(_T("0x%02x"), reg.m_nVcoVdd);
}


void CSemanticBase::UpdateVcoPower(const CRegister& reg)
{
	(reg.m_nVcoPower) ? m_strVcoPower.Format(_T("VCO on")) : m_strVcoPower.Format(_T("VCO off"));
}


void CSemanticBase::UpdateModPower(const CRegister& reg)
{
	(reg.m_nModPower) ? m_strModPower.Format(_T("MOD on")) : m_strModPower.Format(_T("MOD off"));
}


void CSemanticBase::UpdateTestBufferPower(const CRegister& reg)
{
	(reg.m_nTestBufPower) ? m_strTestBufferPower.Format(_T("test buff on")) : m_strTestBufferPower.Format(_T("test buff off"));
}


void CSemanticBase::UpdateDataInputSelect(const CRegister& reg)
{
	(reg.m_nDataInpSel) ? m_strDataInputSelect.Format(_T("Test buff(External)")) : m_strDataInputSelect.Format(_T("SER(Internal)"));
}


void CSemanticBase::UpdateDataPaPower(const CRegister& reg)
{
	(reg.m_nPaPower) ? m_strPaPower.Format(_T("PA on")) : m_strPaPower.Format(_T("PA off"));
}


void CSemanticBase::UpdatePaGainControl2(const CRegister& reg)
{
	m_strPaGainControl2.Format(_T("0x%02x"), reg.m_nPaGainCon2);
}


void CSemanticBase::UpdatePaGainControl1(const CRegister& reg)
{
	m_strPaGainControl1.Format(_T("0x%02x"), reg.m_nPaGainCon1);
}


void CSemanticBase::UpdateTestBufferCurrent(const CRegister& reg)
{
	m_strTestBufferCurrent.Format(_T("0x%02x"), reg.m_nTestBufCur);
}


void CSemanticBase::UpdateBiasBlockEnable(const CRegister& reg)
{
	(reg.m_nBiasBlock) ? m_strBiasBlockEnable.Format(_T("enable")) : m_strBiasBlockEnable.Format(_T("disable"));
}


void CSemanticBase::UpdateLna3Current(const CRegister& reg)
{
	m_strLna3Current.Format(_T("0x%02x"), reg.m_nLna3Cur);
}


void CSemanticBase::UpdateLna1Current(const CRegister& reg)
{
	m_strLna1Current.Format(_T("0x%02x"), reg.m_nLna1Cur);
	m_strLna2Current = m_strLna1Current;
}


void CSemanticBase::UpdateLna2Current(const CRegister& reg)
{
	m_strLna2Current.Format(_T("0x%02x"), reg.m_nLna1Cur);
	m_strLna1Current = m_strLna2Current;
}


void CSemanticBase::UpdateLna5Current(const CRegister& reg)
{
	m_strLna5Current.Format(_T("0x%02x"), reg.m_nLna5Cur);
}


void CSemanticBase::UpdateLna4Current(const CRegister& reg)
{
	m_strLna4Current.Format(_T("0x%02x"), reg.m_nLna4Cur);
}


void CSemanticBase::UpdateDemodRefStageCurrent(const CRegister& reg)
{
	m_strDemodRefStageCurrent.Format(_T("0x%02x"), reg.m_nDemodRefStageCur);
}


void CSemanticBase::UpdateDemodIPStageCurrent(const CRegister& reg)
{
	m_strDemodIPStageCurrent.Format(_T("0x%02x"), reg.m_nDemodIPStageCur);
}


void CSemanticBase::UpdateLaFBCurrent(const CRegister& reg)
{
	m_strLaFBCurrent.Format(_T("0x%02x"), reg.m_nLaFBCur);
}


void CSemanticBase::UpdateLaCoreCurrent(const CRegister& reg)
{
	m_strLaCoreCurrent.Format(_T("0x%02x"), reg.m_nLaCoreCur);
}


void CSemanticBase::UpdateLaOPBufferCurrent(const CRegister& reg)
{
	m_strLaOPBufferCurrent.Format(_T("0x%02x"), reg.m_nLaOPBufCur);
}


void CSemanticBase::UpdateLaIPBufferCurrent(const CRegister& reg)
{
	m_strLaIPBufferCurrent.Format(_T("0x%02x"), reg.m_nLaIPBufCur);
}


void CSemanticBase::UpdateLaHLDataRateCurrent(const CRegister& reg)
{
	m_strLaHLDataRateCurrent.Format(_T("0x%02x"), reg.m_nLaHLDataRateCur);
}


void CSemanticBase::UpdateCMOSGainStageCurrent(const CRegister& reg)
{
	m_strCMOSGainStageCurrent.Format(_T("0x%02x"), reg.m_nCMOSGainStageCur);
}


void CSemanticBase::UpdateCMLInterfaceStageCurrent(const CRegister& reg)
{
	m_strCMLInterfaceStageCurrent.Format(_T("0x%02x"), reg.m_nCMLInterfaceStageCur);
}


void CSemanticBase::UpdateFdCoreCurrent(const CRegister& reg)
{
	m_strFdCoreCur.Format(_T("0x%02x"), reg.m_nFdCoreCur);
}


void CSemanticBase::UpdateFdBufferCurrent(const CRegister& reg)
{
	m_strFdBufCur.Format(_T("0x%02x"), reg.m_nFdBufCur);
}


void CSemanticBase::UpdateRegisters()
{
	ASSERT(Parent());
	const CRegister& reg = getRegister();

	UpdateRxData(reg);
	UpdateLimitAmp(reg);
	UpdateLnaGain(reg);

	UpdateDutyCycle(reg);
	UpdateVcoOscFreq(reg);
	UpdateRegRefVolt(reg);
	UpdateVcoVdd(reg);

	UpdateVcoPower(reg);
	UpdateModPower(reg);
	UpdateTestBufferPower(reg);
	UpdateDataInputSelect(reg);
	UpdateDataPaPower(reg);
	UpdatePaGainControl2(reg);
	UpdatePaGainControl1(reg);
	UpdateTestBufferCurrent(reg);

	UpdateBiasBlockEnable(reg);

	UpdateLna3Current(reg);
	UpdateLna1Current(reg);
	UpdateLna2Current(reg);

	UpdateLna5Current(reg);
	UpdateLna4Current(reg);

	UpdateDemodRefStageCurrent(reg);
	UpdateDemodIPStageCurrent(reg);

	UpdateLaFBCurrent(reg);
	UpdateLaCoreCurrent(reg);

	UpdateLaOPBufferCurrent(reg);
	UpdateLaIPBufferCurrent(reg);

	UpdateLaHLDataRateCurrent(reg);
	UpdateCMOSGainStageCurrent(reg);

	UpdateCMLInterfaceStageCurrent(reg);

	UpdateFdCoreCurrent(reg);
	UpdateFdBufferCurrent(reg);
	UpdateData(FALSE);
}