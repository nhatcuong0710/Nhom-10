#include <iostream>
#include <stack>
#include <string>
using namespace std;

void NhiPhan(int n) {
	stack<int> st;
	while (n != 0) {
		st.push(n % 2);
		n /= 2;
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}
void BatPhan(int n) {
	stack<int> st;
	while (n != 0) {
		st.push(n % 8);
		n /= 8;
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}
void ThapLucPhan(int n) {
	stack<string> st;
	string du ="";
	while (n != 0) {
		int tmp = n % 16;
		if (tmp >= 0 && tmp <= 9)
			du = to_string(tmp);
		else if (tmp == 10)
			du = 'A';
		else if (tmp == 11)
			du = 'B';
		else if (tmp == 12)
			du = 'C';
		else if (tmp == 13)
			du = 'D';
		else if (tmp == 14)
			du = 'E';
		else if (tmp == 15)
			du = 'F';

		st.push(du);
		n /= 16;
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}
int main() {
	int n;
	cout << "Nhap so muon chuyen sang cac he: "; cin >> n;
	cout << "So " << n << " chuyen sang he nhi phan la: ";
	NhiPhan(n);
	cout << endl;
	cout << "So " << n << " chuyen sang he bat phan la: ";
	BatPhan(n);
	cout << endl;
	cout << "So " << n << " chuyen sang he thap luc phan la: ";
	ThapLucPhan(n);
	return 0;
}