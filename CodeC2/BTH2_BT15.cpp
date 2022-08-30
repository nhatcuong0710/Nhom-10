#include<iostream>
#define max 100
using namespace std;
int a[max], b[max];

void Input(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]: ";
		cin >> a[i];
	}
}
void Output(int a[], int& n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
void Intersect(int a[], int b[], int& n, int &m)
{
	int c[max];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (a[i] == b[j])
			{
				c[i] = a[i];
				cout << c[i] << " ";
			}
		}
	cout << endl;
}
int Check(int a[], int &n, int &x)
{
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			return 1;
	return 0;
}
void Union(int a[], int b[], int& n, int& m)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	for (int i = 0; i < m; i++)
	{
		if (!Check(a, n, b[i]))
			cout << b[i] << " ";
	}
	cout << endl;
}
void Compensation(int a[], int b[], int& n, int& m)
{
	for (int i = 0; i < n; i++)
	{
		if (Check(b, m, a[i]) == 0)
			cout << a[i] << " ";
	}
	for (int i = 0; i < m; i++)
	{
		if (Check(a, n, b[i])==0)
			cout << b[i] << " ";
	}
	cout << endl;
}
void menu(int &n, int &m)
{
	system("cls");
	char choose;
	cout << "=====BT 15 Chuong 2======\n";
	cout << "1.Khoi tao 2 danh sach\n";
	cout << "2.Xuat cac phan tu trong 1 danh sach\n";
	cout << "3.Xuat cac phan tu thuoc tap hop cua 2 danh sach\n";
	cout << "4.Xuat cac phan tu thuoc tap giao cua 2 danh sach\n";
	cout << "5.Xuat cac phan tu thuoc phan bu cua 2 danh sach\n";
	cout << "6.Thoat\n";
	cout << "Nhap lua chon cua ban: ";
	cin >> choose;
	switch (choose)
	{
	case '1':
	{
		cout << "Nhap so phan tu cho danh sach 1: ";
		cin >> n;
		Input(a, n);
		cout << "Nhap so phan tu cho danh sach 2: ";
		cin >>m;
		Input(b, m);
		break;
	}
	case '2':
	{
		int x;
		do
		{
			cout << "Nhap danh sach ma ban muon xuat: ";
			cin >> x;
		} while (x != 1 && x != 2);
		if (x == 1)
		{
			cout << "Danh sach 1: ";
			Output(a, n);
			cout << endl;
		}
		else
		{
			cout << "Danh sach 2: ";
			Output(b, m);
			cout << endl;
		}
		break;
	}
	case'3':
	{
		cout << "Tap hop cac phan tu cua 2 danh sach gom: ";
		Union(a, b, n, m);
		break;
	}
	case'4':
	{
		cout << "Tap giao cua 2 danh sach la: ";
		Intersect(a, b, n, m);
		break;
	}
	case'5':
	{
		cout << "Phan bu cua 2 danh sach la: ";
		Compensation(a, b, n, m);
		break;
	}
	case'6':
	{
		cout << "Chuong Trinh Ket Thuc\n";
		return;
	}
	default:
	{
		cout << "Nhap sai, nhap lai\n";
		break;
	}
	}
	system("pause");
	return menu(n,m);
}
int main()
{
	int n = 0, m=0;
	menu(n,m);
	system("pause");
	return 0;
}