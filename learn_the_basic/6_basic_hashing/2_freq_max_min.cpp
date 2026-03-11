#include <iostream>
#include <map>

using std::cin; using std::cout;

class FrequencyCounter {
public:

	// brute force
	void countFreq(int *arr, int n)
	{
		bool *freq = new bool[n];
		int maxFreq = 0, minFreq = n;
		int maxEle = 0, minEle = 0;
		
		for (int i = 0; i < n; i++)
		{
			if (freq[i]) {
				continue;
			}

			// count all array elements once
			int cnt = 1;
			for (int j = i + 1; j < n; j++)
			{
				if (arr[i] == arr[j]) {
					cnt++;
					freq[j] = true;
				}

			}

			// update max and min freq with element
			if (cnt > maxFreq) {
				maxFreq = cnt;
				maxEle = arr[i];
			}
			if (cnt < minFreq) {
				minFreq = cnt;
				minEle = arr[i];
			}
		}

		cout << "Highest Frequency: " << maxEle << " occurs: " << maxFreq << '\n';
		cout << "Lowest Frequency: " << minEle << " occurs: " << minFreq << '\n';
	}
};

int main(void)
{
	int N;
	cin >> N;
	
	int *arr = new int[N];

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	FrequencyCounter fc;
	fc.countFreq(arr, N);

	return 0;
}