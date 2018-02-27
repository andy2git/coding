class MyStack {
    private Queue<Integer> p = new ArrayDeque<>();
    private Queue<Integer> q = new ArrayDeque<>();

    /** Initialize your data structure here. */
    public MyStack() {
        
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        p.offer(x);
        while(!q.isEmpty()) p.offer(q.poll());
        swap();
    }
    
    private void swap() {
        Queue<Integer> k = p;
        p = q;
        q = k;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return q.poll();
    }
    
    /** Get the top element. */
    public int top() {
        return q.peek();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return q.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
