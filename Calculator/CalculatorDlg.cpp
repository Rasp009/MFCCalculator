


#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include "CMatrice.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CMatrice cMatr;




CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	num1 = 0;
	num2 = 0;
	action = 0;
	pointCheck = 0;
	cont = 0;
	multiCount = 0;
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, _EditOut);
	DDX_Control(pDX, IDC_LIST1, _Story);
	DDX_Control(pDX, IDC_Sum, _Sum);
	DDX_Control(pDX, IDC_Subtracting, _Sub);
	DDX_Control(pDX, IDC_Multiplication, _Mult);
	DDX_Control(pDX, IDC_Dividing, _Div);
	DDX_Control(pDX, IDC_Matrice, _Matr);
	DDX_Control(pDX, IDC_Result, _Res);
	DDX_Control(pDX, IDC_Clear, _Clear);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_1, &CCalculatorDlg::Press1)
	ON_BN_CLICKED(IDC_2, &CCalculatorDlg::Press2)
	ON_BN_CLICKED(IDC_3, &CCalculatorDlg::Press3)
	ON_BN_CLICKED(IDC_4, &CCalculatorDlg::Press4)
	ON_BN_CLICKED(IDC_5, &CCalculatorDlg::Press5)
	ON_BN_CLICKED(IDC_6, &CCalculatorDlg::Press6)
	ON_BN_CLICKED(IDC_7, &CCalculatorDlg::Press7)
	ON_BN_CLICKED(IDC_8, &CCalculatorDlg::Press8)
	ON_BN_CLICKED(IDC_9, &CCalculatorDlg::Press9)
	ON_BN_CLICKED(IDC_0, &CCalculatorDlg::Press0)
	ON_BN_CLICKED(IDC_Sum, &CCalculatorDlg::MathSum)
	ON_BN_CLICKED(IDC_Subtracting, &CCalculatorDlg::MathSubtracting)
	ON_BN_CLICKED(IDC_Multiplication, &CCalculatorDlg::MathMultiplication)
	ON_BN_CLICKED(IDC_Dividing, &CCalculatorDlg::MathDividing)
	ON_BN_CLICKED(IDC_Result, &CCalculatorDlg::PressResult)
	ON_BN_CLICKED(IDC_Point, &CCalculatorDlg::PressPoint)
	ON_BN_CLICKED(IDC_Clear, &CCalculatorDlg::PressClear)
	ON_BN_CLICKED(IDC_Backspace, &CCalculatorDlg::BackSpace)
	ON_BN_CLICKED(IDC_Opposite, &CCalculatorDlg::Opposite)
	ON_BN_CLICKED(IDC_Matrice, &CCalculatorDlg::OnBnClickedMatrice)
END_MESSAGE_MAP()



BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		


	_Sum.EnableWindowsTheming(FALSE);
	_Sub.EnableWindowsTheming(FALSE);
	_Mult.EnableWindowsTheming(FALSE);
	_Div.EnableWindowsTheming(FALSE);
	_Matr.EnableWindowsTheming(FALSE);
	_Res.EnableWindowsTheming(FALSE);
	_Clear.EnableWindowsTheming(FALSE);
	_Sum.SetFaceColor(RGB(244, 164, 96),true);
	_Sub.SetFaceColor(RGB(244, 164, 96), true);
	_Mult.SetFaceColor(RGB(244, 164, 96), true);
	_Div.SetFaceColor(RGB(244, 164, 96), true);
	_Matr.SetFaceColor(RGB(64, 224, 208), true);
	_Res.SetFaceColor(RGB(144, 238, 144), true);
	_Clear.SetFaceColor(RGB(250, 128, 114), true);
	cMatr.Create(IDD_Matrice, this);
	return TRUE; 
}


void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); 

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}


HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorDlg::Press1()
{
	press(_T("1"));
}


void CCalculatorDlg::Press2()
{
	press(_T("2"));
}


void CCalculatorDlg::Press3()
{
	press(_T("3"));
}


void CCalculatorDlg::Press4()
{
	press(_T("4"));
}


void CCalculatorDlg::Press5()
{
	press(_T("5"));
}


void CCalculatorDlg::Press6()
{
	press(_T("6"));
}


void CCalculatorDlg::Press7()
{
	press(_T("7"));
}


void CCalculatorDlg::Press8()
{
	press(_T("8"));
}


void CCalculatorDlg::Press9()
{
	press(_T("9"));
}


void CCalculatorDlg::Press0()
{
	press(_T("0"));
}


void CCalculatorDlg::PressPoint()
{
	if (pointCheck == 0 && sInput.GetLength() != 0)
	{
		sInput.Append(L".");
		_EditOut.SetWindowTextW(sInput);
	}
	pointCheck = 1;
}

void CCalculatorDlg::MathSum()
{
	math_action(1);
}


void CCalculatorDlg::MathSubtracting()
{
	math_action(2);
}


void CCalculatorDlg::MathMultiplication()
{
	math_action(3);
}


void CCalculatorDlg::MathDividing()
{
	math_action(4);
}


void CCalculatorDlg::PressResult()
{
	double result = 0;
	CString StoryList;
	num2 = _wtof(sInput);
	switch (action)
	{
	case 1:
		result = num1 + num2;
		StoryList.Format(L"%g + %g = %g", num1, num2, result);
		break;
	case 2:
		result = num1 - num2;
		StoryList.Format(L"%g - %g = %g", num1, num2, result);
		break;
	case 3:
		result = num1 * num2;
		StoryList.Format(L"%g * %g = %g", num1, num2, result);
		break;
	case 4:
		if (num2 == 0)
			AfxMessageBox(L"Zero Divison");
		else
			result = num1 / num2;
			StoryList.Format(L"%g / %g = %g", num1, num2, result);
		break;
	default:
		AfxMessageBox(L"Choose Math Operation");
		break;
	}
	cont = 1;
	multiCount = 0;
	sInput.Format(L"%g", result);
	_EditOut.SetWindowTextW(sInput);
	_Story.AddString(StoryList);
}

void CCalculatorDlg::press(CString x)
{
	if (sInput == "0" || cont == 1)
	{
		sInput = x;
		cont = 0;
	}
	else
		sInput.Append(x);
	_EditOut.SetWindowTextW(sInput);
}


void CCalculatorDlg::math_action(int x)
{
	if (multiCount == 1)
		PressResult();
	else
		num1 = _wtof(sInput);
	cont = 1;
	multiCount = 1;
	action = x;
	pointCheck = 0;
}




void CCalculatorDlg::PressClear()
{
	action = 0;
	pointCheck = 0;
	sInput = L"";
	_EditOut.SetWindowTextW(L"");
}


void CCalculatorDlg::BackSpace()
{
	sInput.Delete(sInput.GetLength() - 1);
	_EditOut.SetWindowTextW(sInput);
}


void CCalculatorDlg::Opposite()
{
	if (sInput.GetLength() > 0 && sInput != L"0")
	{
		double temp = _wtof(sInput);
		temp = temp * -1;
		sInput.Format(L"%g", temp);
		_EditOut.SetWindowTextW(sInput);
	}
}


void CCalculatorDlg::OnBnClickedMatrice()
{
	cMatr.ShowWindow(1);
}
