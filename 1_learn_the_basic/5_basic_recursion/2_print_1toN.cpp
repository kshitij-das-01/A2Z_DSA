#include <iostream>

using std::cin; using std::cout;

class Solution {
	public:

	void printNumber_1(int i, int n)
	{
		if (i > n) {
			return;
		}
		cout << i << ' ';
		printNumber_1(i+1,n);
	}

	// with backtracking
	void printNumber_2(int i, int n)
	{
		if (i < 1) {
			return;
		}
		printNumber_2(i-1, n);
		cout << i << ' ';
	}

	void printNumber_3(int i, int n)
	{
		if (i > n)
			return;
		
		printNumber_3(i+1, n);
		cout << i << ' ';
	}
	
	void printNumber_4(int n)
	{
		if (n < 1) {
			return;
		}
		printNumber_4(n-1);
		cout << n << ' ';
	}
};

int main(void)
{
	int n;
	cin >> n;

	Solution sol;
	sol.printNumber_1(1,n);
	cout << '\n';
	sol.printNumber_2(n, n);
	cout << '\n';
	sol.printNumber_3(1, n);
	cout << '\n';
	sol.printNumber_4(n);

	return 0;
}