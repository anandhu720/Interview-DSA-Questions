/*

Given a binary tree, print nodes of extreme corners of each level but in alternate order.

Example 1:

Input:
       1
     /  \
    2    3
    
Output: 1 2
Explanation: This represents a tree
with 3 nodes and 2 edges where root
is 1, left child of 1 is 3 and
right child of 1 is 2.

link : https://practice.geeksforgeeks.org/problems/extreme-nodes-in-alternate-order

*/

class Solution{
  public:
    /* Function to print nodes of extreme corners
    of each level in alternate order */
    vector<int> ExtremeNodes(Node* root)
    {
        vector<int> ans;
        if(!root) return ans;
        queue<Node *> q;
        bool flag = true;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                root = q.front(); q.pop();
                
                if(flag  && i == size-1)
                    ans.push_back(root->data);
                else if(!flag && i == 0)
                    ans.push_back(root->data);
                
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            flag = !flag;
        }
    }
};
