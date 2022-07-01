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
void findkthSmallest(TreeNode* root, int &k)
{
    if(root == NULL) return; 

    findkthSmallest(root->left, k); 
    k--; 

    if(k == 0) {
        ans = root->val;
    }
    
    findkthSmallest(root->right, k); 
}

int kthSmallest(TreeNode* root, int k) {
    findkthSmallest(root, k); 
    return ans;
}
};