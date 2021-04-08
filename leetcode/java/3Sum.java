public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        if (nums == null || nums.length < 3) return Collections.emptyList();

        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        int i = 0;
        int j = 0;
        int k = 0;
        int n = nums.length;
        while (i < n) {
            j = i + 1;
            k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    result.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    // advance j to the next non-dup j
                    // j < n-1 => j < k is more elegant, ask why?
                    while (j < k && nums[j+1] == nums[j]) j++;
                    j++;
                    // advance k to the next non-dup k
                    // k > 0 => j < k, the same as above
                    while (j < k && nums[k-1] == nums[k]) k--;
                    k--;
                } else if (sum < 0) j++;
                else k--;
            }
            while (i < n-1 && nums[i+1] == nums[i]) i++;
            i++;
        }

        return result;
    }
}

//  --------------------------------
//  i->   j->                    <-k
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        if(nums == null || nums.length <= 2) return Collections.emptyList();
        
        Arrays.sort(nums);
        int n = nums.length;
        List<List<Integer>> result = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    result.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    j++;
                    while(j < n && nums[j-1] == nums[j]) j++;
                    while(k-1>= 0 && nums[k] == nums[k-1]) k--;
                    k--;
                }else if (sum < 0) j++;
                else k--;
            }
        }
        return result;
    }
}

// Solution#2: think it as a+b = -c. It will become 2sum problem
// Since there are n possibilites for c, we will have n * time complexity of 2Sum
// O(n^2) will be the complexity if we take this approach, which is the same as Solution#1


