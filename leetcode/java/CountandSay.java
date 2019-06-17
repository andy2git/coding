class Solution {
    public String countAndSay(int n) {
        if (n <= 0) return "";
        String st = "1";
        String result = "";

        while (n > 1) {
            char x = st.charAt(0);
            int cnt = 1;
            for (int i = 1; i < st.length(); i++) {
                if (st.charAt(i) == x) cnt++;
                else {
                    result = result + cnt + x;
                    x = st.charAt(i);
                    cnt = 1;
                }
            }
            result = result + cnt + x;
            st = result;
            result = "";
            n--;
        }

        return st;
    }
}
