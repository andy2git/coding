class Solution {
public:
    vector<vector<string>> partition(string s) {
        if(s == "") return vector<vector<string>>();
        
        vector<vector<string>> result;
        vector<string> t;
        partition_helper(result, t, s);
        
        return result;
    }
    
private:
    void partition_helper(vector<vector<string>> &result, vector<string> &sofar, string rest){
        if(rest.empty()){
            result.push_back(sofar);
            return;
        }
        
        string w;
        for(int i = 0; i < rest.size(); i++){
            w = rest.substr(0, i+1);
            if(is_pal(w)){
                sofar.push_back(w);
                partition_helper(result, sofar, rest.substr(i+1));
                sofar.pop_back();
            }
        }
    }
    
    bool is_pal(string &st){
        int i = 0;
        int j = st.size()-1;
        
        while(i < j){
            if(st[i] != st[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};

