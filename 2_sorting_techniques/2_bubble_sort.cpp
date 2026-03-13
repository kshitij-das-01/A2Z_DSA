#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2) SC: O(1)
// But the best can be O(N), because
// if no swaps occur during the first run through the array it is already sorted
// will break out of the loop in that case
void bubble_sort(int *arr, int n)
{
	for (int i = n-1; i >= 1; i--)
	{
		int didSwap = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j+1]) {
				arr[j] = arr[j] + arr[j+1];
				arr[j+1] = arr[j] - arr[j+1];
				arr[j] = arr[j] - arr[j+1];
				didSwap = 1;
			}
		}
		if (didSwap == 0) {
			break;
		}
	}

	cout << "After Bubble Sort:\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

int main(void)
{
	int N;
	cin >> N;

	int *arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	bubble_sort(arr, N);

	cout << '\n';
	return 0;
}