class Solution {
    public List<String> generateParenthesis(int n) {
        if(n < 0) throw new IllegalArgumentException("xx");
        if(n == 0) return Collections.emptyList();
        
        List<String> result = new ArrayList<>();
        gph(result, "", 0, 0, n);
        return result;
    }
    
    private void gph(List<String> result, String sofar, int l , int r, int n) {
        if(sofar.length() == 2*n) {
            result.add(sofar);
            return;
        }
        if(l < n) gph(result, sofar+"(", l+1, r, n);
        if(l > r) gph(result, sofar+")", l, r+1, n);
    }

    private void gp(List<String> result, String sofar, int l, int r) {
        // stop condition
        if (r == 0) {
            result.add(sofar);
            return;
        }
        if (l < r) {
            gp(result, sofar + ")", l, r - 1);
            if (l > 0) gp(result, sofar + "(", l - 1, r);
        } else gp(result, sofar + "(", l - 1, r);
    }
}
