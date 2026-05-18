#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
	// Brute force - check count of each element
	// TC: O(N^2) SC: O(1)
	int numberAppearOnce_1(vector<int> &arr)
	{
		int n = arr.size();

		// Loop through every element
		for (int i = 0; i < n; i++) 
		{
			int num = arr[i]; // current element to check
			int cnt = 0;

			// Count occurrences of this element
			for (int j = 0; j < n; j++)
			{
				if (arr[j] == num)
					cnt++;
			}

			// If it occurs only once, return it
			if (cnt == 1) return num;
		}

		// Returns -1 if no elements appears once
		return -1;
	}

	// Better approach - using hashing technique
	// TC: O(3N) SC: O(maxElement + 1)
	int numberAppearOnce_2(vector<int> &arr)
	{
		int n = arr.size();

		// Step 1: Find the maximum value in the array
		int maxi = arr[0];
		for (int i = 0; i < n; i++) {
			maxi = max(maxi, arr[i]);
		}

		// Step 2: Declare and initialize hash array of size max + 1
		vector<int> hash(maxi + 1, 0);

		// Step 3: Count the frequency of each element
		for (int i = 0; i < n; i++) {
			hash[arr[i]]++;
		}

		// Step 4: Find the element that occurs exactly once
		for (int i = 0; i < n; i++)
		{
			if (hash[arr[i]] == 1)
				return arr[i];
		}

		// Returns -1 if no element appears once
		return -1;
	}

	// Optimal Approach - using XOR properties
	// TC: O(N) SC: O(1)
	int numberAppearOnce_3(vector<int> &arr)
	{
		int n = arr.size();
		int xorr = 0;

		for (int i = 0; i < n; i++) {
			xorr = xorr ^ arr[i];
		}

		return xorr;
	}
};

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	Solution sol;

	cout << "Brute force: " << sol.numberAppearOnce_1(arr) << "\n";
	cout << "Better: " << sol.numberAppearOnce_2(arr) << "\n";
	cout << "Optimal: " << sol.numberAppearOnce_3(arr) << "\n";

	return 0;
}