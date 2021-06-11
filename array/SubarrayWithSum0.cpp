/*
 *
 *
 * Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Example 1:

Input:
5
4 2 -3 1 6

Output:
Yes

Explanation:
2, -3, 1 is the subarray
with sum 0.

link : https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1#

*/


class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        unordered_set<int> sumSet;
        int sum = 0;

        for(int i=0;i<n;i++){
            sum+=arr[i];

            if(sum == 0 || sumSet.find(sum) != sumSet.end())
                return true;

            sumSet.insert(sum);
        }

        return false;
    }
};
