public class Solution {
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    public String longestPalindrome(String s) {
        if (s.length() <= 1) return s;

        String maxPS = "";
        for (int i = 0; i < s.length(); i++) {
            String ps = palindromString(s, i, i);
            if (ps.length() > maxPS.length()) {
                maxPS = ps;
            }
            ps = palindromString(s, i - 1, i);
            if (ps.length() > maxPS.length()) {
                maxPS = ps;
            }
        }

        return maxPS;
    }

    private String palindromString(String st, int s, int e) {
        while (s >= 0 && e < st.length() && st.charAt(s) == st.charAt(e)) {
            s--;
            e++;
        };
        return st.substring(s + 1, e);
    }
}
