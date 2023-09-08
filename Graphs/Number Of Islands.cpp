// Link to the Problem: https://leetcode.com/problems/number-of-islands/

// Approach:
// 1) Traverse the land region in the grid. If neighbours exist, add them into the queue.
// 2) The number of BFS traversal is the count of total number of islands.

class Solution {
public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;

        queue<pair<int,int>> q;
        q.push({row,col});

        while(!q.empty()){
            int row1 = q.front().first;
            int col1 = q.front().second;
            q.pop();

            // int delRow[] = {-1,0,1,0};            // Needed for evaluating neighbours in 4 directions
            // int delCol[] = {0,1,0,-1};
            // for(int i = 0; i < 4;i++){
            //     int nrow = row1 + delRow[i];
            //     int ncol = col1 + delCol[i];
            //     if(nrow >= 0 && nrow < n && ncol>= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
            //              vis[nrow][ncol] = 1;
            //              q.push({nrow,ncol});
            //          }
            // }

            
             for(int delRow = -1;delRow <= 1;delRow++){        // Needed for evaluating in 8 directions
                 for(int delCol = -1;delCol <= 1;delCol++){
                     int nrow = row1+delRow;
                     int ncol = col1+delCol;
                     if(nrow >= 0 && nrow < n && ncol>= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                         vis[nrow][ncol] = 1;
                         q.push({nrow,ncol});
                     }
                 }
             }

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m,0));
        int cnt = 0;

        for(int row = 0; row < n;row++){
            for(int col = 0; col < m;col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }

        return cnt;
    }
};