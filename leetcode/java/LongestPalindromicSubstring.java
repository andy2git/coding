class Solution {
    public String longestPalindrome(String s) {
        if(s == null || s.length() == 0) return null;
        String result = "";
        for(int i = 0; i < s.length(); i++) {
            String s1 = lph(s, i, i);
            if(s1.length() > result.length()) result = s1;

            if(i < s.length()-1) {
                s1 = lph(s, i, i+1);
                if(s1.length() > result.length()) result = s1;
            }
        }
        return result;
    }

    private String lph(String s, int l, int r) {
        if(l > r) return "";
        while(l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)){
            l--;
            r++;
        }
        return s.substring(l+1, r);
    }
}
