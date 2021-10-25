/*
 * 
 * Given a full binary expression tree consisting of basic binary operators (+ , – ,*, /) and some integers, Your task is to evaluate the expression tree.

Example 1:

Input: 
              +
           /     \
          *       -
        /  \    /   \
       5    4  100  20 

Output: 100

Explanation:
((5 * 4) + (100 - 20)) = 100

link : https://practice.geeksforgeeks.org/problems/expression-tree/

*/

class Solution{
  public:
    /*You are required to complete below method */
    int toInt(string s){
        stringstream str(s);
        
        int num = 0;
        str >> num;
        
        return num;
    }
    int evalTree(node* root) {
        if(!root) return 0;
        
        if(!root->left && !root->right) return toInt(root->data);
        
        int l_val = evalTree(root->left);
        
        int r_val = evalTree(root->right);
        
        if(root->data == "+")
            return l_val+r_val;
        if(root->data == "-")
            return l_val - r_val;
        if(root->data == "*")
            return l_val * r_val;
        return l_val/r_val;
        
        
    }
};
