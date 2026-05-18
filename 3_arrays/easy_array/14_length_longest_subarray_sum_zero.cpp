#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int longestSubarray_1(vector<int> &nums)
	{
		// Store longest length found so far
		int maxLen = 0;

		//map prefix sum -> first index seen;
		unordered_map<int, int> sumIndexMap;
		
		// running prefix sum
		int sum = 0;

		// iterate through the array
		for (int i = 0; i < nums.size(); i++)
		{
			// update running sum
			sum += nums[i];

			// if sum is zero, subarray has zero sum
			if (sum == 0) {
				// update longest length
				maxLen = i + 1;
			}
		}
	}
};

int main() {
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	

	return 0;
}