class Solution {
    public int search(int[] nums, int target) {
        if(nums == null) throw new IllegalArgumentException("x");
        int s = 0;
        int e = nums.length-1;
        while(s <= e) {
            int m = s + (e-s)/2;
            if(target == nums[m]) return m;
            
            if(nums[m] > nums[e]) {
                if(target < nums[m] && target >= nums[s]) e = m-1;
                else s = m+1;
            } else {
                if(target > nums[m] && target <= nums[e]) s = m+1;
                else e = m-1;
            }
        }
        
        return -1;
    }
}

/* Solution#2 will not work 
 * [3, 1] target = 1 => will not work for the following code
 */
class Solution {
    public int search(int[] nums, int target) {
        if(nums == null) throw new IllegalArgumentException("x");
        int s = 0;
        int e = nums.length-1;
        while(s <= e) {
            int m = s + (e-s)/2;
            if(target == nums[m]) return m;
            
            if(nums[s] < nums[m]) {
                if(target < nums[m] && target >= nums[s]) e = m-1;
                else s = m+1;
            } else {
                if(target > nums[m] && target <= nums[e]) s = m+1;
                else e = m-1;
            }
        }
        
        return -1;
    }
}
