#include <iostream>

using std::cin; using std::cout; using std::string;


// using iteration over the string array
bool isPalindrome_1(string &str)
{
	int len = str.length();
	for (int i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len-i-1]) {
			return false;
		}
	}
	return true;
}

// using recursion with two pointers
bool isPalindrome_2(string &str, int start, int end)
{
	if (start >= end)
		return true;
	
	if (str[start] != str[end-1])
		return false;

	return isPalindrome_2(str, start+1, end-1);
}

// using recursion with one pointer
bool isPalindrome_3(string &str, int i)
{
	if (i >= str.length() / 2)
		return true;
	
	if (str[i] != str[str.length()-i-1])
		return false;
	
	return isPalindrome_3(str, i+1);
}

int main(void)
{
	string str;
	cin >> str;

	if (isPalindrome_3(str, 0))
		cout << "Palindrome ";
	else
		cout << "Not Palindrome ";

	return 0;
}