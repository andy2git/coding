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
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        if(newInterval == null) return intervals;
        List<Interval> result = new ArrayList<>();
        boolean flag = false;
        for(Interval it : intervals) {
            if(it.end < newInterval.start){
                result.add(it);
            } else if (it.start > newInterval.end) {
                if(flag == false) {
                    result.add(newInterval);
                    flag = true;
                }
                result.add(it);
            } else {
                newInterval = new Interval(Math.min(newInterval.start, it.start),
                        Math.max(newInterval.end, it.end));
            }
        }
        if(flag == false) result.add(newInterval);
        return result;
    }
}
