/*
 *
 *
Given an array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.

Return the indices of the two numbers (1-indexed) as an integer array answer of size 2, where 1 <= answer[0] < answer[1] <= numbers.length.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

link of question : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int h=numbers.size()-1;

        while(l<h){
            int sum = numbers[l]+numbers[h];

            if(sum == target)
                return {l+1,h+1};
            else if (sum < target)
                l++;
            else
                h--;
        }

        return {-1};

    }
};
