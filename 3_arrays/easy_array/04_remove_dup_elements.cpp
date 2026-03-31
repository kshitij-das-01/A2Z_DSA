#include <bits/stdc++.h>
using namespace std;

// Brute force Approach
// TC: O(N) SC: O(N)
int remove_dup_1(int arr[], int n)
{
	set<int> dist;

	for (int i = 0; i < n; i++)
		dist.insert(arr[i]);

	int index = 0;
	for (auto it : dist) 
	{
		arr[index] = it;
		index++;
	}
	return index;
}

// Optimal Approach
// TC: O(N) SC: O(1)
int remove_dup_2(int arr[], int n)
{
	int index = 0;
	for (int j = 0; j < n; j++)
	{
		if (arr[index] != arr[j]) {
			index++;
			arr[index] = arr[j];

			// another way to write it
			// arr[index+1] = arr[i];
			// index++;
		}
	}

	return index+1;
}

int main() {
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int k = remove_dup_2(arr, n);
	cout << "Unique Count: " << k << '\n';
	for (int i = 0; i < k; i++)
		cout << arr[i] << ' ';
	cout << '\n';


	return 0;
}