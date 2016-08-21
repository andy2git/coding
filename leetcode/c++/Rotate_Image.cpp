class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if(matrix.empty()) return;
        
        fold_dig(matrix);
        fold_horiz(matrix);
        
    }
    
private:
    void fold_dig(vector<vector<int>> &M){
        int n = (int)M.size();
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                swap(M[i][j], M[j][i]);
            }
        }
    }
    
    void fold_horiz(vector<vector<int>> &M){
        int i = 0;
        int j = (int)M.size()-1;
        
        while(i < j){
            swap_col(M, i, j);    
            i++;
            j--;
        }
    }
    
    void swap_col(vector<vector<int>> &M, int i, int j){
        for(int k = 0; k < M.size(); k++){
            swap(M[k][i], M[k][j]);
        }
    }
    
};
