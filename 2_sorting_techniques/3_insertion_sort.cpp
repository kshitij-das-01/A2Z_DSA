#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = i;

		while (j > 0 && arr[j-1] > arr[j])
		{
			int temp = arr[j-1];
			arr[j-1] = arr[j];
			arr[j] = temp;
			j--;
		}
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

int main(void)
{
	int N;
	cin >> N;

	int *arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	insertion_sort(arr, N);
	cout << '\n';
	return 0;
}