#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Brute force solution
	// TC: O(N) SC: O(N)
	void moveZeroToEnd_1(vector<int> &arr)
	{
		// Create temp array
		vector<int> temp(arr.size(), 0);

		// Pointer for temp array
		int idx = 0;

		// Traverse the array
		for (int i = 0; i < arr.size(); i++)
		{
			// If non-zero, add to temp array
			if (arr[i] != 0) {
				temp[idx] = arr[i];
				idx++;
			}
		}

		// Copy back temp to original
		for (int i = 0; i < temp.size(); i++)
			arr[i] = temp[i];
	}

	// Optimal solution
	// TC: O(N) SC: O(1)
	void moveZeroToEnd_2(vector<int> &num)
	{
		// Pointer for zero
		int idx = -1;

		// Find the first zero
		for (int i = 0; i < num.size(); i++)
		{
			if (num[i] == 0) {
				idx = i;
				break;
			}
		}

		// If no zero found, return
		if (idx == -1) return;

		// Start from the next index of first zero
		for (int i = idx + 1; i < num.size(); i++)
		{
			// If current element is non zero
			if (num[i] != 0) {
				swap(num[i], num[idx]);
				idx++;
			}
		}
	}
};

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	Solution sol;

	sol.moveZeroToEnd_2(arr);
	cout << "After moving zero to end: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << '\n';
	
	return 0;
}