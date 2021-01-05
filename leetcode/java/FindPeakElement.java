// Solution #1
class Solution {
    public int findPeakElement(int[] nums) {
        if(nums == null ||  nums.length == 0) throw new IllegalArgumentException("x");
        for (int i = 0; i < nums.length-1; i++) {
            if(nums[i] > nums[i+1]) return i;
        }
        return nums.length-1;
    }
}

// Solution #2
class Solution {
    public int findPeakElement(int[] nums) {
        if(nums == null ||  nums.length == 0) throw new IllegalArgumentException("x");
        int s = 0;
        int e = nums.length-1;
        while(s < e) {
            int m = (s+e)/2;
            if(nums[m] < nums[m+1]) s = m+1;
            else e = m;
        }
        return s;
    }
}
