class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        
        int i = 0;
        int j = letters.size()-1;
        
        while(i <= j){
            if(letters[i] < 'a') swap(letters[i], letters[j--]);
            else i++;
        }
        
    }
};
