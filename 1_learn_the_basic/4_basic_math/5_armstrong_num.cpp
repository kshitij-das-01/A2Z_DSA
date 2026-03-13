#include <iostream>
#include <cmath>


using std::cin; using std::cout;

void isArmstrong_1(int n)
{
	int armstr = 0, dup = n;
	int digit = (int)(log10(n) + 1);

	while (n != 0)
	{
		int ld = n % 10;
		armstr += pow(ld, digit);
		n /= 10;
	}

	if (armstr == dup)
		cout << dup << " Number is a Armstrong Number ";
	else 
		cout << dup << " Number is not a Armstrong Number ";
}

bool isArmstrong_2(int num)
{
	int k = std::to_string(num).length();
	int sum = 0, n = num;

	while (n > 0)
	{
		int ld = n % 10;
		sum += pow(ld, k);
		n /= 10;
	}

	return sum == num;
}

int main(void)
{
	int N;
	cin >> N;
	
	// isArmstrong_1(N);
	
	if (isArmstrong_2(N))
		cout << N << " Number is Armstrong ";
	else
		cout << N << " Number is not Armstrong ";
	
	return 0;
}