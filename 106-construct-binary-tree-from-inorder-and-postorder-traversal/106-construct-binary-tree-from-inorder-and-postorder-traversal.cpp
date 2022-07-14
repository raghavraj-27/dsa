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
    map<int, int> inMap;
    
    TreeNode* build(vector<int>& postorder, int postStart, int postEnd,
                   vector<int>& inorder, int inStart, int inEnd) {
        if(postStart > postEnd or inStart > inEnd) return nullptr;
        
        TreeNode* new_node = new TreeNode(postorder[postEnd]);
        int inRoot = inMap[new_node->val];
        int numsLeft = inRoot - inStart;
        
        new_node->left = build(postorder, postStart, postStart+numsLeft-1, inorder, inStart, inRoot-1);
        new_node->right = build(postorder, postStart+numsLeft, postEnd-1, inorder, inRoot+1, inEnd);
        return new_node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        
        TreeNode* root = build(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1);
        return root;
    }
};