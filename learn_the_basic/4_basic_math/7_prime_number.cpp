#include <iostream>

using std::cin; using std::cout;

// using the fact that odd numbers need to be only checked to identify primes and eliminating all even numbers
bool isPrime_1(int n)
{
	if (n == 2) return true;
	if (n < 2 || n % 2 == 0) return false;

	for (int i = 3; i * i < n; i += 2)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

// iterating through all numbers from 1 to n
bool isPrime_2(int n)
{
	int count = 0;

	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0) {
			count++;
		}
	}

	if (count == 2) {
		return true;
	}
	else {
		return false;
	}
}

// using iteration till square root of n
bool isPrime_3(int n)
{
	int count = 0;

	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0) {
			count++;

			if (n / i != i) {
				count++;
			}
		}
	}

	if (count == 2) {
		return true;
	}
	else {
		return false;
	}
}

int main(void)
{
	int N;
	cin >> N;

	if (isPrime_1(N))
		cout << "True ";
	else
		cout << "False ";
	
	return 0;
}