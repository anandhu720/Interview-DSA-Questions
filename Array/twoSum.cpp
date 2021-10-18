/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

link of question : https://leetcode.com/problems/two-sum/

this solution is the most efficent one O(n) time

*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums,int target){
        int diff;
        unordered_map<int,int> m;
        
        for(int i=0;i<nums.size();i++){
            diff = target - nums[i];
            
            if(m.find(diff) != m.end() && m.find(diff)->second != i)
                return {i,m.find(diff)->second};
            else
                m[nums[i]] = i;
        }
        
        return {-1};
    }
}
