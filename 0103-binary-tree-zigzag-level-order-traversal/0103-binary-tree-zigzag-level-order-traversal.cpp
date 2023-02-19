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
    map<int, vector<int>> levels;
    void traverse(TreeNode* node, int l) {
        if(node == nullptr) return;
        
        levels[l].push_back(node->val);
        traverse(node->left, l+1);
        traverse(node->right, l+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        traverse(root, 0);
        
        vector<vector<int>> ans;
        for(auto p: levels) {
            ans.push_back(p.second);
            if(ans.size() % 2 == 0) {
                reverse(ans[ans.size()-1].begin(), ans[ans.size()-1].end());
            }
        }
        
        return ans;
    }
};