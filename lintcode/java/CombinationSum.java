public class Solution {
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        if(candidates == null || candidates.length == 0) return Collections.emptyList();
        
        Arrays.sort(candidates);
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> sofar = new ArrayList<>();
        
        combinataionSumHelper(result, sofar, candidates, 0, target);
        return result;
    }
    
    private void combinataionSumHelper(List<List<Integer>> result, List<Integer> sofar, int[] candidates, int ind, int target){
        int sum = sum(sofar);
        if(sum == target){
            result.add(new ArrayList<>(sofar));
            return;
        }
        if(sum > target || ind ==candidates.length) return;
        
        int num = candidates[ind];
        int cnt = 0;
        for(;sum <= target; sum+=num){
            if(cnt > 0) sofar.add(num);
            combinataionSumHelper(result, sofar, candidates, ind+1, target);
            cnt++;
        }

        while(cnt > 1){
            sofar.remove(sofar.size()-1);
            cnt--;
        }
    }
    
    private int sum(List<Integer> nums){
        int sum = 0;
        for(int x: nums) sum+=x;
        return sum;
    }
}
