/*
 
 Given a Binary Tree of size N, find all the nodes which don't have any sibling. You need to return a list of integers containing all the nodes that don't have a sibling in sorted order.

Note: Root node can not have a sibling so it cannot be included in our answer.

Example 1:

Input :
       37
      /   
    20
    /     
  113 

Output: 20 113
Explanation: 20 and 113 dont have any siblings.

Example 2:

Input :
       1
      / \
     2   3 

Output: -1
Explanation: Every node has a sibling.

link : https://practice.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/

*/


/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

vector<int> noSibling(Node* root)
{
    vector<int> ans;
    if(!root) return ans;
    
    queue<Node *> q;
    q.push(root);
    
    while(!q.empty()){
        int size = q.size();
        
        for(int i=0;i<size;i++){
            root = q.front(); q.pop();
            
            if(root->left && !root->right) ans.push_back(root->left->data);
            if(!root->left && root->right) ans.push_back(root->right->data);
            
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }
    }
    
    if(ans.size() == 0) ans.push_back(-1);
    sort(ans.begin(),ans.end());
    return ans;
}
