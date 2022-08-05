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
    
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if(preStart > preEnd or inStart > inEnd) return nullptr;
        
        TreeNode* new_node = new TreeNode(preorder[preStart]);
        int inRoot = inMap[new_node->val];
        int numsLeft = inRoot - inStart;
        
        new_node->left = build(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1);
        new_node->right = build(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd);
        
        return new_node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};