class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums == null) throw new IllegalArgumentException("x");
        int i = 0;
        int j = i+1;
        while(j < nums.length) {
            if(nums[i] == nums[j]) j++;
            else nums[++i] = nums[j++];
        }
        return i+1;
    }
}
