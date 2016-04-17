class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        int k = A.size();
        vector<vector<int>> t(2, vector<int>(m+1, 0));
        
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= m; j++){
                int w = A[i-1];
                if(w > j) t[i%2][j] = t[(i-1)%2][j];
                else{
                    t[i%2][j] = max(t[(i-1)%2][j-w]+w, t[(i-1)%2][j]);
                }
            }
        }
        
        return t[k%2][m];
    }
};


