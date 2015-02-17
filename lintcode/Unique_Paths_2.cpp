class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        if(obstacleGrid.empty()) return 0;
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> t(m, vector<int>(n, 1));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1) t[i][j] = 0;
                else{
                    if(i == 0 && j > 0) t[i][j] = t[i][j-1];
                    else if(j == 0 && i > 0) t[i][j] = t[i-1][j];
                    else if(i > 0 && j > 0){
                        t[i][j] = t[i-1][j] + t[i][j-1];
                    }
                }
            }
        }
        
        return t[m-1][n-1];
    }
};
