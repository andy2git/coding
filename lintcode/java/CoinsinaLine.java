public class Solution {
    /**
     * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
    public boolean firstWillWin(int n) {
        if(n < 0) throw new IllegalArgumentException("xxx");
        
        if(n%3 == 0){
            return false;
        }
        
        return true;
    }
}
