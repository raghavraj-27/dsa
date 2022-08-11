/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool f(TreeNode* node, long mn, long mx) {
        if(node == nullptr) return true;
        
        if(mn >= node->val or mx <= node->val) return false;
        
        bool l = f(node->left, mn, node->val);
        bool r = f(node->right, node->val, mx);
        
        return l and r;
    }
    
    bool isValidBST(TreeNode* root) {
        return f(root, LONG_MIN, LONG_MAX);
    }
};