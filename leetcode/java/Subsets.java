class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        if(nums == null || nums.length == 0) return Collections.emptyList();
        List<List<Integer>> result = new ArrayList<>();
        subsetHelper(result, new ArrayList<>(), nums, 0);
        return result;
    }
    
    private void subsetHelper(List<List<Integer>> result, List<Integer> sofar, int[] nums, int s) {
        if(s == nums.length) {
            result.add(new ArrayList<>(sofar));
            return;
        }
        
        int x = nums[s];
        subsetHelper(result, sofar, nums, s+1);
        sofar.add(x);
        subsetHelper(result, sofar, nums, s+1);
        sofar.remove(sofar.size()-1);
    }
}

// another approach.
// understand the subtle difference 
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        if(nums == null || nums.length == 0) return Collections.emptyList();
        List<List<Integer>> result = new ArrayList<>();
        subsetHelper(result, new ArrayList<>(), nums, 0);
        return result;
    }
    
    private void subsetHelper(List<List<Integer>> result, List<Integer> sofar, int[] nums, int s) {
        if(s == nums.length) {
            result.add(new ArrayList<>(sofar));
            return;
        }
        
        int x = nums[s];
        sofar.add(x);
        subsetHelper(result, sofar, nums, s+1);
        sofar.remove(sofar.size()-1);
        subsetHelper(result, sofar, nums, s+1);       
    }
}
