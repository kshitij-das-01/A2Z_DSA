#include<iostream>
using namespace std;

// Brute force 
void leftRotate_1(int arr[], int n)
{
	int dummy[n];
	for (int i = 1; i < n; i++)
		dummy[i-1] = arr[i];

	dummy[n-1] = arr[0];

	for (int it : dummy)
		cout << it << ' ';
	cout << '\n';
}

// Optimal Solution
void leftRotate_2(int arr[], int n)
{
	int temp = arr[0];
	for (int i = 1; i < n; i++)
	{
		arr[i-1] = arr[i];
	}
	arr[n-1] = temp;

	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << '\n';
}

int main()
{
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	leftRotate_1(arr, n);
	leftRotate_2(arr, n);
	return 0;
}