// also check the coin change problem

[1, 2, 3, 6, 7] target = 7
// backtracking like we do coin change problem
//             cs(7)
               1    2    3   6   7   <-- this branch will use all elems instead of all combinations of one specific elem
//            cs(6)
              1
//          cs(5)

// Another to way to backtracking
//             cs(7)
         0*1     1*1    2*1    3*1  <-- this branch will use all the possible combinations of 1
//     cs(7)     cs(6)
        0*2      0*2                <-- use all combinations of 2
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
