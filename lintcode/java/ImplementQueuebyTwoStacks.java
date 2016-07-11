public class Queue {
    private final Deque<Integer> st1;
    private final Deque<Integer> st2;

    public Queue() {
        st1 = new ArrayDeque<>();
        st2 = new ArrayDeque<>();
    }
    
    public void push(int element) {
        st1.push(element);
    }

    public int pop() {
        if(st2.isEmpty()) copyStack(st1, st2);
        
        if(!st2.isEmpty()) return st2.pop();
        else throw new RuntimeException("empty queue!");
    }

    public int top() {
        if(st2.isEmpty()) copyStack(st1, st2);
        
        if(!st2.isEmpty()) return st2.peek();
        else throw new RuntimeException("empty queue!");
    }
    
    private void copyStack(Deque<Integer> src, Deque<Integer> dst){
        while(!src.isEmpty()){
            dst.push(src.pop());
        }
    }
}
