/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        if(head == null) return null;
        if(head.next == null) return new TreeNode(head.val);
        
        ListNode p = head;
        ListNode q = head.next.next;
        while(q != null) {
            if(q.next == null) break;
            q = q.next.next;
            p = p.next;
        }
        
        ListNode t = p.next;
        TreeNode root = new TreeNode(t.val);
        p.next = null;
        root.left = sortedListToBST(head);
        root.right = sortedListToBST(t.next);
        return root;
    }
}
