/*
 *
 * Share
Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means a modification to the input array will be known to the caller as well.


link of question : https://leetcode.com/problems/remove-duplicates-from-sorted-array/

*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator i;

        i = unique(nums.begin(),nums.end());

        nums.resize(distance(nums.begin(),i));

        return nums.size();
    }
};
