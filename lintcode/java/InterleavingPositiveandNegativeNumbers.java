class Solution {
    /**
     * @param A: An integer array.
     * @return: void
     */
    public void rerange(int[] A) {
        if(A.length <= 2) return;
        
        int n = A.length;
        int x = partation(A);
        int y = n - x;
        rerangeHelper(A, x, y);
    }
    
    private void rerangeHelper(int[] A, int x, int y){
        int n = A.length;
        
        int i = 0, j = 0;
        if(x < y){
            i = 0;
            j = n-2;
        }else if(x == y){
            i = 1;
            j = n-2;
        }else{
            i = 1;
            j = n-1;
        }
        
        while(i < j){
            swap(A, i, j);
            i += 2;
            j -= 2;
        }
    }
   
   private int partation(int[] A){
       int i = 0;
       int j = A.length -1;
       
       while(i <= j){
           if(A[i] < 0) i++;
           else swap(A, i, j--);
       }
       return i;
   }
   
   private void swap(int[] A, int i, int j){
       int tmp = A[i];
       A[i] = A[j];
       A[j] = tmp;
   }
}
