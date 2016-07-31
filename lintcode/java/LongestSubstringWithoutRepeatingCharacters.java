public class Solution {
    /**
     * @param s: a string
     * @return: an integer 
     */
    public int lengthOfLongestSubstring(String s) {
        if(s.length() <= 1) return s.length();
        
        int N = 256;
        boolean[] mark = new boolean[N];
        
        int i = 0;
        int j = 0;
        int maxLen = 0;
        for(; j < s.length(); j++){
            if(!mark[s.charAt(j)]){
                mark[s.charAt(j)] = true;
            }else{
                maxLen = Math.max(maxLen, j-i);
                // remark the marker
                // [-------d------]d------
                // i       k       j
                while(s.charAt(i) != s.charAt(j)){
                    mark[s.charAt(i)] = false;
                    i++;
                }
                i++;
            }
        }
        
        maxLen = Math.max(maxLen, j-i);
        return maxLen;
    }
}
