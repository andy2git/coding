public class Solution {

    private static class Pair<A, B>{
        A f;
        B s;
        Pair(A a, B b){
            this.f = a;
            this.s = b;
        }
    }

    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    public int[] subarraySumClosest(int[] A) {
        if (A.length <= 0) return new int[]{};
        if (A.length == 1) return new int[]{0, 0};

        int n = A.length;
        // can be reppaced with a pair defined before subarraySumClosest()
        int[][] ps = new int[n + 1][2];

        for (int i = 0; i < n; i++) {
            ps[i + 1][0] = ps[i][0] + A[i];
            ps[i + 1][1] = i + 1;
        }

        Arrays.sort(ps, new Comparator<int[]>() {
            @Override
            public int compare(int[] lhs, int[] rhs) {
                if (lhs[0] > rhs[0]) return 1;
                else if (lhs[0] == rhs[0]) return 0;
                else return -1;
            }
        });

        int minDiff = Integer.MAX_VALUE;
        int[] index = new int[2];
        for (int i = 1; i <= n; i++) {
            int diff = Math.abs(ps[i][0] - ps[i - 1][0]);
            if (diff < minDiff) {
                minDiff = diff;
                index[0] = Math.min(ps[i][1], ps[i - 1][1]);
                index[1] = Math.max(ps[i][1], ps[i - 1][1]) - 1;
            }
        }
        return index;
    }
}
