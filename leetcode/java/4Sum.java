public class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        // prefer emptyList() to RTE
        if (nums == null || nums.length < 4) return Collections.emptyList();

        int n = nums.length;
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();

        int i = 0;
        int j = 0;
        int p = 0;
        int q = 0;
        while (i < n) {
            while (i > 0 && i < n && nums[i] == nums[i - 1]) i++;
            j = i + 1;
            while (j < n) {
                while (j > i + 1 && j < n && nums[j] == nums[j - 1]) j++;
                p = j + 1;
                q = n - 1;
                while (p < q) {
                    int sum = nums[i] + nums[j] + nums[p] + nums[q];
                    if (sum == target) {
                        result.add(Arrays.asList(nums[i], nums[j], nums[p], nums[q]));
                        while (p < q && nums[p] == nums[p + 1]) p++;
                        p++;

                        while (p < q && nums[q] == nums[q - 1]) q--;
                        q--;
                    } else if (sum < target) {
                        p++;
                    } else {
                        q--;
                    }
                }
                // DO NOT FORGET TO UPDATE INDEX HERE
                j++;
            }
            // DO NOT FORGET TO UPDATE INDEX HERE
            i++;
        }
        return result;
    }
}
