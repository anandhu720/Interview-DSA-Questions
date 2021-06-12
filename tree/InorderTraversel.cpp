/*
 *
 * Given a binary tree, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.


Example 1:

Input:
    1
  /   \
 3     2
Output:1 3 2
Example 2:

Input:
        10
     /      \
    20       30
  /   \
 40   60
Output:10 20 30 40 60 N N

link of question :https://practice.geeksforgeeks.org/problems/level-order-traversal/1

*/


class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int> ans;
      queue<Node *> q;

      q.push(node);
      ans.push_back(node->data);

      while(!q.empty()){
          node = q.front();
          q.pop();

          if(node->left){
              q.push(node->left);
              ans.push_back(node->left->data);
          }

          if(node->right){
            q.push(node->right);
            ans.push_back(node->right->data);
          }
      }

      return ans;
    }
};

