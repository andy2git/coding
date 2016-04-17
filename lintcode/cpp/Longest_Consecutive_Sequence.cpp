/** Solution: search up and down to find the longest consecutive sequence **/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        if(num.size() <= 1) return num.size();
        
        unordered_map<int, bool> map;
        for(int i = 0; i < num.size(); i++){
            map[num[i]] = false;
        }
        
        int maxLen = 1;
        for(auto it = map.begin(); it != map.end(); ++it){
            if(it->second) continue;
            
            int cnt = 1;
            int x = it->first;
            map[x] = true;
            // search up
            while(map.find(++x) != map.end()){
                map[x] = true;
                cnt++;
            }
            
            // search down
            x = it->first;
            while(map.find(--x) != map.end()){
                map[x] = true;
                cnt++;
            }
            
            if(cnt > maxLen) maxLen = cnt;
        }
        
        return maxLen;
    }
};
