class Solution {
    public void nextPermutation(int[] nums) {
        if(nums == null || nums.length == 0) return;
        
        int i = findBreakPoint(nums);
        Arrays.sort(nums, i, nums.length);
        if(i == 0) return;
        
        int x = findNextElem(nums, i, nums.length, nums[i-1]);
        swap(nums, i-1, x);
    }
    
    private int findBreakPoint(int[] nums){
        int i = nums.length-1;
        while (i > 0) {
            if(nums[i-1] >= nums[i]) i--;
            else break;
        }
        return i;
    }
    
    private int findNextElem(int[] nums, int s, int e, int t){
        if(s > e) return -1;
        int m = s + (e - s)/2;
        if(t >= nums[m]) return findNextElem(nums, m+1, e, t);
        else {
            int x = findNextElem(nums, s, m-1, t) ;
            if (x == -1) return m;
            else return x;
        }
    }
    
    private void swap(int[] nums, int i, int j){
        int x = nums[i];
        nums[i] = nums[j];
        nums[j] = x;
    }
}
