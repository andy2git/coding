class Solution {
    public void sortColors(int[] nums) {
        if(nums == null || nums.length <= 1) return;
        int i = 0;
        int j = 0;
        int k = nums.length-1;
        while(j <= k) {
            if(nums[j] == 1) j++;
            else if(nums[j] < 1) swap(nums, j++, i++);
            else swap(nums, j, k--);
        }
    }
    
    private void swap(int[] A, int i, int j) {
        int x = A[i];
        A[i] = A[j];
        A[j] = x;
    }
}
