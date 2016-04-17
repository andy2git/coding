class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        return (n&mask(i, j)) + (m<<i);
    }
private:
    int mask(int i, int j){
        int result = 0;
        for(int k = 31; k >= 0; k--){
            if(k > j || k < i) result = (result << 1) + 1;
            else result = result << 1;
        }
        return result;
    } 
};
