class Solution {
public:    
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        
        unordered_map<char, int> tMap;
        for(int i = 0; i < target.size(); i++){
            tMap[target[i]]++;
        }
        
        int cnt = 0;
        int i = 0;
        int minLen = INT_MAX;
        int ind = -1;
        unordered_map<char, int> sMap;
        for(int k = 0; k < source.size(); k++){
            
            char t = source[k];
            if(tMap.find(t) != tMap.end()){
                sMap[t]++;
                if(sMap[t] <= tMap[t]) cnt++;
                
                if(cnt == target.size()) {
                    char x = source[i];
                    while(sMap.find(x) == sMap.end() || sMap[x] > tMap[x]){
                        if(sMap.find(x) != sMap.end()){
                            sMap[x]--;
                        }
                        i++;
                        x = source[i];
                    }
                    
                    if(k-i+1 < minLen) {
                        minLen = k-i+1;
                        ind = i;
                    }

                    // look for next candidate
                    sMap[x]--;
                    i++;
                    cnt--;
                }
            }
        }
        
        if(ind < 0) return "";
        else return source.substr(ind, minLen);
    }
};
