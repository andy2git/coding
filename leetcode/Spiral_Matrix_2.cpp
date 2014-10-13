class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        if(n <= 0) return {};
        
        vector<vector<int>> result(n, vector<int>(n, 0));
        int x1 = 0, y1 = 0, x2 = n-1, y2 = n-1;
        int flag = true;
        int ind = 1;
        
        while(x1 <= x2 && y1 <= y2){
            if(flag) {
                print_spiral(result, x1, y1, x2, y2, flag, ind);
                x1++;
                y2--;
                flag = false;
            }else{
                print_spiral(result, x1, y1, x2, y2, flag, ind);
                y1++;
                x2--;
                flag = true;
            }
        }
        
        return result;
    }
    
private:
    // [(x1, y1), (x2, y2)]
    void print_spiral(vector<vector<int>> &result, int x1, int y1, int x2, int y2, bool flag, int &ind){
        if(flag){
            for(int i = y1; i <= y2; i++){
                result[x1][i] = ind++;       
            }        
            for(int i = x1+1; i <= x2; i++){
                result[i][y2] = ind++;
            }
        }else{
            for(int i = y2; i >= y1; i--){
                result[x2][i] = ind++;       
            }        
            for(int i = x2-1; i >= x1; i--){
                result[i][y1] = ind++;
            }
        }
    }
};
