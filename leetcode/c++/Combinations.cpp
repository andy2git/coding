/**
 *                    1234
 *                 1, 234  2,34  3,4
 *     [x,_]: x can be anything, and _ is supposed to be bigger than x
 */
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> t;
        combine_helper(result, t, 1, n, k);
        return result;
    }
    
private:
    void combine_helper(vector<vector<int>> &result, vector<int> &sofar, int s, int n, int k){
        if(sofar.size() == k){
            result.push_back(sofar);
            return;
        }
        
        for(int i = s; i <= n; i++){
            sofar.push_back(i);
            combine_helper(result, sofar, i+1, n, k);
            sofar.pop_back();
        }
    }
};
