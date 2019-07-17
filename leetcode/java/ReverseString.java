// recursive solution
class Solution {
    public void reverseString(char[] s) {
        helper(s, 0, s.length-1);
    }
    
    private void helper(char[] s, int i, int j) {
        if (i >= j) return;
        swap(s, i, j);
        helper(s, i+1, j-1);
    }
    private void swap(char[] s, int i, int j) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

//iterative is more straigtforward
