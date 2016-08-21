/**
 * bottom up dp 
 */
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int m = triangle.size();
        int n = triangle[0].size();
        
        // if the triangle has only one row, no loop will be executed 
        for(int i = m-2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        
        return triangle[0][0];
    }
};

