/*
 *
 * Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.


Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6
numbers form the longest consecutive
subsquence.

Example 2:

Input:
N = 7
a[] = {1,9,3,10,4,20,2}
Output:
4
Explanation:
1, 2, 3, 4 is the longest
consecutive subsequence.


link of question : https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1#

*/

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]

    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
        unordered_set<int> set;
        int longestSubArray = 0;

        for(int i=0;i<N;i++)
            set.insert(arr[i]);

        for(int i=0;i<N;i++){

            if(set.find(arr[i]-1) == set.end()){
                int currentLength = 1;
                int num=arr[i];
                while(set.find(num+1) != set.end()){
                    currentLength++;
                    num++;
                }

                longestSubArray = max(longestSubArray,currentLength);

            }
        }

        return longestSubArray;


    }
};
