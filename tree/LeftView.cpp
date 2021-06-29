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

vector<int> leftUni(Node *root,int *max_level,int level){

    vector<int> ans;

    if(root == NULL)
        return ans;

    if(*max_level < level){
        ans.push_back(root->data);
        // cout<<root->data<<" ";
        *max_level = level;
    }

    leftUni(root->left,max_level,level+1);
    leftUni(root->right,max_level,level+1);


    return ans;
}

vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   int max_level = 0;
   ans = leftUni(root,&max_level,1);

   return ans;
}

