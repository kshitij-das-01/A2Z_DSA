#include <bits/stdc++.h>
using namespace std;

// Brute solution
class BruteSolution {
public:
	// Rotate the array to the right by k elements
	// This function takes an array of n elements and rotates it to the right by k elements
	// If k is greater than n, it is taken as k % n
	void rotateRight(int arr[], int n, int k)
	{
		if (n == 0) return;

		if (k > n) k = k % n;

		int temp[k];
		for (int i = n-k; i < n; i++)
			temp[i-n+k] = arr[i];

		for (int i = n-k-1; i >= 0; i--)
			arr[i+k] = arr[i];

		for (int i = 0; i < k; i++)
			arr[i] = temp[i];
	}

	// Rotate the array to the left by k elements
	// This function takes an array of n elements and rotates it to the left by k elements
	// If k is greater than n, it is taken as k % n
	void rotateLeft(int arr[], int n, int k)
	{
		if (n == 0) return;

		if (k > n) k = k % n;

		// Store the first k elements in a temporary array
		int temp[k];
		for (int i = 0; i < k; i++)
			temp[i] = arr[i];

		// Shift the elements to the left by k positions
		for (int i = k; i < n; i++)
			arr[i-k] = arr[i];
		
		// Copy the elements from the temporary array to the end of the array
		for (int i = 0; i < k; i++)
			arr[n-k+i] = temp[i];
	}
};

// Optimal Solution
class OptimalSolution {
public:
	// This function takes an array of n elements and reverses it in-place
	// It takes two pointers, start and end, and swaps the elements at the start and end indices
	// It then increments the start pointer and decrements the end pointer until start >= end
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

	/**
	 * This function takes an array of n elements and rotates it to the right by k elements
	 * It first reverses the entire array, then reverses the first k elements, and finally reverses the remaining n-k elements
	 * This process effectively rotates the array to the right by k elements
	 * If k is greater than n, it is taken as k % n
	 * @param arr the array to be rotated
	 * @param n the number of elements in the array
	 * @param k the number of positions to rotate the array to the right
	 */
	void rightRotate(int arr[], int n, int k)
	{
		if (n == 0) return; // if the array is empty, return immediately

		if (k > n) k = k % n; // if k is greater than n, take k % n as the effective number of positions to rotate

		// reverse the entire array
		reverseArray(arr, 0, n-1); // call the reverseArray function with start = 0 and end = n-1

		// reverse the first k elements
		reverseArray(arr, 0, k-1); // call the reverseArray function with start = 0 and end = k-1

		// reverse the remaining n-k elements
		reverseArray(arr, k, n-1); // call the reverseArray function with start = k and end = n-1
	}

	/**
	 * This function takes an array of n elements and rotates it to the left by k elements
	 * It first reverses the first k elements, then reverses the remaining n-k elements, and finally reverses the entire array
	 * This process effectively rotates the array to the left by k elements
	 * If k is greater than n, it is taken as k % n
	 * @param arr the array to be rotated
	 * @param n the number of elements in the array
	 * @param k the number of positions to rotate the array to the left
	 */
	void leftRotate(int arr[], int n, int k)
	{
		// if the array is empty, return immediately
		if (n == 0) return;

		// if k is greater than n, take k % n as the effective number of positions to rotate
		if (k > n) k = k % n;

		// reverse the first k elements
		reverseArray(arr, 0, k-1); // call the reverseArray function with start = 0 and end = k-1

		// reverse the remaining n-k elements
		reverseArray(arr, k, n-1); // call the reverseArray function with start = k and end = n-1

		// reverse the entire array
		reverseArray(arr, 0, n-1); // call the reverseArray function with start = 0 and end = n-1
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