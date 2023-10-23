// Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/

// Approach:
// 1) Use Kahn's algorithm to find the topo sort of the graph.
// 2) If topo sort vector has the same size as that of the vertices, it is acyclic.
// 3) If the topo sort vector does not have the same size as that of the number of vertices, it is cyclic.

class Solution
{
	public:
	bool topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int indegree[V] = {0};
	    for(int i = 0; i < V;i++){
	        for(auto it: adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i = 0; i < V;i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    //vector<int> topo;   or
        int cnt = 0;
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        //topo.push_back(node); or
            cnt++;
	        
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
	    
        // if(topo.size() == V){
        //     return false;
        // }
        // return true;      or

        if(cnt == V){
            return false;
        }
        return true;
	    
	}
};