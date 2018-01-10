class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        if(nums == null) throw new IllegalArgumentException("x");
        if(nums.length == 0) return Collections.emptyList();
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        puh(result, new ArrayList<>(), Arrays.stream(nums).boxed().collect(Collectors.toList()));
        return result;
    }
    
    private void puh(List<List<Integer>> result, List<Integer> sofar, List<Integer> cands) {
        if(cands.isEmpty()) {
            result.add(new ArrayList<>(sofar));
            return;
        }
        
        for(int i = 0; i < cands.size(); i++){
            if(i > 0 && cands.get(i).equals(cands.get(i-1))) continue;
            Integer x = cands.get(i); 
            sofar.add(x);
            List<Integer> left = new ArrayList<>(cands);
            left.remove(x);
            puh(result, sofar, left);
            sofar.remove(sofar.size()-1);
        }
    }
}
