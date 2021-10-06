/*
 * Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.

link : https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
*/

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

void helper(Node* root,int d,map<int,vector<int>> &nodes){
    if(!root) return;
    
    nodes[d].push_back(root->data);
    helper(root->left,d+1,nodes);
    helper(root->right,d,nodes);
}

vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> ans;
   map<int,vector<int>> nodes;
   helper(root,0,nodes);
   for(auto i : nodes){
       int size = i.second.size();
       for(int j=0;j<size;j++)
        ans.push_back(i.second[j]);
   }
   
   return ans;
}
