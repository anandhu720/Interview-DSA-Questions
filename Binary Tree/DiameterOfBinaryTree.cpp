/*
 *
 * Given a Binary Tree, find diameter of it.
The diameter of a tree is the number of nodes on the longest path between two end nodes in the tree. The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).



Example 1:

Input:
       1
     /  \
    2    3
Output: 3
Example 2:

Input:
         10
        /   \
      20    30
    /   \
   40   60
Output: 4

link of question :https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1#
*/


class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int height(Node* root){
        int x=0,y=0;
        if(root == 0)
            return 0;
        x=height(root->left);
        y=height(root->right);

        return (x>y)?x+1:y+1;
    }

    int max(int x,int y){
        return (x>y)?x:y;
    }

    int diameter(Node* root) {
        // Your code here

        if(root == NULL)
            return 0;

        int lheight = height(root->left);
        int rheight = height(root->right);

        int ldiameter = diameter(root->left);
        int rdiameter = diameter(root->right);

        return max(lheight+rheight+1,max(ldiameter,rdiameter));
    }
};

//time=O(n^2)

//optimal solution

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
    int height(TreeNode* root,int &diameter){
        if(!root) return 0;
        
        int lh = height(root->left,diameter);
        int rh = height(root->right,diameter);
        diameter = max(diameter,lh+rh);
        
        return 1+ max(lh,rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
};

//time = O(n)

