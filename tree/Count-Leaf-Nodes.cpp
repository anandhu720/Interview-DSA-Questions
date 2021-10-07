/*
 * Given a Binary Tree of size N , You have to count leaves in it. For example, there are two leaves in following tree
 * 
 * link : https://practice.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1#
 * 
 */


//User function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

/* Should return count of leaves. For example, return
    value should be 2 for following tree.
         10
      /      \ 
   20       30 */
 int helper(Node*root,int &count){
  if(root){
      if(!root->left && !root->right) count++;
      helper(root->left,count);
      helper(root->right,count);
  }
  return count;
 }
int countLeaves(Node* root)
{
  // Your code here
  int count = 0;
    return helper(root,count);
}
