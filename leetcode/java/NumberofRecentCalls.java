class RecentCounter {
    private final PriorityQueue<Integer> items = new PriorityQueue<>(Comparator.naturalOrder());

    public RecentCounter() {
        
    }

    public int ping(int t) {
        items.offer(t);
        int min = t - 3000;
        while (items.peek() < min) items.poll();
        return items.size();
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */


// PQ is not needed here, as t will come in an increasing order.
// We can simplely use a Queue

class RecentCounter {
    private final Deque<Integer> items = new ArrayDeque<>();

    public RecentCounter() {

    }

    public int ping(int t) {
        items.offer(t);
        int min = t - 3000;
        while (items.peek() < min) items.poll();
        return items.size();
    }
}
