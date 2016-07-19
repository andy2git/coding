public class Solution {
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    public int median(int[] nums) {
        if(nums.length == 0) throw new IllegalArgumentException("xxx");
        if(nums.length == 1) return nums[0];
        
        int k = (nums.length+1)/2;
        return findKthElem(nums, 0, nums.length-1, k);
    }
    
    private int findKthElem(int[] A, int s, int e, int k){
        if(s > e) throw new IllegalArgumentException("xxx");
        
        int p = partation(A, s, e);
        int m = p-s+1;
        
        if(m == k) return A[p];
        else if(m < k) return findKthElem(A, p+1, e, k-m);
        else return findKthElem(A, s, p-1, k);
    }
    
    // [s, e]
    private int partation(int[] A, int s, int e){
        if(s > e) throw new IllegalArgumentException("xxxx");
        
        int p = A[s];
        int i = s+1;
        int j = e;
        
        while(i <= j){
            if(A[i] <= p) i++;
            else if(A[i] > p) swap(A, i, j--);
        }
        swap(A, s, j);
        return j;
    }
    
    private void swap(int[] A, int i, int j) {
        int t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
}
