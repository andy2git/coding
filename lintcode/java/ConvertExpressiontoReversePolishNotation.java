public class Solution {
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    public ArrayList<String> convertToRPN(String[] expression) {
        Deque<String> st = new ArrayDeque<>();
        ArrayList<String> ret = new ArrayList<>();
        assignOpPriority();

        for (String exp : expression) {
            if (!isOpand(exp)) {
                ret.add(exp);
            } else {
                if (st.isEmpty() || exp.equals("(")) {
                    st.push(exp);
                } else {
                    if (exp.equals(")")) {
                        while (!st.peek().equals("(")) {
                            ret.add(st.pop());
                        }
                        st.pop();
                    } else {
                        while (!st.isEmpty() && lessPriority(exp, st.peek())) {
                            ret.add(st.pop());
                        }
                        st.push(exp);
                    }
                }
            }
        }

        while (!st.isEmpty()) {
            ret.add(st.pop());
        }

        return ret;
    }

    private boolean isOpand(String exp) {
        return priority.containsKey(exp);
    }

    private final Map<String, Integer> priority = new HashMap<>();

    private boolean lessPriority(String lhs, String rhs) {
        return priority.get(lhs) <= priority.get(rhs);
    }

    private void assignOpPriority() {
        priority.put("*", 2);
        priority.put("/", 2);
        priority.put("+", 1);
        priority.put("-", 1);
        priority.put("(", 0);
        priority.put(")", 0);
    }
}
