/*
 *
 * Given a string S, check if it is palindrome or not.

Example 1:

Input: S = "abba"
Output: 1
Explanation: S is a palindrome
Example 2:

Input: S = "abc"
Output: 0
Explanation: S is not a palindrome

link of question : https://practice.geeksforgeeks.org/problems/palindrome-string0817/1#

*/

class Solution{
public:


	int isPlaindrome(string S)
	{
	    // Your code goes here
        int i=0;
        int j=S.length()-1;

        while(i<j){
            if(S[i] != S[j])
                return 0;
            i++;
            j--;
        }

        return 1;
	}

};
