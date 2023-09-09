// Link to the Problem: https://leetcode.com/problems/flood-fill/

// Approach:
// 1) Find out the initial color of the starting co-ordinates.
// 2) Apply DFS/BFS in the four or eight directions to color its neighbours to the new color.
// 3) Return the updated matrix back.
// 4) Note try using an extra matrix instaed of updating the original matrix although it may add some space complexity but
// it's worthwhile in solving.

class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &ans, vector<vector<int>> &image, int color, int delRow[],int delCol[],int iniColor){
        int n = image.size();
        int m = image[0].size();

        ans[row][col] = color;

        for(int i = 0; i < 4;i++){                          // Needed for evaluating in 4 directions
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 &&ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != color){
                dfs(nrow,ncol,ans,image,color,delRow,delCol,iniColor);
            }
        }

        //for(int delRow = -1;delRow <= 1;delRow++){        // Needed for evaluating in 8 directions
        //         for(int delCol = -1;delCol <= 1;delCol++){
        //             int nrow = row1+delRow;
        //             int ncol = col1+delCol;
        //             if(nrow >= 0 && nrow < n && ncol>= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != color){
        //             dfs(nrow,ncol,ans,image,color,delRow,delCol,iniColor);
        //             }
        //         }
        //     }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        dfs(sr,sc,ans,image,color,delRow,delCol,iniColor);

        return ans;
    }
};