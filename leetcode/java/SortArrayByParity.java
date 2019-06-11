class Solution {
    public int[] sortArrayByParity(int[] A) {
        if (A == null || A.length <= 1) return A;
        int i = 0;
        int j = A.length-1;
        while (i <= j) {
            if (isEven(A[i])) i++;
            else swap(A, i, j--);
        }
        return A;
    }
    
    
    private void swap(int[] A, int i, int j) {
        int t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
    
    private boolean isEven(int x) {
        return x % 2 == 0;
    }
}
