#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
	int m[3][3];
public:
	void accept() {
		cout << "Enter Matrix Element (3 X 3)" << endl;
		cin >> m[0][0] >> m[0][1] >> m[0][2] >> m[1][0] >> m[1][1] >> m[1][2] 
			>> m[2][0] >> m[2][1] >> m[2][2];
	}

	void display() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				cout << this->m[i][j] << "\t";
			cout << endl;
		}
	}

	//연산자 함수를 외부 함수로 구현
	//프랜드 함수 사용
	friend Matrix operator+(const Matrix& m, const Matrix& n);
};

//프랜드 함수 구현
Matrix operator+(const Matrix& m, const Matrix& n) {
	Matrix tmp;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			tmp.m[i][j] = m.m[i][j] + n.m[i][j];

	return tmp;
};

int main(void)
{
	Matrix m, n, r;

	m.accept();
	n.accept();
	cout << "\n First Matxrix : \n\n";
	m.display();

	cout << "\n Second Matxrix : \n\n";
	n.display();

	r = m + n;
	cout << "\n Addition of Matrix : \n\n";
	r.display();

	return 0;
}
