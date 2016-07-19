public class Solution {
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target : An integer
     * @return : return the sum of the three integers, the sum closest target.
     */
    public int threeSumClosest(int[] numbers, int target) {
        if (numbers.length < 3) throw new IllegalArgumentException("xxx");

        Arrays.sort(numbers);
        
        int n = numbers.length;
        int minDis = Integer.MAX_VALUE;
        int minSum = 0;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int t = numbers[i] + numbers[j] + numbers[k];
                int dis = Math.abs(t-target);
                if(dis < minDis){
                    minSum = t;
                    minDis = dis;
                }
                if(t > target) k--;
                else if (t == target) return target;
                else j++;
            }
        }
        return minSum;
    }
}
