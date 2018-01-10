class Solution {
    private static Map<Character, String> map = getPhoneMap();
    
    public List<String> letterCombinations(String digits) {
        if(digits == null || digits.equals("")) return Collections.emptyList();
        
        List<String> result = new ArrayList<>();
        
        lch(result, "", digits, 0);
        return result;
    }
    
    private void lch(List<String> result, String sofar, String digits, int n){
        if(n == digits.length()) {
            result.add(sofar);
            return;
        }
        
        char d = digits.charAt(n);
        if(!map.containsKey(d)) throw new IllegalArgumentException("x");
        String chars = map.get(d);
        for(int i = 0; i < chars.length(); i++) {
            lch(result, sofar+chars.charAt(i), digits, n+1);
        }
    }
    
    private static Map<Character, String> getPhoneMap() {
        Map<Character, String> map = new HashMap<>();
        map.put('2', "abc");
        map.put('3', "def");
        map.put('4', "ghi");
        map.put('5', "jkl");
        map.put('6', "mno");
        map.put('7', "pqrs");
        map.put('8', "tuv");
        map.put('9', "wxyz");
        return map;
    }
}
