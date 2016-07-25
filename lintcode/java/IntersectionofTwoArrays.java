public class Solution {
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    public int[] intersection(int[] nums1, int[] nums2) {
        if (nums1.length == 0 || nums2.length == 0) return new int[]{};
        Set<Integer> set = new HashSet<>();

        for (int x : nums1) {
            set.add(x);
        }

        Set<Integer> ret = new HashSet<>();
        for (int y : nums2) {
            if (set.contains(y)) {
                ret.add(y);
            }
        }
        
        //Ints.toArray(ret);
        return toArray(new ArrayList<>(ret));
    }

    private int[] toArray(List<Integer> ret) {
        int[] arr = new int[ret.size()];
        for (int i = 0; i < ret.size(); i++) {
            arr[i] = ret.get(i);
        }
        return arr;
    }
}
