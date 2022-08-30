#include <iostream>
using namespace std;
#define MAX 100

void init(int a[], int& sp) {
	sp = -1;
}
int push(int a[], int& sp, int x) {
	if (sp < MAX - 1) {
		a[++sp] = x;
		return 1;
	}
	return 0;
}
int pop(int a[], int& sp) {
	if (sp != -1) {   
		a[sp--];
		return 1;
	}
	return 0;
}
int isEmpty(int a[], int sp) {
	if (sp == -1)
		return 1;
	return 0;
}
int isFull(int a[], int sp){
	if (sp == MAX - 1)
		return 1;
	return 0;
}
void OutPut(int a[], int sp){
	for (int i = 0; i <= sp; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main(){
	int a[MAX];
	int sp;
	init(a, sp);

	while (1) {
		cout << "-----MENU-----" << endl;
		cout << "1. Khoi tao stack rong." << endl;
		cout << "2. Ktra stack rong." << endl;
		cout << "3. Ktra stack day." << endl;
		cout << "4. Them phan tu vao stack." << endl;
		cout << "5. Lay phan tu cuoi trong stack ra ngoai. (xoa phan tu cuoi)" << endl;
		cout << "6. Xuat cac phan tu trong stack" << endl;
		cout << "--------------" << endl;
		int choose;
		cout << "Moi ban chon: "; cin >> choose;

		if (choose == 1) {
			init(a, sp);
		}
		else if (choose == 2) {
			int res = isEmpty(a, sp);
			if (res) cout << "Stack rong." << endl;
			else cout << "Stack khong rong." << endl;
		}
		else if (choose == 3) {
			int res = isFull(a, sp);
			if (res) cout << "Stack day." << endl;
			else cout << "Stack khong day." << endl;
		}
		else if (choose == 4) {
			int x;
			cout << "Nhap phan tu muon them vao: "; cin >> x;
			int res = push(a, sp, x);
			if (res) cout << "Da them." << endl;
			else cout << "Them khong hop le." << endl;
		}
		else if (choose == 5) {
			int res = pop(a, sp);
			if (res) cout << "Da lay phan tu cuoi ra ngoai." << endl;
		}
		else if (choose == 6) {
			OutPut(a, sp);
		}
		else break;
	}
	return 0;
}