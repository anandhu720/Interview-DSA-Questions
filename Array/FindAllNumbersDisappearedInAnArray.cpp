/*
 *
 * Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

link of question : https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

*/


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector <bool> flag(n,false);
        vector <int> ans;

        for(auto i : nums){
            flag[i-1] = true;
        }

        for(int i=0;i<n;i++){
            if(flag[i] == false)
                ans.push_back(i+1);
        }

        return ans;
    }
};
