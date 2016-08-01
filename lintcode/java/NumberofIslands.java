/* numIslands problem is different from the word search in matrix problem
 * where you need to reset the cells which are marked */
public class Solution {
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    public int numIslands(boolean[][] grid) {
        if(grid.length == 0) return 0;
        int m = grid.length;
        int n = grid[0].length;
        
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    cnt++;
                    explore(grid, i, j);
                }
            }
        }
        return cnt;
    }
    
    private void explore(boolean[][] grid, int i, int j){
        int m = grid.length;
        int n = grid[0].length;
        
        if(i < 0 || i >=m || j < 0 || j>=n || !grid[i][j]) return;
        grid[i][j] = false;
        
        explore(grid, i+1, j);
        explore(grid, i-1, j);
        explore(grid, i, j+1);
        explore(grid, i, j-1);
    }
}
