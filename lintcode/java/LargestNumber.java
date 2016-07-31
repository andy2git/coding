public class Solution {
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    public String largestNumber(int[] num) {
        if (num.length == 0) return "";
        
        List<Integer> nums = intArrayToList(num);
        Collections.sort(nums, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return (o2.toString() + o1.toString()).compareTo(o1.toString() + o2.toString());
            }
        });

        StringBuilder sb = new StringBuilder();
        for (Integer x : nums) {
            if(sb.length() > 0 && sb.charAt(0) == '0') sb.setLength(0);
            sb.append(x);
        }
        return sb.toString();
    }
    
    private List<Integer> intArrayToList(int[] nums){
        List<Integer> list = new ArrayList<>(nums.length);
        for(int x : nums){
            list.add(x);
        }
        return list;
    }
}
