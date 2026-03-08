#include <iostream>

using std::cin; using std::cout; using std::vector;

// iterative approach by printing each term
void fibonacci_1(int n)
{
	int f1 = 0, f2 = 1;
	for (int i = 0; i < n+1; i++) {
		cout << f1 << ' ';
		int f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
}

// recursive approach by returning the nth term of series
int fibonacci_2(int n)
{
	if (n <= 1) {
		return n;
	}

	return fibonacci_2(n-1) + fibonacci_2(n-2);
}

// iterative approach by storing each term in vector
vector<int> fibonacci_3(int n)
{
	vector<int> fib = vector<int>(n+1);
	
	for (int i = 0; i < n+1; i++) 
	{
		if  (i <= 1) {
			fib[i] = i;
		}
		else {
			fib[i] = fib[i-1] + fib[i-2];
		}
	}

	return fib;
}

// recursive approach by storing each term in vector
void fibonacci_4(vector<int> &fib, int n)
{
	if (n <= 1) {
		fib[n] = n;
		return;
	}

	fibonacci_4(fib, n-1);
	fibonacci_4(fib, n-2);
	fib[n] = fib[n-1] + fib[n-2];
}

int main(void)
{
	int n;
	cin >> n;

	// solution 1
	cout << "Fibonacci 1: ";
	fibonacci_1(n);
	cout << '\n';

	// solution 2
	cout << "Fibonacci 2: ";
	for (int i = 0; i <= n; i++) 
	{
		cout << fibonacci_2(i) << ' ';
	}
	cout << '\n';

	// solution 3
	cout << "Fibonacci 3: ";
	vector<int> res1 = fibonacci_3(n);
	for (int ls : res1) {
		cout << ls << ' ';
	}
	cout << '\n';

	// solution 4
	cout << "Fibonacci 4: ";	
	vector<int> res2(n+1);
	fibonacci_4(res2, n);
	for (int ls : res2) {
		cout << ls << ' ';
	}
	cout << '\n';	
	return 0;
}