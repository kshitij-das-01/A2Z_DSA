#include <bits/stdc++.h>
using namespace std;

// Brute force solution
// TC: O(NlogN) SC: O(1)
void secondLargest_1(int arr[], int n)
{
	if (n < 2) {
		cout << -1 << " " << -1 << '\n';
		return;
	}

	sort(arr, arr+n);
	int secondLargest = arr[n-2];
	int secondSmallest = arr[1];

	for (int i = n-2; i >= 0; i--)
	{
		if (arr[i] != secondLargest) {
			secondLargest = arr[i];
			break;
		}
	}

	for (int i = 1; i < n; i++)
	{
		if (arr[i] != secondSmallest) {
			secondSmallest = arr[i];
			break;
		}
	}

	cout << "Second Largest: " << secondLargest << '\n';
	cout << "Second Smallest: " << secondSmallest << '\n';
}

// Better approach
// TC: O(2N) SC: O(1)
void secondLargest_2(int arr[], int n)
{
	int largest = arr[0], smallest = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > largest)
			largest = arr[i];

		if (arr[i] < smallest) 
			smallest = arr[i];
	}
	int sLargest = INT_MIN, sSmallest = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > sLargest && arr[i] != largest)
			sLargest = arr[i];
		
		if (arr[i] < sSmallest && arr[i] != smallest)
			sSmallest = arr[i];
	}
}

// Optimal Approach
// TC: O(N) SC: O(1)
void secondLargest_3(int arr[], int n)
{
	int largest = arr[0], smallest = arr[0];
	int sLargest = INT_MIN, sSmallest = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > largest) {
			sLargest = largest;
			largest = arr[i];
		}
		else if (arr[i] < largest && arr[i] > sLargest) {
			sLargest = arr[i];
		}

		if (arr[i] < smallest) {
			sSmallest = smallest;
			smallest = arr[i];
		}
		else if (arr[i] > smallest && arr[i] < sSmallest) {
			sSmallest = arr[i];
		}
	}

	cout << "Second Largest: " << sLargest << '\n';
	cout << "Second Smallest: " << sSmallest << '\n';
}

int main() {

	int n; 
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	secondLargest_3(arr, n);
	return 0;
}