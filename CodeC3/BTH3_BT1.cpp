#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define MAX 5000
int a[MAX], n, b[MAX];
void Nhap_DS(int a[], int &n) {
	srand(time(NULL));
	cout << "Nhap so luong phan tu: "; cin >> n;
	for (int i = 0; i < n; i++)
		a[i] = rand() % 100000;
}
void Xuat_DS(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void copyArray(int a[], int b[], int n) {
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}
void InsertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int x = a[i]; 
		int j = i - 1;
		while (j >= 0 && a[j] > x) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void swap(int& a, int& b) {
	int tmp = a;
	a = b; 
	b = tmp;
}
void SelectionSort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int min_pos = i;
		for (int j = i + 1; j < n; j++) 
			if (a[j] < a[min_pos])
				min_pos = j;

		swap(a[min_pos], a[i]);
	}
}
void InterchangeSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
	}
}
void BubbleSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				swap(a[j], a[j - 1]);
	}
}
void QuickSort(int a[], int left, int right) {
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i < j) {
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		
		if (i <= j) {
			swap(a[i], a[j]);
			i++; j--;
		}
		if (left < j) QuickSort(a, left, j);
		if (right > i) QuickSort(a, i, right);
	}
}
void shift(int a[], int i, int n){
	int j = 2 * i + 1;
	if (j >= n) 
		return;
	if (j + 1 < n) 
		if (a[j] < a[j + 1]) 
			j++;

	if (a[i] >= a[j])
		return;
	else {
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n);
	}
}
void HeapSort(int a[], int n){
	int i = n / 2;
	while (i >= 0) {
		shift(a, i, n - 1);	i--;
	}
	int right = n - 1; 
	while (right > 0){
		swap(a[0], a[right]); 
		right--;
		if (right > 0)
			shift(a, 0, right);
	}
}
int Search(int a[], int n, int x) {
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i < n)
		return i;
	return -1;
}
int BinarySearch(int a[], int n, int x) {
	int l = 0, r = n - 1, mid;
	while (l <= r){
		mid = (l + r) / 2;
		if (a[mid] == x) 
			return mid;
		if (x > a[mid]) 
			l = mid + 1;
		else r = mid - 1;
	}
	return -1;
}
int main() {
	clock_t start;
	double duration;
	int choose;
	while (1) {
		cout << "-----MENU-----" << endl;
		cout << "1.Nhap DS. " << endl;
		cout << "2.Xuat DS. " << endl;
		cout << "3.Xep thu tu InsertionSort. " << endl;
		cout << "4.Xep thu tu SelectionSort. " << endl;
		cout << "5.Xep thu tu InterchangeSort. " << endl;
		cout << "6.Xep thu tu BubbleSort. " << endl;
		cout << "7.Xep thu tu QuickSort. " << endl;
		cout << "8.Xep thu tu HeapSort. " << endl;
		cout << "9.Tim kiem tuan tu." << endl;
		cout << "10.Tim kiem nhi phan." << endl;
		cout << "--------------" << endl;
		cout << "Nhap lua chon: "; cin >> choose;
		
		if (choose == 1) {
			Nhap_DS(a, n);
		}
		else if (choose == 2) {
			Xuat_DS(a, n);
		}
		else if (choose == 3) {
			copyArray(a, b, n);
			start = clock();
			InsertionSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < MAX) {
				cout << "DS sau khi sap xep voi InsertionSort: ";
				Xuat_DS(b, n);
				cout << endl;
			}
			if (duration > 0) {
				cout << "Thoi gian InsertionSort la " << duration * 1000000 << " Miliseconds " << endl;
			}
		}
		else if (choose == 4) {
			copyArray(a, b, n);
			start = clock();
			SelectionSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < MAX) {
				cout << "DS sau khi sap xep voi SelectionSort: ";
				Xuat_DS(b, n);
				cout << endl;
			}
			if (duration > 0) {
				cout << "Thoi gian SelectionSort la " << duration * 1000000 << " Miliseconds " << endl;
			}
		}
		else if (choose == 5) {
			copyArray(a, b, n);
			start = clock();
			InterchangeSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < MAX) {
				cout << "DS sau khi sap xep voi InterchangeSort: ";
				Xuat_DS(b, n);
				cout << endl;
			}
			if (duration > 0) {
				cout << "Thoi gian InterchangeSort la " << duration * 1000000 << " Miliseconds " << endl;
			}
		}
		else if (choose == 6) {
			copyArray(a, b, n);
			start = clock();
			BubbleSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < MAX) {
				cout << "DS sau khi sap xep voi BubbleSort(a, n) ";
				Xuat_DS(b, n);
				cout << endl;
			}
			if (duration > 0) {
				cout << "Thoi gian BubbleSort la " << duration * 1000000 << " Miliseconds " << endl;
			}
		}
		else if (choose == 7) {
			copyArray(a, b, n);
			start = clock();
			QuickSort(b, 0, n - 1);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < MAX) {
				cout << "DS sau khi sap xep voi QuickSort: ";
				Xuat_DS(b, n);
				cout << endl;
			}
			if (duration > 0) {
				cout << "Thoi gian QuickSort la " << duration * 1000000 << " Miliseconds " << endl;
			}
		}
		else if (choose == 8) {
			copyArray(a, b, n);
			start = clock();
			HeapSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < MAX) {
				cout << "DS sau khi sap xep voi HeapSort: ";
				Xuat_DS(b, n);
				cout << endl;
			}
			if (duration > 0) {
				cout << "Thoi gian HeapSort la " << duration * 1000000 << " Miliseconds " << endl;
			}
		}
		else if (choose == 9) {
			copyArray(a, b, n);
			start = clock();
			cout << "Nhap phan tu muon tim: "; int x; cin >> x;
			int pos = Search(b, n, x);
			if (pos == -1)
				cout << "Khong co phan tu " << x << " trong mang. " << endl;
			else cout << "Phan tu " << x << " nam o vi tri thu " << pos << endl;
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (duration > 0) {
				cout << "Thoi gian Search (tim kiem tuan tu) la " << duration << " seconds " << endl;
			}
		}
		else if (choose == 10) {
			cout << "Da sap xep mang." << endl;
			InterchangeSort(a, n);
			copyArray(a, b, n);
			start = clock();
			cout << "Nhap phan tu muon tim: "; int x; cin >> x;
			int pos = BinarySearch(b, n, x);
			if (pos == -1)
				cout << "Khong co phan tu " << x << " trong mang. " << endl;
			else cout << "Phan tu " << x << " nam o vi tri thu " << pos << endl;
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (duration > 0) {
				cout << "Thoi gian BinarySearch (tim kiem nhi phan) la " << duration  << " seconds " << endl;
			}
		}
		else break;
	}
	return 0;
}