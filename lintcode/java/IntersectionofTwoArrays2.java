public class Solution {
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    public int[] intersection(int[] nums1, int[] nums2) {
        if (nums1.length == 0 || nums2.length == 0) return new int[]{};
        
        // elem -> count
        Map<Integer, Integer> map = new HashMap<>();
        for(int x : nums1){
            if(map.containsKey(x)){
                map.put(x, map.get(x)+1);
            }else{
                map.put(x, 1);
            }
        }
        
        List<Integer> ret = new ArrayList<>();
        for(int x: nums2){
            if(map.containsKey(x) && map.get(x) > 0){
                ret.add(x);
                map.put(x, map.get(x)-1);
            }
        }
        return toArray(ret);
    }
    
    private int[] toArray(Collection<Integer> ret) {
        Object[] vals = ret.toArray();
        int[] arr = new int[vals.length];
        for (int i = 0; i < vals.length; i++) {
            arr[i] = (int) vals[i];
        }
        return arr;
    }
}
