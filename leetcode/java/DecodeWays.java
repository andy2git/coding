class Solution {
    public int numDecodings(String s) {
        if(s == null || s.length() == 0) return 0;
        int n = s.length();
        int[] t = new int[n+1];
        t[0] = 1;
        
        for(int i = 1; i <= n; i++) {
            if(s.charAt(i-1) != '0') t[i] += t[i-1];
            if(isRange(s, i-2, i)) t[i] += t[i-2];
        }
        return t[n];
    }
    
    private boolean isRange(String st, int s, int e) {
        if(s < 0) return false;
        
        int base = 1;
        int result = 0;
        for(int i = s; i < e; i++) {
            result = result*base + st.charAt(i)-'0';
            base *= 10;
        }
        return result >= 10 && result <= 26;
    }
}
