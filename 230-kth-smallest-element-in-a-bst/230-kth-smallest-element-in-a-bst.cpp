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
int K, ans;
void f(TreeNode* node) {
    if(node == nullptr) return;

    f(node->left);
    K--;
    if(K == 0) {
        ans = node->val;
        return;
    }
    f(node->right);
}

int kthSmallest(TreeNode* root, int k) {
    K = k;
    f(root);
    return ans;
}
};