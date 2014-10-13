// find the unique solution without using set<T>
// One example:
// [1, 1, 2, 2, 2] 
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> result;
        if(num.size() < 3) return result;
        
        sort(num.begin(), num.end());
        int j, k;
        int sum;
        for(int i = 0; i < num.size()-2; i++){
            // index i is used to filter out the duplicate case for j
            if(i > 0 && num[i] == num[i-1]) continue;
            
            j = i+1;
            k = num.size()-1;
            
            while(j < k){
                sum = num[i] + num[j] + num[k];
                if(sum == 0){
                    result.push_back({num[i], num[j], num[k]});
                    while(num[j+1] == num[j]) j++;
                    while(num[k-1] == num[k]) k--;
                    j++;
                    k--;
                }else if(sum < 0){
                    j++;
                }else{
                    k--;
                }
            }
        }
        
        return result;
    }
};

// Using set<T> to filter out the duplicated element
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> result;
        if(num.size() < 3) return result;
        
        sort(num.begin(), num.end());
        
        set<vector<int>> unique;
        int j, k;
        int sum;
        for(int i = 0; i < num.size()-2; i++){
            j = i+1;
            k = num.size()-1;
            
            while(j < k){
                sum = num[i] + num[j] + num[k];
                if(sum == 0){
                    unique.insert({num[i], num[j], num[k]});
                    j++;
                    k--;
                }else if(sum < 0){
                    j++;
                }else{
                    k--;
                }
            }
        }
        
        for(auto it = unique.begin(); it != unique.end(); ++it){
            result.push_back(*it);
        }
        
        return result;
    }
};
