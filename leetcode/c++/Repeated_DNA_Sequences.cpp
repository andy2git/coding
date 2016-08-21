class Solution {
private:
    const int M = 10;
    const int B = 4;
    unordered_map<char, int> bMap= {{'A', 0}, {'C', 1}, {'T', 2}, {'G', 3}};
    vector<char> iMap = {'A', 'C', 'T', 'G'};
    
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() <= M) return {};
        
        unordered_map<int, int> map;
        int ind = getIndex(s, 0, M-1);
        map[ind]++;
        
        int t = pow(B, M-1);
        for(int i = M; i < s.size(); i++){
            ind = (ind%t)*B + bMap[s[i]];
            map[ind]++;
        }
        
        vector<string> result;
        for(auto it = map.begin(); it != map.end(); ++it){
            if(it->second > 1){
                result.push_back(deCode(it->first));
            }
        }
        return result;
    }
    
private:
    string deCode(int ind){
        string st;
        int cnt = M;
        while(cnt > 0){
            st = iMap[ind%B] + st;
            ind /= B;
            cnt--;
        }
        return st;
    }
    
    int getIndex(string &st, int s, int e){
        int ind = 0;
        for(int i = s; i <= e; i++){
            cout << st[i];
            ind = ind*B + bMap[st[i]];
        }
        cout << endl;
        
        return ind;
    }
};
