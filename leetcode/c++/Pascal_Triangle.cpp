/* lower half of a 2-d matrix 
 * 
 * 1
 * 1 1
 * 1 2 1
 * 1 3 3 1
 */
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        if(numRows <= 0) return {};

        vector<vector<int>> result;
        result.push_back({1});
        
        vector<int> row;
        for(int i = 1; i < numRows; i++){
            row.clear();
            for(int j = 0; j <= i; j++){
                if(j == 0) row.push_back(1);
                else if(j == i) row.push_back(1);
                else row.push_back(result[i-1][j-1] + result[i-1][j]);
            }
            result.push_back(row);
        }
        
        return result;
    }
};
