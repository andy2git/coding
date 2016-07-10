public class Solution {
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    public int findMin(int[] A) {
        if(A.length <= 0) throw new IllegalArgumentException("xxx");
        
        int l = 0;
        int h = A.length-1;
        int m;
        
        while(l <= h){
            if(l == h) {
                return A[l];
            }
            m = l + (h-l)/2;
            if(A[m] < A[h]){
                h = m;
            } else {
                l = m+1;
            }
        }
        
        throw new RuntimeException("should not be there");
    }
}
