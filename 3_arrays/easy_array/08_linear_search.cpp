#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int num)
{
	// Loop through the array to find the number;
	for (int i = 0; i < n; i++)
	{
		// If the current element matches the number, return its index
		if (num == arr[i])
			return i;
	}

	// If the number is not found, return -1
	return -1;
}

int main() {
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++) 
		cin >> arr[i];

	int num;
	cin >> num;

	// Search function to store the result
	int numIdx = linearSearch(arr, n, num);

	// Print index of the found number or -1 if not found
	if (numIdx == -1)
		cout << "Element not found";
	else
		cout << "Element found at index: " << numIdx;

	return 0;
}