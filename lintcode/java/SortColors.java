class Solution {
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */
    public void sortColors(int[] A) {
        if(A.length <= 1) return;
        
        int i = 0;
        int j = A.length -1;
        int k = 0;
        
        while(k <= j){
            if(A[k] < 1) {
                swap(A, k++, i++);
            }else if(A[k] == 1) {
                k++;
            }else{
                swap(A, j--, k);
            }
        }
    } 
    
    private void swap(int[] A, int k, int i){
        if(k < 0 || i < 0 || k >= A.length || i >= A.length) throw new IllegalArgumentException("xxx");
        int t = A[k];
        A[k] = A[i];
        A[i] = t;
    }
}
