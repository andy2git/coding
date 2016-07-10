class Solution {
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    public int findPeak(int[] A) {
        if(A.length <= 2) return -1;
        
        int s = 1;
        int e = A.length -2;
        while(s <= e){
            int m = s +(e-s)/2;
            if(A[m] > A[m-1] && A[m] > A[m+1]){
                return m;
            }else if (A[m] <= A[m-1]){
                e = m-1;
            }else {
                s = m+1;
            }
        }
        
        return -1;
    }
}

