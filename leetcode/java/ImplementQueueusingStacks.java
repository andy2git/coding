class MyQueue {
    private final Deque<Integer> st1;
    private final Deque<Integer> st2;

    /** Initialize your data structure here. */
    public MyQueue() {
        st1 = new ArrayDeque<>();
        st2 = new ArrayDeque<>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        st1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if(st2.isEmpty()) {
            move();
        }
        return st2.pop();
    }
    
    private void move() {
        while(!st1.isEmpty()) {
            st2.push(st1.pop());
        }
    }
    
    /** Get the front element. */
    public int peek() {
        if(st2.isEmpty()) {
            move();
        }
        return st2.peek();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return st2.isEmpty() && st1.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
