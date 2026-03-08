/*
	? Approaches to try:
	Brute force: 
	* Another array to store the elements in reverse order

	Better approach:
	* Two pointer approach with swap logic
	* Two pointer approach with swap function and recursion
	* One pointer approach with swap logic
	* One pointer approach with swap function and recursion
	
	Built-in Function Approach:
	reverse function from STL 
*/
#include <iostream>

using std::cin; using std::cout;

class Solution {
	public:
	
	// brute force
	int* reverseArray_brute(int arr[], int n)
	{
		int *rev = new int[n];

		for (int i = 0; i < n; i++) {
			rev[n-i-1] = arr[i];
		}

		return rev;
	}

	// two pointer and swap logic
	void reverseArray_1(int arr[], int start, int end)
	{
		int n = end;
		while (start <= end)
		{
			int temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;

			start++; end--;
		}
	}

	// two pointer and swap function with recursion
	void reverseArray_2(int *arr, int start, int end)
	{
		if (start >= end) {
			return;
		}
		
		std::swap(arr[start], arr[end]);

		reverseArray_2(arr, start+1, end-1);
	}

	// One pointer approach with swap logic 
	void reverseArray_3(int *arr, int n)
	{
		int i = 0;
		while (i < n/2)
		{
			arr[i] = arr[i] + arr[n-i-1];
			arr[n-i-1] = arr[i] - arr[n-i-1];
			arr[i] = arr[i] - arr[n-i-1];
			i++;
		}
	}

	// One pointer approach with swap function and recursion
	void reverseArray_4(int *arr, int i, int n) 
	{
		if (i >= n/2) {
			return;
		}

		std::swap(arr[i], arr[n-i-1]);

		reverseArray_4(arr, i+1, n);
	}
};

int main(void)
{
	int n;
	cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	Solution sol;

	arr = sol.reverseArray_brute(arr, n);
	cout << "Reverse: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << '\n';

	cout << "Reverse 1: ";
	sol.reverseArray_1(arr, 0, n-1);
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << '\n';
	
	cout << "Reverse 2: ";
	sol.reverseArray_2(arr, 0, n-1);
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << '\n';

	cout << "Reverse 3: ";
	sol.reverseArray_3(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << '\n';

	cout << "Reverse 4: ";
	sol.reverseArray_4(arr, 0, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << '\n';

	return 0;
}