// Link to the Problem: https://leetcode.com/problems/number-of-provinces/

// Approach:
// 1) To find the number of disconnected components, traverse inside of a sub graph using either bfs or dfs.
// 2) the number of traversal calls in a for loop determines the number of province via a counter variable.


void dfs(int node,vector<int> adj[],vector<int> &visited){           // Depth-First Search
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {            // Driver Function
        int m=isConnected.size(),n=isConnected[0].size();
        vector<int> visited(m,0);
        vector<int> adj[m];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int res=0;                                                   // Counter
        for(int i=0;i<m;i++){
            if(!visited[i]){
                dfs(i,adj,visited);
                res++;
            }
        }
        return res;
    }

// P.S: Evaluate constraints
