#include <iostream>
#include <string>

using namespace std;

void swap(string a[], string b[]);
void selectionSort(string list[], int n);
void display(string list[], int n);

int main()
{
	string list[10] = { "Dana","Apple","Election","Fluence","Oyster","Best","Concept","Quiz","Newton","Horse" };
	

	display(list, 10);

	selectionSort(list, 10);

	display(list, 10);

	cin.get();
	cin.get();
	return 0;
}

void swap(string& a, string& b)
{
	string tmp = a;
	a = b;
	b = tmp;
}

void display(string list[], int n)
{
	for (int i = 0; i < n; i++) {
		cout << list[i] << " ";
	}
	cout << endl;
}

void selectionSort(string list[], int n)
{
	int max, i, j;
	for (i = 0; i < n - 1; i++) {
		int index = i;

		for (j = i + 1; j < n; j++) {
			if (list[j] < list[index]) {
				index = j;
			}
		}
		swap(list[i], list[index]);
	}

}
