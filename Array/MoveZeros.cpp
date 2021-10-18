/*
 *
 * Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.


link of the question : https://leetcode.com/problems/move-zeroes/

*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> ans;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0)
                ans.push_back(nums[i]);
            else
                count++;
        }

        while(count!=0){
            ans.push_back(0);
            count--;
        }

        for(int i=0;i<nums.size();i++){
            nums[i] = ans[i];
        }
    }
};
