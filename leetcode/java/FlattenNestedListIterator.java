public class NestedIterator implements Iterator<Integer> {
    private final Deque<NestedInteger> queue = new ArrayDeque<>();

    public NestedIterator(List<NestedInteger> nestedList) {
        for (NestedInteger x : nestedList) {
            queue.offerLast(x);
        }
    }

    @Override
    public Integer next() {
        NestedInteger t = queue.removeFirst();
        if (t.isInteger()) return t.getInteger();
        else throw new IllegalStateException("xxx");
    }

    @Override
    public boolean hasNext() {
        while(!queue.isEmpty()){
            NestedInteger t = queue.pollFirst();
            if (t.isInteger()) {
                queue.offerFirst(t);
                return true;
            } else {
                List<NestedInteger> list = t.getList();
                for (int i = list.size() - 1; i >= 0; i--) {
                    queue.offerFirst(list.get(i));
                }
            }
        }
        return false;
    }

    
}
