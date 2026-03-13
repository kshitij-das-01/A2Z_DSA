#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2) SC: O(1)
void selection_sort(int *arr, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int min = i;
		for (int j = i; j < n; j++)
		{
			if (arr[j] < arr[min]) 
				min = j;
		}

		arr[i] = arr[i] + arr[min];
		arr[min] = arr[i] - arr[min];
		arr[i] = arr[i] - arr[min];
	}
}

int main(void)
{
	int N;
	cin >> N;

	int *arr = new int(N);

	for (int i = 0; i < N; i++) 
		cin >> arr[i];

	selection_sort(arr, N);

	for (int i = 0; i < N; i++) 
		cout << arr[i] << " ";
	
	
	return 0;
}