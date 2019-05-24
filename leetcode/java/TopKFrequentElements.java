/* Similar to "sorting by frequency" problem */
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        if(nums == null) return Collections.emptyList();

        Map<Integer, Integer> count = new HashMap<>();
        for(int x : nums) {
            count.put(x, count.getOrDefault(x, 0)+1);
        }

        PriorityQueue<Integer> heap = new PriorityQueue<>((l, r) -> count.get(l) - count.get(r));
        for(Integer x : count.keySet()) {
            heap.offer(x);
            if(heap.size() > k) heap.poll();
        }
        List<Integer> result = new ArrayList<>();
        while(!heap.isEmpty()) {
            result.add(heap.poll());
        }
        return result;
    }
}
