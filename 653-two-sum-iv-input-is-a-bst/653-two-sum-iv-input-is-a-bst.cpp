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
class BSTiterator {
public:
    bool reverse;
    stack<TreeNode *> st;
    
    BSTiterator(TreeNode* node, bool isReverse) {
        reverse = isReverse;
        pushAll(node);
    }
    
    void pushAll(TreeNode* node) {
        while(node != nullptr) {
            st.push(node);
            if(reverse == true) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
    }
    
    bool hasNext() {
        return not st.empty();
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        if(reverse == true) {
            pushAll(node->left);
        } else {
            pushAll(node->right);
        }
        return node->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;
        
        BSTiterator l(root, false);
        BSTiterator r(root, true);
        
        int i = l.next();
        int j = r.next();
        
        while(i < j) {
            if(i + j == k) return true;
            if(i + j < k) i = l.next();
            if(i + j > k) j = r.next();
        }
        
        return false;
    }
};