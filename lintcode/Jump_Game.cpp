/** Solution: t[i]: jumpable from A[i] to the end */
class Solution { 
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        int n = A.size();
        vector<bool> t(n, false);
        t[n-1] = true;
        
        for(int i = n-2; i >= 0; i--){
            for(int j = i+1; j <= n-1; j++){
                if(t[j] && A[i] >= j-i){
                    t[i] = true;
                    break;
                }
            }
        }
        
        return t[0];
    }
};

/** Solution: t[i]: jumpable from A[0] to A[i] */
class Solution { 
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        int n = A.size();
        vector<bool> t(n, false);
        t[0] = true;
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(t[j] && A[j] >= i-j){
                    t[i] = true;
                    break;
                }
            }
        }
        
        return t[n-1];
    }
};


/* BFS solution */
class Solution { 
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        int n = A.size();
        
        // index queue
        queue<int> p;
        p.push(0);
        
        while(!p.empty()){
            int t = p.front();
            p.pop();
            
            for(int i = t+1; i <= t+A[t]; i++){
                if(i == n-1) return true;
                p.push(i);
            }
        }
        
        return false;
    }
};
