public class Solution {
     private static class Node<K, V> {
        K k;
        V v;

        Node(K k, V v) {
            this.k = k;
            this.v = v;
        }
    }

    private final int capacity;
    private final Map<Integer, Node> keyMap = new HashMap<>();
    private final Deque<Node> keyValList = new LinkedList<>();

    public Solution(int capacity) {
        this.capacity = capacity;
    }

     public void set(int key, int value) {
        if (keyMap.containsKey(key)) {
            if(get(key) != value) refresh(key, value);
        } else {
            if (keyMap.size() == capacity) {
                // evict the oldest key
                Node t = keyValList.removeFirst();
                keyMap.remove(t.k);
            }
            // add (k, v) in the LRU
           add(key, value);
        }
    }

    public int get(int key) {
        if (keyMap.containsKey(key)) {
            Node<Integer, Integer> t = keyMap.get(key);
            refresh(t);
            return t.v;
        }

        return -1;
    }

    /**
     * No need to update the keyMap, as we donot need to recreate the Node
     * @param t
     */
    private void refresh(Node t){
        keyValList.remove(t);
        keyValList.addLast(t);
    }

    private void refresh(int key, int val) {
        Node t = keyMap.get(key);
        keyValList.remove(t);
        add(key, val);
    }

    private void add(int key, int val){
        Node t = new Node(key, val);
        keyValList.addLast(t);
        keyMap.put(key, t);
    }
}
