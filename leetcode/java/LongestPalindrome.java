class Solution {
    public int longestPalindrome(String s) {
        if (s == null || s.length() == 0) return 0;
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        int cnt = 0;
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            if (entry.getValue() % 2 == 0) cnt += entry.getValue();
            else {
                cnt += entry.getValue()-1;
                if (cnt % 2 == 0) cnt++;
            }
        }
        
        return cnt;
    }
}
