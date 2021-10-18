/*
 *
 *Given a Binary Search Tree and a node value X, find if node with value X is present in the BST or not. 
 *
 *time =o(log n)
 *
 *link = https://practice.geeksforgeeks.org/problems/search-a-node-in-bst/1
 *
 */ 

// Function to search a node in BST.
bool search(Node* root, int x) {
    // Your code here
    if(!root) return false;
    if(root->data == x) return true;
    if(x < root->data) return search(root->left,x);
    return search(root->right,x);
}
