class Solution {
    public int[] sortArrayByParityII(int[] A) {
        if(A == null || A.length <= 1) return A;
        
        int i = 0; 
        int j = A.length-1;
        while(i<=j) {
            if(A[j] % 2 == 0) swap(A, i++, j);
            else j--;
        }
        
        shuffle(A);
        return A;
    }

    private void swap(int[] A, int i, int j) {
        int t = A[j];
        A[j] = A[i];
        A[i] = t;
    }
    
    private void shuffle(int[] A) {
        int i = 1;
        int j = A.length-1;
        if(j%2 != 0) j--;
        while(i < j) {
            swap(A, i, j);
            i += 2;
            j -= 2;   
        }
    }
}
