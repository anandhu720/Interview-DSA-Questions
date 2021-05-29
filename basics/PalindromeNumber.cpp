/*
 *
 * Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.



link of question : https://leetcode.com/problems/palindrome-number/

*/

class Solution {
public:
    bool isPalindrome(int x) {
        int number = x;
        int rev =0,rem;
        if(number < 0)
            return false;
        while(x != 0){
            if(rev>(INT_MAX/10) || rev<(INT_MIN)/10)
                return 0;
            rem = x%10;
            rev = rev*10 + rem;
            x/=10;
        }

        if(number == rev)
            return true;
        return false;
    }
};
