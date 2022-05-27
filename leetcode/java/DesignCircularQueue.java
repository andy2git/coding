class MyCircularQueue {
    private final int[] a;
    private int start;
    private int end;
    private int cnt;
    private int size;

    public MyCircularQueue(int k) {
        a = new int[k];
        size = k;
    }
    
    public boolean enQueue(int value) {
        if(cnt == size) return false;
        a[end++] = value;
        cnt++;
        end = end % size;
        return true;
    }
    
    public boolean deQueue() {
        if(cnt == 0) return false;
        cnt--;
        start++;
        start = start % size;
        return true;
    }
    
    public int Front() {
        if(cnt == 0) return -1;
        return a[start];
    }
    
    public int Rear() {
        if(cnt == 0) return -1;
        if(end == 0) return a[size-1];
        return a[end-1];
    }
    
    public boolean isEmpty() {
        return cnt == 0;
    }
    
    public boolean isFull() {
        return cnt == size;
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */
