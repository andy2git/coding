class Solution {
    public String decodeString(String s) {
        if (s == null) return null;

        Deque<Integer> nst = new ArrayDeque<>();
        Deque<Character> st = new ArrayDeque<>();
        int num = 0;
        for (char x : s.toCharArray()) {
            if (Character.isDigit(x)) {
                num = num * 10 + x - '0';
            } else if (x == '[') {
                st.push(x);
                nst.push(num);
                num = 0;
            } else if (x == ']') {
                String tmp = "";
                char t;
                while ((t = st.pop()) != '[') {
                    tmp = t + tmp;
                }
                pushIntoStack(st, repeat(nst.pop(), tmp));
            } else st.push(x);
        }
        String result = "";
        while (!st.isEmpty()) result = st.pop() + result;
        return result;
    }

    private String repeat(int t, String x) {
        String s = "";
        for (int i = 0; i < t; i++) {
            s += x;
        }
        return s;
    }

    private void pushIntoStack(Deque<Character> st, String s) {
        for (char x : s.toCharArray()) {
            st.push(x);
        }
    }
}

// Solution 2: use recursive solution
