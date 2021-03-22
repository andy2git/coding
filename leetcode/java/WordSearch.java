// Prefer this one, as it has better readability and same efficiency
class Solution {
    public boolean exist(char[][] board, String word) {
        if(board == null || board.length == 0) return false;
        
        int m = board.length;
        int n = board[0].length;
        boolean[][] v = new boolean[m][n];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(explore (board, i, j, word, 0, v)) return true;
            }
        }
        return false;
    }
    
    private boolean explore(char[][] A, int i, int j, String s, int k, boolean[][] v) {
        int m = A.length;
        int n = A[0].length;
        if(i < 0 || i >= m || j < 0 || j >= n) return false;
        
        if(A[i][j] != s.charAt(k) || v[i][j]) return false;
        if(k == s.length()-1) return true;
        v[i][j] = true;
        boolean result = explore(A, i-1, j, s, k+1, v)
            || explore(A, i+1, j, s, k+1, v)
            || explore(A, i, j-1, s, k+1, v)
            || explore(A, i, j+1, s, k+1, v);
        if(!result) v[i][j] = false;
        return result;
    }
}

class Solution {
    public boolean exist(char[][] board, String word) {
        if(board == null || board.length == 0) return false;
        if(word == null || word.length() == 0) return false;
        int m = board.length;
        int n = board[0].length;
        
        boolean[][] t = new boolean[m][n];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word.charAt(0)){ 
                    t[i][j] = true;
                    if(wsh(board, t, i, j, word, 0)) return true;
                    t[i][j] = false;
                }
            }
        }
        return false;
    }
    
    private boolean wsh(char[][] A, boolean[][] t, int i, int j, String w, int k) {
        if(k == w.length()-1) return true;
        
        int m = A.length;
        int n = A[0].length;
        int[][] cands = new int[][]{{i, j-1}, {i, j+1}, {i-1, j}, {i+1, j}};
        // It is not iterative, and it is active recursive. Just another way to write recursive
        // instead of write four directions
        for(int x = 0; x < cands.length; x++) {
            int p = cands[x][0];
            int q = cands[x][1];
            if(p >= 0 && p < m && q >= 0 && q < n){
                if(A[p][q] == w.charAt(k+1) && t[p][q] == false) {
                    t[p][q] = true;
                    if(wsh(A, t, p, q, w, k+1)) return true;
                    t[p][q] = false;
                }
            }
        }
        return false;
    }
}

