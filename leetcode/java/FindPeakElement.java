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

// Solution#3
class Solution {
    public int findPeakElement(int[] nums) {
        if(nums == null || nums.length == 0) throw new IllegalArgumentException("x");
        
        int l = 0;
        int h = nums.length-1;
        int m;
        while(l <= h) {
            m = (l+h)/2;
            // We will have at least one peak in the provided array.
            // if only one elem is left, this should be the answer.
            if(less(nums, m-1, m) && less(nums, m+1, m)) return m;
            // nums[m+1] is guaranteed to be a valid elem
            if(nums[m] < nums[m+1]) l = m+1;
            else h = m;
        }

        // this should not happen, it is added to compile the code
        return -1;
    }
    
    private boolean less(int[] A, int i, int j) {
        if(i < 0 || i > A.length-1) return true;
        return A[i] < A[j];
    }
}
