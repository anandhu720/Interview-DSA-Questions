/*
 * Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode *,pair<int,int>>> todo;
        todo.push({root,{0,0}});
        while(!todo.empty()){
            auto it = todo.front();
            todo.pop();
            root = it.first;
            int vertical = it.second.first;
            int level = it.second.second;
            nodes[vertical][level].insert(root->val);
            if(root->left)
                todo.push({root->left,{vertical-1,level+1}});
            if(root->right)
                todo.push({root->right,{vertical+1,level+1}});
        }
        vector<vector<int>> ans;
        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second)
                col.insert(col.end(),q.second.begin(),q.second.end());
            ans.push_back(col);
        }
        return ans;
    }
};
