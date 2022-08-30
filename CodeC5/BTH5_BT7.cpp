#include<stdio.h>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
#define Max 20
// DSLK su dung cho STACK va QUEUE, va DANH SACH KE
struct Node
{
	int info;
	Node* link;
};
Node* sp;
Node* front, * rear;
Node* First[Max]; // DS cac DSK
int n; // so dinh cua do thi
char vertex[Max]; // ten dinh
void InitStack()
{
	sp = NULL;
}
int isEmptyS()
{
	if (sp == NULL)
		return 1;
	return 0;
}
void PushS(int x)
{
	Node* p = new Node;
	x = p->info;
	sp = p->link;
	sp = p;
}
int PopS(int& x)
{
	if (sp != NULL)
	{
		Node* p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
// end Stack


/// QUEUE
void InitQueue()
{
	front = NULL;
	rear = NULL;
}
int isEmptyQ()
{
	if (front == NULL)
		return 1;
	return 0;
}
void PushQ(int x) {
	Node* p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
int PopQ(int& x)
{
	if (front != NULL) {
		Node* p = front;
		front = p->link;
		x = p->info;
		if (front == NULL) {
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}
// end QUEUE
void InitGraph()
{
	n = 0;
}
void InsertLast(Node*& first, Node* p)
{
	if (first == NULL)
		first = p;
	else
	{
		Node* q = first;
		while (q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}

/// Nhap bang tay DSK
void inputGraph()
{
	cout << "Nhap so dinh do thi n: ";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for (int i = 0; i < n + 1; i++)
		cin >> vertex[i];
	for (int i = 0; i < n + 1; i++)
	{
		if (i > 0)
			cout << "Nhap DSK cua dinh thu " << i - 1 << " (" << vertex[i - 1] << ") : ";
		int u;
		string str;
		while (getline(cin, str))
		{
			istringstream ss(str);
			while (ss >> u)
			{
				Node* p = new Node;
				p->info = u;
				p->link = NULL;
				InsertLast(First[i - 1], p);
			}
			break;
		}
	}
}

// Nhap DSK tu file txt
void inputGraphFromText()
{
	string line;
	ifstream myfile("dslk1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		string str;
		int i = 0;
		while (getline(myfile, str))
		{
			istringstream ss(str);
			int u;
			while (ss >> u)
			{
				/// Dinh u
				Node* p = new Node;
				p->info = u;
				p->link = NULL;
				InsertLast(First[i - 1], p);
			}
			i++;
		}
	}
}
// Xuat DSK
void outputGraph()
{
	for (int i = 0; i < n; i++)
	{
		cout << "Dinh " << i << " (" << vertex[i] << "): ";
		Node* p = First[i];
		while (p != NULL)
		{
			cout << p->info << " ";
			p = p->link;
		}
		cout << endl;
	}
}

void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << " ";
}
// Duyet BFS
int C[100], bfs[100];
int nbfs = 0;
void InitC()
{
	for (int i = 0; i < n; i++)
		C[i] = 1;
}
void BFS(int v)
{
	int p;
	Node* w;
	PushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		w = First[p];
		nbfs++;
		while (w != NULL)
		{
			if (C[w->info])
			{
				PushQ(w->info);
				C[w->info] = 0;
			}
			w = w->link;
		}
	}
}
// DFS
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int u = s;
	Node* v = NULL;
	while (isEmptyS() == 0)
	{
		if (v == NULL)
			PopS(u);
		v = First[u];
		while (v != NULL)
		{
			if (C[v->info] == 1)
			{
				PushS(u);
				PushS(v->info);
				dfs[ndfs] = v->info;
				ndfs++;
				C[v->info] = 0;
				u = v->info;
				break;
			}
			v = v->link;
		}
	}
}
// Search
void search_DFS(int s)
{
	PushS(s);
	C[s] = 0;
	int v = -1, u = s;
	while (front != NULL)
	{
		int p;
		PopS(p);
		if (p == s)
		{
			dfs[ndfs++] = p;
			cout << "co tron do thi" << endl;
			return;
		}
		dfs[ndfs++] = p;
	}
}
int main()
{
	int a[Max];
	int b[Max];
	int choice, x, i;
	system("cls");
	cout << "---------------BAI TAP 7, CHUONG 5, DO THI------------------" << endl;
	cout << "1.Nhap DANH SACH KE tu file text " << endl;
	cout << "2.Nhap DANH SACH KE " << endl;
	cout << "3.Xuat DANH SACH KE " << endl;
	cout << "4.Duyet do thi theo chieu rong BFS - DSLK " << endl;
	cout << "5.Duyet do thi theo chieu sau DFS - DSLK " << endl;
	cout << "6.Tim dinh co gia tri x theo DFS " << endl;
	cout << "7.Ket thuc chuong trinh" << endl;
	do
	{
		cout << "\n Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			inputGraphFromText();
			cout << "Ban vua nhap DANH SACH KE tu file: \n";
			outputGraph();
			break;
		case 2:
			inputGraph();
			break;
		case 3:
			outputGraph();
			break;
		case 4:
			InitQueue();
			InitC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "Thu tu dinh sau khi duyet DFS: " << endl;
			output(bfs, n);
			break;
		case 5:
			InitStack();
			InitC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "Thu tu dinh sau khi duyet DFS: " << endl;
			output(dfs, n);
			break;
		case 6:
			InitQueue();
			InitC();
			nbfs = 0;
			cout << "Vui long nhap gia tri x can tim: ";
			cin >> x;
			search_DFS(x);
			break;
		case 7:
			cout << "Good Bye!!!!!!!!!!!!!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 7);
	system("pause");
	return 0;
}