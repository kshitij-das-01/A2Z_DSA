#include <iostream>
#include <cmath>
#include <string>

using std::cin; using std::cout;

// using log to get the number of digits and 
// then using 10's power to define the place value

// using pow function
int reverse_num_1(int n)
{
	int digit = log10(n);
	int rev_num = 0;

	while (n != 0)
	{
		int r = (int) (n % 10) * pow(10, digit);
		rev_num += r;
		n /= 10;
		digit--;
	}

	return rev_num;
}

// without power function
int reverse_num_2(int n)
{
	int revNum = 0;

	while (n > 0)
	{
		int lastDigit = n % 10;
		revNum = revNum * 10 + lastDigit;
		
		n /= 10;
	}

	return revNum;
}

// Leet code specific approach below
// storing number in another integer till it is smaller than the given, then comparing them if equal them it is a palindrome
bool isPalindrome_1(int n)
{
	if (n < 0 || (n % 10 == 0 && n != 0))
		return false;

	int rev = 0;
	
	while (n > rev)
	{
		rev = (rev * 10) + (n % 10);
		n /= 10;
	}

	return (n == rev || n == rev / 10);
}
// two pointer with vector store int
bool isPalindrome_1(int x) {
	if (x < 0 || (x % 10 == 0 && x != 0)) {
		return false;
	}

	std::vector<int> num;
	while (x > 0) {
		num.push_back(x % 10);
		x /= 10;
	}

	int i = 0, j = num.size() - 1;
	while (i < j)
	{
		if (num[i] != num[j]) {
			return false;
		}
		i++;
		j--;
	}

	return true;
}

int main(void)
{
	int N;
	cin >> N;

	// int rev_num = reverse_num_1(N);

	// cout << "The reverse of " << N << " is " << rev_num;
	
	// if (N == rev_num)
	// 	cout << " it is palindrome number\n";
	// else 
	// 	cout << " it is not palindrome number\n";

	if (isPalindrome_1(N))
		cout << "Palindrome ";
	else 
		cout << "Not Palindrome ";
	
	return 0;
}