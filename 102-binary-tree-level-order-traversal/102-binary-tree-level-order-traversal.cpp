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
    void traverse(TreeNode* node, int level, vector<vector<int>>& res) {
        if(node == nullptr) return;
        if(res.size() == level)
            res.push_back(vector<int>());
        
        res[level].push_back(node->val);
        traverse(node->left, level+1, res);
        traverse(node->right, level+1, res);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        traverse(root, 0, res);
        return res;
    }
};