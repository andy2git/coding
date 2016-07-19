class Solution {
    /*
     * @param k : description of k
     * @param nums : array of nums
     * @return: description of return
     */
    public int kthLargestElement(int k, int[] nums) {
        if(k <= 0 || nums.length < k) throw new IllegalArgumentException("xxx");
        
        return kthLargestElementHelper(nums, 0, nums.length-1, k);
    }
    
    private int kthLargestElementHelper(int[] A, int s, int e, int k){
        if(s > e) throw new IllegalArgumentException("xxx");
        
        int j = partation(A, s, e);
        int p = j-s+1;
        
        if(p == k) return A[j];
        else if(p > k) return kthLargestElementHelper(A, s, j-1, k);
        else return kthLargestElementHelper(A, j+1, e, k-p);
    }
    
    
    private int partation(int[] A, int s, int e){
        if(s > e) throw new IllegalArgumentException("xxx");
        int i = s;
        int j = e;
        int p = A[s];
        
        while(i <= j){
            if(A[i] >= p) i++;
            else swap(A, i, j--);
        }
        swap(A, s, j);
        
        return j;
    }
    
    private void swap(int[] A, int i, int j) {
        int t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
};
