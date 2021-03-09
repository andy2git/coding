/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {
    
    private static class NI {
        private final TreeNode node;
        private final int index;

        NI(TreeNode node, int index) {
            this.node = node;
            this.index = index;
        }
    }

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        String result = "";
        if (root == null) return result;

        Queue<NI> queue = new ArrayDeque<>();
        queue.offer(new NI(root, 0));
        while (!queue.isEmpty()) {
            NI x = queue.poll();
            result = result + x.node.val + "#" + x.index + ";";
            if (x.node.left != null) queue.offer(new NI(x.node.left, 2 * x.index + 1));
            if (x.node.right != null) queue.offer(new NI(x.node.right, 2 * x.index + 2));
        }
        return result.substring(0, result.length() - 1);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        List<int[]> values = load(data);

        TreeNode root = null;
        Map<Integer, TreeNode> map = new HashMap<>();
        for (int[] val : values) {
            int ind = val[1];
            if (ind == 0) {
                root = new TreeNode(val[0]);
                map.put(0, root);
            } else {
                int p = (ind-1) / 2;
                TreeNode node = new TreeNode(val[0]);
                map.put(ind, node);
                if (ind % 2 == 0) map.get(p).right = node;
                else map.get(p).left = node;
            }
        }
        return root;
    }

    private List<int[]> load(String data) {
        if (data == null || data.length() == 0) return Collections.emptyList();
        String[] values = data.split(";");
        List<int[]> result = new ArrayList<>();
        for(String val : values) {
            String[] x = val.split("#");
            result.add(new int[]{Integer.valueOf(x[0]), Integer.valueOf(x[1])});
        }
        return result;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));
