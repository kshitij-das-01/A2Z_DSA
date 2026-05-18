#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    // Brute force
    // TC: O(N^3) SC: O(1)
    int longestSubarray_1(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxLen = 0;

        // starting index
        for (int stIdx = 0; stIdx < n; stIdx++)
        {
            // ending index
            for (int edIdx = stIdx; edIdx < n; edIdx++)
            {
                // add all the elements of subarray
                int currentSum = 0;
                for (int i = stIdx; i <= edIdx; i++)
                {
                    currentSum += nums[i];
                }

                if (currentSum == k) 
                    maxLen = max(maxLen, edIdx - stIdx + 1);
            }
        }

        return maxLen;
    }

    // Optimal Solution - Two Pointers
	// TC: O(N) SC: O(1)
	int longestSubarray_2(vector<int> &nums, int k)
	{
		int n = nums.size();

		// To store the maximum length of the subarray
		int maxLen = 0;

		// Pointers to mark the start and end of window
        int lf = 0, rt = 0;

        // To store the sum of elements in the window
        int sum = nums[0];

        // Traverse all the elements
        while (rt < n) 
        {
            // If the sum exceeds K, shrink the window
            while (lf <= rt && sum > k) 
            {
                sum -= nums[lf];
                lf++;
            }

            // Store the maximum length
            if (sum == k) {
                maxLen = max(maxLen, rt - lf + 1);
            }

            rt++;

            if (rt < n) sum += nums[rt];
        }

        return maxLen;
	}
};

int main() {
	int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    Solution sol;
    cout << "Brute force: " << sol.longestSubarray_1(arr, k) << "\n";
    cout << "Optimal: " << sol.longestSubarray_2(arr, k) << "\n";

	return 0;
}