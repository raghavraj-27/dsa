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
    int ans;
    void findKthSmallest(TreeNode* node, int& k) {
        if(node == nullptr) return;
        
        findKthSmallest(node->left, k);
        k--;
        if(k == 0) {
            ans = node->val;
            return;
        }
        findKthSmallest(node->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        ans = 1;
        findKthSmallest(root, k);
        return ans;
    }
};