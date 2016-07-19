public class Solution {
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1 + 1, index2 + 1] (index1 < index2)
     */
    public int[] twoSum(int[] numbers, int target) {
        if(numbers.length < 2) return new int[]{0, 0};
        
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < numbers.length; i++){
            int x = target - numbers[i];
            if(map.get(x) != null){
                return new int[]{map.get(x), i+1};
            }else{
                map.put(numbers[i], i+1);
            }
        }
        
        return new int[]{0, 0};
    }
}
