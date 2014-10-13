class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if(board.empty()) return;
        
        int m = board.size();
        int n = board[0].size();
        
        queue<int> q;
        
        // top row and the last row
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O'){
                board[0][j] = 'n';
                q.push(s_index(0, j, n));
            }
            if(board[m-1][j] == 'O'){
                board[m-1][j] = 'n';
                q.push(s_index(m-1,j, n));
            }
        }
        
        // top col and the last col
        for(int i = 1; i < m-1; i++){
            if(board[i][0] == 'O'){
                board[i][0] = 'n';
                q.push(s_index(i, 0, n));
            }
            if(board[i][n-1] == 'O'){
                board[i][n-1] = 'n';
                q.push(s_index(i,n-1, n));
            }
        }
        
        int t;
        int x, y;
        while(!q.empty()){
            t = q.front();
            q.pop();
            d_index(t, x, y, n);
            
            if(x > 0 && board[x-1][y] == 'O') {
                board[x-1][y] = 'n';
                q.push(s_index(x-1, y, n));
            }
            if(y > 0 && board[x][y-1] == 'O') {
                board[x][y-1] = 'n';
                q.push(s_index(x, y-1, n));
            }
            if(y < n-1 && board[x][y+1] == 'O') {
                board[x][y+1] = 'n';
                q.push(s_index(x, y+1, n));
            }
            if(x < m-1 && board[x+1][y] == 'O') {
                board[x+1][y] = 'n';
                q.push(s_index(x+1, y, n));
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'n') {
                    board[i][j] = 'O';
                    continue;
                }
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                    continue;
                }
            }
        }
    }
private:
    int s_index(int i, int j, int n){
        return i*n + j;
    }
    
    void d_index(int ind, int &i, int &j, int n){
        j = ind%n;
        i = ind/n;
    }
};
