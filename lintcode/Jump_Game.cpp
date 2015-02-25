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
