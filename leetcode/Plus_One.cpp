class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int cbit = 1;
        vector<int> result(digits);
        
        for(int i = digits.size()-1; i >= 0; i--){
            if(digits[i] == 9){
                if(cbit == 1){
                    cbit = 1;
                    result[i] = 0;
                }
            }else{
                if(cbit == 1){
                    cbit = 0;
                    result[i]++;
                }
            }
        }
        
        if(cbit == 1) result.insert(result.begin(), 1);
        
        return result;
    }
};
