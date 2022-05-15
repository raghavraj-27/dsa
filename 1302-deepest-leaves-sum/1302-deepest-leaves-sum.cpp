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
    int sum=0;
    
    int height(TreeNode * root)
    {
        if(root)
        {
            int leftH = height(root->left);
            int rightH = height(root->right);
            return max(leftH, rightH) + 1;
        }
        return 0;
    }
    
    void sumDeepNode(TreeNode * root, int depth)
    {
        if(root)
        {
            if(depth == 1)
                sum += root->val;
            else 
            {
                sumDeepNode(root->left, depth-1);
                sumDeepNode(root->right, depth-1);   
            }
        }
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int depth = height(root);
        
        sumDeepNode(root, depth);
        
        return sum;
    }
};