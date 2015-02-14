class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        
        int k = A.size();
        vector<vector<int>> t(k+1, vector<int>(m+1, 0));
        
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= m; j++){
                int w = A[i-1];
                if(w > j) t[i][j] = t[i-1][j];
                else t[i][j] = max(t[i-1][j-w]+V[i-1], t[i-1][j]);
            }
        }
        
        return t[k][m];
    }
};


