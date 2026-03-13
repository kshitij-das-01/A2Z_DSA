#include <iostream>

using std::cin; using std::cout;

class Solution {
public:

	// using iteration
	int factorial_1(int n)
	{
		int fact = 1;
		for (int i = 1; i <= n; i++) {
			fact *= i;
		}

		return fact;
	}

	// using recursion
	int factorial_2(int n)
	{
		if (n == 0) {
			return 1;
		}

		return n * factorial_2(n-1);
	}
};

int main(void)
{
	int n;
	cin >> n;

	Solution sol;
	cout << sol.factorial_1(n) << '\n';
	cout << sol.factorial_2(n) << '\n';

	return 0;
}