class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.empty()) return false;
        
        int r = matrix.size();
        int c = matrix[0].size();
        int l = 0;
        int h = r*c-1;
        
        while(l <= h){
            int m = l + (h-l)/2;
            int x = matrix[m/c][m%c];
            
            if(x == target) return true;
            else if(x < target) l = m+1;
            else h = m-1;
        }
        
        return false;
    }
};
