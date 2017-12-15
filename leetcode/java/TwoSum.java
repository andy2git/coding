public class Solution {
     public int[] twoSum(int[] nums, int target) {
        if (nums == null || nums.length < 2) throw new IllegalArgumentException("xx");
        Map<Integer, Integer> indMap = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int x = target - nums[i];
            if (indMap.containsKey(x)) {
                return new int[]{indMap.get(x), i};
            } else {
                indMap.put(nums[i], i);
            }
        }

        // return result depends on the requirement
        return new int[]{-1, -1};
    }
}
