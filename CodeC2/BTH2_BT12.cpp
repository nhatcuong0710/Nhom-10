#include <iostream>
#include <stdio.h>
#include <conio.h>
#define MAX 10000
using namespace std;

//Khai bao cau trc danh sach
struct Node
{
	int value;
	Node* next, *previous;
};
struct DoubleLinkedList
{
	Node* head;
	Node* tail;
};
Node* createNode(int x)
{
	Node* p = new Node;
	p->value = x;
	p->next = NULL;
	p->previous = NULL;

	return p;
}
void addFirst(DoubleLinkedList& ls, int x)
{
	Node* p = createNode(x);
	if (ls.head == NULL)// danh sach rong
	{
		ls.head = ls.tail = p;
	}
	else
	{
		p->next = ls.head;
		ls.head->previous = p;
		ls.head = p;
	}
 }

// Khoi tao danh sach 
void init(DoubleLinkedList &ls)
{
	ls.head = NULL;
	ls.tail = NULL;
}
void outputLeftToRight(const DoubleLinkedList ls)
{
	Node* p = ls.head;
	while (p != NULL)
	{
		cout << p->value << "\t";
		p = p->next;
	}
	cout << endl;
}
void outputRightToLeft(const DoubleLinkedList ls)
{
	Node* p = ls.tail;
	while (p != NULL)
	{
		cout << p->value << "\t";
		p = p->previous;
	}
	cout << endl;
}
//12.1: khai bao cau truc ds
struct node
{
	int info; //khai bao thanh phan dl co kieu int
	node* previous, * next;	 //khai bao con tro; next chi phan tu co kieu node chua dchi ptu sau, previous chua dchi ptu truoc
};
node* first, * last;

//12.2: Khoi tao ds rong
void init()
{
	first = NULL;
	last = NULL;
}

//12.3: xuat cac phan tu trong ds
void process_list()
{
	node* p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << endl;
		p = p->next;
	}
}

//12.4: them phan tu vao dau ds
void insert_first(int x)
{
	node* p;
	p = new node;
	p->info = x;
	p->next = first;
	p->previous = NULL;
	if (first != NULL)
		first->previous = p;
	else //ds nay rong truoc khi them phan tu p
		last = p; // co nghia la sau khi them p, ds co 1 phan tu la p
	first = p;
}

// 12.5 them phan tu vao cuoi danh sach 
void Insert_last(int x)
{
	node* p;
	p = new node;
	p->info = x;
	p->next = NULL;
	p->previous = last;
	if (last != NULL)
		last->next = p;
	else
		first = p;
	last = p;

}

//12.6 xoa phan tu dau danh sach 
int Delete_first(int n)
{
	if (first != NULL)
	{
		node* p = first;
		first = first->next;
		delete p;
		if (first != NULL)
			first->previous = NULL;
		else
			last = NULL;
		return 1;
	}
	return 0;
}


// 12.7 xoa phan tu cuoi danh sach
int Delete_last(int n)
{
	if (last != NULL)
	{
		node* p = last;
		last = last->previous;
		if (last != NULL)
			last->next = NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}


	int main()
	{
		int choice = 0;
		int x, t, n;
		node* next, * last;
		init();
		do {
			system("cls");
			cout << "==== BAI 12 - CHUONG 2 ====\n"
				<< "1. Xuat danh sach\n"
				<< "2. Them phan tu vao dau danh sach\n"
				<< "3. Them phan tu vao cuoi ds\n"
				<< "4. Xoa phan tu dau ds\n"
				<< "5. Xoa phan tu cuoi ds\n"
				<< "6. Tim ptu, neu tim thay thi xoa ptu nay\n"
				<< "7. Tim phan tu co gia tri bang voi X hoac gan bang nhat va lon hon phan tu nhap vao. Them1 phan tu dung truoc ptu tim thay\n"
				<< "0. Thoat\n";
			cout << "Ban chon: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "Danh sach gom: \n";
				process_list();

				break;
			case 2:
				cout << "Nhap gia tri mun them: ";
				cin >> x;
				insert_first(x);
				cout << "Them thanh cong\n";
				break;
			case 3:
				cout << "Nhap gia tri mun them: ";
				cin >> x;
				Insert_last(x);
				cout << "Them thanh cong\n";
				break;
			case 4:
				cout << "Nhap gia tri mun xoa: ";
				cin >> n;
				Delete_first(n);
				cout << "Xoa thanh cong\n";
				break;
			case 5:
				cout << "Nhap gia tri mun xoa: ";
				cin >> n;
				Delete_last(n);
				cout << "Xoa thanh cong\n";
				break;


			default:
				cout << "Gia tri ban chon khong dung!\n";
				break;
			}
			_getch();
		} while (choice <= 7);
		return 0;
	}
	
