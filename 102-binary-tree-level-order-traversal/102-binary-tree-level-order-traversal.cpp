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

void traverse(TreeNode* root, int level) 
{
    if(root == NULL) 
        return; 

    levels[level].push_back(root->val);
    traverse(root->left, level+1);
    traverse(root->right, level+1);
}

vector<vector<int>> levelOrder(TreeNode* root) {
    traverse(root, 0);

    vector<vector<int>> ans; 
    for(auto v : levels) {
        ans.push_back(v.second);
    }

    return ans;
}
};