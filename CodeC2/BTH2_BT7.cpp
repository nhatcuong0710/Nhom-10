#include <iostream>
using namespace std;
#define MAX 100
void init(int a[], int& front, int& rear) {
	front = -1;
	rear = -1;
}
int isEmpty(int a[], int front) {
	if (front == -1)
		return 1;
	return 0;
}
int isFull(int a[], int front, int rear) {
	if ((rear - front) == MAX - 1) 
		return 1;
	return 0;
}
int push(int a[], int &front, int &rear, int x){
	if ((rear - front) == MAX - 1) 
		return 0;
	else {
		if (front == -1)   
			front = 0;
		if (rear == MAX - 1){ 
			for (int i = front; i <= rear; i++)  
				a[i - front] = a[i];

			rear = MAX - 1 - front;             
			front = 0;                         
		}
		a[++rear] = x;
		return 1;
	}
}
int pop(int a[], int& front, int& rear){
	if (front == -1)    
		return 0;
	else {
		a[front++];
		if (front > rear){    
			front = -1;
			rear = -1;
		}
		return 1;
	}
}
void OutPut(int a[], int front, int rear) {
	for (int i = front; i <= rear; i++) 
		cout << a[i] << " ";
	cout << endl;
}
int main() {
	int a[MAX];
	int front, rear; 
	init(a, front, rear);
	while (1) {
		cout << "-----MENU-----" << endl;
		cout << "1. Khoi tao queue rong." << endl;
		cout << "2. Ktra queue rong." << endl;
		cout << "3. Ktra queue day." << endl;
		cout << "4. Them phan tu vao queue." << endl;
		cout << "5. Xoa 1 phan tu dau trong queue." << endl;
		cout << "6. Xuat cac phan tu trong queue" << endl;
		cout << "--------------" << endl;
		int choose;
		cout << "Moi ban chon: "; cin >> choose;

		if (choose == 1) {
			init(a, front, rear);
		}
		else if (choose == 2) {
			int res = isEmpty(a, front);
			if (res) cout << "Stack rong." << endl;
			else cout << "Stack khong rong." << endl;
		}
		else if (choose == 3) {
			int res = isFull(a, front, rear);
			if (res) cout << "Stack day." << endl;
			else cout << "Stack khong day." << endl;
		}
		else if (choose == 4) {
			int x;
			cout << "Nhap phan tu muon them vao: "; cin >> x;
			int res = push(a, front,rear, x);
			if (res) cout << "Da them." << endl;
			else cout << "Them khong hop le." << endl;
		}
		else if (choose == 5) {
			int res = pop(a, front, rear);
			if (res) cout << "Da lay dau ra ngoai." << endl;
		}
		else if (choose == 6) {
			OutPut(a, front, rear);
		}
		else break;
	}
	return 0;
}