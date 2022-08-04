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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // [verticle][level] = {node1, node2, ... nodek}
        map<int, map<int, multiset<int>>> mp;

        // pq value = {node, {verticle, level}}
        queue<pair<TreeNode*, pair<int, int>>> pq;

        pq.push({root, {0, 0}});

        while(not pq.empty()) {
            TreeNode* curr = pq.front().first;
            // verticle axis
            int x = pq.front().second.first;
            // level axis
            int y = pq.front().second.second;

            pq.pop();
            mp[x][y].insert(curr->val);

            if(curr->left != nullptr) {
                pq.push({curr->left, {x-1, y+1}});
            } 
            if(curr->right != nullptr) {
                pq.push({curr->right, {x+1, y+1}});
            }
        }

        vector<vector<int>> ans;
        // for each verticle col
        for(auto p: mp) {
            vector<int> col;
            // take all the levels
            for(auto q: p.second) {
                // insert it into the column for this particular verticle line
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};