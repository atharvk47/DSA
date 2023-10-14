// Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/

// Approach:
// 1) Create A visited array and a path visited array and mark them both visited if going on the same path.
//   Once the path terminates, unmark the path visited array but not visited array.

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int node, vector<int> adj[], int vis[], int pathVis[]){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis, pathVis) == true)return true;
            }else if(pathVis[it] == 1){
                return true;
            }
        }
        
        pathVis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        int pathVis[V] = {0};
        
        for(int i = 0; i < V;i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis) == true) return true;
            }
        }
        
        return false;
    }
};