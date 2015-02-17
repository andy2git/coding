class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<vector<int>> result;
        vector<int> sofar;
        
        combineHelper(result, sofar, 1, n, k);
        
        return result;
    }
private:
    
    void combineHelper(vector<vector<int>> &result, vector<int> &sofar, 
        int s, int e, int k){
            if(sofar.size() == k){
                result.push_back(sofar);
                return;
            }
            
            for(int i = s; i <= e; i++){
                sofar.push_back(i);
                combineHelper(result, sofar, i+1, e, k);
                sofar.pop_back();
            }
        }
};
