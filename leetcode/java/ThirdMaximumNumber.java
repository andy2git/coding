class Solution {
    public int thirdMax(int[] nums) {
        if(nums == null || nums.length == 0) throw new IllegalArgumentException("xxx");
        int MAX_SIZE = 3;
        SortedSet<Integer> tops = new TreeSet();
        for(int num: nums) {
            tops.add(num);
            if(tops.size() > MAX_SIZE) {
                tops.remove(tops.first());                
            }
        }    
        
        return tops.size() == MAX_SIZE ? tops.first() : tops.last();
    }
}
