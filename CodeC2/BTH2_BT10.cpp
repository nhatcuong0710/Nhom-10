#include <iostream>
#include <string>
using namespace std;
struct Node {
	string data;
	Node* next;
};
typedef struct Node* node;
void init(node top) {
	top = NULL;
}
int isEmpty(node top) {
	if (top == NULL)
		return 1;
	return 0;
}
node makeNode(string x) {
	node tmp = new Node();
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}
void push(node& top, string x) {
	node tmp = makeNode(x);
	if (top == NULL) {
		top = tmp;
	}
	else {
		tmp->next = top;
		top = tmp;
	}
}
void pop(node& top) {
	if (top == NULL)
		return;
	top = top->next;
}
string GetTop(node top) {
	return top->data;
}
void ThapPhan_NhiPhan(node top) {
	long long n;
	cout << "Nhap so thap phan muon chuyen sang nhi phan: "; cin >> n;
	while (n) {
		int du = n % 2;
		string tmp = to_string(du);
		push(top, tmp);
		n /= 2;
	}
	cout << "Dang nhi phan la: ";
	while (!isEmpty(top)) {
		cout << GetTop(top);
		pop(top);
	}
}
int main() {
	node top = NULL;
	ThapPhan_NhiPhan(top);
	//Bài Tháp Hà Nội xem BTH9
	return 0;
}