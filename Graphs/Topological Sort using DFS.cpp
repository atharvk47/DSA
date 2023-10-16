// Link: https://practice.geeksforgeeks.org/problems/topological-sort/

// Approach:
// 1) Simply apply dfs for every node. When visited, push it to the stack.
// 2) Pop out of the stack and pushback to the vector.

class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	void dfs(int node, int vis[], vector<int> adj[], stack<int> &st){
	    vis[node] = 1;
	    for(auto it: adj[node]){
	        if(!vis[it]){
	            dfs(it, vis, adj, st);
	        }
	    }
	    st.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int vis[V] = {0};
	    stack<int> st;
	    vector<int> ans;
	    for(int i = 0; i < V;i++){
	        if(!vis[i]){
	            dfs(i,vis, adj, st);
	        }
	    }
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	   
	}
};