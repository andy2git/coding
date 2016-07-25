class Solution {
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
     
    // NOTES:
    // do not use int[], it does not bring too much gain here.
    // use List<List<Integer>>
    public ArrayList<ArrayList<Integer>> subsets(int[] nums) {
        if(nums.length == 0) return new ArrayList<>();
        
        
        Arrays.sort(nums);
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        ArrayList<Integer> sofar = new ArrayList<>();
        subsetHelper(result, sofar, nums, 0);

        return result;
    }

    // do not use int[], it does not bring too much gain here.
    private void subsetHelper(ArrayList<ArrayList<Integer>> result, ArrayList<Integer> sofar, int[] nums, int ind){
        if(nums.length == ind){
            result.add(new ArrayList<>(sofar));
            return;
        }

        subsetHelper(result, sofar, nums, ind+1);
        sofar.add(nums[ind]);
        subsetHelper(result, sofar, nums, ind+1);
        sofar.remove(sofar.size()-1);
    }
}
