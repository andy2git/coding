class Solution {
    public int[] findErrorNums(int[] nums) {
        if(nums == null) throw new IllegalArgumentException("xx");
        Arrays.sort(nums);
        
        int[] result = new int[2];
        for(int i = 0; i < nums.length-1; i++) {
            if(nums[i] == nums[i+1]) {
                result[0] = nums[i];
                break;
            }
        }
        result[1] = result[0] - diff(nums);
        return result;
    }
    
    private int diff(int[] A){
        int sum = 0;
        int expectedSum = 0;
        for(int i = 0; i < A.length; i++) {
            sum += A[i];
            expectedSum += i+1;
        }
        return sum - expectedSum;
    }
}
