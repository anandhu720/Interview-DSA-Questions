/*
 * Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary.

link : https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#
*/


struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    bool isLeaf(Node* root) {
        return !root->left && !root->right;
    }
    
    void addLeftBoundary(Node* root, vector<int> &res) {
        Node* cur = root->left;
        while (cur) {
            if (!isLeaf(cur)) res.push_back(cur->data);
            if (cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }
    void addRightBoundary(Node* root, vector<int> &res) {
        Node* cur = root->right;
        stack<int> tmp;
        while (cur) {
            if (!isLeaf(cur)) tmp.push(cur->data);
            if (cur->right) cur = cur->right;
            else cur = cur->left;
        }
        while(!tmp.empty()){
            res.push_back(tmp.top());
            tmp.pop();
        }
    }
    
    void addLeaves(Node* root, vector<int>& res) {
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        if (root->left) addLeaves(root->left, res);
        if (root->right) addLeaves(root->right, res);
    }
public:
    vector <int> printBoundary(Node *root)
    {
        vector<int> res;
        if (!root) return res;

        if (!isLeaf(root)) res.push_back(root->data);

        addLeftBoundary(root, res); 
        
        // add leaf nodes
        addLeaves(root, res);

        addRightBoundary(root, res); 
        return res;
    }
};
