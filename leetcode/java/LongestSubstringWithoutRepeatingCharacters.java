class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s == null) throw new IllegalArgumentException("xx");
        
        int i = 0;
        int j = 0;
        int maxLen = 0;
        // bitset can do the same job
        boolean[] mark = new boolean[256];
        while(j < s.length()) {
            char ch = s.charAt(j);
            if(!mark[ch]) {
                mark[ch] = true;
                j++;
            }else {
                maxLen = Math.max(maxLen, j-i);
                while(s.charAt(i) != s.charAt(j)) {
                    mark[s.charAt(i++)] = false;
                }
                i++;
                j++;
            }
        }
        maxLen = Math.max(maxLen, j-i);
        return maxLen;
    }
}
