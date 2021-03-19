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
        // flip the island into water if we can modify the original matrix
        grid[i][j] = false;
        
        explore(grid, i+1, j);
        explore(grid, i-1, j);
        explore(grid, i, j+1);
        explore(grid, i, j-1);
    }
}

// treat the problem as a DFS problem. 
// In tree DFS, you have root.left, and root.right. Here you have 4 directions, and you do not want visit the visited node again.
// Two ways to achive this. Use a Map or flip the '1' into '0'

// input is char[][] instead of boolean[][]
class Solution {
    public int numIslands(char[][] grid) {
        if(grid.length == 0) return 0;
        int m = grid.length;
        int n = grid[0].length;

        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    explore(grid, i, j);
                }
            }
        }
        return cnt;
    }

    private void explore(char[][] grid, int i, int j){
        int m = grid.length;
        int n = grid[0].length;

        if(i < 0 || i >=m || j < 0 || j>=n || grid[i][j] == '0') return;
        // flip the island into water if we can modify the original matrix
        grid[i][j] = '0';

        explore(grid, i+1, j);
        explore(grid, i-1, j);
        explore(grid, i, j+1);
        explore(grid, i, j-1);
    }
}

// DFS search using stack
class Solution {
    public int numIslands(char[][] A) {
        if (A == null || A[0].length == 0) return 0;
        int cnt = 0;
        int m = A.length;
        int n = A[0].length;
        boolean[][] v = new boolean[m][n];
        Deque<int[]> st = new ArrayDeque<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] == '1' && !v[i][j]) {
                    st.push(new int[]{i, j});
                    while (!st.isEmpty()) {
                        int[] x = st.pop();
                        v[x[0]][x[1]] = true;
                        for (int[] t : moves(x, v, A)) {
                            st.push(t);
                        }
                    }
                    cnt++;
                }
            }
        }
        return cnt;
    }

    private List<int[]> moves(int[] p, boolean[][] v, char[][] A) {
        int i = p[0];
        int j = p[1];
        int m = v.length;
        int n = v[0].length;

        List<int[]> result = new ArrayList<>();
        if (legitMove(A, v, i, j+1)) result.add(new int[]{i, j+1});
        if (legitMove(A, v, i, j-1)) result.add(new int[]{i, j-1});
        if (legitMove(A, v, i+1, j)) result.add(new int[]{i+1, j});
        if (legitMove(A, v, i-1, j)) result.add(new int[]{i-1, j});

        return result;
    }
    
    private boolean legitMove(char[][] A, boolean[][] v, int i, int j) {
        int m = A.length;
        int n = A[0].length;
        if(j >= n || i < 0 || i >= m || j < 0) return false;
        return A[i][j] == '1' && !v[i][j];
    }
}
