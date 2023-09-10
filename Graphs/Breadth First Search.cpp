// Link to the solution: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/

// Approach:
// 1) Take a visited array of the size equal to the number of vertices in the graph.
// 2) Take a queue and put the starting node into it.
// 3) Run a while loop till the queue is empty where the top node is popped and its neighbours are maked visited and explored further.
// 4) Always put the popped node into the solution vector.

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> sol;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            sol.push_back(node);
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        
        return sol;
    }
};