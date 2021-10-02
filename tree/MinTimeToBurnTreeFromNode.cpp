/*
 * 
 * Given a binary tree and a node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
 * 
 * link of question : https://practice.geeksforgeeks.org/problems/burning-tree/1
 */

class Solution {
  public:
    Node * findParent(Node *root,unordered_map<Node *,Node *> &parent_track,int target){
        queue<Node *> q;
        q.push(root);
        Node * temp;
        while(!q.empty()){
            root = q.front(); q.pop();
            if(root->data == target) temp = root;
            if(root->left){
                parent_track[root->left] = root;
                q.push(root->left);
            }
            if(root->right){
                parent_track[root->right] = root;
                q.push(root->right);
            }
        }
        return temp;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        if(!root) return 0;
        unordered_map<Node *,Node *> parent_track;
        Node *targetNode = findParent(root,parent_track,target);
        
        unordered_map<Node *,bool> visited;
        queue<Node *> q;
        int minTime = 0;
        q.push(targetNode);
        visited[targetNode] = true;
        while(!q.empty()){
            int size = q.size();
            int flag = 0;
            for(int i=0;i<size;i++){
                Node *curr = q.front();
                q.pop();
                
                if(curr->left && !visited[curr->left]){
                    visited[curr->left] = true;
                    q.push(curr->left);
                    flag = 1;
                }
                if(curr->right && !visited[curr->right]){
                    visited[curr->right] = true;
                    q.push(curr->right);
                    flag = 1;
                }
                if(parent_track[curr] && !visited[parent_track[curr]]){
                    visited[parent_track[curr]] = true;
                    q.push(parent_track[curr]);
                    flag = 1;
                }
            }
            if(flag == 1) minTime++;
        }
        return minTime;
    }
};
