class MyHashMap {
    private final LinkedList[] data;
    private static final int N = 10;

    /** Initialize your data structure here. */
    public MyHashMap() {
        data = new LinkedList[N];
        for(int i = 0; i < N; i++) {
            data[i] = new LinkedList();
        }
    }
    
    /** value will always be non-negative. */
    public void put(int key, int value) {
        data[key%N].add(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    public int get(int key) {
        return data[key%N].get(key);
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    public void remove(int key) {
        data[key%N].remove(key);
    }
    
    private static class LinkedList {
        static class Node {
            int key;
            int val;
            Node next;

            public Node(int key, int val) {
                this.key = key;
                this.val = val;
            }
        }

        private final Node dummy = new Node(0, 0);

        void add(int k, int v) {
            Node p = dummy.next;
            while (p != null) {
                if (p.key == k) {
                    p.val = v;
                    break;
                }
                p = p.next;
            }

            if (p == null) {
                Node node = new Node(k, v);
                node.next = dummy.next;
                dummy.next = node;
            }
        }

        void remove(int k) {
            Node p = dummy;

            while (p.next != null) {
                if (p.next.key == k) {
                    p.next = p.next.next;
                    return;
                }
                p = p.next;
            }
        }

        int get(int k) {
            Node p = dummy.next;
            while (p != null) {
                if (p.key == k) return p.val;
                p = p.next;
            }
            return -1;
        }
    }

}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
