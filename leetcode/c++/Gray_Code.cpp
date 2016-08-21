class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0) return {0};
        
        vector<int> result = {0, 1};
        int k = 1;
        int add = 1;
        int t;
        
        while(k < n){
            t = result.size();
            add *= 2;
            for(int i = t-1; i >= 0; i--){
                result.push_back(result[i]+add);
            }
            k++;
        }
        
        return result;
    }
};
