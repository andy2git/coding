class Solution {
    const char O_CHAR = 'O';
    const char X_CHAR = 'X';
    const char N_CHAR = 'N';
public:
    void solve(vector<vector<char>> &board) {
        if(board.empty()) return;
        
        int m = board.size();
        int n = board[0].size();
        
        queue<pair<int, int>> q;
        initQueue(q, board);
        
        while(!q.empty()){
            pair<int, int> t = q.front();
            q.pop();
            
            int x = t.first;
            int y = t.second;
            
            if(y>=1 && board[x][y-1] == O_CHAR){
               q.push({x, y-1});
               board[x][y-1] = N_CHAR;
            }
            if(x>=1 && board[x-1][y] == O_CHAR){
               q.push({x-1, y});
               board[x-1][y] = N_CHAR;
            }
            if(y<n-1 && board[x][y+1] == O_CHAR){
               q.push({x, y+1});
               board[x][y+1] = N_CHAR;
            }
            if(x<m-1 && board[x+1][y] == O_CHAR){
               q.push({x+1, y});
               board[x+1][y] = N_CHAR;
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == N_CHAR) board[i][j] = O_CHAR;
                else if(board[i][j] == O_CHAR) board[i][j] = X_CHAR;
            }
        }
    }
    
private:
    void initQueue(queue<pair<int, int>> &q, vector<vector<char>> &board){
        int m = board.size();
        int n = board[0].size();
        
        for(int j = 0; j < n; j++){
            if(board[0][j] == O_CHAR) {
                q.push({0,j});
                board[0][j] = N_CHAR;
            }
            if(board[m-1][j] == O_CHAR){
                q.push({m-1,j});
                board[m-1][j] = N_CHAR;
            }
        }
        
        for(int i = 1; i < m-1; i++){
            if(board[i][0] == O_CHAR){
                q.push({i,0});
                board[i][0] = N_CHAR;
            }
            if(board[i][n-1] == O_CHAR){
                q.push({i,n-1});
                board[i][n-1] = N_CHAR;
            }
        }
    }
};
