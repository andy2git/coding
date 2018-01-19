class Solution {
    public int findDuplicate(int[] nums) {
        if(nums == null) throw new IllegalArgumentException("x");
        
        int l = 1;
        int h = nums.length-1;
        while(l < h) {
            int m = l + (h-l)/2;
            int cnt = 0;
            for(int x : nums) {
                if(x <= m) cnt++;
            }
            if(cnt <= m) l = m+1;
            else h = m;
        }
        return l;
    }
}
