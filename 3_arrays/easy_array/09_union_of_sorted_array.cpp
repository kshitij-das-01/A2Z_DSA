#include <bits/stdc++.h>
using namespace std;
// Note: Elements in the union should be in ascending order
class Solution {
public:
	// Approach using Map
	// TC: O((N+M) log(N+M)) SC: O(N+M)
	vector<int> findUnion_1(int arr1[], int arr2[], int n, int m)
	{
		// Create a map to store frequency of each element
		map<int, int> freq;

		// Create a vector to store the union result
		vector<int> unionResult;

		// Loop through first array and store frequency
		for (int i = 0; i < n; i++)
			freq[arr1[i]]++;

		// Loop through second array and store frequency
		for (int i = 0; i < m; i++)
			freq[arr2[i]]++;

		// Traverse the map to get unique sorted elements
		for (auto it : freq)
			unionResult.push_back(it.first);

		return unionResult;
	}

	// Approach using set
	// TC: O((N+M) log(N+M)) SC: O(N+M)
	vector<int> findUnion_2(int arr1[], int arr2[], int n, int m)
	{
		// Create a set to store the union of two arrays
		set<int> st;

		// Insert all elements of first array into the set
		for (int i = 0; i < n; i++)
			st.insert(arr1[i]);

		// Insert all elements of second array into the set
		for (int i = 0; i < m; i++)
			st.insert(arr2[i]);

		// Create a vector to store the union result
		vector<int> unionArr(st.begin(), st.end());
		return unionArr;
	}

	// Optimal Approach - Two Pointers
	// TC: O(N+M) SC:(N+M)
	vector<int> findUnion_3(int arr1[], int arr2[], int n, int m)
	{
		// Vector to store union elements
		vector<int> unionArr;

		// Initialize two pointers for both arrays
		int i = 0, j = 0;

		// Loop until either pointer reaches the end
		while (i < n && j < m) 
		{
			// If current element in arr1 is smaller
			if (arr1[i] < arr2[j]) {
				// Add element if union empty or different from last added
				if (unionArr.empty() || unionArr.back() != arr1[i])
					unionArr.push_back(arr1[i]);

				i++; // Move pointer in arr1
			}
			// If current element in arr2 is smaller
			else if (arr2[j] < arr1[i]) {
				// Add element if union empty or different from last added
				if (unionArr.empty() || unionArr.back() != arr2[j])
					unionArr.push_back(arr2[j]);

				j++; // Move pointer in arr2
			}
			else {
				// Elements are equal, add once if not duplicate
				if (unionArr.empty() || unionArr.back() != arr1[i]) 
					unionArr.push_back(arr1[i]);
				
				i++; j++; // Move both pointers
			}
		}

		// Append remaining elements from arr1
		while (i < n) {
			if (unionArr.empty() || unionArr.back() != arr1[i])
				unionArr.push_back(arr1[i]);
			i++;
		}

		// Append remaining elements from arr2
		while (j < m) {
			if (unionArr.empty() || unionArr.back() != arr2[j])
				unionArr.push_back(arr2[j]);
			j++;
		}

		// Return the final union vector
		return unionArr;
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	int arr1[n];
	for (int i = 0; i < n; i++)
		cin >> arr1[i];
	
	int arr2[m];
	for (int i = 0; i < m; i++)
		cin >> arr2[i];

	Solution sol;
	vector<int> unionArr = sol.findUnion_1(arr1, arr2, n, m);

	for (int i = 0; i < unionArr.size(); i++)
		cout << unionArr[i] << ' ';
	cout << '\n';

	return 0;
}