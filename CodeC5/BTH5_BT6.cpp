#include<iostream>
#include<stdio.h>
using namespace std;
#define MAXDT 20
#define MAX 100

//do thi hinh 5.1
int a[MAX][MAX] = {
    {0,1,1,1,0,0,0},
    {1,0,1,0,1,1,0},
    {1,1,0,1,0,1,0},
    {1,0,1,0,0,1,1},
    {0,1,0,0,0,1,0},
    {0,1,1,1,1,0,1},
    {0,0,0,1,0,1,0}
};
int n = 7;

int C[MAXDT];
//Stack
int dfs[MAXDT];
int ndfs = 0;

int aS[MAX];
int sp;
//Queue
int bfs[MAXDT];
int nbfs = 0;

int aQ[MAX];
int front, rear;

void init_bfs()
{
    n = 0;
}
//6.1 Nhap ma tran ke
void input()
{
    cout << "nhap so dinh do thi n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "nhap vao dong thu " << i + 1 << ": ";
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
}
//6.2 Xuat ma tran ke
void output()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "  ";
        cout << endl;
    }
}

void khoitaochuaxet()
{
    for (int i = 0; i < n; i++) // n là s? d?nh c?a d? th?
        C[i] = 1;
}
//6.3 Duyet do thi BFS voi Queue DS dac
void initQ()
{
    front = rear = -1;
}


int PushQ(int x)
{
    if (rear - front == MAX - 1)
        return 0;
    else
    {
        if (front == -1)
            front = 0;
        if (rear == MAX - 1)
        {
            for (int i = front; i <= rear; i++)
                aQ[i - front] = aQ[i];
            rear = MAX - 1 - front;
            front = 0;
        }
        aQ[++rear] = x;
        return 1;
    }
}

int PopQ(int& x)
{

    if (front == -1)
        return 0;
    else
    {
        x = aQ[front++];
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
        return 1;
    }
}

void BFS(int v)
{
    int w, p;
    PushQ(v);
    C[v] = 0;
    while (front != -1)
    {
        PopQ(p);
        bfs[nbfs] = p;
        nbfs++;
        for (w = 0; w < n; w++)
            if (C[w] && a[p][w] == 1)
            {
                PushQ(w);
                C[w] = 0;
            }
    }
}

void output_bfs()
{
    for (int i = 0; i < nbfs; i++)
        cout << char(bfs[i] + 'A') << "  ";
}
//6.4 Duyet do thi DFS voi Stack DS dac
void initS()
{
    sp = -1;
}

int isEmpty() {
    if (sp == -1)
        return 1;
    return 0;
}

int isFull()
{
    if (sp == MAX - 1)
        return 1;
    return 0;
}

int PushS(int x)
{
    if (sp < MAX - 1)
    {
        aS[++sp] = x;
        return 1;
    }
    return 0;
}

int PopS(int& x)
{
    if (sp != -1)
    {
        x = aS[sp--];
        return 1;
    }
    return 0;
}

void DFS(int s)
{
    PushS(s);
    dfs[ndfs] = s;
    ndfs++;
    C[s] = 0;
    int v = -1, u = s;
    while (!isEmpty())
    {
        if (v == n)
            PopS(u);
        for (v = 0; v < n; v++)
            if (a[u][v] != 0 && C[v] == 1)
            {
                PushS(v);
                dfs[ndfs] = v;
                ndfs++;
                C[v] = 0;
                u = v;
                break;
            }
    }
}

void output_dfs()
{
    for (int i = 0; i < ndfs; i++)
        cout << char(dfs[i] + 'A') << "  ";
}

void Search_by_DFS(int x, int s)
{
    initS();
    PushS(s);
    dfs[ndfs] = s;
    ndfs++;
    C[s] = 0;
    int v = -1, u = s;
    while (!isEmpty())
    {
        if (v == n)
            PopS(u);
        if (x == u)
        {
            cout << "Dinh " << x << ": Ton tai\n";
        }
        for (v = 0; v < n; v++)
            if (a[u][v] != 0 && C[v] == 1)
            {
                PushS(v);
                dfs[ndfs] = v;
                ndfs++;
                C[v] = 0;
                u = v;
                break;
            }
    }
    cout << "Dinh " << x << ": Khong ton tai";
    cout << endl;
}
void menu()
{
    char choose;
    system("cls");
    cout << "===========BAI TAP 6 CHUONG 5==========" << endl;
    cout << "1.Nhap ma tran ke cua do thi 5.1" << endl;
    cout << "2.Xuat ma tran ke cua do thi 5.1" << endl;
    cout << "3.Duyet do thi theo chieu rong (theo Queue bang DS dac)" << endl;
    cout << "4.Duyet do thi theo chieu sau (theo Stack bang DS dac)" << endl;
    cout << "5.Kiem tra X co ton tai hay khong" << endl;
    cout << "6.Ket thuc chuong trinh" << endl;
    khoitaochuaxet();
    cout << "Moi ban chon: ";
    cin >> choose;
    switch (choose)
    {
    case '1':
    {
        input();
        break;
    }
    case '2':
    {
        cout << "\nDo thi duoc bieu dien duoi dang ma tran ke\n";
        output();
        break;
    }
    case'3':
    {
        cout << "Ket qua duoc duyet theo BFS (voi dinh xuat phat tu A): " << endl;
        initQ();
        BFS(0);
        output_bfs();
        break;
    }
    case '4':
    {
        cout << "Ket qua duoc duyet theo DFS (voi dinh xuat phat tu A): " << endl;
        initS();
        DFS(0);
        output_dfs();
        break;
    }
    case '5':
    {
        int x;
        cout << "Nhap dinh can tim: ";
        cin >> x;
        Search_by_DFS(x, 0);
        break;
    }
    case '6':
    {
        cout << "Chuong Trinh Ket Thuc\n";
        return;
    }
    default:
        cout << "Nhap sai, nhap lai\n";
        break;
    }
    system("pause");
    return menu();
}
int main()
{
    menu();
    return 0;
}