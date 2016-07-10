public class Solution {
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    public boolean wordBreak(String s, Set<String> dict) {
        // parameters check
        if (s.length() == 0) return true;
        if (dict.isEmpty()) return false;

        int n = s.length();
        boolean[] t = new boolean[n + 1];
        t[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                t[i] = t[j] && dict.contains(s.substring(j, i));
                if(t[i]) break;
            }
        }

        return t[n];
    }
}
