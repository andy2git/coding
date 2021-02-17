// More concise version
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        if(candidates == null || candidates.length == 0) return Collections.emptyList();

        List<List<Integer>> result = new ArrayList<>();
        csh(result, new ArrayList<>(), candidates, 0, target);
        return result;
    }
    
    private void csh(List<List<Integer>> result, List<Integer> sofar, int[] nums, int d, int t){
        int sum = sofar.stream().reduce(0, Integer::sum);
        if (sum == t) {
            result.add(new ArrayList<>(sofar));
            return;
        }
        if (d == nums.length) return;
        
        int cnt = 0;
        while(sum + cnt*nums[d] <= t) {
            csh(result, sofar, nums, d+1, t);
            sofar.add(nums[d]);
            cnt++;
        }
        for(int i = 0; i < cnt; i++) sofar.remove(sofar.size()-1);
    }
}
