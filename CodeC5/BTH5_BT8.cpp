#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define MAX 20

int a[MAX][MAX];
int n;


int C[MAX];

int bfs[100];
int nbfs = 0;

int dfs[100];
int ndfs = 0;

//=============================================
struct Node
{
	int info;
	Node* link;
};
Node* front, * rear;//Queue DSLKD
Node* sp; // stack DSLKD
//=============================================
//Doc file
bool Doc_File(string filename)
{
	ifstream ifs;
	ifs.open(filename);
	if (!ifs.is_open())
	{
		cout << "Error";
		return false;
	}
	string temp;
	getline(ifs, temp, '\n');
	n = atoi(temp.c_str());

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			getline(ifs, temp, ' ');
			a[i][j] = atoi(temp.c_str());
		}
		getline(ifs, temp, '\n');
		a[i][n - 1] = atoi(temp.c_str());
	}
	ifs.close();
}
//=============================================
//5.1 Nhap ma tran ke
void input()
{
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap dong thu " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}
//5.2 Xuat ma tran ke
void output()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}

//=============================================
void initQ()
{
	front = rear = NULL;
}
//=============================================
int isEmptyQ()
{
	if (front == NULL)
		return 1;
	return 0;
}
//=============================================
int PushQ(int x)
{
	Node* p = new Node;
	p->info = x;

	p->link = front;
	if (front == NULL)
		front = rear = p;
	else
		front = p;

	return 1;
}
//=============================================
int PopQ(int& x)
{
	if (front != NULL)
	{
		Node* p = front;
		x = p->info;
		front = p->link;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//=============================================
void khoitaochuaxet()
{
	for (int i = 0; i < n; i++)
		C[i] = 1;
}
//=============================================
void output_bfs()
{
	for (int i = 0; i < nbfs; i++)
		cout << char(bfs[i] + 'A') << "  ";
}


//=============================================
void initS()
{
	sp = NULL;
}
//=============================================
int isEmptyS()
{
	if (sp == NULL)
		return 1;
	return 0;
}
//=============================================
int PushS(int x)//chen vao cuoi
{
	Node* p = new Node;
	p->info = x;
	p->link = NULL;
	if (sp == NULL)
		sp = p;
	else
	{
		Node* q = sp;
		while (q->link != NULL)
			q = q->link;
		q->link = p;
	}
	return 1;
}
//=============================================
int PopS(int& x)
{

	if (sp != NULL) // if(!isEmpty())
	{
		Node* p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
//8.2 Duyet DFS dua tren Queue voi DSLKD
void DFS(int s)
{
	PushQ(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while (front != NULL)
	{
		if (v == n)
			PopQ(u);
		for (v = 0; v < n; v++)
		{
			if (a[u][v] != 0 && C[v] == 1)
			{
				PushQ(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
		}
	}
}
//=============================================
void output_dfs()
{
	for (int i = 0; i < ndfs; i++)
	{
		cout << char(dfs[i] + 'A') << "  ";
	}
}
//=============================================
//8.3 Duyet BFS dua tren Stack voi DSLKD
void BFS(int v)
{
	int w, p;
	PushS(v);
	C[v] = 0;
	while (sp != NULL)
	{
		PopS(p);
		bfs[nbfs] = p;
		nbfs++;
		for (w = 0; w < n; w++)
		{
			if (C[w] && a[p][w] == 1)
			{
				PushS(w);
				C[w] = 0;
			}
		}
	}
}
//=============================================
void DFS_DQ(int u)
{
	C[u] = 0;
	dfs[ndfs++] = u;
	for (int v = 0; v < n; v++)
	{
		if (a[u][v] != 0 && C[v] == 1)
			DFS_DQ(v);
	}
}
//=============================================
void search_BFS(int x, int v)
{
	int w, p;
	PushS(v);
	C[v] = 0;
	while (sp != NULL)
	{
		PopS(p);
		if (x == p)
		{
			cout << "Ton tai\n";
			return;
		}
		for (w = 0; w < n; w++)
		{
			if (C[w] && a[p][w] == 1)
			{
				PushS(w);
				C[w] = 0;
			}
		}
	}
	cout << "Khong ton tai\n";
}
//=============================================
int main()
{
	string filename = "DoThi5.1.txt";
	int chon;
	system("cls");
	cout << "===========BAI TAP 8 _ CHUONG 5==========" << endl;
	cout << "1.Doc tu FILE text vao ma tran ke cua do thi 5.1" << endl;
	cout << "2.Duyet do thi theo chieu rong (theo Queue bang DSLKD)" << endl;
	cout << "3.Duyet do thi theo chieu sau (theo Stack bang DSLKD)" << endl;
	cout << "4.Duyet DFS bang de qui" << endl;
	cout << "5.Kiem tra X co ton tai hay khong" << endl;

	cout << "0.Thoat" << endl;
	do
	{
		ndfs = 0;
		cout << "\nMoi ban chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			Doc_File(filename);
			cout << "\nDo thi duoc bieu dien duoi dang ma tran ke voi so luong DINH = " << n << "\n";
			output();
			break;
		case 2:
			cout << "\nKet qua duyet theo BFS (voi dinh xuat phat la A): \n";
			initS();
			khoitaochuaxet();
			BFS(0);
			output_bfs();
			break;
		case 3:
			cout << "\nKet qua duyet DFS theo Stack (voi dinh xuat phat la A): \n";
			initQ();
			khoitaochuaxet();
			DFS(0);
			output_dfs();
			break;
		case 4:
			cout << "\nKet qua duyet DFS theo de qui (voi dinh xuat phat la A): \n";
			khoitaochuaxet();
			DFS_DQ(0);
			output_dfs();
			break;
		case 5:
			int x;
			cout << "Nhap dinh can tim voi dinh bat dau la A: ";
			cin >> x;
			initS();
			khoitaochuaxet();
			search_BFS(x, 0);
			break;
		default: chon = 0;
		}
	} while (chon != 0);
	system("pause");

	return 0;
}