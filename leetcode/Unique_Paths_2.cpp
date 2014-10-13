class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = (int)obstacleGrid.size();
        int n = (int)obstacleGrid[0].size();
        
        vector<vector<int>> tbl(m, vector<int>(n, 0));
        
        // set the first row
        for(int j = 0; j < n; j++){
            if(obstacleGrid[0][j] == 0) tbl[0][j] = 1;
            else break;
        }
        
        // set the first col
        for(int i = 0; i < m; i++){
            if(obstacleGrid[i][0] == 0) tbl[i][0] = 1;
            else break;
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 1) tbl[i][j] = 0;
                else tbl[i][j] = tbl[i-1][j] + tbl[i][j-1];
            }
        }
        
        return tbl[m-1][n-1];
    }
};
