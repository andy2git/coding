public class Solution {
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    public ArrayList<String> generateParenthesis(int n) {
        if(n == 0) return new ArrayList<>();
        List<String> result = new ArrayList<>();
        List<String> sofar = new ArrayList<>();
        
        generateParenthesis(result, "", 0, 0, n);
        return new ArrayList<>(result);
    }
    
    private void generateParenthesis(List<String> result, String sofar, int l, int r, int n){
        if(l+r == 2*n) {
            result.add(sofar);
            return;
        }
        if(l < n) generateParenthesis(result, sofar+"(", l+1, r, n);
        if(l > r) generateParenthesis(result, sofar+")", l, r+1, n);
    }
}
