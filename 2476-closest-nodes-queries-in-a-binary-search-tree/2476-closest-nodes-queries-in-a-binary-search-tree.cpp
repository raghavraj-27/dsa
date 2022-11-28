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
    void inorder(TreeNode* node, vector<int>& v) {
        if(node == nullptr) return;
        inorder(node->left, v);
        v.push_back(node->val);
        inorder(node->right, v);
    }
    int lower(vector<int>& v, int q) {
        int ans = -1;
        int low = 0, high = v.size()-1;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            
            if(v[mid] <= q) {
                ans = max(ans, v[mid]);
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        
        return ans;
    }
    int upper(vector<int>& v, int q) {
        int ans = INT_MAX;
        int low = 0, high = v.size()-1;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            
            if(v[mid] >= q) {
                ans = min(ans, v[mid]);
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        
        return ans==INT_MAX ? -1 : ans;
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        int n = queries.size();
        vector<vector<int>> ans(n, vector<int> (2, 0));
        
        vector<int> v;
        inorder(root, v);
        
        for(int i=0; i<n; i++) {
            ans[i][0] = lower(v, queries[i]);
            ans[i][1] = upper(v, queries[i]);
        }
        
        return ans;
    }
};