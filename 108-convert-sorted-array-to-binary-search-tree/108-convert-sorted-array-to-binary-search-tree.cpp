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
    TreeNode* buildBST(int start, int end, vector<int>& nums)
    {
        if(start>end)
            return NULL;


        int mid = ( start + end ) / 2; 

        TreeNode* new_node = new TreeNode(nums[mid]); 
        new_node->left = buildBST(start, mid-1, nums); 
        new_node->right = buildBST(mid+1, end, nums); 

        return new_node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(0, nums.size()-1, nums); 
    }
};