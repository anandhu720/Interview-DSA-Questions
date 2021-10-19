/*
Given a BST and an integer. Find the least absolute difference between any node value of the BST and the given integer.

Example 1:

Input:
        10
      /   \
     2    11
   /  \ 
  1    5
      /  \
     3    6
      \
       4
K = 13
Output: 2
Explanation: K=13. The node that has
value nearest to K is 11. so the answer
is 2

link = https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1#

time = o(logn)

*/

class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
	void helper(Node *root,int K,int &min_diff){
	    if(!root) return;
	    
	    if(min_diff > abs(root->data - K)){
	        min_diff = abs(root->data - K);
	    }
	    
	    if(K < root->data) helper(root->left,K,min_diff);
	    else helper(root->right,K,min_diff);
	}
    int minDiff(Node *root, int K)
    {
        int min_diff = INT_MAX;
        helper(root,K,min_diff);
        return min_diff;
    }
};
