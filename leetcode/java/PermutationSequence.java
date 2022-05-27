class Solution {
    public String getPermutation(int n, int k) {
        int[] f = factorial(n);
        List<Integer> nums = nums(n);
        String result = "";

        while (n > 1 && k > 1) {
            if (k == f[n - 1] * n) {
                for (int i = nums.size() - 1; i >= 0; i--) {
                    result += nums.get(i);
                }
                return result;
            }

            int index = (k - 1) / f[n - 1];
            Integer x = nums.get(index);
            nums.remove(x);
            result += x;
            if (k != f[n - 1]) k = k - index*f[n-1];
            n--;
        }
        for (Integer x : nums) {
            result += x;
        }
        return result;
    }
    
    private int[] factorial(int n) {
        int[] x = new int[n];
        int f = 1;
        x[0] = 1;
        for(int i = 1; i < n; i++) {
            x[i] = x[i-1]*i;
        }
        return x;
    }
    
    private List<Integer> nums(int n){
        List<Integer> list = new ArrayList<>(n);
        for(int i = 1; i <=n; i++) {
            list.add(i);
        }
        return list;
    }
}
