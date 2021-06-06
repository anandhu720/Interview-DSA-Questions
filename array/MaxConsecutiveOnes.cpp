/*
 *
 *Given a binary array nums, return the maximum number of consecutive 1's in the array.

 Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2

link of question : https://leetcode.com/problems/max-consecutive-ones/

*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int mx = INT_MIN;

        for(int i=0;i<nums.size();i++){
            count = (nums[i] == 1) ? count+1 : count = 0;
            mx = max(mx,count);
        }

        return mx;
    }
};
