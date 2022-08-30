#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
using namespace std;
# define MAX 20
int a[MAX][MAX];
int n;
char vertex[MAX];
void initGraph()
{
	n = 0;
}
void inputGraph()
{
	cout << "Nhap vao so dinh cua do thi: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "NHap ten dinh: ";
		cin >> vertex[i];
		cout << "Nhap vao dong thu " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}
void inputGraphFromText()
{
	string line;
	ifstream fi("mtts2.txt");
	if (fi.is_open())
	{
		fi >> n;
		for (int i = 0; i < n; i++)
			fi >> vertex[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				fi >> a[i][j];
		}
	}
}
void outputGraph()
{
	cout << setw(6) << left;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << setw(6) << left;
		cout << endl;
	}
}
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0;
//==================================
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0;
//==================================
int TonTai(int d, int D[], int nD)
{
	for (int i = 0; i < nD; i++)
		if (D[i] == d)
			return 1;
	return 0;
}
void XoaViTriE(int i)
{
	for (int j = i; j < nE; j++)
	{
		E1[j] = E1[j + 1];
		E2[j] = E2[j + 1];
		wE[j] = wE[j + 1];
	}
	nE--;
}

void XoaCanhE(int u, int v)
{
	for (int i = 0; i < nE; i++)
		if (E1[i] == u && E2[i] == v)
		{
			XoaViTriE(i);
			break;
		}
}
void prim(int s) // s là đỉnh bắt đầu
{
	int u = s, min, i, d1, d2;
	while (nT < n - 1)
	{
		for (int v = 0; v < n; v++)
			if (a[u][v] != 0)
				if (TonTai(v, T2, nT) == 0)
				{
					E1[nE] = u;
					E2[nE] = v;
					wE[nE] = a[u][v];
					nE++;
				}
		for (i = 0; i < nE; i++)
			if (TonTai(E2[i], T2, nT) == 0)
			{
				min = wE[i]; d1 = E1[i];
				d2 = E2[i]; break;
			}
		for (int i = 0; i < nE; i++)
			if (TonTai(E2[i], T2, nT) == 0)
				if (min > wE[i])
				{
					min = wE[i];
					d1 = E1[i];
					d2 = E2[i];
				}
		T1[nT] = d1;
		T2[nT] = d2;
		wT[nT] = a[d1][d2];
		a[d1][d2] = 0;
		a[d2][d1] = 0;
		nT++;
		XoaCanhE(d1, d2);
		u = d2;
	}
}
//===========================
void taoE()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] != 0)
			{
				E1[nE] = i;
				E2[nE] = j;
				wE[nE] = a[i][j];
				a[i][j] = 0;
				a[j][i] = 0;
				nE++;
			}
}
void Swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}
void SapXepE()
{
	for (int i = 0; i < nE - 1; i++)
		for (int j = i + 1; j < nE; j++)
			if (wE[i] > wE[j])
			{
				swap(wE[i], wE[j]);
				swap(E1[i], E1[j]);
				swap(E2[i], E2[j]);
			}
}
void kruskal()
{
	for (int i = 0; i < nE; i++)
	{
		if (TonTai(E1[i], T1, nT) == 1 && TonTai(E2[i], T2, nT) == 1)
			continue;
		if (TonTai(E1[i], T2, nT) == 1 && TonTai(E2[i], T1, nT) == 1)
			continue;
		T1[nT] = E1[i];
		T2[nT] = E2[i];
		wT[nT] = wE[i];
		nT++;
		if (nT == n - 1)
			break;
	}
}
//===========================
int ConnectedComponents() {
	int visited[MAX] = { 0 };
	int nV = 0;
	int i = 0, j = 0;
	int nC = 0;

	while (nV < n) {
		for (j = 0; j < n; j++) {
			if (a[i][j] != 0 && visited[j] != 1) {
				visited[j] = 1;
				nV++;
				i = j;
				break;
			}
		}
		if (j >= n && i < n - 1) {
			i++;
			visited[i] = 1;
			nV++;
			nC++;
		}
		else if (j > n && i >= n - 1) {
			i = 1;
			visited[i] = 1;
			nV++;
			nC++;
		}
	}
	return nC;
}
//===========================
void output(bool VertexName)
{
	int tong = 0;
	for (int i = 0; i < nT; i++)
	{
		if (VertexName)
			cout << endl << "(" << vertex[T1[i]] << "," << vertex[T2[i]] << ") = " << wT[i];
		else
			cout << endl << "( " << T1[i] << "," << T2[i] << ") =" << wT[i];
		tong += wT[i];
	}
	cout << "\n  Tong = " << tong << endl;
}
void outputE(bool VertexName)
{
	int tong = 0;
	for (int i = 0; i < nE; i++)
	{
		if (VertexName)
			cout << endl << "(" << vertex[E1[i]] << "," << vertex[E2[i]] << ") = " << wE[i];
		else
			cout << endl << "(" << E1[i] << "," << E2[i] << ") = " << wE[i];
		tong += wE[i];
	}
	cout << "\n  Tong = " << tong;
}
int main()
{
	int choice, x, i;
	system("cls");
	cout << "------------------ Bai tap 7, Chuong 6, Tim kiem cay khung toi thieu ----------\n";
	cout << "1. Khoi tao MTK rong \n";
	cout << "2. Nhap MTK tu file text\n";
	cout << "3. Nhap MTK\n";
	cout << "4. Xuat MTK\n";
	cout << "5. In ra tap E:" << endl;
	cout << "6. Tim CAY KHUNG TOI THIEU bang PRIM\n";
	cout << "7. Tim CAY KHUNG TOI THIEU bang KRUSKAL " << endl;
	cout << "8. Connected Graph - Do thi lien thong" << endl;
	cout << "9. Thoat\n";
	do {
		cout << "Vui long nhap lua chon cua ban: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			initGraph();
			cout << "Ban vua khoi tao MTK rong thanh cong !!\n";
			break;
		case 2:
			inputGraphFromText();
			cout << "Ban vua nhap MTK tu file !!\n";
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 6:
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			prim(x);
			cout << "Cay khung toi thieu voi PRIM: " << endl;
			output(true);
			break;
		case 7:
			nT = 0;
			taoE();
			SapXepE();
			kruskal();
			cout << "Cay khung toi thieu voi KRUSKAL: " << endl;
			output(true);
			break;
		case 5:
			outputE(true);
			break;
		case 8:
			i = ConnectedComponents();
			cout << "Do thi co so tplt = " << i << endl;
			break;
		case 9:
			cout << "Good bye\n";
			break;
		default:
			break;
		}
	} while (choice != 9);
	system("pause");
	return 0;
}