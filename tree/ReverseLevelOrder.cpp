/*
 *
 * Given a binary tree of size N, find its reverse level order traversal. ie- the traversal must begin from the last level.

Example 1:

Input :
        1
      /   \
     3     2

Output: 3 2 1
Explanation:
Traversing level 1 : 3 2
Traversing level 0 : 1
Example 2:

Input :
       10
      /  \
     20   30
    / \
   40  60

Output: 40 60 20 30 10
Explanation:
Traversing level 2 : 40 60
Traversing level 1 : 20 30
Traversing level 0 : 10


link of question : https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1#

*/

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    queue<Node *> q;
    vector<int> ans;

    q.push(root);

    while(!q.empty()){

        root = q.front();
        q.pop();

        if(root->right)
            q.push(root->right);

        if(root->left)
            q.push(root->left);

        ans.push_back(root->data);
    }

    reverse(ans.begin(),ans.end());

    return ans;
}
