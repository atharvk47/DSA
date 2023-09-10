// Link to the problem: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/

// Approach:
// 1) Create a visited array of the size equal to the number of nodes present in the graph.
// 2) Call a recursive function dfs which visits all the possible degrees of the given nodes.
// 3) Mark the nodes explored as visited and print them.

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node, vector<int> adj[],vector<int> &ls,int vis[]){
        vis[node] = 1;
        ls.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,ls,vis);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        vector<int> ls;
        dfs(0,adj,ls,vis);
        return ls;
    }
};