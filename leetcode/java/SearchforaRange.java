class Solution {
    public int[] searchRange(int[] nums, int target) {
        if (nums == null) throw new IllegalArgumentException("x");
        if (nums.length == 0) return new int[] {-1, -1};
        return new int[] {lowerBound(nums, target), upperBound(nums, target)};
    }
    
    private int lowerBound(int[] A, int t) {
        int l = 0;
        int h = A.length-1;
        int lp = -1;
        while (l <= h) {
            int m = l + (h-l)/2;
            if(A[m] == t) {
                lp = m;
                h = m-1;
            }
            else if (A[m] > t) h = m-1;
            else l = m+1;
        }
        return lp;
    }
    
    private int upperBound(int[] A, int t) {
        int l = 0;
        int h = A.length-1;
        int up = -1;
        while (l <= h) {
            int m = l + (h-l)/2;
            if(A[m] == t) {
                up = m;
                l = m+1;
            }
            else if (A[m] > t) h = m-1;
            else l = m+1;
        }
        return up;
    }
}
