public class Solution {
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    public int minPathSum(int[][] grid) {
        if(grid.length == 0) return 0;
        
        int m = grid.length;
        int n = grid[0].length;
        
        int[][] t = new int[m][n];
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) t[i][j] = grid[i][j];
                else if(i == 0 && j > 0) t[i][j] = t[i][j-1] + grid[i][j];
                else if(i > 0 && j == 0) t[i][j] = t[i-1][j] + grid[i][j];
                else t[i][j] = Math.min(t[i-1][j], t[i][j-1]) + grid[i][j];
            }
        }
        
        return t[m-1][n-1];
    }
}

