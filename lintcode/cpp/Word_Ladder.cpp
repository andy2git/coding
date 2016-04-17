class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start == end) return 1;
        
        queue<string> p, q;
        unordered_set<string> mark;
        p.push(start);
        mark.insert(start);
        
        int depth = 1;
        while(!p.empty()){
            string st = p.front();
            p.pop();
            
            bool status = fillQueue(st, end, q, dict, mark);
            if(status) return depth+1;
            if(p.empty()) {
                swap(p, q);
                depth++;
            }
        }
        
        return 0;
    }
private:
    bool fillQueue(string &st, string &target, queue<string> &q, unordered_set<string> &dict, unordered_set<string> &mark){
        for(int i = 0; i < st.size(); i++){
            char x = st[i];
            
            for(char k = 'a'; k <= 'z'; k++){
                if(k != x) {
                    st[i] = k;
                    if(st == target) return true;
                    if(dict.find(st) != dict.end() && mark.find(st) == mark.end()){
                        q.push(st);
                        mark.insert(st);
                    }
                }
            }
            st[i] = x;
        }
        return false;
    }
};
