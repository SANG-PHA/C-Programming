#include <iostream>

using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}

	Power operator+(const Power& a);
	friend Power& operator++(Power& a);
	friend const Power operator++(Power& a, int x);
	void show();
};

Power Power::operator+(const Power& a) {
	Power tmp;
	tmp.kick = this->kick + a.kick;
	tmp.punch = this->punch + a.punch;
	return tmp;
}
 
void Power::show() {
	cout << "kick = " << kick << ", punch = " << punch << endl;
}

Power& operator++(Power& a)
{
	++(a.kick);
	++(a.punch);
	return a;
}

const Power operator++(Power& a, int x)
{
	Power tmp = a;
	a.kick++;
	a.punch++;
	return tmp;
}


int main(void)
{
	Power a(1, 1), b(2, 2), c, d, e;

	c = ++a;
	d = b++;
	e = c + d;

	a.show();
	b.show();
	c.show();
	d.show();
	e.show();

	return 0;
}
