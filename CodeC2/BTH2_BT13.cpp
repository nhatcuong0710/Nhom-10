#include <iostream>
using namespace std;
struct Node {
    int info;
    Node* pre, * next;
};
Node* first, * last;
void Init() {
    first = last = NULL;
}
void OutputList_Nguoc() {
    for (Node* i = last; i != NULL; i = i->pre) {
        cout << i->info << "\t";
    }
}
void OutputList_Thuan() {
    for (Node* i = first; i != NULL; i = i->next) {
        cout << i->info << "\t";
    }
}
void InsertFirstList(int X) {
    Node* p = new Node;
    p->info = X;
    p->next = p->pre = NULL;

    if (first == NULL) {
        last = first = p;
    }
    else {
        p->next = first;
        first->pre = p;
        first = p;
    }
}
void InsertLastList(int X) {
    Node* p = new Node;
    p->info = X;
    p->next = p->pre = NULL;

    if (first == NULL) {
        last = first = p;
    }
    else {
        last->next = p;
        p->pre = last;
        last = p;
    }
}
void CreataList() {
    int X;
    do {
        cout << "Nhap danh sach( 0 la dung): ";
        cin >> X;
        if (X != 0) {
            InsertLastList(X);
        }
    } while (X != 0);
}
void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}
void InterchangeSort_ASC() {
    for (Node* i = first; i->next != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (i->info > j->info)
                swap(i->info, j->info);
        }
    }
}
bool DelFirstList() {
    if (first == NULL)
        return false;

    Node* p = first;
    if (last == first) {    //list có 1 node
        first = last = NULL;
        delete p;
        return true;
    }
    first = first->next;
    first->pre = NULL;
    delete p;
    return true;
}
bool DelLastList() {
    if (first == NULL) //list rong
        return false;

    Node* p = last;
    if (last == first) {
        first = last = NULL;
        delete p;
        return true;
    }
    last = last->pre;
    last->next = NULL;
    delete p;
    return true;
}
int main() {
    int chon, X;
    system("cls");
    cout << "===========BAI TAP 12 _ CHUONG 5 ==========" << endl;
    cout << "12.1 Khai bao cau truc danh sach" << endl;
    cout << "12.2 Khoi tao danh sach rong" << endl;
    cout << "12.3 Xuat cac phan tu trong danh sach" << endl;
    cout << "12.4 Them phan tu vao dau danh sach" << endl;
    cout << "12.5 Them phan tu vao cuoi danh sach" << endl;
    cout << "12.6 Xoa phan tu dau danh sach" << endl;
    cout << "12.7 Xoa phan tu cuoi danh sach" << endl;

    cout << "0.Thoat" << endl;
    do {
        cout << "\nMoi ban chon: ";
        cin >> chon;
        switch (chon)
        {
        case 1:
            cout << "Khai bao cau truc danh sach thanh cong!" << endl;
            break;
        case 2:
            CreataList();
            break;
        case 3:
            OutputList_Thuan();
            break;
        case 4:
            cout << "Nhap phan tu muon them vao dau danh sach: ";
            cin >> X;
            InsertFirstList(X);
            OutputList_Thuan();
            break;
        case 5:
            cout << "Nhap phan tu muon them vao cuoi danh sach: ";
            cin >> X;
            InsertLastList(X);
            OutputList_Thuan();
            break;
        case 6:
            DelFirstList();
            OutputList_Thuan();
            break;
        case 7:
            DelLastList();
            OutputList_Thuan();
            break;
        default: chon = 0;
        }
    } while (chon != 0);
    system("pause");

    return 0;
}

