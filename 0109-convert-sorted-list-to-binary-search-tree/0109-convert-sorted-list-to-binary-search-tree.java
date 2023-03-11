/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        return f(head, null);
    }
    private TreeNode f(ListNode start, ListNode end) {
        if(start == end) return null;
        
        ListNode mid = start, fast = start;
        while(fast != end && fast.next != end) {
            mid = mid.next;
            fast = fast.next.next;
        }
        
        TreeNode currNode = new TreeNode(mid.val);
        currNode.left = f(start, mid);
        currNode.right = f(mid.next, end);
        
        return currNode;
    }
}