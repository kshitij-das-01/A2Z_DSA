// Solution 1
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;

        for (int i = 5; i <= n; i++)
        {	
            int num = i;

            while (num % 5 == 0)
            {
                cnt++;
                num /= 5;
            }
        }

		return cnt;
    }
};

// Solution 2
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;

        for (int i = 5; i <= n; i += 5)
        {	
            int num = i;

            while (num % 5 == 0)
            {
                cnt++;
                num /= 5;
            }
        }

		return cnt;
    }
};

// Solution 3
class Solution {
public:
    int trailingZeroes(int n) {
		int cnt = 0;

        for (int i = 5; n / i >= 1; i *= 5)
        {
            cnt += (n / i);
        }
        return cnt;
    }
};