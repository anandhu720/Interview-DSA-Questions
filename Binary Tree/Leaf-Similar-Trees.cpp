/*
 * Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

link : https://leetcode.com/problems/leaf-similar-trees/
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
    void leaf(TreeNode *root,vector<int> &ans){
        if(root){
            leaf(root->left,ans);
            if(!root->left && !root->right) ans.push_back(root->val);
            leaf(root->right,ans);
        }
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1, seq2;
        leaf(root1,seq1);
        leaf(root2,seq2);
        
        for(int i=0;i<seq1.size();i++)
            cout<<seq1[i]<<" ";
        
        if(seq1.size() != seq2.size()) return false;
        
        for(int i=0;i<seq1.size();i++){
            if(seq1[i] != seq2[i])
                return false;
        }
        return true;
    }
};
