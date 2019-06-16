class MyHashSet {
    private static class LinkedList {
        static class Node {
            int val;
            Node next;

            public Node(int val) {
                this.val = val;
            }
        }

        private final Node dummy = new Node(0);

        void add(int x) {
            Node p = dummy.next;
            while (p != null) {
                if (p.val == x) break;
                else p = p.next;
            }

            if (p == null) {
                Node node = new Node(x);
                node.next = dummy.next;
                dummy.next = node;
            }
        }

        void remove(int x) {
            Node p = dummy;

            while (p.next != null) {
                if (p.next.val == x) {
                    p.next = p.next.next;
                    return;
                }
                p = p.next;
            }
        }

        boolean contains(int x) {
            Node p = dummy.next;
            while(p != null) {
                if(p.val == x) return true;
                p = p.next;
            }
            return false;
        }
    }
    private final LinkedList[] data;
    private final static int N = 10;

    /**
     * Initialize your data structure here.
     */
    public MyHashSet() {
        data = new LinkedList[N];
        for (int i = 0; i < N; i++) {
            data[i] = new LinkedList();
        }
    }

    public void add(int key) {
        int ind = key % N;
        data[ind].add(key);
    }

    public void remove(int key) {
        int ind = key % N;
        data[ind].remove(key);
    }

    /**
     * Returns true if this set contains the specified element
     */
    public boolean contains(int key) {
        int ind = key % N;
        return data[ind].contains(key);
    }
}
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */
