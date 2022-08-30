#include <iostream>
using namespace std;
const int MAX = 100;

int arr[MAX];
int n;

void input() {
	cout << "Nhap vao so luong phan tu: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu thu " << i << ": ";
		cin >> arr[i];
	}
}

void output() {
	for (int i = 0; i < n; i++) {
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
}


void find() {
	int x;
	cout << "Nhap phan tu ban muon tim: ";
	cin >> x;
	bool check = false;
	for (int i = 0; i < n; i++) {
		if (arr[i] == x)
		{
			check = true;
		}
	}
	if (check) cout << "Tim thay " << endl;
	else cout << "Khong tim thay " << endl;
}



void addlast() {
	int x;
	cout << "Nhap phan tu ban muon them vao cuoi mang: ";
	cin >> x;
	n++;
	arr[n - 1] = x;
}

void deletelast() {
	cout << "Xoa phan tu o cuoi danh sach: ";
	n--;
}

void indexdelete() {
	int x;
	while (true)
	{
		cout << "Nhap vi tri ban muon xoa phan tu: ";
		cin >> x;
		if (x >= 0 && x < n) break;
	}
	for (int i = x; i < n - 1; i++) {
		arr[i] = arr[i + 1];
	}
	n--;
}

void finddelete() {
	int x;
	cout << "Nhap phan tu ban muon tim va xoa: ";
	cin >> x;
	bool check = false;
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) {
			arr[i] = arr[i + 1];
			n--;
			check = true;
			break;
		}
	}
	if (!check) cout << "Khong tim thay phan tu " << x << " trong mang \n";
}


int main() {
	int choose;
	while (1)
	{
		cout << "--------BAI 1 TAP CHUONG 2 ----------------" << endl;
		cout << "1.Nhap danh sach\n";
		cout << "2.Xuat danh sach\n";
		cout << "3.Tim phan tu co gia tri x trong ds\n";
		cout << "4.Them 1 phan tu\n";
		cout << "5.Xoa phan tu cuoi danh sach\n";
		cout << "6.Xoa phan tu tai vi tri x\n";
		cout << "7.Tim va xoa phan tu\n";
		cout << "8.Thoat\n";
		cout << "-------------------------------------------" << endl;
		cout << "Nhap lua chon cua ban: ";
		cin >> choose;
		if (choose == 1) {
			input();
			cout << endl;
		}
		else if (choose == 2) {
			output();
			cout << endl;
		}
		else if (choose == 3) {
			find();
			cout << endl;
		}
		else if (choose == 4) {
			addlast();
			cout << endl;
			output();
			cout << endl;
		}
		else if (choose == 5) {
			deletelast();
			cout << endl;
			output();
			cout << endl;
		}
		else if (choose == 6) {
			indexdelete();
			cout << endl;
			output();
			cout << endl;
		}
		else if (choose == 7) {
			finddelete();
			cout << endl;
			output();
			cout << endl;
		}
		else if (choose == 8) {
			cout << "--- GOOD BYE ---\n";
			break;
		}
		else
			cout << "Ban da nhap sai vui long nhap tu 1 - 8\n";
	}
	return 0;
}