#include<iostream>
#include<fstream>
using namespace std;
#define MAX 20

int a[MAX][MAX];
int n;
char vertex[MAX];

struct Node
{
	int val;
	Node* link;
};
typedef struct Node* node;
node sp;
node front, rear;

void InitStack()
{
	sp = NULL;
}
int EmptyS()
{
	if (sp == NULL)
		return 1;
	return 0;
}
void PushS(int x)
{
	node p = new Node;
	p->val = x;
	p->link = sp;
	sp = p;
}
int PopS(int& x)
{
	if (sp != NULL)
	{
		node p = sp;
		x = p->val;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

void InitQueue()
{
	front = NULL;
	rear = NULL;
}
int EmptyQ()
{
	if (front == NULL)
		return 1;
	return 0;
}
void PushQ(int x)
{
	node p = new Node;
	p->val = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
int PopQ(int& x)
{
	if (front != NULL)
	{
		node p = front;
		front = p->link;
		x = p->val;
		if (front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}



void InitGraph()
{
	n = 0;
}

//Nhap MTK bang tay
void Input()
{
	cout << "Nhap so dinh cua do thi n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap ten dinh: ";
		cin >> vertex[i];
		cout << "Nhap vao dong thu " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}

//Nhap MTK tu file txt 
void InputTXT()
{
	string line;
	ifstream fi("mtk1.txt");
	if (fi.is_open())
	{
		fi >> n;
		for (int i = 0; i < n; i++)
			fi >> vertex[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				fi >> a[i][j];
		}

	}
}


//Xuat MTK
void OutputGraph()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << vertex[i] << " ";
	}
	cout << endl;
}

//Duyet BFS theo QUEUE
int c[100], bfs[100];
int nbfs = 0;
void Init()
{
	for (int i = 0; i < n; i++)
		c[i] = 1;
}
void BFS(int v)
{
	int w, p;
	PushQ(v);
	c[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for (w = 0; w < n; w++)
		{
			if (c[w] && a[p][w] == 1)
			{
				PushQ(w);
				c[w] = 0;
			}
		}
	}
}

//Duyet DFS theo STACK
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	c[s] = 0;
	int v = -1, u = s;
	while (EmptyS() == 0)
	{
		if (v == n)
			PopS(u);
		for (v = 0; v < n; v++)
		{
			if (a[u][v] != 0 && c[v] == 1)
			{
				PushS(u);
				PushS(v);
				dfs[ndfs] = v;
				ndfs++;
				c[v] = 0;
				u = v;
				break;
			}
		}
	}
}

//Search su dung BFS
void Search_BFS(int x, int v)
{
	int w, p;
	PushQ(v);
	c[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		if (x == p)
		{
			cout << "Tim thay x = " << x << endl;
			return;
		}
		for (w = 0; w < n; w++)
		{
			if (c[v] && a[p][w] == 1)
			{
				PushQ(w);
				c[w] = 0;
			}
		}
	}
}
void menu(int& x)
{
	system("cls");
	char choose;
	cout << "========MENU========\n";
	cout << "1.Khoi tao Ma Tran Ke rong\n";
	cout << "2.Nhap MTK tu file txt\n";
	cout << "3.Nhap MTK\n";
	cout << "4.Xuat MTK\n";
	cout << "5.Duyet do thi theo chieu ngang BFS - DSLK\n";
	cout << "6.Duyet do thi theo chieu sau DFS - DSLK\n";
	cout << "7.Tim dinh co gia tri x theo BFS\n";
	cout << "8.Thoat\n";
	cout << "Nhap lua chon cua ban: ";
	cin >> choose;
	switch (choose)
	{
	case '1':
	{
		InitGraph();
		cout << "Khoi tao thanh cong\n";
		break;
	}
	case '2':
	{
		InputTXT();
		cout << "Nhap MTK tu file thanh cong\n";
		OutputGraph();
		break;
	}
	case '3':
	{
		Input();
		break;
	}
	case '4':
	{
		OutputGraph();
		break;
	}
	case '5':
	{
		InitQueue();
		Init();
		cout << "Nhap dinh xuat phat: ";
		cin >> x;
		BFS(x);
		cout << "Thu tu dinh sau khi duyet BFS: ";
		Output(bfs, n);
		break;
	}
	case '6':
	{
		InitStack();
		Init();
		cout << "Nhap dinh xuat phat: ";
		cin >> x;
		DFS(x);
		cout << "Thu tu dinh sau khi duyet BFS: ";
		Output(dfs, n);
		break;
	}
	case '7':
	{
		cout << "Nhap gia tri x can tim: ";
		cin >> x;
		Search_BFS(x, 0);
		break;
	}
	case '8':
	{
		cout << "Chuong Trinh Ket Thuc\n";
		return;
	}
	default:
	{
		cout << "Nhap sai, nhap lai\n";
		break;
	}
	}
	system("pause");
	return menu(x);
}

int main()
{
	int a[MAX];
	int b[MAX];
	int x = 0;
	menu(x);
	system("pause");
	return 0;

}