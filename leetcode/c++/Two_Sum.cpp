class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        if(numbers.size() < 2) return {-1, -1};
        
        unordered_map<int, int> map;
        vector<int> result;
        
        for(int i = 0; i < numbers.size(); i++){
            auto it = map.find(target-numbers[i]);
            
            if(it != map.end()){
                result.push_back(it->second);
                result.push_back(i+1);
                return result;
            }else{
                map[numbers[i]] = i+1;
            }
        }
        
        return {-1, -1};
    }
};





class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
       if(numbers.size() < 2) return {-1, -1};
       
       vector<int> A(numbers.begin(), numbers.end());
       sort(A.begin(), A.end());
       
       int i = 0;
       int j = numbers.size()-1;
       int x = -1;
       int y = -1;
       
       while(i < j){
           int t = A[i] + A[j];
           if(t == target){
               x = A[i];
               y = A[j];
               break;
           }else if(t < target){
               i++;
           }else{
               j--;
           }
       }
       
       if(x == -1 || y == -1) return {-1, -1};
       
       int ind_x = -1;
       int ind_y = -1;
       for(int i = 0; i < numbers.size(); i++){
           if(ind_x == -1 && numbers[i] == x){
               ind_x = i+1;
               if(ind_y > -1) break;
               else continue;
           }
           if(ind_y == -1 && numbers[i] == y){
               ind_y = i+1;
               if(ind_x > -1) break;
               else continue;
           }
       }
       
       if(ind_x < ind_y){
           return {ind_x, ind_y};
       }else{
           return {ind_y, ind_x};
       }
    }
};
