class Solution {
    public List<List<Integer>> combine(int n, int k) {
        if(k <= 0) return Collections.emptyList();
        List<List<Integer>> result = new ArrayList<>();
        ch(result, new ArrayList<>(), 1, k, n);
        return result;
    }
    
    private void ch(List<List<Integer>> result, List<Integer> sofar, int s, int k, int n) {
        if(sofar.size() == k) {
            result.add(new ArrayList<>(sofar));
            return;
        }
        
        for(int i = s; i <= n ; i++){
            sofar.add(i);
            ch(result, sofar, i+1, k, n);
            sofar.remove(sofar.size()-1);
        }
    }
}
