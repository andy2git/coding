class Solution {
public:
    int singleNumber(int A[], int n) {
        unordered_map<int, int> map;
        
        for(int i = 0; i < n; i++){
            map[A[i]]++;
        }
        
        for(auto it = map.begin(); it != map.end(); ++it){
            if(it->second != 3) return it->first;
        }
    }
};
