class Solution {
    public List<List<Integer>> permute(int[] nums) {
        if(nums == null) throw new IllegalArgumentException("x");
        if(nums.length == 0) return Collections.emptyList();
        
        List<List<Integer>> result = new ArrayList<>();
        // use Guava Ints.asList(int[] arr)
        // The reason why Arrays.asList() does not work is because of the type is List<Int[]>
        ph(result, new ArrayList<>(), Arrays.stream(nums).boxed().collect(Collectors.toList()));
        return result;
    }
    
    private void ph(List<List<Integer>> result, List<Integer> sofar, List<Integer> cands) {
        if(cands.isEmpty()) {
            // need to make a deep copy here.
            result.add(new ArrayList<>(sofar));
            return;
        }
        
        for(Integer x : cands) {
            sofar.add(x);
            // make a new copy, so we do not need to deal with CME
            List<Integer> left = new ArrayList<>(cands);
            left.remove(x);
            ph(result, sofar, left);
            // sofar appends elements at the end, so we can use sofar.remove(sofar.size()-1) as well
            sofar.remove(x);
        }
    }
}
