class Solution {
public:
    int majorityElement(vector<int> &num) {
        int cand = num[0];
        int count = 1;
        
        for(int i = 1; i < num.size(); i++){
            if(count == 0) {
                cand = num[i];
                count = 1;
                continue;
            }
            
            if(num[i] == cand) count++;
            else count--;
        }
        if(count > 0) return cand;
    }
};
