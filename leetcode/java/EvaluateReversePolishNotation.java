class Solution {
    public int evalRPN(String[] tokens) {
        if(tokens == null || tokens.length == 0) throw new IllegalArgumentException("x");
        Deque<Integer> st = new ArrayDeque<>();
        
        for(String t : tokens) {
            if(isOp(t)) {
                int x = st.pop();
                int y = st.pop();
                st.push(compute(x, y, t));
            }else {
                st.push(Integer.valueOf(t));   
            }
        }
        return st.pop();
    }
    
    private boolean isOp(String st) {
        if(st.equals("+") ||st.equals("-") || st.equals("/") || st.equals("*") ) return true;
        return false;
    }
    
    private int compute(int x, int y, String op) {
        if(op.equals("+")) return x+y;
        else if(op.equals("-")) return y-x;
        else if(op.equals("*")) return x*y;
        else return y/x;
    }
}
