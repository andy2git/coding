public class Solution {
    /**
     * @param nums: a list of integers
     * @return: find a  majority number
     */
    public int majorityNumber(List<Integer> nums) {
        if(nums == null || nums.isEmpty()) {
            throw new IllegalArgumentException("xxx");
        }
        
        int num = 0;
        int count = 0;
        for(int x : nums) {
            if(count == 0) {
                num = x;
                count++;
                continue;
            }
            
            if(x == num) count++;
            else count--;
        }
        
        return num;
    }
}
