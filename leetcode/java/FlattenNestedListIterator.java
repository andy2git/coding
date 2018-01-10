/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class NestedIterator implements Iterator<Integer> {
    private Deque<NestedInteger> st = new ArrayDeque<>();
    
    public NestedIterator(List<NestedInteger> nestedList) {
        for(NestedInteger x : nestedList) {
            st.addLast(x);
        }    
    }

    @Override
    public Integer next() {
        // add extra check to make sure we can pop()
        // or throw NoSuchElementException()
        return st.pop().getInteger();
    }

    @Override
    public boolean hasNext() {
        while(!st.isEmpty()) {
            NestedInteger ni = st.peek();
            if (ni.isInteger()) return true;
            List<NestedInteger> list = st.pop().getList();
            for(int i = list.size()-1; i >= 0; i--){
                st.push(list.get(i));
            }
        }
        return false;
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */
