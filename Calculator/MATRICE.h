#pragma once


// Диалоговое окно MATRICE

class MATRICE : public CDialogEx
{
	DECLARE_DYNAMIC(MATRICE)

public:
	MATRICE(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~MATRICE();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = MATRICE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};
