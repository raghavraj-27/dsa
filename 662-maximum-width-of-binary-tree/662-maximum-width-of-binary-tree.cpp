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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int width = 0;
        queue<pair<TreeNode*, long long>> pq;
        pq.push({root, 0});
        
        while(not pq.empty()) {
            int sz = pq.size();
            int mn = pq.front().second;
            
            int first, last;
            for(int i=0; i<sz; i++) {
                long long ind = pq.front().second - mn;
                TreeNode* curr = pq.front().first;
                pq.pop();
                
                if(i==0) first = ind;
                if(i==sz-1) last = ind;
                
                if(curr->left != nullptr) {
                    pq.push({curr->left, 2*ind + 1});
                }
                if(curr->right != nullptr) {
                    pq.push({curr->right, 2*ind + 2});
                }
            }
            
            width = max(width, last - first + 1);
        }
        
        return width;
    }
};