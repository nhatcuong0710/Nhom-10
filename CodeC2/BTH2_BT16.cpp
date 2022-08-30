#include <iostream>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
typedef struct Node {
	int data;
	struct Node* next;
}*node;
void Init(node& phead) {
	phead = NULL;
}
int Empty(node phead) {
	return phead == NULL;
}
node createNode(int x) {
	node p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}
void iLast(node& phead, int x) {
	node tmp = createNode(x), q;
	if (Empty(phead)) phead = tmp;
	else {
		q = phead;
		while (q->next != NULL) {
			q = q->next;
		}
		q->next = tmp;
	}
}
void input(node& phead) {
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		iLast(phead, x);
	}
}
void output(node phead) {
	for (node p = phead; p != NULL; p = p->next) {
		cout << p->data << " ";
	}
}
void giaoHaiTapHop(node phead1, node phead2) {
	for (node p = phead1; p != NULL; p = p->next) {
		for (node q = phead2; q != NULL; q = q->next) {
			if (p->data == q->data) {
				cout << q->data << " ";
			}
		}
	}
}
void phanTuBu(node phead1, node phead2) {
	for (node p = phead1; p != NULL; p = p->next) {
		for (node q = phead2; q != NULL; q = q->next) {
			if (p->data == q->data) {
				p->data = 0;
			}
		}
	}
	for (node p = phead1; p != NULL; p = p->next) {
		if (p->data != 0) {
			cout << p->data << " ";
		}
	}
}
int main() {
	node phead1, phead2;
	Init(phead1);
	Init(phead2);
	cout << "\nNhap so luong phan tu cua danh sach 1: ";
	input(phead1);
	cout << "\nNhap so luong phan tu cua danh sach 2: ";
	input(phead2);
	cout << "Danh sach 1: ";
	output(phead1);
	cout << "\n";
	cout << "Danh sach 2: ";
	output(phead2);
	cout << "\n";
	cout << "\nCac phan tu giao cua hai tap hop: ";
	giaoHaiTapHop(phead1, phead2);
	cout << "\nPhan tu bu cua hai tap hop: ";
	phanTuBu(phead1, phead2);
	return 0;
}