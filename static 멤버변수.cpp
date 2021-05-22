#include <iostream>

using namespace std;

class Something {
private:
	int m_id;
public:
	static int s_idGenerator;
	Something() { m_id = s_idGenerator++; }

	int getID() { return m_id; }
};

int Something::s_idGenerator = 1;

int main()
{
	Something first;
	Something second;
	Something third;


	cout << first.getID() << endl;
	cout << second.getID() << endl;
	cout << third.getID() << endl;
	cout << Something::s_idGenerator << endl;

	return 0;
}
