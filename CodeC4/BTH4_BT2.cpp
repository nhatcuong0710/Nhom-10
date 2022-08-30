#include <iostream>
#define MAX 100
using namespace std;
struct Node
{
    int info;
    Node* left, * right;
};
Node* root;
void init()
{
    root = NULL;
}
Node* create(int x)
{
    Node* q = new Node;
    if (q != NULL)
    {
        q->info = x;
        q->left = NULL;
        q->right = NULL;
    }
    return q;
}
void addTree(int x)
{
    if (root == NULL)
        root = create(x);
    else
    {
        Node* q = root;
        Node* parent = NULL;
        while (q != NULL && q->info != x)
        {
            parent = q;
            if (q->info > x)
                q = q->left;
            else
                q = q->right;
        }
        if (q == NULL)
        {
            q = create(x);
            if (parent->info > x)
                parent->left = q;
            else
                parent->right = q;
        }
    }
}
Node* searchTree(Node* q, int x)
{
    while (q != NULL)
    {
        if (q->info == x)
            return q;
        else if (q->info > x)
            q = q->left;
        else
            q = q->right;
    }
    return NULL;
}
void DelTree(int x)
{
    if (root != NULL)
    {
        Node* q = root;
        Node* parent = NULL;
        while (q != NULL && q->info != x)
        {
            parent = q;
            if (q->info > x)
                q = q->left;
            else
                q = q->right;
        }
        if (q != NULL)
        {
            // Xoa 2 con
            if (q->left != NULL && q->right != NULL)
            {
                Node* r = q->right;
                while (r->left != NULL)
                {
                    parent = r;
                    r = r->left;
                }
                q->info = r->info;
                q = r;
            }
            // Xoa 1 con or 1 la
            Node* t = NULL;
            if (q->right == NULL)
                t = q->left;
            else if (q->left == NULL)
                t = q->right;
            if (parent->info > q->info)
                parent->left = t;
            else
                parent->right = t;
            delete q;
        }
    }
}
struct Stack
{
    int top;
    Node* a[MAX];
};
void initStack(Stack& s)
{
    s.top = -1;
}
void PushStack(Stack& s, Node* x)
{
    s.a[++s.top] = x;
}
Node* PopStack(Stack& s)
{
    return s.a[s.top--];
}
bool isEmptyStack(Stack s)
{
    return s.top < 0;
}
void NLRStack(Stack& s)
{
    if (root != NULL)
    {
        Node* q = root;
        while (true)
        {
            while (q != NULL)
            {
                cout << q->info << "\t";
                PushStack(s, q);
                q = q->left;
            }
            if (!isEmptyStack(s))
            {
                Node* r = PopStack(s);
                if (r->right != NULL)
                    q = r->right;
            }
            else
                break;
        }
    }
}
void LNRStack(Stack& s)
{
    if (root != NULL)
    {
        Node* q = root;
        while (true)
        {
            while (q != NULL)
            {
                PushStack(s, q);
                q = q->left;
            }
            if (!isEmptyStack(s))
            {
                Node* r = PopStack(s);
                cout << r->info << "\t";
                if (r->right != NULL)
                    q = r->right;
            }
            else
                break;
        }
    }
}
struct Queue
{
    int front, rear;
    Node* a[MAX];
};
void initQueue(Queue& s)
{
    s.front = s.rear = -1;
}
bool isEmptyQueue(Queue& s)
{
    return ((s.front == -1) || (s.front > s.rear));
}
int PushQueue(Queue& s, Node* n)
{
    if (s.rear - s.front == MAX - 1)
        return 0;
    if (s.front == -1)
        s.front = 0;
    if (s.rear == MAX - 1)
    {
        for (int i = s.front; i <= s.rear; i++)
            s.a[i - s.front] = s.a[i];
        s.rear = MAX - 1 - s.front;
        s.front = 0;
    }
    s.a[++s.rear] = n;
    return 1;
}
void* PopQueue(Queue& s, Node*& x)
{
    if (s.front == -1)
        return 0;
    x = s.a[s.front++];
    if (s.front > s.rear)
    {
        s.front = s.rear = -1;
    }
}
void LRNQueue(Queue& s)
{
    if (root != NULL)
    {
        Node* q = root;
        PushQueue(s, q);
        while (!isEmptyQueue(s))
        {
            PopQueue(s, q);
            if (q->left != NULL)
                PushQueue(s, q->left);
            if (q->right != NULL)
                PushQueue(s, q->right);
            cout << q->info << "\t";
        }
    }
}

void menu()
{
    cout << "1. Them phan tu vao cay" << endl;  // khong dung de quy
    cout << "2. Tim phan tu trong cay" << endl; // khong dung de quy
    cout << "3. Xoa mot nut trong cay" << endl; // dung de quy
    cout << "4. Duyet cay NLR" << endl;         // dung stack
    cout << "5. Duyet cay LNR" << endl;         // dung stack
    cout << "6. Duyet cay LRN" << endl;         // dung queue
}
int main()
{
    Stack s;
    Queue q;
    init();
    initStack(s);
    initQueue(q);
    int n, chon;
    do
    {
        system("cls");
        menu();
        cout << "Moi ban chon: ";
        cin >> chon;
        switch (chon)
        {
        case 1:
            cout << "Nhap gia tri can them vao: ";
            cin >> n;
            addTree(n);
            break;
        case 2:
            cout << "Nhap gia tri can tim kiem: ";
            cin >> n;
            if (searchTree(root, n))
                cout << "Da tim thay!" << endl;
            else
                cout << "Khong tim thay!" << endl;
            break;
        case 3:
            cout << "Nhap gia tri muon xoa: ";
            cin >> n;
            DelTree(n);
            break;
        case 4:
            cout << "Duyet cay theo NLR: " << endl;
            NLRStack(s);
            cout << endl;
            break;
        case 5:
            cout << "Duyet cay theo LNR: " << endl;
            LNRStack(s);
            cout << endl;
            break;
        case 6:
            cout << "Duyet cay theo LRN: " << endl;
            LRNQueue(q);
            cout << endl;
            break;
        }
        system("pause");
    } while (chon >= 1 && chon < 7);
    return 0;
}