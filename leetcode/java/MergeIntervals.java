/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
class Solution {
    public List<Interval> merge(List<Interval> intervals) {
        if(intervals == null || intervals.isEmpty()) return Collections.emptyList();
        Collections.sort(intervals, (l, r) -> l.start - r.start);
        
        List<Interval> result = new ArrayList<>();
        int i = 0;
        int j = 1;
        while(j < intervals.size()) {
            Interval cur = intervals.get(i);
            Interval next = intervals.get(j);
            if(next.start <= cur.end) {
                cur.end = Math.max(cur.end, next.end);
            } else {
                result.add(cur);
                i = j;
            }
            j++;
        }
        result.add(intervals.get(i));
        return result;
    }
}
