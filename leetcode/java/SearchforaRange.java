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
            int m = (h+l)/2;
            if (A[m] < t) l = m+1;
            else {
                if(A[m]==t) lp = m;
                h = m-1;
            }
        }
        return lp;
    }
    
    private int upperBound(int[] A, int t) {
        int l = 0;
        int h = A.length-1;
        int up = -1;
        while (l <= h) {
            int m = (l + h)/2;
            if (A[m] > t) h = m-1;
            else {
                if(A[m] == t) up = m;
                l = m+1;
            }
        }
        return up;
    }
}


class Solution {
    public int[] searchRange(int[] nums, int target) {
        if(nums == null || nums.length == 0) return new int[]{-1, -1};
        return new int[]{lb(nums, target), ub(nums, target)};
    }
    
    private int lb(int[] A, int t) {
        int l = 0;
        int h = A.length-1;
        while(l < h){
            int m = (l+h)/2;
            if(A[m] < t) l = m+1;
            else h = m;
        }
        if(A[l] == t) return l;
        else return -1;
    }
    
    private int ub(int[] A, int t) {
        int l = 0;
        int h = A.length-1;
        int cand = -1;
        while(l <= h){
            int m = (l+h)/2;
            if(A[m] > t) h = m-1;
            else{
                if(A[m] == t) cand = m;
                l = m+1;
            }
        }
        return cand;
    }
}
