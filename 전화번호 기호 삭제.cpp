#include <iostream>
#include <string>

using namespace std;

void convert(string a);

int main()
{
	string a;

	while(1){
		cout << "Enter a phone number : ";
		cin >> a;

		if (a == "quit")
			break;

		convert(a);
	}

	cin.get();
	cin.get();
	return 0;
}

void convert(string a)
{
	for (int i = 0; i < strlen(a.c_str()); i++) {
		if (a[i] == '(' || a[i] == ')')
			continue;
		cout << a[i];
	}
}
