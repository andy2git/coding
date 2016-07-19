public class Solution {
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    public int jump(int[] A) {
        if(A.length <= 1) return 0;

        int n = A.length;
        int[] t = new int[n];
        t[n-1] = 0;

        for(int i = n-2; i >=0; i--){
            if(i + A[i] >=n-1) {
                t[i] = 1;
                continue;
            }
            for(int j = i+1; j <= A[i] + i; j++){
                if(t[j] > 0){
                    if(t[i] > 0) t[i] = Math.min(t[j]+1, t[i]);
                    else t[i] = t[j]+1;
                }
            }
        }

        return t[0];
    }
}

