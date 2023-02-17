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
    
    pair<int, int> f(TreeNode* node, int mini, int maxi) {
        pair<int, int> pl, pr;
        if(node->left == nullptr) {
            pl = {100001, -100001};
        } else {
            pl = f(node->left, mini, maxi);
        }
        
        if(node->right == nullptr) {
            pr = {100001, -100001};
        } else {
            pr = f(node->right, mini, maxi);
        }
        
        ans = min(ans, node->val - pl.second);
        ans = min(ans, pr.first - node->val);
        
        return {min(pl.first, node->val), max(pr.second, node->val)};
    }
    int getMinimumDifference(TreeNode* root) {
        ans = INT_MAX;
        f(root, INT_MAX, INT_MIN);
        return ans;
    }
};