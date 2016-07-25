public class Solution {
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    public int evalRPN(String[] tokens) {
        if (tokens.length == 0) return 0;

        Deque<Integer> st = new ArrayDeque<>();
        for (String x : tokens) {
            if (isOp(x)) {
                int a = st.pop();
                int b = st.pop();
                st.push(evaExp(b, a, x));
            } else {
                st.push(Integer.valueOf(x));
            }
        }

        if (st.size() > 1) throw new IllegalArgumentException("wrong RPN format");
        else return st.pop();
    }

    private final static Set<String> OPERATORS = new HashSet<>(Arrays.asList("+", "-", "*", "/"));

    private boolean isOp(String x) {
        return OPERATORS.contains(x);
    }
    
    private int evaExp(int a, int b, String x) {
        return Operation.fromVal(x).apply(a, b);
    }

    private enum Operation {
        ADD("+") {
            @Override
            int apply(int x, int y) {
                return x+y;
            }
        },
        SUB("-") {
            @Override
            int apply(int x, int y) {
                return x - y;
            }
        },
        MUL("*") {
            @Override
            int apply(int x, int y) {
                return x * y;
            }
        },
        DIV("/") {
            @Override
            int apply(int x, int y) {
                return x / y;
            }
        };

        private final String val;
        private static final Map<String, Operation> stToEnum = new HashMap<>();
        static {
            for (Operation op : values()) {
                stToEnum.put(op.val, op);
            }
        }

        public static Operation fromVal(String symbol) {
            return stToEnum.get(symbol);
        }

        Operation(String val) {
            this.val = val;
        }

        abstract int apply(int x, int y);
    }
}
