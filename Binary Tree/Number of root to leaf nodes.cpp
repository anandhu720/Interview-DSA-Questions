/*

Given a binary tree, you need to find the number of all root to leaf paths along with their path lengths.

Example 1:

Input:
3 2 4

Output:
2 2 $

Explanation :
There are 2 roots to leaf paths
of length 2.     
Example 2:

Input:
10 20 30 40 60

Output:
2 1 $3 2 $

Explanation:
There is 1 root leaf paths of
length 2 and 2 roots to leaf paths
of length 3.

link : https://practice.geeksforgeeks.org/problems/number-of-root-to-leaf-paths/

*/

/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*You are required to complete below method */
void helper(Node* root,map<int,int> &ans,int path_length = 1){
    if(!root) return;
    
    if(!root->left && !root->right){
        ans[path_length]++;
        return;
    }
    
    helper(root->left,ans,path_length+1);
    helper(root->right,ans,path_length+1);
}
void pathCounts(Node *root)
{
    map<int,int> ans;
    
    helper(root,ans);
    
    for(auto i : ans)
        cout<<i.first <<" "<< i.second << " $";
}
