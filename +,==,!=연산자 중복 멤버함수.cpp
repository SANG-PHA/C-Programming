#include <iostream>
 
using namespace std;

class Color {
	int r, g, b;
public:
	Color() { r = g = b = 0; }
	Color(int r, int g, int b) {
		this->r = r;
		this->g = g;
		this->b = b;
	}

	void show() {
		cout << r << " " << g << " " << b << endl;
	}

	Color operator+(Color& a) {
		this->r += a.r;
		this->g += a.g;
		this->b += a.b;
		return *this;
	}

	bool operator==(Color& a) {
		if (this->r == a.r && this->g == a.g && this->b == a.b)
			return true;
		else return false;
	}

	bool operator!=(Color &a) {
		if (this->r == a.r && this->g == a.g && this->b == a.b)
			return false;
		else return true;
	}
};

int main() {
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show();

	Color fuchsia(255, 0, 255);
	if (c == fuchsia)
		cout << "보라색 맞음";
	else cout << "보라색 아님";

	getchar();
	return 0;
}
