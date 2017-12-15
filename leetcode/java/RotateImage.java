class Solution {
    public void rotate(int[][] A) {
        if(A == null) throw new IllegalArgumentException("xx");
        if(A.length == 0) return;
        int n = A.length;
        // double check to make sure A is of size n x n 

        // switch rows
        for(int i = 0; i < n/2; i++) {
            swapRow(A, i, n-i-1);
        }    
        // switch diagonally
        swapDiagonally(A);
    }
    
    private void swapRow(int[][] A, int i, int j) {
        int n = A.length;
        for(int k = 0; k < n; k++){
            int t = A[i][k];
            A[i][k] = A[j][k];
            A[j][k] = t;
        }
    }
    
    private void swapDiagonally(int[][] A) {
        int n = A.length;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int t = A[i][j];
                A[i][j] = A[j][i];
                A[j][i] = t;
            }    
        }
    }
    
}
