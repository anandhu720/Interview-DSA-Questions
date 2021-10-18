/*
 * Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree
 */
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(!root) return ans;
        map<int,int> nodes; //node data and vertical line 
        queue<pair<Node *,int>> todo; //node and vertical line
        todo.push({root,0});
        while(!todo.empty()){
            auto it = todo.front();
            todo.pop();
            root = it.first;
            int line = it.second;
            if(nodes.find(line) == nodes.end()) nodes[line] = root->data;
            
            if(root->left)
                todo.push({root->left,line-1});
            if(root->right)
                todo.push({root->right,line+1});
        }
        for(auto i : nodes)
            ans.push_back(i.second);
        
        return ans;
    }

};
