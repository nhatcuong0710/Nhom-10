#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

//Cau 2.1
#define MAX 100
int a[MAX];
int n;

//Cau 2.2
void input(int a[], int &n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
//Cau 2.3
void output(int a[], int n)
{
	cout << "Mang cua ban: "<<endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
 //Cau 2.4
void searchSequence(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i == n)
		cout << "Khong tim thay";
	else
		cout << "Tim thay tai vi tri" << i+1<<endl;
}

//Cau 2.5
int binarySearch(int a[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			return binarySearch(a, l, mid - 1, x);
		return binarySearch(a, mid + 1, r, x);
	}
	return -1;
}

//Cau 2.6
void Delete(int a[], int& n, int index)
{
	if (index < 0)
		index = 0;
	if (index >= n)
		index = n - 1;
	for (int i = index; i < n-1; i++)
		a[i] = a[i + 1];
	n--;
}
int SearchandDelete(int a[], int& n, int x)
{
	for (int i = 0; i < n; i++)
		if (a[i] == x)
		{
			Delete(a, n, i);
			return 1;
		}
	return 0;
}

int main()
{
	clock_t start;
	double duration;
	int choice, x, i;
	system("cls");
	cout << "---BAI TAP LAM THEM 2 CHUONG 2---" << endl;
	cout << "1. Them mot phan tu vao danh sach" << endl;
	cout << "2. Xuat danh sach" << endl;
	cout << "3. Thuc hien tim x theo searhcSequenece" << endl;
	cout << "4. Thuc hien tim x theo searchBinary" << endl;
	cout << "5. Thuc hien tim va xoa phan tu" << endl;
	cout << "6. Thoat" << endl;
	do
	{
		cout << "\nVui long chon lenh thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Nhap so luong phan tu ban muon thuc hien: ";
			cin >> n;
			input(a, n);
			break;
		case 2:
			output(a, n);
			break;
		case 3:
			cout << "Vui long nhap gia tri x can tim: ";
			cin >> x;
			start = clock();
			searchSequence(a, n, x);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (duration > 0)
			{
				cout << "Thoi gian tim kiem tuan tu la: " << duration * 1000000 << " miliseconds" << endl;
			}
			break;
		case 4:
			cout << "Vui long nhap gia tri x can tim: ";
			cin >> x;
			start = clock();
			i = binarySearch(a, 0, n - 1, x);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (i == -1)
				cout << "Khong tim thay x= " << x << " trong day" << endl;
			else
				cout << "Tim thay x= " << x << " tai vi tri i= " << i+1 << endl;
			if (duration > 0)
			{
				cout << "Thoi gian tim kiem nhi phan la: " << duration * 1000000 << " miliseconds" << endl;
			}
			break;
		case 5:
			cout << "Vui long nhap gia tri x can tim va xoa: ";
			cin >> x;
			i = SearchandDelete(a, n, x);
			if (i == 0)
				cout << "Khong tim thay x= " << x << " de xoa";
			else
			{
				cout << "Xoa thanh cong, mang hien tai la: " << endl;
				output(a, n);
			}
			cout << n;
			break;
		case 6:
			cout << "BYE" << endl;
			break;
		default:
			break;
		}
	} while (choice != 6);
	system("pause");
	return 0;
}