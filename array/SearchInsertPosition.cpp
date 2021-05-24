/*
 *
 * Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

link of question:https://leetcode.com/problems/search-insert-position/

*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int length = nums.size();
        for(int i=0;i<length;i++){
            if(nums[i] == target)
                return i;
        }

        int i;
        for(i=0;i<length;i++){
            if(nums[i] > target)
                return i;
        }

        return i;
    }
};
