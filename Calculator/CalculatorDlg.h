
// CalculatorDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CCalculatorDlg
class CCalculatorDlg : public CDialogEx
{
// Создание
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	int action;
	double num1;
	double num2;
	CString sInput;
	bool cont;
	bool multiCount;
public:
	bool pointCheck;
	CEdit _EditOut;
	afx_msg void Press1();
	afx_msg void Press2();
	afx_msg void Press3();
	afx_msg void Press4();
	afx_msg void Press5();
	afx_msg void Press6();
	afx_msg void Press7();
	afx_msg void Press8();
	afx_msg void Press9();
	afx_msg void Press0();
	afx_msg void MathSum();
	afx_msg void MathSubtracting();
	afx_msg void MathMultiplication();
	afx_msg void MathDividing();
	afx_msg void PressResult();
	afx_msg void PressPoint();
	void press(CString x);
	void math_action(int x);
	afx_msg void PressClear();
	afx_msg void BackSpace();
	afx_msg void Opposite();
	CListBox _Story;
	afx_msg void OnBnClickedMatrice();
	CMFCButton _Sum;
	CMFCButton _Sub;
	CMFCButton _Mult;
	CMFCButton _Div;
	CMFCButton _Matr;
	CMFCButton _Res;
	CMFCButton _Clear;
};

