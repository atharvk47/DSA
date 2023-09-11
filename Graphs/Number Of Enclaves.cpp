// Link to the problem: https://leetcode.com/problems/number-of-enclaves/

// Approach:
// 1) Look for the boundary 1s and mark them 1 in the auxilliary visited vector.
// 2) Traverse these boundary 1s to find the cluster or the group of 1s and mark them visited respectively.
// 3) Run a for loop in the visited matrix and count the number of 0s in it which are 1 in the original matrix. 
// Those are the number of enclaves.


class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int> (m,0));
        //int i,j,k;
        int k;
        for(k = 0;k < n;k++){
          if(grid[k][0] == 1){
              vis[k][0] = 1;
              q.push({k,0});
          }
          if(grid[k][m-1] == 1){
              vis[k][m-1] = 1;
              q.push({k,m-1});
          }
        }
        //j = n-1;
        for(k = 0;k < m;k++){
          if(grid[0][k] == 1){
              vis[0][k] = 1;
              q.push({0,k});
          }
          if(grid[n-1][k] == 1){
              vis[n-1][k] = 1;
              q.push({n-1,k});
          }
        }

        
            int delRow[] = {-1,0,1,0};
            int delCol[] = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();


            for(int a = 0;a < 4;a++){
                int nrow = r + delRow[a];
                int ncol = c + delCol[a];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            } 
        }
        int ans = 0;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    ans++;
                }
            }
        }
        return ans;

    }
};