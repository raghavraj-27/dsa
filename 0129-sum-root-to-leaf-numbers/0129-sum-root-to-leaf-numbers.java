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
    List<Integer> li;
    private void f(TreeNode node, String s) {
        if(node == null) return;
        
        String digitString = String.valueOf(node.val);
        s = s + digitString;
        
        if(node.left == null && node.right == null) {
            li.add(Integer.parseInt(s));
            return;
        }
        
        f(node.left, s);
        f(node.right, s);
    }
    public int sumNumbers(TreeNode root) {
        li = new ArrayList<>();
        
        f(root, "");
        
        int sum = 0;
        for(int i=0; i<li.size(); i++) {
            sum += li.get(i);
        }
        return sum;
    }
}