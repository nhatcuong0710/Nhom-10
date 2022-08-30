#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
typedef struct Node* node;
node a;
void DS_Rong() {
	a = NULL;
}
node makeNode(int x) {
	node tmp = new Node();
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}
void Them_Dau(int x) {
	node p = makeNode(x);
	if (a == NULL)
		a = p;
	else {
		p->next = a;
		a = p;
	}
}
void Them_Bki(int x, int pos) {
	node p = makeNode(x);
	int i = 0;
	node tmp = a;
	while (tmp != NULL) {
		if (i == pos) {
			break;
		}
		i++;
		tmp = tmp->next;
	}
	p->next = tmp->next;
	tmp->next = p;
}
void XuatDS() {
	node p;
	p = a;
	while (p != NULL) {
		cout << p->data << endl;
		p = p->next;
	}
}
node Tim_Kiem(int x) {
	node p = a;
	while (p != NULL && p->data != x) {
		p = p->next;
	}
	return p;
}
void Xoa_Dau() {
	if (a == NULL)
		return;
	if (!a->next) a = NULL;
	else {
		node to_del = a;
		a = a->next;
		delete to_del;
	}
}
void Tim_Xoa(int x) {
	node tmp = Tim_Kiem(x);
	int cnt = 0;
	if (tmp == NULL)
		return;
	else {
		while (tmp) {
			node p = tmp;
			if (p == a) {
				Xoa_Dau();
			}
			else {
				node x = a;
				while (x->next != tmp) {
					x = x->next;
				}
				x->next = tmp->next;
				tmp->next = NULL;
				delete(tmp);
			}
			tmp = Tim_Kiem(x);
		}
	}
}
int main() {
	while (1) {
		cout << "----------MENU----------\n";
		cout << "1. Khoi tao danh sach rong. \n";
		cout << "2. Them vi tri bat ki trong DS. \n";
		cout << "3. Xuat cac phan tu trong DS. \n";
		cout << "4. Tim mot phan tu trong DS.\n";
		cout << "5. Tim va Xoa 1 phan tu trong DS. \n";
		cout << "6. Them 1 phan tu vao dau trong DS. \n";
		cout << "---------------------------\n";
		cout << "Moi ban chon: ";
		int choose; cin >> choose;
		if (choose == 1) {
			DS_Rong();
		}
		else if (choose == 2) {
			int pos, x;
			cout << "Nhap vi tri muon them: "; cin >> pos;
			cout << "Nhap phan tu muon them: "; cin >> x;
			Them_Bki(x, pos);
			cout << "Xuat cac phan tu: " << endl;
			XuatDS();
		}
		else if (choose == 3) {
			XuatDS();
		}
		else if (choose == 4) {
			int x;
			cout << "Nhap phan tu muon tim: "; cin >> x;
			if (Tim_Kiem(x) != NULL)
				cout << "Co " << x << " trong DS." << endl;
			else cout << "Khong co " << x << " trong DS." << endl;
		}
		else if (choose == 5) {
			int x;
			cout << "Nhap phan tu muon tim va xoa: "; cin >> x;
			Tim_Xoa(x);
			cout << "Xuat cac phan tu: " << endl;
			XuatDS();
		}
		else if (choose == 6) {
			int x; cout << "Nhap phan tu muon them: "; cin >> x;
			Them_Dau(x);
		}
		else break;
	}
	return 0;
}