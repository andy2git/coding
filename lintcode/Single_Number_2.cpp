/** This problem can be generalized to k*n+1 scenario */
class Solution {
public:
    /**
     * @param A : An integer array
     * @return : An integer 
     */
    int singleNumberII(vector<int> &A) {
        const int N = 32;
        
        int result = 0;
        for(int i = 0; i < N; i++){
            int cnt = 0;
            for(int j = 0; j < A.size(); j++){
                if((A[j]>>i)&1) {
                    cnt++;
                }
            }
            // fix the i bit for the unique element
            result |= (cnt%3) << i;   
        }
        
        return result;
    }
};
