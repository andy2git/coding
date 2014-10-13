class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<string> results;
        unordered_map<string, int> mark;
        for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it) {
            string st = *it;
            sort(st.begin(), st.end());
            mark[st]++;
        }
        
        for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it) {
            string st = *it;
            sort(st.begin(), st.end());
            if(mark[st] > 1) results.push_back(*it);
        }
        
        return results;
    }
};
