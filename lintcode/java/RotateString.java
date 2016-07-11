public class Solution {
    /**
     * @param str: an array of char
     * @param offset: an integer
     * @return: nothing
     */
    public void rotateString(char[] str, int offset) {
        if(offset < 0) throw new IllegalArgumentException("xxx");
        if(str.length == 0) return;
        
        offset %= str.length;
        if(offset == 0) return;
        
        int i = 0;
        int j = str.length-1;
        
        reverse(str, i, j);
        reverse(str, i, offset-1);
        reverse(str, offset, j);
    }
    
    private void reverse(char[] A, int i, int j){
        if(i > j) throw new IllegalArgumentException("xxx");
        
        while(i < j){
            swap(A, i++, j--);
        }
    }
    
    private void swap(char[] A, int i, int j){
        char t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
}
