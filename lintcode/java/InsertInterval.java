/**
 * Definition of Interval:
 * public classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this.start = start;
 *         this.end = end;
 *     }
 */

class Solution {
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: A new interval.
     * @return: A new sorted interval list.
     */
    public ArrayList<Interval> insert(ArrayList<Interval> intervals, Interval newInterval) {
        ArrayList<Interval> result = new ArrayList<>();
        
        int i = 0;
        for(; i < intervals.size(); i++) {
            Interval x = intervals.get(i);
            if(x.end < newInterval.start){
                result.add(x);
            }else if (x.start > newInterval.end){
                break;
            }else {
                newInterval.start = Math.min(newInterval.start, x.start);
                newInterval.end = Math.max(newInterval.end, x.end);
            }
        }
        
        result.add(newInterval);
        for(;i < intervals.size(); i++){
            result.add(intervals.get(i));
        }
        
        return result;
    }
}
