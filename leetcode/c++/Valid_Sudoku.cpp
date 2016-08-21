class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int rows = board.size();
        int cols = board[0].size();
        
        for(int i = 0; i < rows; i++){
            if(!is_valid_row(board, i)) return false;
        }
        
        for(int i = 0; i < cols; i++){
            if(!is_valid_col(board, i)) return false;
        }
        
        for(int i = 0; i < rows; i+=3){
            for(int j = 0; j < cols; j+=3){
                if(!is_valid_block(board, i, j)) return false;
            }
        }
        
        return true;
    }

private:
    bool is_valid_block(vector<vector<char>> &board, int x, int y){
        vector<bool> map(10, false);
        
        for(int i = x; i <= x+2; i++){
            for(int j = y; j <= y+2; j++){
                if(board[i][j] == '.') continue;
                
                int x = board[i][j] - '0';
                if(x > 0 && x < 10 && map[x] == false){
                    map[x] = true;
                }else{
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool is_valid_row(vector<vector<char>> &board, int row){
        vector<bool> map(10, false);
        int n = board[0].size();
        
        for(int i = 0; i < n; i++){
            if(board[row][i] == '.') continue;
            
            int x = board[row][i] - '0';
            if(x > 0 && x < 10 && map[x] == false){
                map[x] = true;
            }else{
                return false;
            }
        }
        return true;
    }
    
     bool is_valid_col(vector<vector<char>> &board, int col){
        vector<bool> map(10, false);
        int n = board.size();
        
        for(int i = 0; i < n; i++){
            if(board[i][col] == '.') continue;
            
            int x = board[i][col] - '0';
            if(x > 0 && x < 10 && map[x] == false){
                map[x] = true;
            }else{
                return false;
            }
        }
        return true;
    }
};
