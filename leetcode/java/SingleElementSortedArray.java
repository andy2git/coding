class Solution {
    public int singleNonDuplicate(int[] A) {
        if(A == null || A.length < 3) throw new IllegalArgumentException("xx");
        for(int i  =0; i < A.length-1; i+=2) {
            if(A[i] != A[i+1]) return A[i];
        }
        // the last one is odd
        return A[A.length-1];
    }
}
