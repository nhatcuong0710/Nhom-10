#include <iostream>
#include <string>
using namespace std;
struct daThuc
{
    int soMu;
    float* heSo;
    
};
void NhapDT(daThuc *d) {
    do {
        cout << "\nNhap vao so bac cua da thuc ";
        cin >> d->soMu;
        if (d->soMu < 1) {
            cout << "\nSo bac cua da thuc phai >=1. Xin kiem tra lai";
        }
    } while (d->soMu < 1);
    d->heSo = new float[d->soMu + 1];
    for (int i = d->soMu; i >0 ; i--) {
        cout << "\nHe so bac " << i << " la: ";
        cin >> d->heSo[i];
    }
    cout << "\nHe so tu do ";
    cin >> d->heSo[0];
}
void XuatDaThuc(daThuc* d) {
    for (int i = d->soMu; i > 0; i--) {
        cout << d->heSo[i] << "x^" << i << " + ";
    }
    cout << d->heSo[0] << endl;
}
daThuc* Tong2DaThuc(daThuc* x, daThuc* y)
{
    int Max = x->soMu > y->soMu ? x->soMu : y->soMu;
    int Min = x->soMu < y->soMu ? x->soMu : y->soMu;
    daThuc* kq = new daThuc;
    kq->soMu = Max;
    kq->heSo = new float[kq->soMu + 1];
    for (int i = 0; i <= Min; ++i)
    {
        kq->heSo[i] = x->heSo[i] + y->heSo[i];
    }
    if (Max == x->soMu)
    {
        for (int i = Min + 1; i <= Max; ++i)
        {
            kq->heSo[i] = x->heSo[i];
        }
    }
    else
    {
        for (int i = Min + 1; i <= Max; ++i)
        {
            kq->heSo[i] = y->heSo[i];
        }
    }
    return kq;
}
daThuc* Hieu2DaThuc(daThuc* x, daThuc* y)
{
    int Max = x->soMu > y->soMu ? x->soMu : y->soMu;
    int Min = x->soMu < y->soMu ? x->soMu : y->soMu;
    daThuc* kq = new daThuc;
    kq->soMu = Max;
    kq->heSo = new float[kq->soMu + 1];
    for (int i = 0; i <= Min; ++i)
    {
        kq->heSo[i] = x->heSo[i] - y->heSo[i];
    }
    if (Max == x->soMu)
    {
        for (int i = Min + 1; i <= Max; ++i)
        {
            kq->heSo[i] = x->heSo[i];
        }
    }
    else
    {
        for (int i = Min + 1; i <= Max; ++i)
        {
            kq->heSo[i] = 0 - y->heSo[i];
        }
    }
    return kq;
}
daThuc* Tich2DaThuc(daThuc *a, daThuc *b)
{
    daThuc *ketqua=new daThuc;

    // xét bậc đa thức kết quả
    ketqua->soMu = a->soMu + b->soMu;
    ketqua->heSo = new float[ketqua->soMu + 1];
    // Xét hệ số đa thức kết quả
    for (int i = 0; i <= a->soMu; i++)
    {
        for (int j = 0; j <= b->soMu; j++)
        {
            ketqua->heSo[i + j] = a->heSo[i] * b->heSo[j];
        }
    }
    return ketqua;
}
daThuc* Thuong2DaThuc(daThuc* x, daThuc* y) {
    daThuc* ketqua = new daThuc;
    daThuc* chia = x;
    daThuc* biChia = y;
    daThuc* temp = new daThuc;

    int a=ketqua->soMu = x->soMu - y->soMu;
    ketqua->heSo = new float[ketqua->soMu + 1];
    int b = 0;
    while (a>0)
    {
        temp->soMu= x->soMu - y->soMu;
        temp->heSo = new float[temp->soMu + 1];
        temp->heSo[temp->soMu]= chia->heSo[b] / biChia->heSo[b];
        biChia = Hieu2DaThuc(biChia, Tich2DaThuc(temp, chia));
    }

}
int main()
{   
    daThuc* d = new daThuc;
    daThuc *e = new daThuc;
    int chonNhap=1,chonTinh=1;
    while (chonNhap!= 0) {
        NhapDT(d);
        NhapDT(e);
        while (chonTinh!=0)
        {
            cout << "\n1.Tinh tong 2 da thuc ";
            cout << "\n2.Tinh hieu 2 da thuc ";
            cout << "\n3.Tinh tich 2 da thuc ";
            cout << "\n4.Tinh thuong 2 da thuc ";
            cout << "\n5.Nhap 2 da thuc khac ";
            cout << "\n0.Thoat ";
            cin >> chonTinh;
            switch (chonTinh)
            {
            case 1:
                XuatDaThuc(Tong2DaThuc(d, e));
                break;
            case 2:
                XuatDaThuc(Hieu2DaThuc(d, e));
                break;
            case 3:
                XuatDaThuc(Tich2DaThuc(d, e));
                break;
            case 5:
                chonTinh = 0;
                break;
            case 0:
                chonNhap = 0;
                chonTinh = 0;
                break;
            default:
                break;
            }
        }
        
    }
    delete d;
    delete e;
    system("pause");
    return 0;
}