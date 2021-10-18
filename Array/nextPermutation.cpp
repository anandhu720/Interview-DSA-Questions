/*
 *
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.



Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]

link of question : https://leetcode.com/problems/next-permutation/

*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)
            return;

        int index1 = -1;
        int index2 = -1;

        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index1=i;
                break;
            }
        }


        if(index1 == -1){
            sort(nums.begin(),nums.end());
            return;
        }

        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>nums[index1]){
                index2=i;
                break;
            }
        }

        swap(nums[index1],nums[index2]);

        sort(nums.begin()+index1+1,nums.end());
    }
};
