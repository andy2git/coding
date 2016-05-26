public class Solution {
    /**
     * @param n the nth
     * @return the nth sequence
     */
    public String countAndSay(int n) {
        if(n <= 0) throw new IllegalArgumentException("xxx");
        String ret = "1";
        while(n > 1){
            ret = countAndSayHelper(ret);
            n--;
        }
        return ret;
    }
    
    private String countAndSayHelper(String s){
        if(s == null || s == "") throw new IllegalArgumentException("xxx");
        
        char ch = s.charAt(0);
        int cnt = 1;
        StringBuilder ret = new StringBuilder();
        for(int i = 1; i < s.length(); i++){
            if(s.charAt(i) == ch) {
                cnt++;
            } else {
                ret.append(cnt);
                ret.append(ch);
                ch = s.charAt(i);
                cnt = 1;
            }
        }
        
        // last case
        ret.append(cnt);
        ret.append(ch);
        return ret.toString();
    }
}
