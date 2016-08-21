class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        
        vector<vector<string>> solution;
        vector<vector<bool>> board(n, vector<bool>(n, false));
        
        solve(solution, board, 0);
        
        return solution;
    }
private:    
    void solve(vector<vector<string>> &solution, vector<vector<bool>> &board, int col){
        if(col >= board.size()){
            solution.push_back(board_str(board));
            return;
        }
        
        for(int row = 0; row < board.size(); row++){
            if(is_safe(board, row, col)){
                place_queen(board, row, col);
                solve(solution, board, col+1);
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
        // row and column check for
        for(int j = 0; j < board.size(); j++){
            if(board[row][j]) return false;
            if(board[j][col]) return false;
        }
        
        // check diag
        if(row>=1 && col>=1 && board[row-1][col-1]) return false;
        if(row+1<board.size() && col>1 && board[row+ind][col-ind]) return false;

        return true;
    }
    
    vector<string> board_str(vector<vector<bool>> &board){
        string layer;
        vector<string> result;
        
        for(int i = 0; i < board.size(); i++){
            layer = "";
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j]) layer += 'Q';
                else layer += '.';
            }
            result.push_back(layer);
        }
        return result;
    }
};
