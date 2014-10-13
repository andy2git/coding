/* search anti-diagonally */
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int i = 0;
        int j = n-1;
        while(i < m && j >= 0){
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] < target) i++;
            else j--;
        }
        
        return false;
    }
};

/* binary search based solution */
pair<int, int> search_2D_matrix(vector<vector<int>> &A, int sr, int sc, int er, int ec, int target){
    if(sr > er || sc > ec) return {-1, -1};
    
    int mr = sr + (er-sr)/2;
    int mc = sc + (ec-sc)/2;
    
    if(A[mr][mc] == target) return {mr, mc};
    else if(A[mr][mc] > target) {
        pair<int, int> t = search_2D_matrix(A, sr, sc, er, mc-1, target);
        if(t.first == -1 && t.second == -1) return search_2D_matrix(A, sr, mc, mr-1, ec, target);
        else return t;
    }else{
        pair<int, int> t = search_2D_matrix(A, mr+1, sc, er, mc, target);
        if(t.first == -1 && t.second == -1) return search_2D_matrix(A, sr, mc+1, mr, ec, target);
        else return t;
    }
}
