#include <bits/stdc++.h>
using namespace std;

// Solution 1
class Solution {
public:
    bool isPalindrome(string s) {

        transform(s.begin(), s.end(), s.begin(), ::tolower);

        string res;
        for (int i = 0; i < s.length(); i++) 
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
                res += s[i];
            }
        }

        if (res.empty())
            return true;
        
        int len = res.length();
        cout << len;
        for (int i = 0; i < len; i++)
        {
            if (res[i] != res[len-1-i]) {
                return false;
            }
        }

        return true;
    }
};

