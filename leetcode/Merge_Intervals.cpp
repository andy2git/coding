/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.empty()) return vector<Interval>();
        
        sort(intervals.begin(), intervals.end(), Solution::interval_cmp);
        
        vector<Interval> result;
        int i = 1;
        int n = intervals.size();
        int s, e;
        
        s = intervals[0].start;
        e = intervals[0].end;
        while(i < n){
            if(intervals[i].start <= e){
                e = max(e, intervals[i].end);
            }else{
                result.push_back(Interval(s, e));
                s = intervals[i].start;
                e = intervals[i].end;
            }
            
            i++;
        }
        result.push_back(Interval(s, e));
        
        return result;
    }
private:
    static bool interval_cmp(const Interval &lhs, const Interval &rhs){
        return lhs.start < rhs.start;
    }
};

