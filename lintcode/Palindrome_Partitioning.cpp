class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        if(s == "") return {};
        
        vector<string> sofar;
        vector<vector<string>> result;
        partitionHelper(result, sofar, s, 0);
        
        return result;
    }
private:
    void partitionHelper(vector<vector<string>> &result, vector<string> &sofar, string &remain, int s){
        if(s == remain.size()){
            result.push_back(sofar);
            return;
        }
        
        for(int i = s; i < remain.size(); i++){
            string st = remain.substr(s, i-s+1);
            if(isPalindrome(st)){
                sofar.push_back(st);
                partitionHelper(result, sofar, remain, i+1);
                sofar.pop_back();
            }
        }
    }
    
    bool isPalindrome(string &st){
        int i = 0;
        int j = st.size()-1;
        while(i < j){
            if(st[i++] != st[j--]) return false;
        }
        return true;
    }
};
