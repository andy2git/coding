class Solution {
    public String removeOuterParentheses(String s) {
        if(s == null) return null;
        Deque<Character> st = new ArrayDeque<>();
        
        String result = "";
        for(int i = 0; i < s.length(); i++) {
            char x = s.charAt(i);
            if(x == '(') {
                if(!st.isEmpty()) result += x;
                st.push(x);
            }else {
                st.pop();
                if(!st.isEmpty()) result += x;
            }
        }
        return result;
    }
}


class Solution {
    public String removeOuterParentheses(String s) {
        if(s == null) return null;
        
        
        StringBuilder result = new StringBuilder();;
        int d = 0;
        for(int i = 0; i < s.length(); i++) {
            char x = s.charAt(i);
            if(x == '(' && (d++) > 0) result.append(x);
            if(x == ')' && (--d) > 0) result.append(x);
        }
        return result.toString();
    }
}
