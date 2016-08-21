/**
 * Solution: look at the structure of the solution.
 * If the loop starts somewhere. Its prefix cannot be < 0.
 * So if the prefix is < 0. The start index has to be the next.
 *       |------------| == 0 | > 0 |
 *
 * Also we have to check if there exists such a solution.
 */

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if(gas.empty() || cost.empty()) return -1;
        
        vector<int> diff(gas.size());
        for(int i = 0; i < gas.size(); i++){
            diff[i] = gas[i] - cost[i];
        }
        
        int sum = 0;
        int remain = 0;
        int ind = 0;

        for(int i = 0; i < diff.size(); i++){
            sum += diff[i];
            remain += diff[i];
            if(sum < 0){
                sum = 0;
                ind = i+1;
            }
        }
        
        if(ind < diff.size() && remain >= 0) return ind;
        else return -1;
    }
};
