public class Solution {
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    public int longestIncreasingContinuousSubsequence(int[] A) {
        if(A.length == 0) return 0;
        
        int l = LICSHelper(A);
        reverse(A);
        int r = LICSHelper(A);

        return Math.max(l, r);
    }
    
    private int LICSHelper(int[] A){
        int n = A.length;
        // t[i]: LIS ending with A[i]
        int[] t = new int[n];
        t[0] = 1;

        int maxLen = 1;
        for(int i = 1; i < n; i++){
            if(A[i] >= A[i-1]) t[i] = t[i-1]+1;
            else t[i] = 1;
            
            if(t[i] > maxLen) maxLen = t[i];
        }
        return maxLen;
    }
    
    private void reverse(int[] A){
        int i = 0;
        int j = A.length-1;
        while(i < j){
            swap(A, i++, j--);
        }
    }
    
    private void swap(int[] A, int i, int j){
        int t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
}
