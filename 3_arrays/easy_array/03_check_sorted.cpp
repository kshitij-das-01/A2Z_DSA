#include <bits/stdc++.h>
using namespace std;

// Brute force approach
// TC: O(N^2) SC: O(1)
bool isSorted_1(int arr[], int n)
{
	if (n <= 1) return true;

	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (arr[i] > arr[j])
				return false;
		}
	}

	return true;
}

// Optimal Approach
// TC: O(N) SC: O(1)
bool isSorted_2(int arr[], int n)
{
	if (n <= 1) return true;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] < arr[i-1])
			return false;
	}

	return true;
}

int main() {
	int n; 
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	if (isSorted_2(arr, n)) 
		cout << "Sorted\n";
	else 
		cout << "Not Sorted\n";

	
	return 0;
}