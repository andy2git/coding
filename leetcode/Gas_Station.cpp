class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        vector<int> left(gas.size());
        
        for(int i = 0; i < gas.size(); i++){
            left[i] = gas[i] - cost[i];
        }
        
        int s = 0;
        int sum = 0;
        int t_sum = 0;
        
        for(int i = 0; i < left.size(); i++){
            sum += left[i];
            t_sum += left[i];
            
            if(sum < 0){
                sum = 0;
                s = i+1;
            }
        }
        if(s >= left.size() || t_sum < 0) return -1;
        else return s;
        
    }
};
