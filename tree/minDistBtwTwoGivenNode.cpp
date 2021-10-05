/*
 * Given a binary tree and two node values your task is to find the minimum distance between them.
 * 
 * link : https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1#
 */

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node * lca(Node *root,int p,int q){
        if(!root || root->data == p || root->data == q) return root;
        
        Node* left = lca(root->left,p,q);
        Node* right = lca(root->right,p,q);
        
        if(!left) return right;
        else if(!right) return left;
        else return root;
    }
    
    int findNodeDistance(Node* root,int key,int length=0){
        if(root == NULL) return -1;
        if(root->data == key) return length;
        
        int left = findNodeDistance(root->left,key,length+1);
        if(left == -1)
            return findNodeDistance(root->right,key,length+1);
        return left;
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* head = lca(root,a,b);
        
        int d1 = findNodeDistance(head,a);
        int d2 = findNodeDistance(head,b);
        
        return d1+d2;
    }
};
