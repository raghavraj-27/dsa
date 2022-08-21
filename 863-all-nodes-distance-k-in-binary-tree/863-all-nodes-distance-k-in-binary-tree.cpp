/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        unordered_map<TreeNode*, bool> vis;
        
        queue<TreeNode*> q;
        q.push(root);
        while(not q.empty()) {
            TreeNode* curr = q.front(); q.pop(); 
            
            if(curr->left != nullptr) {
                q.push(curr->left);
                parent_track[curr->left] = curr;
            }
            if(curr->right != nullptr) {
                q.push(curr->right);
                parent_track[curr->right] = curr;
            }
        }
        
        vis[target] = true;
        q.push(target);
        int currLevel = 0;
        while(not q.empty()) {
            
            if(currLevel == k) {
                break;
            }
            currLevel++;
            
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
        
        vector<int> res;
        while(not q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }
        
        return res;
    }
};