class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.empty()) return;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<bool> zRow(m, false);
        vector<bool> zCol(n, false);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0) {
                    zRow[i] = true;
                    zCol[j] = true;
                }
            }
        }
        
        for(int i = 0; i < m; i++) {
            if(zRow[i]) zeroRow(matrix, i);
        }
        for(int i = 0; i < n; i++) {
            if(zCol[i]) zeroCol(matrix, i);
        }
    }
private:
    void zeroRow(vector<vector<int>> &matrix, int i){
        for(int j = 0; j < matrix[i].size(); j++){
            matrix[i][j] = 0;
        }
    }
    
    void zeroCol(vector<vector<int>> &matrix, int i){
        for(int j = 0; j < matrix.size(); j++){
            matrix[j][i] = 0;
        }
    }
};
