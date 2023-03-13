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
    public boolean isSymmetric(TreeNode root) {
        return f(root.left, root.right);
    }
    private boolean f(TreeNode nodeL, TreeNode nodeR) {
        if(nodeL == null && nodeR == null) return true;
        if(nodeL == null && nodeR != null) return false;
        if(nodeL != null && nodeR == null) return false;
        
        if(nodeL.val != nodeR.val) return false;
        
        boolean r1 = f(nodeL.left, nodeR.right);
        boolean r2 = f(nodeL.right, nodeR.left);
        
        return r1 && r2;
    }
}