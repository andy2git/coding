public class BinaryTreeSerialization {

    private static class TreeNode {
        public int val;
        public TreeNode left, right;

        public TreeNode(int val) {
            this.val = val;
            this.left = this.right = null;
        }
    }

    private static class TreeNodePosition {
        private final TreeNode node;
        private final int pos;

        private TreeNodePosition(TreeNode node, int pos) {
            this.node = node;
            this.pos = pos;
        }

        public static TreeNodePosition of(TreeNode node, int pos) {
            return new TreeNodePosition(node, pos);
        }

        public static TreeNodePosition of(String st) {
            List<String> splits = Splitter.on('#').trimResults().splitToList(st);
            return new TreeNodePosition(new TreeNode(Integer.valueOf(splits.get(0))), Integer.valueOf(splits.get(1)));
        }

        @Override
        public String toString() {
            return node.val + "#" + pos;
        }
    }

    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    public String serialize(TreeNode root) {
        if (root == null) return "";

        List<TreeNodePosition> list = new ArrayList<>();
        Deque<TreeNodePosition> st = new ArrayDeque<>();
        st.push(TreeNodePosition.of(root, 0));

        while (!st.isEmpty()) {
            TreeNodePosition t = st.pop();
            list.add(t);
            if (t.node.left != null) st.push(TreeNodePosition.of(t.node.left, 2 * t.pos + 1));
            if (t.node.right != null) st.push(TreeNodePosition.of(t.node.right, 2 * t.pos + 2));
        }

        StringBuilder sb = new StringBuilder();
        Joiner.on(',').skipNulls().appendTo(sb, list);

        return sb.toString();
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
    public TreeNode deserialize(String data) {

        List<String> list = Splitter.on(',').splitToList(data);
        Map<Integer, TreeNode> posNodeMap = new HashMap<>();

        TreeNode root = null;
        for (String st : list) {
            TreeNodePosition t = TreeNodePosition.of(st);
            posNodeMap.put(t.pos, t.node);

            if (t.pos == 0) {
                root = t.node;
                continue;
            }

            if (t.pos % 2 == 1) {
                posNodeMap.get((t.pos - 1) / 2).left = t.node;
            } else {
                posNodeMap.get((t.pos - 1) / 2).right = t.node;
            }
        }


        return root;
    }

    @Test
    public void test(){
        TreeNode node1 = new TreeNode(3);
        TreeNode node2 = new TreeNode(9);
        TreeNode node3 = new TreeNode(20);
        TreeNode node4 = new TreeNode(15);
        TreeNode node5 = new TreeNode(7);
        node1.left = node2;
        node1.right = node3;
        node3.left = node4;
        node3.right = node5;

        BinaryTreeSerialization solution = new BinaryTreeSerialization();
        System.out.println(solution.serialize(node1));
        System.out.println(solution.serialize(solution.deserialize(solution.serialize(node1))));
    }
}

