#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Brute force
	// TC: O(N^2) SC: O(1)
	int missingNum_1(int arr[], int n) {
		// Iterate from 1 to n and check
		// if the current number is present
		for (int i = 1; i <= n+1; i++)
		{
			bool found = false;
			for (int j = 0; j < n; j++)
			{
				if (arr[j] == i) {
					found = true;
					break;
				}
			}

			if (!found) {
				return i;
			}
		}
		return -1;
	}

	// Better Approach - Using Hashing
	// TC: O(N) SC: O(N)
	int missingNum_2(int arr[], int n)
	{
		// Creating hash array of size n+1
		vector<int> hash(n+1, 0);

		// Store frequencies of elements
		for (int i = 0; i < n; i++) {
			hash[arr[i]]++;
		}

		// Find the missing number
		for (int i = 1; i <= n + 1; i++)
		{
			if (hash[i] == 0) {
				return i;
			}
		}
		return -1;
	}

	// Optimal Approach - Sum of n terms
	// TC: O(N) SC: O(1)
	int missingNum_3(int arr[], int n) 
	{
		// Calculate the sum of array elements
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += arr[i];
		}

		// Calculate the expected sum
		long long expSum = (n * 1LL * (n + 1)) / 2;

		// Return the missing number
		return expSum - sum;
	}

	// Optimal Approach 2 - XOR Operation
	// TC: O(N) SC: O(1)
	int missingNum_4(int arr[], int n)
	{
		int xor1 = 0, xor2 = 0;

		// XOR all array elements
		for (int i = 0; i < n; i++) {
			xor2 ^= arr[i];
		}

		// XOR all numbers from 1 to n
		for (int i = 1; i <= n+1; i++) {
			xor1 ^= i;
		}

		// Missing number is the XOR of xor1 and xor2
		return xor1 ^ xor2;
	}
};

int main() {
	int n;
	cin >> n;
	
	// Given an array of size n-1 with distinct integers in the range of [1,n]
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	Solution sol;

	cout << sol.missingNum_1(arr, n) << '\n';
	

	return 0;
}