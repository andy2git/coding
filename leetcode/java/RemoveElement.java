class Solution {
    public int removeElement(int[] nums, int val) {
        if(nums == null) throw new IllegalArgumentException("x");
        int i = 0;
        int j = 0;
        while(j < nums.length){
            if(nums[j] == val) j++;
            else nums[i++] = nums[j++];
        }
        return i;
    }
}
