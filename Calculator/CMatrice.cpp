

#include "pch.h"
#include "Calculator.h"
#include "CMatrice.h"
#include "afxdialogex.h"
#include  <string.h>
#include <vector>
using namespace std;


IMPLEMENT_DYNAMIC(CMatrice, CDialogEx)

CMatrice::CMatrice(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Matrice, pParent)
{

}

CMatrice::~CMatrice()
{
}

void CMatrice::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, _m1r);
	DDX_Control(pDX, IDC_EDIT3, _m1c);
	DDX_Control(pDX, IDC_EDIT2, _m2r);
	DDX_Control(pDX, IDC_EDIT4, _m2c);
	DDX_Control(pDX, IDC_Row1, _Matrice1);
	DDX_Control(pDX, IDC_Row2, _Matrice2);
	DDX_Control(pDX, IDC_MatMult, MatMult);
}


BEGIN_MESSAGE_MAP(CMatrice, CDialogEx)
	ON_BN_CLICKED(IDC_Multiply, &CMatrice::Multiply)
	ON_BN_CLICKED(IDCANCEL, &CMatrice::OnBnClickedCancel)
END_MESSAGE_MAP()

void CMatrice::Multiply()
{
	int m1r, m1c, m2r, m2c, sizeM1, sizeM2;
	CString sm1r, sm1c, sm2r, sm2c, sMatrice1, sMatrice2, elem, Char;
	_m1r.GetWindowTextW(sm1r);
	m1r = _wtoi(sm1r);
	_m1c.GetWindowTextW(sm1c);
	m1c = _wtoi(sm1c);
	_m2r.GetWindowTextW(sm2r);
	m2r = _wtoi(sm2r);
	_m2c.GetWindowTextW(sm2c);
	m2c = _wtoi(sm2c);
	_Matrice1.GetWindowTextW(sMatrice1);
	sizeM1 = sMatrice1.GetLength();
	_Matrice2.GetWindowTextW(sMatrice2);
	sizeM2 = sMatrice2.GetLength();
	if (m1c != m2r)
	{
		AfxMessageBox(L"Number of columns of Matrix 1 should be equal to number of columns Matrix 2");
		_Matrice1.SetWindowTextW(L"");
		_Matrice2.SetWindowTextW(L"");
		_m1r.SetWindowTextW(L"");
		_m2r.SetWindowTextW(L"");
		_m1c.SetWindowTextW(L"");
		_m2c.SetWindowTextW(L"");
		MatMult.SetWindowTextW(L"");
		CDialogEx::OnCancel();
	}
	
	vector < vector <double> > vMatrice1(m1r, vector <double>(m1c));
	int k = 0;
	int r1 = 0;
	for (int i = 0; i <= (sizeM1); i++)
	{ 
		Char = sMatrice1[i];
			if (k < (m1c))
			{
				if ((Char == L",") || (Char == L"") || (Char == L"\n"))
				{
					vMatrice1[r1][k] = _wtof(elem);
					elem = L"";
					k++;
				}
				else
				elem.Append(Char);
			}
			else
			{
				k = 0;
				r1++;
				i--;
			}
	}
	vector < vector <double> > vMatrice2(m2r, vector <double>(m2c));
	int c2 = 0;
	k = 0;
	for (int i = 0; i <= (sizeM2); i++)
	{
		Char = sMatrice2[i];
		if (c2 < (m2c))
		{
			if ((Char == L",") || (Char == L"")|| (Char == L"\n"))
			{
				vMatrice2[k][c2] = _wtof(elem);
				elem = L"";
				c2++;
			}
			else
			elem.Append(Char);
		}
		else
		{
			c2 = 0;
			k++;
			i--;
		}
	}
	vector < vector <double> > vMatrice3(m1r, vector <double>(m2c));
	for (r1 = 0; r1 < m1r; r1++)
	{
		for (c2 = 0; c2 < m2c; c2++)
		{
			vMatrice3[r1][c2] = 0;
			for (k =0; k < m2r; k++)
			vMatrice3[r1][c2] += vMatrice1[r1][k] * vMatrice2[k][c2];
		}
	}
	CString result, result_elem;
	for (r1 = 0; r1 < m1r; r1++)
	{
		for (c2 = 0; c2 < m2c; c2++)
		{
			result_elem.Format(L"%g ", vMatrice3[r1][c2]);
			if (c2 == (m2c - 1))
				result.Append(result_elem + L"\r\n");
			else
			result.Append(result_elem);
		}
	}
	MatMult.SetWindowTextW(result);
}


void CMatrice::OnBnClickedCancel()
{
	_Matrice1.SetWindowTextW(L"");
	_Matrice2.SetWindowTextW(L"");
	_m1r.SetWindowTextW(L"");
	_m2r.SetWindowTextW(L"");
	_m1c.SetWindowTextW(L"");
	_m2c.SetWindowTextW(L"");
	MatMult.SetWindowTextW(L"");
	CDialogEx::OnCancel();
}
