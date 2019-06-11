class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        if(A == null || A.length == 0) return A;
        for(int[] x : A) {
            flipAndInvert(x);
        }
        return A;
    }
    
    private void flipAndInvert(int[] A) {
        int i = 0; 
        int j = A.length-1;
        
        while(i <= j) {
            swap(A, i++, j--);
        }
    }
    
    private void swap(int[] A, int i, int j) {
        int t = reverse(A[i]);
        A[i] = reverse(A[j]);
        A[j] = t;
    }
    
    private int reverse(int x) {
        if(x == 0) return 1;
        else return 0;
    }
}
