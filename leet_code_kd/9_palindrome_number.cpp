// similar to the pointer approach of a string but here
// we are storing the last digits of the number till it is smaller than the given, then comparing them
// if they are equal then it is a palindrome or else it is not
// but here we have to take care about the odd number of digits as they will not be equal so we have to divide by 10 the rev number
// the rev number will be updated by the digits of the number while multiplying by 10
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
};