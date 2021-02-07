class Trie {
    private static final int R = 26;
    private static final Object DUMMY = new Object();

    private static class Node {
        Object val;
        Node[] next = new Node[R];
    }
    
    private final Node root;
    public Trie() {
        root = new Node();    
    }
    
    public void insert(String word) {
        insertHelper(root, word, 0);
    }
    
    private Node insertHelper(Node root, String key, int depth) {
        if(root == null) root = new Node();
        if(depth == key.length()){
            root.val = DUMMY;
            return root;
        }
        int x = key.charAt(depth) -'a';
        root.next[x] = insertHelper(root.next[x], key, depth+1);
        return root;
    }
    
    public boolean search(String word) {
        Node x = search(root, word, 0);
        if(x == null) return false;
        return x.val != null;
    }
    
    private Node search(Node root, String key, int depth) {
        if(root == null) return null;
        if(depth == key.length()) return root;
        int x = key.charAt(depth)-'a';
        return search(root.next[x], key, depth+1);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        Node x = search(root, prefix, 0);
        if(x == null) return false;
        else return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
