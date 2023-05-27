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
    TreeNode* transform(int low, int high, vector<int>& trees) {
        if(low > high) return nullptr;
        
        int mid = (low + high)/2;
        TreeNode* new_node = new TreeNode(trees[mid]);
        
        new_node->left = transform(low, mid-1, trees);
        new_node->right = transform(mid+1, high, trees);
        
        return new_node;
    }
    void travel(TreeNode* node, vector<int>& trees) {
        if(node == nullptr) return;
        
        travel(node->left, trees);
        trees.push_back(node->val);
        travel(node->right, trees);
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> trees;
        travel(root, trees);
        return transform(0, trees.size()-1, trees);
    }
};