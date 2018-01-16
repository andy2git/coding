class Solution {
    public int missingNumber(int[] nums) {
        if(nums == null) throw new IllegalArgumentException("x");
        
        int l = 0;
        int h = nums.length;
        while(l < h) {
            int m = l + (h-l)/2;
            int cnt = 0;
            for(int x : nums) {
                if(x <= m) cnt++;
            }
            if(cnt < m+1) h = m;
            else l = m+1;
        }
        return l;
    }
}
