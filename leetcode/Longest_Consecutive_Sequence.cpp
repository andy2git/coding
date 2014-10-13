class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if(num.empty()) return 0;
        if(num.size() == 1) return 1;
        
        unordered_map<int, bool> map;
        for(int i = 0; i < num.size(); i++){
            map[num[i]] = false;
        }
        
        int max_len = INT_MIN;
        int len;
        int p;
        for(int i = 0; i < num.size(); i++){
            if(map[num[i]]) continue;

            len = 1;
            map[num[i]] = true;
            
            // search the increasing direction
            p = num[i]+1;
            while(map.find(p) != map.end()){
                len++;
                map[p] = true;
                p++;
            }
            // search the decreasing direction
            p = num[i]-1;
            while(map.find(p) != map.end()){
                len++;
                map[p] = true;
                p--;
            }
            
            if(len > max_len){
                max_len = len;
            }
        }
        
        return max_len;
    }
};
