public class Solution {
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    public boolean isValidParentheses(String s) {
        Deque<Character> st = new ArrayDeque<>(); 
        for(int i= 0; i < s.length(); i++){
            char x = s.charAt(i);
            if(isOpenParen(x)) {
                st.push(x);
            }else{
                if(st.isEmpty()) return false;
                if(!isMatchParen(st.pop(), x)) return false;
            }
        }
        return st.isEmpty();
    }
    
    private boolean isOpenParen(char x){
        return x == '(' || x == '{' || x =='[';
    }
    
    private boolean isMatchParen(char left, char right){
        return left == '(' && right == ')'
                || left == '{' && right == '}'
                || left == '[' && right == ']';
    }
}
