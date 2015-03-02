/** BFS solution, no need to store the BFS tree */
class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        int n = A.size();
        if(n <= 1) return 0;
        
        int s = 0;
        int e = 0;
        int depth = 1;
        while(true){
            int reach = e;
            for(int i = s; i <= e; i++){
                if(i+A[i] >= n-1) return depth;
                reach = min(i+A[i], n-1);
            }
            s = e+1;
            e = reach;
            depth++;
        }
        
        return -1;
    }
};

/** BFS solution - this BFS does not need to be explictly stored */
class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        int n = A.size();
        queue<int> p, q;
        p.push(0);
        
        int depth = 1;
        while(!p.empty()){
            int t = p.front();
            p.pop();
            
            for(int i = t+1; i <= t+A[t]; i++){
                if(i == n-1) return depth;
                q.push(i);
            }
            
            if(p.empty()){
                swap(p, q);
                depth++;
            }
        }
        
        return -1;
    }
};
