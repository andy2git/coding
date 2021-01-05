// think the problem as squeeze the bubble 0 instead of the partition problem
class Solution {
    public void moveZeroes(int[] nums) {
        if(nums == null || nums.length <= 1) return;
        int i = 0;
        int j = 0;
        while(j < nums.length) {
            if(nums[j] == 0) j++;
            else swap(nums, i++, j++);
        }
    }
    
    private void swap(int[] A, int i, int j) {
        int t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
}
