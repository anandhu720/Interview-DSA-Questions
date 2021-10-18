/*
 *
 *You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.


Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.


link of question : https://leetcode.com/problems/merge-sorted-array/

*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int c[m+n+1];
        int i,j,k;
        i=j=k=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j])
                c[k++]=nums1[i++];
            else
                c[k++]=nums2[j++];
        }
        
        for(;i<m;i++)
            c[k++]=nums1[i];
        for(;j<n;j++)
            c[k++]=nums2[j];
        
        for(int a=0;a<nums1.size();a++)
            nums1[a]=c[a];
    }
};
