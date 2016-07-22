/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie = new Trie();
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
public class Trie {
    private static final int R = 26;

    private static class Node {
        private Object val;
        private Node[] next = new Node[R];
    }

    private static enum Value {
        EMPTY,
        NON_EMPTY
    }

    private final Node root = new Node();

    // Inserts a word into the trie.
    public void insert(String word) {
        insertHelper(root, word, 0);
    }

    private Node insertHelper(Node t, String word, int depth) {
        if (t == null) t = new Node();
        if (word.length() == depth) {
            t.val = Value.NON_EMPTY;
            return t;
        }

        int p = word.charAt(depth) - 'a';
        t.next[p] = insertHelper(t.next[p], word, depth + 1);
        return t;
    }

    // Returns if the word is in the trie.
    public boolean search(String word) {
        Node x = searchHelper(root, word, 0);
        if (x == null) return false;
        else return true;
    }

    private Node searchHelper(Node t, String word, int depth) {
        if (t == null) return null;
        if (depth == word.length()) {
            if(t.val == Value.NON_EMPTY) return t;
            else return null;
        }
        int p = word.charAt(depth) - 'a';
        return searchHelper(t.next[p], word, depth + 1);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    public boolean startsWith(String prefix) {
        Node x = startsWithHelper(root, prefix, 0);
        if (x == null) return false;
        else return true;
    }

    private Node startsWithHelper(Node t, String word, int depth) {
        if (t == null) return null;
        if (depth == word.length()) {
            return t;
        }
        int p = word.charAt(depth) - 'a';
        return startsWithHelper(t.next[p], word, depth + 1);
    }
}
