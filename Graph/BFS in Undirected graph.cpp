/*
 *
 *Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.

link : https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

*/

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        queue<int> q;
        vector<int> visited(V,0);
        q.push(0);
        visited[0] = 1;
        while(!q.empty()){
            int node = q.front(); q.pop();
            bfs.push_back(node);
            for( auto it : adj[node] ){
                if(!visited[it]){
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
        
        return bfs;
    }
};
