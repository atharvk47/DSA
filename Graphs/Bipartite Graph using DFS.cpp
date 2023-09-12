// Link: https://practice.geeksforgeeks.org/problems/bipartite-graph/

// Approach:
// 1) Traverse using DFS and color the adjacent nodes in a brute-force fashion.
// 2) If there comes a case in which above thing is not possible, return false.

class Solution {
public:

bool dfs(int node, int val, int color[],vector<int> adj[]){
    color[node] = val;
    
    for(auto it: adj[node]){
        if(color[it] == -1){
            if(dfs(it,!val,color,adj) == false){
                return false;
            }
        }else if(color[it] == color[node]){
            return false;
        }
    }
    
    return true;
}

bool isBipartite(int V,vector<int> adj[]){
    int color[V] ;
    for(int i = 0; i < V;i++){ color[i] = -1;}
    for(int i = 0; i < V;i++){
        if(color[i] == -1){
            if(dfs(i,0,color,adj)== false){
                return false;
            }
        }
    }
    return true;
}
};