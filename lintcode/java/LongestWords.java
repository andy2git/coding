class Solution {
    /**
     * @param dictionary: an array of strings
     * @return: an arraylist of strings
     */
    List<String> longestWords(String[] dictionary) {
        int maxLen = 0;
        List<String> ret = new ArrayList<>();
        
        for(String st : dictionary) {
            int len = st.length();
            if(len > maxLen){
                maxLen = len;
                ret.clear();
                ret.add(st);
            }else if(len == maxLen){
                ret.add(st);
            }
        }
        
        return ret;
    }
};
