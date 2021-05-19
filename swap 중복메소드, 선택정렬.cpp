#include <iostream>

using namespace std;

void swap(int* a, int* b);
void swap(int& a, int& b);
void selectionSort(int a[], int n);
void display(int a[], int n);

int main()
{
	/*int a = 10, b = 20;

	cout << "a : " << a << " b : " << b << endl;

	swap(&a, &b);

	cout << "a : " << a << " b : " << b << endl;

	swap(a, b);

	cout << "a : " << a << " b : " << b << endl;*/

	int a[] = { 5,3,10,8,1,2,9,7,4,6 };
	int n = 10;

	cout << "초기 배열 : ";
	display(a, n);

	selectionSort(a, n);

	cout << "정렬된 배열 : ";
	display(a, n);

	cin.get();
	cin.get();
	return 0;
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void selectionSort(int a[], int n)
{
	int max, i, j;
	for (i = 0; i < n - 1; i++) {
		int index = i;

		for (j = i + 1; j < n; j++) {
			if (a[j] < a[index]) {
				index = j;
			}
		}
		swap(a[i], a[index]);
	}

}

void display(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
