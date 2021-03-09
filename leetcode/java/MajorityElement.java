class Solution {
    public int majorityElement(int[] nums) {
        if(nums == null || nums.length == 0) throw new IllegalArgumentException("x");
        int elem = nums[0];
        int cnt = 1;
        for(int i = 1; i < nums.length; i++) {
            if(elem == nums[i]) cnt++;
            else{
                if(cnt > 0) cnt--;
                else {
                    elem = nums[i];
                    cnt++;
                }
            }
        }
        return elem;
    }
}
