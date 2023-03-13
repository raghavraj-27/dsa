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
    bool f(TreeNode* nodeL, TreeNode* nodeR) {
        if(nodeL == nullptr and nodeR != nullptr) return false;
        if(nodeL != nullptr and nodeR == nullptr) return false;
        if(nodeL == nullptr and nodeR == nullptr) return true;
        if(nodeL->val != nodeR->val) return false;
        bool r1 = f(nodeL->left, nodeR->right);
        bool r2 = f(nodeL->right, nodeR->left);
        return r1 and r2;
    }
    bool isSymmetric(TreeNode* root) {
        return f(root->left, root->right);
    }
};