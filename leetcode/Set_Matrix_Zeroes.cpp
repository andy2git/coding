class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.empty()) return;
        
        vector<bool> row(matrix.size(), false);
        vector<bool> col(matrix[0].size(), false);
        
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        
        // zero out all rows
        for(int i = 0; i < row.size(); i++){
            if(row[i]){
                for(int j = 0; j < matrix[i].size(); j++){
                    matrix[i][j] = 0;
                }
            }
        }
        
        // zero out all cols
        for(int i = 0; i < col.size(); i++){
            if(col[i]){
                for(int j = 0; j < matrix.size(); j++){
                    matrix[j][i] = 0;
                }
            }
        }
        

    }
};
