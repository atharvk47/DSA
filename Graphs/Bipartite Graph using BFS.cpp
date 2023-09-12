// Link: https://practice.geeksforgeeks.org/problems/bipartite-graph/

// Approach:
// 1) Traverse using BFS and color the adjacent nodes in a brute-force fashion.
// 2) If there comes a case in which above thing is not possible, return false.


class Solution {
public:

bool check(int start,int V,vector<int> adj[],int color[]){
    queue<int> q;
    q.push(start);
    color[start] = 0;
    while(!q.empty()){
       int node = q.front();
       q.pop();

       for(auto it: adj[node]){
           if(color[it] == -1){
            color[it] = !color[node];
            q.push(it);
           }else if(color[it] == color[node]){
            return false;
           }
       }
    }

    return true;
}

bool isBipartite(int V,vector<int> adj[]){
    int color[V] ;
    for(int i = 0; i < V;i++){ color[i] = -1;}
    for(int i = 0; i < V;i++){
        if(color[i] == -1){
            if(check(i,V,adj,color) == false){
                return false;
            }
        }
    }
    return true;
}
};
