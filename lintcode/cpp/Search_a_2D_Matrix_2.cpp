class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.empty()) return 0;
        
        int cnt = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int i = 0;
        int j = n-1;
        while(i < m && j >= 0){
            if(matrix[i][j] == target) {
                cnt++;
                j--;
            }else if(matrix[i][j] < target) i++;
            else j--;
        }
        
        return cnt;
    }
};
