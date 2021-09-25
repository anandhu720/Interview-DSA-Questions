/*
 * Given a Binary Tree of size N, you need to find all the possible paths from root node to all the leaf node's of the binary tree.
 */

/* Structure of Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/

/* The function should print all the paths from root
 to leaf nodes of the binary tree */
void helper(Node *root,vector<vector<int>> &ans,vector<int> arr){
    if(!root) return;
    arr.push_back(root->data);
    if(!root->left && !root->right){
        ans.push_back(arr);
        return;
    }
    helper(root->left,ans,arr);
    helper(root->right,ans,arr);
}
vector<vector<int>> Paths(Node* root)
{
    // Code here
    vector<vector<int>> ans;
    if(!root) return ans;
    vector<int> arr;
    helper(root,ans,arr);
    return ans;
}
