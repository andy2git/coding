
class Solution {
    public int[][] updateMatrix(int[][] A) {
        if(A == null || A.length == 0) return A;
        
        int m = A.length;
        int n = A[0].length;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(A[i][j] == 0) {}
                else {
                    if(hasZero(A, i, j)) A[i][j] = 1;
                    else A[i][j] = Math.min(lv(A,i,j-1), lv(A,i-1,j))+1;
                }
            }
        }
        
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(A[i][j] == 0) {}
                else {
                    if(hasZero(A, i, j)) A[i][j] = 1;
                    else A[i][j] = Math.min(A[i][j], Math.min(lv(A,i,j+1), lv(A,i+1,j))+1);
                }
            }
        }
        
        return A;
    }

    private int lv(int[][] A, int i, int j) {
        if(i < 0 || i >= A.length) return 10000;
        if(j < 0 || j >= A[0].length) return 10000;
        return A[i][j];
    }
        
        
    private boolean hasZero(int[][]A, int i, int j) {
        if (lm(A, i, j-1) ||  lm(A, i-1, j) || lm(A, i, j+1) || lm(A, i+1, j)) return true;
        return false;
    }
    
    private boolean lm(int[][] A, int i, int j) {
        if(i < 0 || i >= A.length) return false;
        if(j < 0 || j >= A[0].length) return false;
        if(A[i][j] == 0) return true;
        return false;
    }
}


// Approach #2: improved version
class Solution {
    public int[][] updateMatrix(int[][] A) {
        if(A == null || A.length == 0) return A;
        
        int m = A.length;
        int n = A[0].length;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(A[i][j] == 0) {}
                else {
                    A[i][j] = Math.min(lv(A,i,j-1), lv(A,i-1,j))+1;
                }
            }
        }
        
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(A[i][j] == 0) {}
                else {
                    A[i][j] = Math.min(A[i][j], Math.min(lv(A,i,j+1), lv(A,i+1,j))+1);
                }
            }
        }
        
        return A;
    }

    private int lv(int[][] A, int i, int j) {
        if(i < 0 || i >= A.length) return 10000;
        if(j < 0 || j >= A[0].length) return 10000;
        return A[i][j];
    }
}
