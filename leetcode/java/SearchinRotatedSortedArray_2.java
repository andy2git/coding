class Solution {
    public boolean search(int[] nums, int target) {
        if(nums == null) throw new IllegalArgumentException("x");
        int s = 0;
        int e = nums.length-1;
        while(s <= e) {
            int m = s + (e-s)/2;
            if(target == nums[m]) return true;

            if(nums[m] == nums[e]) {
                e--;
            } else if(nums[m] > nums[e]) {
                if(target == nums[s]) return true;
                if(target < nums[m] && target > nums[s]) e = m-1;
                else s = m+1;
            } else {
                if(target == nums[e]) return true;
                if(target > nums[m] && target < nums[e]) s = m+1;
                else e = m-1;
            }
        }

        return false;
    }
}
