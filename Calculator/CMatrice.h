#pragma once


// Диалоговое окно CMatrice

class CMatrice : public CDialogEx
{
	DECLARE_DYNAMIC(CMatrice)

public:
	CMatrice(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CMatrice();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Matrice };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Multiply();
	CEdit _m1r;
	CEdit _m1c;
	CEdit _m2r;
	CEdit _m2c;
	CEdit _Matrice1;
	CEdit _Matrice2;
	CListBox _Result;
	afx_msg void OnBnClickedCancel();
	CEdit MatMult;
};
