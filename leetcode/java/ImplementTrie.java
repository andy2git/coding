class Trie {
    private static final int R = 26;
    private static final Object dummy = new Object();
    private Node root = new Node();
    
    private static class Node {    
        Node[] link = new Node[R];
        Object val;
    }

    /** Initialize your data structure here. */
    public Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        insertHelper(root, word, 0);
    }
    
    private Node insertHelper(Node x, String w, int d) {
        if(x == null) x = new Node();
        if(d == w.length()){
            x.val = dummy;
            return x;
        }
        int c = w.charAt(d) - 'a';
        x.link[c] = insertHelper(x.link[c], w, d+1);
        return x;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        return searchHelper(root, word, 0);
    }
    
    private boolean searchHelper(Node x, String word, int d) {
        if(x == null) return false;
        if(d == word.length()) {
            return x.val != null;
        }
        int c = word.charAt(d) - 'a';
        return searchHelper(x.link[c], word, d+1);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        return startWithHelper(root, prefix, 0);
    }
    
    private boolean startWithHelper(Node x, String word, int d) {
        if(x == null) return false;
        if(d == word.length()) return true;
        int c = word.charAt(d) - 'a';
        return startWithHelper(x.link[c], word, d+1);
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
