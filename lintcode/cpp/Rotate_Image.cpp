class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void rotate(vector<vector<int> > &matrix) {
        // write your code here
        int n = matrix.size();
        
        swapDig(matrix);
        int i = 0;
        int j = n-1;
        while(i < j){
            swapRow(matrix, i++, j--);
        }
    }
    
private:
    void swapRow(vector<vector<int>> &m, int i, int j){
        int n = m.size();
        
        for(int k = 0; k < n; k++){
            swap(m[k][i], m[k][j]);
        }
    }
    
    void swapDig(vector<vector<int>> &m){
        int n = m.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                swap(m[i][j], m[j][i]);
            }
        }
    }
};

