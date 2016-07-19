public class Solution {
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    public ArrayList<ArrayList<Integer>> threeSum(int[] numbers) {
        if (numbers.length < 3) return new ArrayList<>();

        Arrays.sort(numbers);
        int n = numbers.length;

        ArrayList<ArrayList<Integer>> ret = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            // find first non-dup element
            while (i > 0 && i < n && numbers[i - 1] == numbers[i]) i++;

            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int t = numbers[i] + numbers[j] + numbers[k];
                if (t == 0) {
                    ret.add(new ArrayList<>(Arrays.asList(numbers[i], numbers[j], numbers[k)));
                    while (j < k && numbers[j] == numbers[j + 1]) j++;
                    j++;
                    while (j < k && numbers[k] == numbers[k - 1]) k--;
                    k--;
                } else if (t < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return ret;
    }
}
