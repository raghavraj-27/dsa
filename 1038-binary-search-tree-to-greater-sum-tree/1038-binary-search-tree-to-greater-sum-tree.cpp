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
    int p;
    void inorder(TreeNode* node, vector<int>& v) {
        if(node == nullptr) return;
        inorder(node->left, v);
        v.push_back(node->val);
        inorder(node->right, v);
    }
    void setValue(TreeNode* node, vector<int>& v) {
        if(node == nullptr) return;
        setValue(node->left, v);
        node->val = v[p++];
        setValue(node->right, v);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> v; 
        inorder(root, v);
        
        int n = v.size(); 
        for(int i=n-2; i>=0; i--) {
            v[i] = v[i] + v[i+1];
        }
        p = 0;
        setValue(root, v);
        return root;
    }
};