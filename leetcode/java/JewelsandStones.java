class Solution {
    public int numJewelsInStones(String J, String S) {
        if(J == null || S == null) return 0;
        Set<Character> jls = new HashSet<>();
        for(int i = 0; i < J.length(); i++) {
            jls.add(J.charAt(i));
        }
        
        int cnt = 0;
        for(int i = 0; i < S.length(); i++) {
            if(jls.contains(S.charAt(i))) cnt++;
        }
        return cnt;
    }
}
