// Link To The Problem: https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/

// This is a really good problem on graphs.

// Approach:
// 1) Run dfs over the island part and store the island coordinates in a set such that the same co-ordinates 
// in the same directions remain identical.

class Solution {
  public:
  
    void dfs(int row,int col, vector<pair<int,int>> &vec, vector<vector<int>> &grid, vector<vector<int>> &vis, int row0, int col0){
        int n = grid.size();
        int m = grid[0].size();
        
        vis[row][col] = 1;
        vec.push_back({row - row0,col - col0});
        
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,-1,0,1};
        
        for(int  i =0; i < 4;i++){
            int nrow = row+delRow[i];
            int ncol = col +delCol[i];
            
            if(nrow>= 0 && nrow< n && ncol  >=  0 &&ncol < m &&!vis[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow,ncol,vec,grid,vis,row0,col0);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        set<vector<pair<int,int>>> st;
        
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>> vec;
                    dfs(i,j,vec,grid,vis,i,j);
                    st.insert(vec);
                }
            }
        }
        
        return st.size();
    }
};