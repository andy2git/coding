class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> solution;
        set<vector<int>> unique;
        
        if(num.size() < 4) return solution;
        
        sort(num.begin(), num.end());
        
        for(int i = 0; i < num.size()-3; i++){
            for(int j = i+1; j < num.size(); j++){
                
                int p = j+1;
                int q = num.size()-1;
                
                while(p < q){
                    if(num[i]+num[j]+num[p]+num[q] == target){
                        unique.insert({num[i], num[j], num[p], num[q]});
                        p++;
                        q--;
                    }else if(num[i]+num[j]+num[p]+num[q] > target){
                        q--;
                    }else{
                        p++;
                    }
                }
            }
        }
        
        for(auto it = unique.begin(); it != unique.end(); ++it){
            solution.push_back(*it);
        }
        
        return solution;
    }
};
