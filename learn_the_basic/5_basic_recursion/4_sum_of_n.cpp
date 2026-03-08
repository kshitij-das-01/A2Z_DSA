#include <iostream>

using std::cin; using std::cout;

class Solution {
	public:

	// using iteration
	int sumOfNumber_1(int n)
	{
		int sum = 0;
		for (int i = 0; i <= n; i++) 
		{
			sum += i;
		}
		return sum;
	}
	
	// using formula
	int sumOfNumber_2(int n)
	{
		return (n * (n+1)) / 2;
	}
	
	// using parameter recursion
	void sumOfNumber_3(int n, int sum)
	{
		if (n < 1) {
			cout << sum;
			return;
		}

		sumOfNumber_3(n-1, sum+n);
	}

	// using functional recursion
	int sumOfNumber_4(int n)
	{
		if (n == 1)
			return 1;
		
		return n + sumOfNumber_4(n-1);
	}

};

int main(void)
{
	int n;
	cin >> n;
	int sum;
	Solution sol;
	cout << "Sum is: \n";
	sum = sol.sumOfNumber_1(n);
	cout << sum << '\n';

	sum = sol.sumOfNumber_2(n);
	cout << sum << '\n';

	sol.sumOfNumber_3(n, 0);
	cout << '\n';

	sum = sol.sumOfNumber_4(n);
	cout << sum << '\n';

	return 0;
}