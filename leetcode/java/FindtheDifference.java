class Solution {
    public char findTheDifference(String s, String t) {
        if(s == null || t == null) throw new IllegalArgumentException("x");
        Map<Character, Integer> map = new HashMap<>();
        for(int i = 0; i < s.length(); i++) {
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0)+1);
        }
        
        for(int i = 0; i < t.length(); i++) {
            Character x = t.charAt(i);
            if(!map.containsKey(x)) return x;
            else {
                if(map.get(x) == 0) return x;
                else map.put(x, map.get(x)-1);
            }
        }
        throw new RuntimeException("x");
    }
}
