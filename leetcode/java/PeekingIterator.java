// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html
class PeekingIterator implements Iterator<Integer> {
    private Iterator<Integer> it;
    private Integer cache;

	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
	    it = iterator;
	}

    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        if(cache == null) cache = it.next();
        return cache;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
	    if(cache != null) {
            Integer val = cache;
            cache = null;
            return val;
        } else return it.next();
	}

	@Override
	public boolean hasNext() {
        // if (cache != null) return true;
        // return it.hasNext();
	    return cache != null || it.hasNext();
	}
}
