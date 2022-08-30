#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
typedef struct Node* node;

void init(node back) {
	back = NULL;
}
int isEmpty(node back) {
	if (back == NULL)
		return 1;
	return 0;
}
node makeNode(int x) {
	node tmp = new Node();
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}
void push(node& back, int x) {
	node tmp = makeNode(x);
	tmp->next = back;
	back = tmp;
}
void pop(node& back) {
	if (back == NULL) return;
	node truoc = NULL, sau = back;
	while (sau->next != NULL) {
		truoc = sau;
		sau = sau->next;
	}
	if (truoc == NULL)
		back = NULL;
	else truoc->next = NULL;
}
void OutPut(node back) {
	while (back != NULL) {
		cout << back->data << " ";
		back = back->next;
	}
	cout << endl;
}
int main() {
	node back = NULL;
	while (1) {
		cout << "-----MENU-----" << endl;
		cout << "1. Khoi tao queue rong." << endl;
		cout << "2. Ktra queue rong." << endl;
		cout << "3. Them phan tu vao queue." << endl;
		cout << "4. Xoa 1 phan tu dau trong queue." << endl;
		cout << "5. Xuat cac phan tu trong queue" << endl;
		cout << "--------------" << endl;
		int choose;
		cout << "Moi ban chon: "; cin >> choose;

		if (choose == 1) {
			back = NULL;
			/*init(back);*/
		}
		else if (choose == 2) {
			int res = isEmpty(back);
			if (res) cout << "Stack rong." << endl;
			else cout << "Stack khong rong." << endl;
		}
		else if (choose == 3) {
			int x;
			cout << "Nhap gia tri muon them: "; cin >> x;
			push(back, x);
			cout << "Da them." << endl;
		}
		else if (choose == 4) {
			pop(back);
			cout << "Da xoa." << endl;
		}
		else if (choose == 5) {
			OutPut(back);
		}
		else break;
	}
	return 0;
}