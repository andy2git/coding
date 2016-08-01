public class Solution {
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    public int[] plusOne(int[] digits) {
        if(digits == null || digits.length == 0) throw new IllegalArgumentException("xx");
        
        int n = digits.length;
        boolean cbit = true;
        for(int i = n-1; i >=0; i--){
            cbit = digitPlus(digits, i, cbit);   
        }
        
        if(cbit){
            int[] t = new int[digits.length+1];
            t[0] = 1;
            for(int i = 1; i <= digits.length; i++)t[i] = digits[i-1];
            return t;
        }
        return digits;
    }
    
    private boolean digitPlus(int[] digits, int index, boolean cbit){
        //parameter check
        if(index >= digits.length) throw new IllegalArgumentException("xx");
        
        int t = digits[index];
        if(cbit) {
            t++;
            cbit = false;
        }
        if(t >= 10){
            t %= 10;
            cbit = true;
        }
        digits[index] = t;
        return cbit;
    }
}
