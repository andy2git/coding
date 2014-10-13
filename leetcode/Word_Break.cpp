class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s == "") return true;
        
        // -1: init. 0: false, 1: true
        vector<int> A(s.size()+1, -1);
        A[s.size()] = 1;
        
        return word_break_helper(s, dict, 0, A) > 0;
        
    }
private:
    //b is the start index for the new string s, it is used to mark the index for A
    int word_break_helper(string s, unordered_set<string> &dict, int b, vector<int> &A){
        if(s == "") return 1;
        
        for(int i = 1; i <= s.size(); i++){
            if(dict.find(s.substr(0, i)) != dict.end()){
                if(A[b+i] == -1){
                    A[b+i] = word_break_helper(s.substr(i), dict, b+i, A);
                }
                
                // pre-cached value for A[i]
                if(A[b+i] == 1){
                    return 1;
                }
            }
        }
        
        return 0;
    }
};

