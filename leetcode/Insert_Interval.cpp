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
        if(intervals.empty()) return {newInterval};
        
        vector<Interval> result;
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

/* not a lgn solution prefer the above method */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if(intervals.empty()) return {newInterval};
        
        int i = ceil(intervals, newInterval.start);
        int j = floor(intervals, newInterval.end);
        
        if(i <= j){
            int x = min(newInterval.start, intervals[i].start);
            int y = max(newInterval.end, intervals[j].end);
            auto it = intervals.erase(intervals.begin()+i, intervals.begin()+j+1);
            intervals.insert(it, {x, y});
        }else{
            intervals.insert(intervals.begin()+i, newInterval);
        }
        
        return intervals;
    }
private:
    // floor of the start to x
    int floor(vector<Interval> &intervals, int x){
        int l = 0;
        int h = intervals.size()-1;
        int ind = -1;
        
        while(l <= h){
            int m = l + (h-l)/2;
            int t = intervals[m].start;
            
            if(t == x) return m;
            else if(t > x) h = m-1;
            else {
                ind = m;
                l = m+1;
            }
        }
        
        return ind;
    }
    
    // ceil of the end to the x
    int ceil(vector<Interval> &intervals, int x){
        int l = 0;
        int h = intervals.size()-1;
        int ind = -1;
        
        while(l <= h){
            int m = l + (h-l)/2;
            int t = intervals[m].end;
            
            if(t == x) return m;
            else if(t < x) l = m+1;
            else {
                ind = m;
                h = m-1;
            }
        }
        
        return ind;
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
