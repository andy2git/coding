class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if(grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        int cnt = 0;
        set<pair<int, int>> mark;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && mark.find({i, j}) == mark.end()){
                    dfsTraverse(i, j, mark, grid);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
    
private:
    // use set<pair<int, int>> to avoid hash() requirement for unordered_set<T>
    void dfsTraverse(int i, int j, set<pair<int, int>> &mark, vector<vector<char>> &grid){
        
        int m = grid.size();
        int n = grid[0].size();
        
        mark.insert({i, j});
        
        if(j+1 < n && grid[i][j+1] == '1' && mark.find({i, j+1}) == mark.end()) dfsTraverse(i, j+1, mark, grid);
        if(j-1 >= 0 && grid[i][j-1] == '1' && mark.find({i, j-1}) == mark.end()) dfsTraverse(i, j-1, mark, grid);
        
        if(i+1 < m && grid[i+1][j] == '1' && mark.find({i+1, j}) == mark.end()) dfsTraverse(i+1, j, mark, grid);
        if(i-1 >= 0 && grid[i-1][j] == '1' && mark.find({i-1, j}) == mark.end()) dfsTraverse(i-1, j, mark, grid);
    }
};
