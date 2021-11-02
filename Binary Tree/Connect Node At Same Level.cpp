/*
 *
Given a binary tree, connect the nodes that are at same level. You'll be given an addition nextRight pointer for the same.

Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.
       10                       10 ------> NULL
      / \                       /      \
     3   5       =>     3 ------> 5 --------> NULL
    / \     \               /  \           \
   4   1   2          4 --> 1 -----> 2 -------> NULL

 

Example 1:

Input:
     3
   /  \
  1    2
Output:
3 1 2
1 3 2
Explanation:The connected tree is
        3 ------> NULL
     /    \
    1-----> 2 ------ NULL
Example 2:

Input:
      10
    /   \
   20   30
  /  \
 40  60
Output:
10 20 30 40 60
40 20 60 10 30
Explanation:The connected tree is
         10 ----------> NULL
       /     \
     20 ------> 30 -------> NULL
  /    \
 40 ----> 60 ----------> NULL
 
 link : https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/
 */

class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       if(!root) return;
       queue<Node*> q;
       q.push(root);
       while(!q.empty()){
           int size = q.size();
           
           
           for(int i=0;i<size;i++){
               root = q.front(); q.pop();
               
               if(i == size-1) root->nextRight = nullptr;
               else root->nextRight = q.front();
               
               
               if(root->left) q.push(root->left);
               if(root->right) q.push(root->right);
           }
       }
    }    
      
};
