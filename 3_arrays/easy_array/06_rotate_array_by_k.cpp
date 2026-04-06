#include <bits/stdc++.h>
using namespace std;

// Brute solution
class BruteSolution {
public:
	void rotateRight(int arr[], int n, int k)
	{
		if (n == 0) return;

		if (k > n) k = k % n;

		int temp[k];
		for (int i = n-k; i < n; i++)
			temp[i-n+k] = arr[i];

		for (int i =n-k-1; i >= 0; i--)
			arr[i+k] = arr[i];

		for (int i = 0; i < k; i++)
			arr[i] = temp[i];
	}

	void rotateLeft(int arr[], int n, int k)
	{
		if (n == 0) return;

		if (k > n) k = k % n;

		int temp[k];
		for (int i = 0; i < k; i++)
			temp[i] = arr[i];

		for (int i = k; i < n; i++)
			arr[i-k] = arr[i];
		
		for (int i = 0; i < k; i++)
			arr[n-k+i] = temp[i];
	}
};

// Optimal Solution
class OptimalSolution {
public:
	void reverseArray(int arr[], int start, int end)
	{
		while (start < end) 
		{
			int temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
			start++, end--;
		}
	}

	void rightRotate(int arr[], int n, int k)
	{
		if (n == 0) return;

		if (k > n) k = k % n;

		reverseArray(arr, 0, n-1);
		reverseArray(arr, 0, k-1);
		reverseArray(arr, k, n-1);
	}

	void leftRotate(int arr[], int n, int k)
	{
		if (n == 0) return;

		if (k > n) k = k % n;

		reverseArray(arr, 0, k-1);
		reverseArray(arr, k, n-1);
		reverseArray(arr, 0, n-1);
	}
};

int main() {
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int k;
	cin >> k;

	BruteSolution bs;
	bs.rotateRight(arr, n, k);
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << '\n';

	bs.rotateLeft(arr, n, k);
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << '\n';

	OptimalSolution os;
	os.rightRotate(arr, n, k);
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << '\n';

	os.leftRotate(arr, n, k);
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << '\n';

	return 0;
}