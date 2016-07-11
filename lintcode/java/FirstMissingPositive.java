public class Solution {
    /**    
     * @param A: an array of integers
     * @return: an integer
     */
    public int firstMissingPositive(int[] A) {
        Arrays.sort(A);
        
        int ind = 1;
        for(int x : A){
            if(x <= 0) continue;
            else {
                if(x == ind) ind++;
                else if(x < ind) continue;
                else return ind;
            }
        }
        return ind;
    }
}
