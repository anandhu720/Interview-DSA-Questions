/*
 *
 * Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3


link of question : https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#

*/

/* A binary tree node

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

//Function to return a list containing elements of left view of the binary tree.

void recursion(Node *root,int level,vector<int> &ans){
    if(!root) return;
    if(ans.size() == level) ans.push_back(root->data);
    recursion(root->left,level+1,ans);
    recursion(root->right,level+1,ans);
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   recursion(root,0,ans);
   return ans;
}

