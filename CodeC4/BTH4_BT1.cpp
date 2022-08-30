#include <iostream>
using namespace std;
struct Node {
	int info;
	Node* left;
	Node* right;
};
typedef struct Node* node;
void tree_empty(node root) {
	root = NULL;
}
node makeNode(int x) {
	node tmp = new Node();
	tmp->info = x;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}
void InsertNode(node &root, int x) {
	if (root == NULL) {
		root = makeNode(x);
	}
	else {
		if (root->info == x)
			return;
		else if (root->info > x)
			return InsertNode(root->left, x);
		else
			return InsertNode(root->right, x);
	}
}
node Search(node root,int x) {
	if (root != NULL) {
		if (root->info == x)
			return root;
		else {
			if (root->info > x)
				return Search(root->left, x);
			else return Search(root->right, x);
		}
	}
	return NULL;
}
void searchStandFor(node& p, node& q){
	if (q->left == NULL) {
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		searchStandFor(p, q->left);
}
int Xoa(node& root, int x) {
	if (root == NULL) return 0;
	if (root->info == x){
		node p = root;
		if (root->left == NULL)
			root = root->right;
		else if (root->right == NULL)
			root = root->left;
		else
			searchStandFor(p, root->right);
		delete p;
		return 1;
	}
	if (root->info < x) return Xoa(root->right, x);
	if (root->info > x) return Xoa(root->left, x);
}
void duyetNLR(node root){
	if (root != NULL){
		cout << root->info << " ";
		duyetNLR(root->left);
		duyetNLR(root->right);
	}
}
void duyetLNR(node root) {
	if (root != NULL) {
		duyetLNR(root->left);
		cout << root->info << " ";
		duyetLNR(root->right);
	}
}
void duyetLRN(node root){
	if (root != NULL){
		duyetLRN(root->left);
		duyetLRN(root->right);
		cout << root->info << " ";
	}
}

int main() {
	node root = NULL;
	while (1) {
		cout << "----------MENU----------\n";
		cout << "1. Khoi tao cay rong. \n";
		cout << "2. Them 1 nut vao cay. \n";
		cout << "3. Tim 1 nut trong cay.\n";
		cout << "4. Xoa 1 nut trong cay. \n";
		cout << "5. Duyet cay theo thu tu NLR \n";
		cout << "6. Duyet cay theo thu tu LNR \n";
		cout << "7. Duyet cay theo thu tu LRN \n";
		cout << "---------------------------\n";
		cout << "Moi ban chon: ";
		int choose; cin >> choose;
		if (choose == 1) {
			tree_empty(root);
		}
		else if (choose == 2) {
			int x;
			cout << "Nhap phan tu can them: "; cin >> x;
			InsertNode(root, x);
		}
		else if (choose == 3) {
			int x; 
			cout << "Nhap phan tu can tim: "; cin >> x;
			if (Search(root, x) != NULL)
				cout << "Co phan tu " << x << " trong cay." << endl;
			else 
				cout << "Khong co phan tu " << x << " trong cay." << endl;
		}
		else if (choose == 4) {
			int x;
			cout << "Nhap phan tu can xoa: "; cin >> x;
			if (Xoa(root, x) == 0)
				cout << "Khong co phan tu " << x << " trong cay." << endl;
			else cout << "Da xoa." << endl;
		}
		else if (choose == 5) {
			duyetNLR(root);
			cout << endl;
		}
		else if (choose == 6) {
			duyetLNR(root);
			cout << endl;
		}
		else if (choose == 7) {
			duyetLRN(root);
			cout << endl;
		}
		else break;
	}
	return 0;
}