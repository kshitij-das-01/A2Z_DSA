/*
	? Approaches to try:
	Brute force: 
	* Another vector to store the elements in reverse order
	* Another vector to store and reverse and then set the main vector to it

	Better approach:
	* Two pointer approach with swap logic
	* Two pointer approach with swap function and recursion
	* One pointer approach with swap logic
	* One pointer approach with swap function and recursion
	
	Built-in Function Approach:
	reverse function from STL 
*/
#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::vector;

class Solution {
	public:

	// brute force
	vector<int> reverseArray_brute(vector<int> arr)
	{
		int n = arr.size();
		vector<int> rev(n);

		for (int i = 0; i < n; i++)
		{
			rev[i] = arr[n-i-1];
		}
		return rev;
	}

	// brute force with reference
	void reverseArray_brute_2(vector<int> &arr)
	{
		int n = arr.size();
		vector<int> rev(n);

		for (int i = 0; i < n; i++)
		{
			rev[i] = arr[n-i-1];
		}

		arr = rev;
	}

	// Two pointer approach with swap logic
	void reverseArray_1(vector<int> &arr)
	{
		int p1 = 0, p2 = arr.size() - 1;

		while (p1 < p2)
		{
			arr[p1] = arr[p1] + arr[p2];
			arr[p2] = arr[p1] - arr[p2];
			arr[p1] = arr[p1] - arr[p2];
			p1++; p2--;
		}
	}

	// Two pointer approach with swap function and recursion

	void reverseArray_2(vector<int> &arr, int p1, int p2)
	{
		if (p1 >= p2) {
			return;
		}

		std::swap(arr[p1], arr[p2]);
		reverseArray_2(arr, p1+1, p2-1);
	}

	// One pointer approach with swap logic
	void reverseArray_3(vector<int> &arr, int n)
	{
		int p1 = 0;
		while (p1 < n / 2)
		{
			int temp = arr[p1];
			arr[p1] = arr[n-p1-1];
			arr[n-p1-1] = temp;
			p1++;
		}
	}

	// One pointer approach with swap function and recursion
	void reverseArray_4(vector<int> &arr, int i, int n)
	{
		if (i >= n/2) {
			return;
		}

		std::swap(arr[i], arr[n-i-1]);

		reverseArray_4(arr, i+1, n);
	}

	//reverse function from STL 
	void reverseArray_std(vector<int> &arr)
	{
		std::reverse(arr.begin(), arr.end());
	}
};

int main(void)
{
	vector<int> arr;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		arr.push_back(x);
	}

	Solution sol;

	arr = sol.reverseArray_brute(arr);
	cout << "Reverse 1: ";
	for (int l : arr)
		cout << l << ' ';
	cout << '\n';

	sol.reverseArray_brute_2(arr);
	cout << "Reverse 2: ";
	for (int l : arr)
		cout << l << ' ';
	cout << '\n';

	sol.reverseArray_1(arr);
	cout << "Reverse 3: ";
	for (int l : arr)
		cout << l << ' ';
	cout << '\n';

	sol.reverseArray_2(arr, 0, arr.size() - 1);
	cout << "Reverse 4: ";
	for (int l : arr)
		cout << l << ' ';
	cout << '\n';

	sol.reverseArray_3(arr, arr.size());
	cout << "Reverse 5: ";
	for (int l : arr)
		cout << l << ' ';
	cout << '\n';

	cout << "Reverse 6: ";
	sol.reverseArray_4(arr, 0, arr.size());
	for (int l : arr)
		cout << l << ' ';
	cout << '\n'; 

	cout << "Reverse 7: ";
	sol.reverseArray_std(arr);
	for (int l : arr)
		cout << l << ' ';
	cout << '\n';
	return 0;
}