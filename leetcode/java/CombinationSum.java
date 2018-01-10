class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        if(candidates == null || candidates.length == 0) return Collections.emptyList();
        
        Arrays.sort(candidates);
        List<List<Integer>> result = new ArrayList<>();
        csh(result, new ArrayList<>(), 0, transform(candidates), 0, target);
        return result;
    }
    
    private void csh(List<List<Integer>> result, List<Integer> sofar, int sum, List<Integer> cands, int s, int t) {
        if(sum == t) {
            // make a copy
            result.add(new ArrayList<>(sofar));
            return;
        }
        
        if(s == cands.size()) return;
        
        int x = cands.get(s);
        
        int i = 0;
        while (sum + i*x <= t) {
            if(i > 0) sofar.add(x);
            csh(result, sofar, sum+i*x, cands, s+1, t);
            i++;
        }

        while(i > 1){
            sofar.remove(sofar.size()-1);
            i--;
        }
    }
    
    private List<Integer> transform(int[] arr){
        if(arr == null) return Collections.emptyList();
        
        List<Integer> result = new ArrayList<>();
        for(int x : arr) {
            result.add(x);
        }
        return result;
    }
}
