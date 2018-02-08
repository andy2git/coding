class Solution {
    public int findKthLargest(int[] nums, int k) {
        if(nums == null || nums.length == 0) throw new IllegalArgumentException("xx");
        return flh(nums, 0, nums.length-1, k);
        
    }

    public int flh(int[] A, int s, int e, int k) {
        // solution can always be found, so it will never hit here
        if(s > e) throw new IllegalArgumentException("xx");
            
        int p = partation(A, s, e);
        int r = p-s+1;
        if(r == k) return A[p];
        else if (k < r) return flh(A, s, p-1, k);
        else return flh(A, p+1, e, k-r);
    }
    
    private int partation(int[] A, int s, int e) {
        int i = s;
        int j = s;
        while(j <= e) {
            if(A[j] >= A[s]) swap(A, i++, j++);
            else j++;
        }
        swap(A, s, i-1);
        return i-1;
    }
    
    private void swap(int[] A, int i, int j) {
        int t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
}
