public class Solution {
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */

    /* Solution #1, O(2^n)*/
    /* Time complexity is O(2^n) 
     * T(n) = T(n-1) + T(n-2) + .... + T(1) */
    public boolean canJump(int[] A) {
        if(A.length <= 1) return true;
        
        int n = A.length;
        //index queue
        Queue<Integer> queue = new ArrayDeque<>();
        queue.offer(0);
        
        while(!queue.isEmpty()) {
            int t = queue.poll();
            for(int i = t+1; i <= t+A[t]; i++){
                if(i == n-1) return true;
                queue.offer(i);
            }    
        }
        
        return false;
    }

    /* Solution #2, O(2^n)*/
    public boolean canJump(int[] A) {
        if(A.length <= 1) return true;
        
        return canJumpHelper(A, 0);
    }
    
    private boolean canJumpHelper(int[] A, int pos){
        if(pos + A[pos] >= A.length-1) return true;
        
        for(int i = pos+1; i <= pos+A[pos]; i++){
            if(canJumpHelper(A, i)) return true;
        }
        return false;
    }

    /* Solution #3, O(n)*/
    /* linear approach */
    public boolean canJump(int[] A) {
        if(A.length <= 1) return true;
        
        int n = A.length;
        int lastPos = n-1;
        for(int i = n-2; i >= 0; i--) {
            if(A[i] + i >= lastPos){
                lastPos = i;
            }
        }
      
        return lastPos == 0;
    }

    /* Solution#4, DP. O(n^2) */
    public boolean canJump(int[] A) {
        if(A.length <= 1) return true;
        
        int n = A.length;
        boolean[] t = new boolean[n];
        t[n-1] = true;
        
        for(int i = n-2; i >=0; i--){
            if(i + A[i] >=n-1) {
                t[i] = true;
                continue;
            }
            for(int j = i+1; j <= A[i] + i; j++){
                if(t[j]){
                    t[i] = true;
                    break;
                }
            }
        }
        
        return t[0];
    }
}

