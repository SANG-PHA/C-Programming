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

	friend Power operator+(const Power& a, const Power& b);
	void show();
};

Power operator+(const Power& a, const Power& b) {
	Power tmp;
	tmp.kick = b.kick + a.kick;
	tmp.punch = b.punch + a.punch;
	return tmp;
}

void Power::show() {
	cout << "kick = " << kick << ", punch = " << punch << endl;
}


int main(void)
{
	Power a(3, 5), b(4, 6), c;

	c = a + b;

	a.show();
	b.show();
	c.show();

	return 0;
}
