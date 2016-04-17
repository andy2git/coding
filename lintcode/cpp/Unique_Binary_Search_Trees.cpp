class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        if(n <= 1) return 1;
        
        vector<int> t(n+1, 1);
        
        for(int i = 2; i <= n; i++){
            int sum = 0;
            for(int j = 1; j <= i; j++){
                sum += t[j-1]*t[i-j];
            }
            t[i] = sum;
        }
        
        return t[n];
    }
};
