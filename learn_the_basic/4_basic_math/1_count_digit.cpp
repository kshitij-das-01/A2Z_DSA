#include <iostream>

using std::cin; using std::cout;

// optimal
int digitCounter_1(int n)
{
	int count = (int)(log10(n) + 1);
	return count;
}

// brute force
int digitCounter_2(int n)
{
	int digits = 0;

	while (n != 0)
	{
		digits++;
		n /= 10;
	}
	return digits;
}

int main(void)
{
	
	int N;
	cin >> N;

	int digits = digitCounter_1(N);
	cout << "The number " << N << " has " << digits << '\n';
	return 0;
}