public class Solution {
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */
    public int numDecodings(String s) {
        if(s.isEmpty()) return 0;
        int n = s.length();
        
        // t[i] : #ways to decode till s[i-1]
        int[] t = new int[n+1];
        t[0] = 1;
        
        for(int i=1; i <= n; i++){
            if(s.charAt(i-1) != '0') t[i] += t[i-1];
            if(isValid(s, i-2, i)) t[i] += t[i-2];
        }
        return t[n];
    }
    
    // [s, e)
    private boolean isValid(String st, int s, int e){
        if(s < 0) return false;
        int val = Integer.valueOf(st.substring(s, e));
        
        if(val >= 10 && val <= 26) return true;
        else return false;
    }
}
