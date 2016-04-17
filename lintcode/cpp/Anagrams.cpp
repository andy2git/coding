class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        unordered_map<string, vector<int>> m;
        
        int i = 0;
        for(auto s : strs){
            sort(s.begin(), s.end());
            m[s].push_back(i);
            i++;
        }
        
        vector<string> result;
        for(auto it = m.begin(); it != m.end(); ++it){
            vector<int> &t = it->second;
            if(t.size() > 1){
                for(auto k:t){
                    result.push_back(strs[k]);
                }
            }
        }
        
        return result;
    }
};

