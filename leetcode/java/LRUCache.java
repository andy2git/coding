class LRUCache {
    private final Map<Integer, Node<Integer, Integer>> map;
    private final Deque<Node<Integer, Integer>> list;
    private final int cap;

    public LRUCache(int capacity) {
        this.map = new HashMap<>(capacity);
        this.list = new LinkedList<>();
        this.cap = capacity;
    }

    public int get(int key) {
        Node<Integer, Integer> t = map.get(key);
        if (t == null) return -1;
        refresh(t);
        return t.v;
    }

    public void put(int key, int value) {
        if (map.containsKey(key)) {
            Node t = map.get(key);
            t.v = value;
            refresh(t);
        } else {
            if (map.size() == cap) {
                Node t = list.removeFirst();
                map.remove(t.k);
            }

            Node t = new Node(key, value);
            list.addLast(t);
            map.put(key, t);
        }
    }

    private void refresh(Node t) {
        list.remove(t);
        list.addLast(t);
    }

    private static class Node<K, V> {
        K k;
        V v;

        Node(K k, V v) {
            this.k = k;
            this.v = v;
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
