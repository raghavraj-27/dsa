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
class NodeValue {
public:
    int maxSum, minVal, maxVal;
    NodeValue(int minVal, int maxVal, int maxSum) {
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->maxSum = maxSum;
    }
};

class Solution {
public:
    int sum;
    NodeValue findMaxSum(TreeNode* node) {
        if(node == nullptr) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        auto l = findMaxSum(node->left);
        auto r = findMaxSum(node->right);
        
        if(l.maxVal < node->val and node->val < r.minVal) {
            sum = max(sum, l.maxSum + r.maxSum + node->val);
            return NodeValue(min(l.minVal, node->val), max(node->val, r.maxVal), l.maxSum + r.maxSum + node->val);
        }
        
        return NodeValue(INT_MIN, INT_MAX, max(l.maxSum, r.maxSum));
    }
    
    int maxSumBST(TreeNode* root) {
        sum = 0;
        auto obj = findMaxSum(root);
        return sum;
        // return obj.maxSum;
    }
};