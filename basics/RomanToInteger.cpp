/*
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.



Example 1:

Input: s = "III"
Output: 3
Example 2:

Input: s = "IV"
Output: 4

link of question : https://leetcode.com/problems/roman-to-integer/
*/


class Solution {
public:
    int romanToInt(string s) {
        int length = s.length();
        int ans = 0;
        for(int i=length-1;i>=0;i--){
            char n = s[i];
            if(n == 'I'){
                int next = s[i+1];
                if(next == 'V' || next == 'X')
                    ans-=1;
                else
                    ans+=1;
            }
            else if(n == 'V')
                ans+=5;
            else if(n == 'X'){
                int next = s[i+1];
                if(next == 'L' || next == 'C')
                    ans-=10;
                else
                    ans+=10;
            }
            else if (n == 'L')
                ans+=50;
            else if (n == 'C'){
                int next = s[i+1];
                if(next == 'D' || next == 'M')
                    ans-=100;
                else
                    ans+=100;
            }
            else if(n == 'D')
                ans+=500;
            else if(n == 'M')
                ans+=1000;

        }
        return ans;
    }
};
