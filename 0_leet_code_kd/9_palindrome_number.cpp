// similar to the pointer approach of a string but here
// we are storing the last digits of the number till it is smaller than the given, then comparing them
// if they are equal then it is a palindrome or else it is not
// but here we have to take care about the odd number of digits as they will not be equal so we have to divide by 10 the rev number
// the rev number will be updated by the digits of the number while multiplying by 10
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return 0;
            
        int rev = 0;
        while (x > rev)
        {
            rev = (rev * 10) + (x % 10);
            x /= 10;
        }                

        if (rev == x || x == rev / 10) return true;
        else return false;
    }

    // two pointer with vector store int
    bool isPalindrome_1(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        vector<int> num;
        while (x > 0) {
            num.push_back(x % 10);
            x /= 10;
        }

        int i = 0, j = num.size() - 1;
        while (i < j)
        {
            if (num[i] != num[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};