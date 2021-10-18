/*
 * 
 * Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
 * 
 * link : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode * create(vector<int> &preorder,int preStart,int preEnd,vector<int> &inorder,int inStart,int inEnd,map<int,int> &inMap){
        if(preStart > preEnd || inStart > inEnd) return NULL;
        
        TreeNode * root = new TreeNode(preorder[preStart]);
        
        int inRoot = inMap[root->val];
        int numLeft = inRoot - inStart;
        
        root->left = create(preorder,preStart+1,preStart+numLeft,inorder,inStart,inRoot-1,inMap);
        root->right = create(preorder,preStart+numLeft+1,preEnd,inorder,inRoot+1,inEnd,inMap);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inMap;
        
        for(int i=0;i<inorder.size();i++)
            inMap[inorder[i]] = i;
        
        TreeNode *root = create(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
        
        return root;
    }
};
