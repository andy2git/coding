class Solution {
public:
    int totalNQueens(int n) {
        
        int num_solutions = 0;
        
        vector<vector<bool>> board(n, vector<bool>(n, false));
        solve(num_solutions, board, 0);
        
        return num_solutions;
    }
private:
    void solve(int &num_solutions, vector<vector<bool>> &board, int col){
        if(col >= board.size()){
            num_solutions++;
            return;
        }
        
        for(int row = 0; row < board.size(); row++){
            if(is_safe(board, row, col)){
                place_queen(board, row, col);
                solve(num_solutions, board, col+1);
                remove_queen(board, row, col);
            }
        }
        
    }
    
    void place_queen(vector<vector<bool>> &board, int row, int col){
        board[row][col] = true;
    }
    
    void remove_queen(vector<vector<bool>> &board, int row, int col){
        board[row][col] = false;
    }
    
    bool is_safe(vector<vector<bool>> &board, int row, int col){
        for(int j = 0; j < board.size(); j++){
            if(board[row][j]) return false;
            if(board[j][col]) return false;
        }
        
        int ind = 1;
        while(row-ind>=0 && col-ind>=0){
            if(board[row-ind][col-ind]) return false;
            ind++;
        }
        
        ind = 1;
        while(row+ind < board.size() && col-ind>=0){
            if(board[row+ind][col-ind]) return false;
            ind++;
        }
        return true;
    }
};
