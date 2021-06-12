/*
 *
 * Given a binary tree, find its height.


Example 1:

Input:
     1
    /  \
   2    3
Output: 2
Example 2:

Input:
  2
   \
    1
   /
 3
Output: 3

link of question:https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1#
*/

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here
        int x=0,y=0;

        if(node==0){
            return 0;
        }

        x=height(node->left);
        y=height(node->right);

        return (x>y)?x+1:y+1;
    }
};

