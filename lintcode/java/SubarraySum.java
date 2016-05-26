public class Solution {
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    public List<Integer> subarraySum(int[] A) {
        if(A.length == 0) throw new IllegalArgumentException("input cannot be empty.");
        
        int sum = 0;
        for(int i = 0; i < A.length; i++){
            sum = 0;
            for(int j = i; j < A.length; j++){
                sum += A[j];
                if(sum == 0) return Arrays.asList(i, j);
            }
        }
        return Collections.emptyList();
    }
}
