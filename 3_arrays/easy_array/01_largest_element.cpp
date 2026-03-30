#include <bits/stdc++.h>
using namespace std;

// Brute force solution
// Sort and return the last element
int largestElement_1(int arr[], int n)
{
	sort(arr, arr+n);

	return arr[n-1];
}

// Another brute force solution using nested loops
int largestElement_3(int arr[], int n)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i] > arr[j] && arr[i] > max) 
				max = arr[i];
		}
	}
}

// Optimized solution
// Set it to the first element and compare in the array for element largest than that
int largestElement_2(int arr[], int n)
{
	int largest = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > largest) 
			largest = arr[i];
	}
	return largest;
}

int main() {
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++) 
		cin >> arr[i];

	cout << largestElement_1(arr, n) << '\n';
	return 0;
}