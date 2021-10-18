/*
 * 
 * Given a binary tree in which each node element contains a number. Find the maximum possible path sum from one leaf node to another leaf node.

Note: Here Leaf node is a node which is connected to exactly one different node.

Example

Input:      
           3                               
         /    \                          
       4       5                     
      /  \      
    -10   4                          
Output: 16
Explanation:
Maximum Sum lies between leaf node 4 and 5.
4 + 4 + 3 + 5 = 16.

link : https://practice.geeksforgeeks.org/problems/maximum-path-sum/1/

*/

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    int findMax(Node* root,int &maxi){
        if(!root) return 0;
        if(!root->left && !root->right) return root->data;
        
        int ls = findMax(root->left,maxi);
        int rs = findMax(root->right,maxi);
        
        if(root->left && root->right){
            maxi = max(maxi,ls+rs+root->data);
            return max(ls,rs)+root->data;
        }
        
        return (!root->left)? rs+root->data:ls+root->data;
    }
    int maxPathSum(Node* root)
    {
        // code here
        int maxi = INT_MIN;
        int val = findMax(root,maxi);
        if(maxi == INT_MIN) return val;
        return maxi;
    }
};
