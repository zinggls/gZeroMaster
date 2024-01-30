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
{
	m_pParentWnd = pParent;
}

CSemanticBase::~CSemanticBase()
{
}

CgZeroMasterDlg* CSemanticBase::Parent()
{
	return dynamic_cast<CgZeroMasterDlg*>(m_pParentWnd);
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

void CSemanticBase::SetSliders(SelectStatic ss, int min, int max, CString strCurVal, int ticFreq, int lineSize, int pageSize, UINT idcStatic)
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
