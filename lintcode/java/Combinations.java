public class Solution {
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    public List<List<Integer>> combine(int n, int k) {
        if(k > n) throw new IllegalArgumentException("xxx");
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> sofar = new ArrayList<>();
        
        combineHelper(result, sofar, 1, n, k);
        return result;
    }
    
    private void combineHelper(List<List<Integer>> result, List<Integer> sofar, int s, int e, int k){
        if(sofar.size() == k){
            result.add(new ArrayList<>(sofar));
            return;
        }
        
        for(int i = s; i <= e; i++){
            sofar.add(i);
            combineHelper(result, sofar, i+1, e, k);
            sofar.remove(sofar.size()-1);
        }
    }
}
