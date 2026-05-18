#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Optimal Approach - Count and Update Max
	// TC: O(N) SC: O(1)
	int maxConsecutiveOnes(vector<int> &nums)
	{
		// Variable to store current count of consecutive 1's
		int cnt = 0;
		// Variable to store maximum consecutive 1's
		int maxCnt = 0;

		// Traverse the array
		for (int i = 0; i < nums.size(); i++)
		{
			// If current element is 1, increment count
			if (nums[i] == 1) {
				cnt++;
			}
			else {
				// If element is 0, reset count
				cnt = 0;
			}

			// Update maximum if current count is greater
			maxCnt = max(maxCnt, cnt);
		}

		// Return maximum consecutive 1's
		return maxCnt;
	}
};

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	Solution sol;

	cout << sol.maxConsecutiveOnes(arr) << '\n';
	return 0;
}