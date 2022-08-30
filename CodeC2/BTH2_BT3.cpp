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
void Them_Cuoi(int x) {
	node p = makeNode(x);
	if (a == NULL)
		a = p;
	else {
		node tmp = a;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = p;
	}
}
void Xoa_Cuoi() {
	if (a == NULL)
		return;
	node truoc = NULL;
	node sau = a;
	while (sau->next != NULL) {
		truoc = sau;
		sau = sau->next;
	}
	if (truoc == NULL)
		a = NULL;
	else truoc->next = NULL;
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

void Sap_Xep() {
	for (node p = a; p->next != NULL; p = p->next) {
		node min = p;
		for (node q = p->next; q != NULL; q = q->next) {
			if (q->data < min->data)
				min = q;
		}
		int tmp = min->data;
		min->data = p->data;
		p->data = tmp;
	}
}
int main() {
	while (1) {
		cout << "----------MENU----------\n";
		cout << "1. Khoi tao danh sach rong. \n";
		cout << "2. Xuat cac phan tu trong DS. \n";
		cout << "3. Tim mot phan tu trong DS.\n";
		cout << "4. Them 1 phan tu vao dau DS. \n";
		cout << "5. Xoa 1 phan tu o dau DS. \n";
		cout << "6. Them 1 phan tu vao cuoi DS. \n";
		cout << "7. Xoa 1 phan tu o cuoi DS. \n";
		cout << "8. Tim va Xoa 1 phan tu trong DS. \n";
		cout << "9. Sap xep cac phan tu trong DS. \n";
		cout << "---------------------------\n";
		cout << "Moi ban chon: ";
		int choose; cin >> choose;
		if (choose == 1) {
			DS_Rong();
		}
		else if (choose == 2) {
			XuatDS();
		}
		else if (choose == 3) {
			int x;
			cout << "Nhap phan tu muon tim: "; cin >> x;
			if (Tim_Kiem(x) != NULL)
				cout << "Co " << x << " trong DS." << endl;
			else cout << "Khong co " << x << " trong DS." << endl;
		}
		else if (choose == 4) {
			int x;
			cout << "Nhap phan tu muon them vao dau DS: "; cin >> x;
			Them_Dau(x);
		}
		else if (choose == 5) {
			Xoa_Dau();
		}
		else if (choose == 6) {
			int x;
			cout << "Nhap phan tu muon them vao cuoi DS: "; cin >> x;
			Them_Cuoi(x);
		}
		else if (choose == 7) {
			Xoa_Cuoi();
		}
		else if (choose == 8) {
			int x;
			cout << "Nhap phan tu muon tim va xoa: "; cin >> x;
			Tim_Xoa(x);
		}
		else if (choose == 9) {
			Sap_Xep();
		}
		else break;
	}
	return 0;
}