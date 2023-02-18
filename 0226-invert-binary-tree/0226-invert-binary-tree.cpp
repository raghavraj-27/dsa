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
    void change(TreeNode* node) {
        if(node == nullptr) return;
        
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
        
        change(node->left);
        change(node->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        change(root);
        return root;
    }
};