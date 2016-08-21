/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool intervalCmp(Interval &lhs, Interval &rhs){
    return lhs.start < rhs.start;
}
 
class Solution {
public:
    vector<Interval> merge(vector<Interval> &A) {
        if(A.empty()) return {};
        
        
        sort(A.begin(), A.end(), intervalCmp);
        
        int cInd = 0;
        int nInd = 1;
        
        vector<Interval> result;
        while(nInd < A.size()){
            if(A[cInd].end >= A[nInd].start){
                A[cInd].end = max(A[cInd].end, A[nInd].end);
                nInd++;
            }else{
                result.push_back(A[cInd]);
                cInd = nInd;
                nInd++;
            }
        }
        
        result.push_back(A[cInd]);
        
        return result;
    }
};
