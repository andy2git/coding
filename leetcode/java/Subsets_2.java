class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        if(nums == null || nums.length == 0) return Collections.emptyList();
        
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        sdh(result, new ArrayList<>(), nums, 0);
        return result;
    }
    
    private void sdh(List<List<Integer>> result, List<Integer> sofar, int[] nums, int s) {
        if(s == nums.length) {
            result.add(new ArrayList<>(sofar));
            return;
        }
        
        int e = s;
        while(e < nums.length-1) {
            if(nums[e] == nums[e+1]) e++;
            else break;
        }
        e++;
        
        sdh(result, sofar, nums, e);
        
        int i = s;
        int x = nums[s];
        while(i < e) {
            sofar.add(x);
            sdh(result, sofar, nums, e);
            i++;
        }
        
        while(i > s) {
            sofar.remove(sofar.size()-1);
            i--;
        }
    }
}
