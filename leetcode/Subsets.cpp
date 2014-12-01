class Solution {
public:
    vector<vector<int> > subsets(vector<int> &s) {
        if(s.empty()) return {};
       
        vector<vector<int>> result;
        vector<int> vec;
       
        sort(s.begin(), s.end());
        subsets_helper(result, vec, s);
        return result;
    }
   
private:
    void subsets_helper(vector<vector<int>> &result, vector<int> &sofar, vector<int> &remain){
        if(remain.empty()){
            result.push_back(sofar);
            return;
        }
       
        int t = remain[0];
        remain.erase(remain.begin());
        subsets_helper(result, sofar, remain);
       
        sofar.push_back(t);
        subsets_helper(result, sofar, remain);
       
        //recover as sofar and remain are global variables now
        remain.insert(remain.begin(),t);
        sofar.pop_back();
    }
};
