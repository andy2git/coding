class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        if(num.size() < 4) return {};

        vector<vector<int>> result;
        sort(num.begin(), num.end());
        
        for(int i = 0; i < num.size()-3; i++){
            if(i > 0 && num[i] == num[i-1]) continue;
            for(int j = i+1; j < num.size()-2; j++){
                // a duplicate after using once
                if(j > i+1 && num[j] == num[j-1]) continue;
                
                int p = j+1;
                int q = num.size()-1;
                
                while(p < q){
                    if(num[i]+num[j]+num[p]+num[q] == target){
                        result.push_back({num[i], num[j], num[p], num[q]});
                        p++;
                        q--;
                        while(num[p] == num[p-1]) p++;
                        while(num[q] == num[q+1]) q--;
                    }else if(num[i]+num[j]+num[p]+num[q] > target){
                        q--;
                    }else{
                        p++;
                    }
                }
            }
        }
        
        return result;
    }
};
