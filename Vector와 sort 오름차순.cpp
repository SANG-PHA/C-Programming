#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void getData(vector<string>& v);
void sortData(vector<string>& v);
void display(vector<string> v);

bool compare(string p, string q);

int main(void)
{
	vector<string> vec;

	getData(vec);
	sortData(vec);
	display(vec);
	
	cin.get();
	return 0;
}

void getData(vector<string>& v)
{
	v.push_back("MILK");
	v.push_back("BREAD");
	v.push_back("BUTTER");
}

void sortData(vector<string>& v)
{
	sort(v.begin(), v.end(), compare);
}

void display(vector<string> v)
{
	for (string e : v)
		cout << " " << e;
}

bool compare(string p, string q)
{
	return p < q;
}
