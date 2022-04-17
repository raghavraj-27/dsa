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
    void travel(TreeNode* node, vector<int>& inorder) {
        if(node == nullptr) return;
        travel(node->left, inorder);
        inorder.push_back(node->val);
        travel(node->right, inorder);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> inorder;
        travel(root, inorder);
        TreeNode *new_root = new TreeNode(inorder[0]);
        TreeNode *prev = new_root;
        for(int i=1; i<inorder.size(); i++) {
            TreeNode *new_node = new TreeNode(inorder[i]);
            prev->right = new_node;
            new_node->left = nullptr;
            prev = new_node;
        }
        prev->right = nullptr;
        return new_root;
    }
};