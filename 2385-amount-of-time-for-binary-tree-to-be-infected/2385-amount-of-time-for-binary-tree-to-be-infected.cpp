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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        unordered_map<TreeNode*, bool> vis;
        TreeNode* target = nullptr;
        
        queue<TreeNode*> q;
        q.push(root);
        while(not q.empty()) {
            TreeNode* curr = q.front(); q.pop(); 
            
            if(curr->val == start) target = curr;
            
            if(curr->left != nullptr) {
                q.push(curr->left);
                parent_track[curr->left] = curr;
            }
            if(curr->right != nullptr) {
                q.push(curr->right);
                parent_track[curr->right] = curr;
            }
        }
        
        q.push(target);
        int count = 0; 
        vis[target] = true;
        
        while(not q.empty()) {
            count++;
            int sz = q.size(); 
            
            for(int i=0; i<sz; i++) {
                TreeNode* curr = q.front(); q.pop(); 
                
                if(curr->left and vis[curr->left] == false) {
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if(curr->right and vis[curr->right] == false) {
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if(parent_track[curr] and vis[parent_track[curr]] == false) {
                    q.push(parent_track[curr]);
                    vis[parent_track[curr]] = true;
                }
            }
        }
        
        return count-1;
    }
};