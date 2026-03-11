#include <iostream>
#include <map>
// #include <bits/stdc++.h>

using std::cin; using std::cout;

// brute force
void freqArray_1(int *arr, int n)
{
	bool *visit = new bool[n];
	
	for (int i = 0; i < n; i++)
	{
		if (visit[i]) {
			continue;
		}

		// count all array elements once
		int cnt = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] == arr[j]) {
				cnt++;
				visit[j] = true;
			}
		}

		cout << arr[i] << " occurs: " << cnt << '\n';
	}
}

// optimized approach using map
void freqArray_2(int *arr, int n)
{
	// std::map<int, int> mp;
	// unordered map 
	std::unordered_map<int, int> mp;

	for (int i = 0; i < n; i++) {
		mp[arr[i]]++;
	}

	for (auto it : mp) {
		cout << it.first << " occurs: " << it.second << '\n';
	}
}


int main(void)
{
	int N;
	cin >> N;

	int *arr = new int[N];

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	freqArray_2(arr, N);
	return 0;
}