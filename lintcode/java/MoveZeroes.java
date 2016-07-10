public class Solution {
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    public void moveZeroes(int[] A) {
        if(A.length <= 1) return;
        
        int i = 0;
        int j = 0;
        int n = A.length;
        while(j < n){
            if(A[j] == 0){
                j++;
            }else{
                swap(A, i++, j++);
            }
        }
    }
    
    private void swap(int[] A, int i, int j){
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }
}
