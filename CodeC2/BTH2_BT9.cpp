#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
};
typedef struct Node* node; 

void init(node& p) {
	p = NULL;
}

bool isEmpty(node p) {
	return p == NULL;
}


node makeNode(int x) {
	node tmp = new Node();
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}

void push(node& top, int x) {
	node tmp = makeNode(x);
	if (top == NULL) {
		top = tmp;
	}
	else {
		tmp->next = top;
		top = tmp;
	}
}

int pop(node& top) {
	if (isEmpty(top)) {
		return -1;
	}
	int a = top->data;
	top = top->next;
	return a;
}

void outPut(node top) {
	while (!isEmpty(top)) {
		cout << top->data << " ";
		top = top->next;
	}
}

void moveDisc(int disc, char a, char b) {
	cout << "Chuyen dia thu " << disc << " tu cot " << a << " sang cot " << b << endl;
}

void moveDiscAction(node n, node m, char a, char b) {
	int top1 = pop(n);
	int top2 = pop(m);
	if (top1 == -1) {
		push(n, top2);
		moveDisc(top2, b, a);
	}
	else if (top2 == -1) {
		push(m, top1);
		moveDisc(top1, a, b);
	}
	else if (top1 > top2) {
		push(n, top1);
		push(n, top2);
		moveDisc(top2, b, a);
	}
	else if (top1 < top2) {
		push(m, top2);
		push(m, top1);
		moveDisc(top1, a, b);
	}
}

void towerOfHaNoi(int ndisc, node n, node m, node k) {
	char a = 'A', b = 'B', c = 'C';

	if (ndisc % 2 == 0) {
		char tmp = b;
		b = c;
		c = tmp;
	}
	int nmove = pow(2, ndisc) + 1;
	for (int i = ndisc; i >= 1; i--) {
		push(n, i);
	}

	for (int i = 1; i <= nmove; i++) {
		if (i % 3 == 0) {
			moveDiscAction(m, k, c, b);
		}
		else if (i % 3 == 2) {
			moveDiscAction(n, m, a, c);
		}
		else if (i % 3 == 1) {
			moveDiscAction(n, k, a, b);
		}
	}
}

int main() {
	int ndisc;
	cout << "Nhap so dia: "; cin >> ndisc;
	node n, k, m;
	n = makeNode(ndisc);
	m = makeNode(ndisc);
	k = makeNode(ndisc);
	towerOfHaNoi(ndisc, n, m, k);
	delete(n);
	delete(m);
	delete(k);
	return 0;
}