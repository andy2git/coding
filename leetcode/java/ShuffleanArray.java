class Solution {
    private int[] data;
    private int[] nums;
    private Random rand = new Random();

    public Solution(int[] nums) {
        data = Arrays.copyOf(nums, nums.length);
        this.nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        System.arraycopy(data, 0, nums, 0, nums.length);
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    public int[] shuffle() {
        for(int i = 1; i < nums.length; i++) {
            int k = rand.nextInt(i);
            int t = nums[k];
            nums[k] = nums[i];
            nums[i] = t;
        }
        return nums;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */
