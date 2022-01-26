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
    void pushLeft(stack<TreeNode*>& st, TreeNode* node) {
        while(node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> st1, st2;
        vector<int> ans;
        pushLeft(st1, root1);
        pushLeft(st2, root2);
        
        while(not st1.empty() or not st2.empty()) 
        {
            stack<TreeNode*>& s = st1.empty() ? st2 : st2.empty() ? st1 : 
            st1.top()->val < st2.top()->val ? st1 : st2;
            
            auto node = s.top(); s.pop();
            ans.push_back(node->val);
            pushLeft(s, node->right);
        }
        
        return ans;
    }
};