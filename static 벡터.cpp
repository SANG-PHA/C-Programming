#include <iostream>
#include <vector>

using namespace std;

class Table {
private:
	int m_id;
public:
	static vector<int> m_entries;
	static int id_generator;

	Table() {
		m_id = id_generator++;
	}

	int get_id() { return m_id; }

	void push(int n) {
		m_entries.push_back(n);
	}

	static void get_entries() {
		for (int n : m_entries)
			cout << n << " ";
	}

};

int Table::id_generator = 1;
vector<int> Table::m_entries;

int main()
{
	Table obj1;
	Table obj2;

	cout << obj1.get_id() << " " << obj2.get_id() << endl;
	obj1.push(2);
	obj2.push(3);
	Table::get_entries();

	return 0;
}
