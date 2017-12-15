class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        if(magazine == null) return false;
        if(ransomNote == null) return true;
    
        Map<Character, Integer> mag = new HashMap<>();
        for(int i = 0; i < magazine.length(); i++) {
            char ch = magazine.charAt(i);
            mag.put(ch, mag.getOrDefault(ch, 0)+1);
        }
    
        for(int i = 0; i < ransomNote.length(); i++) {
            char ch = ransomNote.charAt(i);
            if(!mag.containsKey(ch) || mag.get(ch) == 0) return false;
            mag.put(ch, mag.get(ch)-1);
        }
    
        return true;
    }
}
