class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if(strs.empty()) return "";
    
        int match_ind = match_ind_helper(strs);
        return strs[0].substr(0, match_ind);
        
    }
private:
    int match_ind_helper(vector<string> &strs){
        vector<string>::iterator min_elem_it;
        min_elem_it = min_element(strs.begin(), strs.end(), [](string &lhs, string &rhs){ return lhs.size() < rhs.size();});

        int i = 0;
        for (i = 0; i < min_elem_it->size(); i++) {
            char match = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != match) {
                    return i;
                }
            }
        }
        
        return i;
    }
};
