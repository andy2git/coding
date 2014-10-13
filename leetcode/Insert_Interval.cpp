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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        if(intervals.empty()){
            result.push_back(newInterval);
            return result;
        }
        
        int i;
        for(i = 0; i < intervals.size(); i++){
            if(intervals[i].end < newInterval.start){
                result.push_back(intervals[i]);
            }else if(intervals[i].start > newInterval.end){
                break;
            }else{
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        
        result.push_back(newInterval);
        while(i < intervals.size()){
            result.push_back(intervals[i]);
            i++;
        }
        
        return result;
    }
};


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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        if(intervals.empty()){
            result.push_back(newInterval);
            return result;
        }
        
        auto ind_it = lower_bound(intervals.begin(), intervals.end(), newInterval, interval_cmp);
        intervals.insert(ind_it, newInterval);
        
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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        if(intervals.empty()){
            result.push_back(newInterval);
            return result;
        }
        
        auto it = intervals.begin();
        while(it != intervals.end()){
            if(it->end < newInterval.start){
                ++it;
            }else if(it->start > newInterval.end){
                break;
            }else{
                newInterval.start = min(it->start, newInterval.start);
                newInterval.end = max(it->end, newInterval.end);
                it = intervals.erase(it);
            }
        }
        intervals.insert(it, newInterval);
        return intervals;
    }
private:
    static bool interval_cmp(const Interval &lhs, const Interval &rhs){
        return lhs.start < rhs.start;
    }
};
