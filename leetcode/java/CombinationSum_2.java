class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        if(candidates == null || candidates.length == 0) return Collections.emptyList();
        
        Arrays.sort(candidates);
        List<List<Integer>> result = new ArrayList<>();
        csh(result, new ArrayList<>(), 0, candidates, 0, target);
        return result;
    }
    
    
     private void csh(List<List<Integer>> result, List<Integer> sofar, int sum, int[] cands, int s, int t) {
        if(sum == t) {
            result.add(new ArrayList<>(sofar));
            return;
        }
        if(s == cands.length) return;

        int i = s;
        while(i < cands.length-1) {
            if(cands[i] != cands[i+1]) break;
            i++;
        }
        i++;

        int x = cands[s];
        int k = s;
        int count = 0;
        while(k <= i) {
            if(sum + (k-s)*x > t) break;
            if(k > s) {
                sofar.add(x);
                count++;
            }
            csh(result, sofar, sum+(k-s)*x, cands, i, t);
            k++;
        }

        while(count > 0) {
            sofar.remove(sofar.size()-1);
            count--;
        }
    }
}
