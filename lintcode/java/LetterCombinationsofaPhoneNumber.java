public class Solution {
    private final Map<Character, String> map = new HashMap<>();

    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    public ArrayList<String> letterCombinations(String digits) {
        if (digits == null || digits.isEmpty()) return new ArrayList<>();
        initMap();
        List<String> list = new ArrayList<>();
        list.add("");

        for (int i = 0; i < digits.length(); i++) {
            list = lcHelper(list, digits, i);
        }
        return new ArrayList<>(list);
    }

    private List<String> lcHelper(List<String> sofar, String digits, int ind) {
        List<String> result = new ArrayList<>();
        for (String list : sofar) {
            String comb = map.get(digits.charAt(ind));
            if (comb == null) throw new IllegalArgumentException("wrong input!");
            for (int i = 0; i < comb.length(); i++) {
                result.add(list + comb.charAt(i));
            }
        }
        return result;
    }
    // end of Solution#1: use iterative, but recursive solution is more concise


    // Solution#2: recursive solution
    public ArrayList<String> letterCombinations(String digits) {
        if (digits == null || digits.isEmpty()) return new ArrayList<>();
        initMap();
        return new ArrayList<>(lcHelper(digits, 0));
    }

    private List<String> lcHelper(String digits, int ind) {
        if (ind == digits.length()) return Arrays.asList("");

        List<String> result = new ArrayList<>();
        String comb = map.get(digits.charAt(ind));
        if (comb == null) throw new IllegalArgumentException("wrong input!");

        List<String> sofar = lcHelper(digits, ind+1);
        for(String list: sofar){
            for (int i = 0; i < comb.length(); i++) {
                result.add(comb.charAt(i)+list);
            }
        }
        return result;
    }

    private void initMap() {
        map.put('2', "abc");
        map.put('3', "def");
        map.put('4', "ghi");
        map.put('5', "jkl");
        map.put('6', "mno");
        map.put('7', "pqrs");
        map.put('8', "tuv");
        map.put('9', "wxyz");
    }
}
