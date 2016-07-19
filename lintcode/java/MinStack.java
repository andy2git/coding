public class MinStack {
    private final Deque<Integer> minStack = new ArrayDeque<>();
    private final Deque<Integer> dataStack = new ArrayDeque<>();
    
    public MinStack() {}

    public void push(int x) {
        dataStack.push(x);
        
        if(minStack.isEmpty() || x <= minStack.peek()) minStack.push(x);
    }

    public int pop() {
        if(minStack.isEmpty() || dataStack.isEmpty()) {
            throw new IllegalArgumentException("xxxx");
        }
        int x = dataStack.pop();
        
        if (x == minStack.peek()) minStack.pop();
        return x;
    }

    public int min() {
        if(minStack.isEmpty()) throw new IllegalArgumentException("xxxx");
        return minStack.peek();
    }
}

