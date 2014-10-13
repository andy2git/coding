class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if(matrix.empty()) return {};
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int x1 = 0, y1 = 0, x2 = m-1, y2 = n-1;
        int flag = true;
        vector<int> result;
        
        while(x1 <= x2 && y1 <= y2){
            if(flag) {
                print_spiral(result, matrix, x1, y1, x2, y2, flag);
                x1++;
                y2--;
                flag = false;
            }else{
                print_spiral(result, matrix, x1, y1, x2, y2, flag);
                y1++;
                x2--;
                flag = true;
            }
        }
        return result;
    }

private:
    // [(x1, y1), (x2, y2)]
    void print_spiral(vector<int> &result, vector<vector<int>> &m, int x1, int y1, int x2, int y2, bool flag){
        if(flag){
            for(int i = y1; i <= y2; i++){
                result.push_back(m[x1][i]);       
            }        
            for(int i = x1+1; i <= x2; i++){
                result.push_back(m[i][y2]);
            }
        }else{
            for(int i = y2; i >= y1; i--){
                result.push_back(m[x2][i]);       
            }        
            for(int i = x2-1; i >= x1; i--){
                result.push_back(m[i][y1]);
            }
        }
    }
};
