class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        if(board.empty()) return false;
        
        set<pair<int, int>> map;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(word[0] == board[i][j] && existHelper(map, word, 0, board, i, j)) return true;
            }
        }
        
        return false;
    }
private:
    bool existHelper(set<pair<int,int>> &map, string &st, int k, vector<vector<char>> &A, int i, int j){
        if(k+1 == st.size()) return true;
        
        int m = A.size();
        int n = A[0].size();
        
        vector<pair<int,int>> cand = {{i+1, j}, {i-1, j}, {i, j+1}, {i, j-1}};
        
        for(int d = 0; d < cand.size(); d++){
            int p = cand[d].first;
            int q = cand[d].second;
            if(p < m && p >= 0 && q >= 0 && q < n){
                if(A[p][q] == st[k+1] && map.find({p, q}) == map.end()){
                    map.insert({p, q});
                    if(existHelper(map, st, k+1, A, p, q)) return true;
                    map.erase({p, q});
                }
            }
        }
        
        return false;
    }
};
