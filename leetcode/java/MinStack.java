// MaxStack can be implemented in a similar fashion as well.

class MinStack {
    private final Deque<Integer> st;
    private final Deque<Integer> mst;

    /** initialize your data structure here. */
    public MinStack() {
        st = new ArrayDeque<>();
        mst = new ArrayDeque<>();
    }
    
    public void push(int x) {
        st.push(x);
        
        if(mst.isEmpty() || x <= mst.peek()){
            mst.push(x);
        }
    }
    
    public void pop() {
        int x = st.pop();
        if(x == mst.peek()) mst.pop();
    }
    
    public int top() {
        return st.peek();
    }
    
    public int getMin() {
        return mst.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
