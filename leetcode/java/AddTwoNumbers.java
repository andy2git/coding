public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;

        int cb = 0;
        ListNode pre = null;
        ListNode p = l1;
        while (p != null && l2 != null) {
            cb = computeSum(p, l2, cb);
            pre = p;
            p = p.next;
            l2 = l2.next;
        }

        if (l2 != null) {
            pre.next = l2;
            p = l2;
        }

        while (p != null) {
            cb = computeSum(p, null, cb);
            pre = p;
            p = p.next;
        }

        if (cb == 1) {
            pre.next = new ListNode(1);
        }

        return l1;
    }

    private int computeSum(ListNode x, ListNode y, int cb) {
        if (x == null) throw new IllegalArgumentException("xxx");

        int t = 0;
        if (y != null) t = y.val;

        x.val = x.val + t + cb;
        cb = 0;
        if (x.val >= 10) {
            cb = 1;
            x.val %= 10;
        }
        return cb;
    }
}
