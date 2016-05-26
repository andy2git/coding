public class Solution {
    /**
     * @param nums: The rotated sorted array
     * @return: void
     */
    public void recoverRotatedSortedArray(List<Integer> nums) {
        if(nums == null || nums.size() <= 1) return;
        
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums.get(i) > nums.get(i+1)) {
                reverseCollection(nums, 0, i);    
                reverseCollection(nums, i+1, nums.size()-1);
                reverseCollection(nums, 0, nums.size()-1);
                return;
            }
        }
    }
    
    private <T> void reverseCollection(List<T> nums, int i, int j) {
        while(i < j) {
            T tmp = nums.get(i);
            nums.set(i, nums.get(j));
            nums.set(j, tmp);
            i++; j--;
        }
    }
}
