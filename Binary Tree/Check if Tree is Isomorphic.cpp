/*
Given two Binary Trees. Check whether they are Isomorphic or not.

Input:
 T1    1     T2:   1
     /   \        /  \
    2     3      3    2
   /            /
  4            4
Output: No

Example 2:

Input:
T1    1     T2:    1
    /  \         /   \
   2    3       3     2
  /                    \
  4                     4
Output: Yes

link : https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/

*/

Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
        if(!root1 && !root2) return true;
        
        if(!root1 || !root2) return false;
        
        if(root1->data != root2->data) return false;
        
        return(
            (isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right)) ||
            (isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left))
            );
    }
};
