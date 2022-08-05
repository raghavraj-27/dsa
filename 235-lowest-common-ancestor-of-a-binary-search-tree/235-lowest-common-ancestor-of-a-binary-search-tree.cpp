/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // when root is null, root is p or root is q
        if(root == nullptr or root->val == p->val or root->val == q->val)
            return root;
        
        // when root is LCA
        if(root->val < p->val and root->val > q->val) 
            return root;
        if(root->val > p->val and root->val < q->val) 
            return root;
        
        // Now, LCA might exist in left subtree or right subtree
        if(root->val < p->val) return lowestCommonAncestor(root->right, p, q);
        
        return lowestCommonAncestor(root->left, p, q);
    }
};