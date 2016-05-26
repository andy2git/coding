public class BinaryTreePaths {
    private static class TreeNode {
        private final int val;
        private final TreeNode left, right;

        TreeNode(int val) {
            this.val = val;
            this.left = this.right = null;
        }
    }

    public List<String> binaryTreePaths(TreeNode root) {
        if (root == null) return Collections.emptyList();
        if (root.left == null && root.right == null) return Arrays.asList(String.valueOf(root.val));

        List<String> leftSuffix = binaryTreePaths(root.left);
        List<String> rightSuffix = binaryTreePaths(root.right);

        List<String> results = new ArrayList<>();
        for (String st : leftSuffix) {
            results.add(root.val + "->" + st);
        }

        for (String st : rightSuffix) {
            results.add(root.val + "->" + st);
        }

        //NOTE: Collections.unmodifiableList(results) does not work for lintcode
        return results;
    }

    @Test
    public void test() {
        TreeNode node1 = new TreeNode(1);
        TreeNode node2 = new TreeNode(2);
        TreeNode node3 = new TreeNode(3);
        TreeNode node4 = new TreeNode(5);
        node1.left = node2;
        node1.right = node3;
        node2.right = node4;

        BinaryTreePaths btp = new BinaryTreePaths();
        System.out.println(btp.binaryTreePaths(node1));
    }

}
