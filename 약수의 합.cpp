#include <iostream>

using namespace std;

int sum_divisor(int num);

int main()
{
	int num, result;

	cout << "정수를 입력하시오 : ";
	cin >> num;

	result = sum_divisor(num);

	cout << "모든 약수의 합 : " << result;

	cin.get();
	cin.get();
	return 0;
}

int sum_divisor(int num)
{
	int sum = 0;
	
	for (int i = 1; i <= num; i++)
		if (num % i == 0)
			sum += i;

	return sum;
}
