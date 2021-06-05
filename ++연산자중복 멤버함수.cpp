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
	Power& operator++();
	const Power operator++(int x);
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

Power& Power::operator++()
{
	++(this->kick);
	++(this->punch);
	return *this;
}

const Power Power::operator++(int x)
{
	Power tmp = *this;
	this->kick++;
	this->punch++;
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
