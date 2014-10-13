class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        
        if(dist(start, end) == 1) return 2;
        
        queue<string> fq1, fq2;
        map<string, bool> fmap;
        
        fq1.push(start);
        fmap[start] = true;
        
        string w;
        int f_dep = 1;
        
        while(!fq1.empty()){
            w = fq1.front();
            fq1.pop();
            
            for(int i = 0; i < w.size(); i++){
                char p = w[i];
                for(char t = 'a'; t <= 'z'; t++){
                    w[i] = t;
                    if(w == end) return f_dep+1;
                    if(dict.find(w) != dict.end() && !fmap[w]){
                        fq2.push(w);
                        fmap[w] = true;
                    }
                }
                w[i] = p;
            }
            
            if(fq1.empty()){
                swap(fq1, fq2);
                f_dep++;
            }
        }
        
        return 0;
    }
    
private:
    
    int dist(string &s, string &t){
        int cnt = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] != t[i]) cnt++;
        }
        return cnt;
    }
};

/*
 * Without the quick distance check in the front.
 */

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        
        queue<string> fq1, fq2;
        map<string, bool> fmap;
        
        fq1.push(start);
        fmap[start] = true;
        
        string w;
        int f_dep = 1;
        
        while(!fq1.empty()){
            w = fq1.front();
            fq1.pop();
            
            for(int i = 0; i < w.size(); i++){
                char p = w[i];
                for(char t = 'a'; t <= 'z'; t++){
                    w[i] = t;
                    if(w == end) return f_dep+1;
                    if(dict.find(w) != dict.end() && !fmap[w]){
                        fq2.push(w);
                        fmap[w] = true;
                    }
                }
                w[i] = p;
            }
            
            if(fq1.empty()){
                swap(fq1, fq2);
                f_dep++;
            }
        }
        
        return 0;
    }
};

