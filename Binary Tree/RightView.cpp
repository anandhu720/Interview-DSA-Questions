/*
 * Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.
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
}; */

// Should return  right view of tree
class Solution
{
    public:
    void recursion(Node *root,int level,vector<int> &ans){
        if(!root) return;
        if(ans.size() == level) ans.push_back(root->data);
        recursion(root->right,level+1,ans);
        recursion(root->left,level+1,ans);
    }
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
        vector<int> ans;
        recursion(root,0,ans);
        return ans;
    }
};
