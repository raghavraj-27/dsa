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
    int minNode, maxNode, maxSum;
    NodeValue(int minNode, int maxNode, int maxSum) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSum = maxSum;
    }
};

class Solution {
public:
    int sum;
    NodeValue largestBSTsubtreeHeight(TreeNode* node) {
        if(node == nullptr) 
            return NodeValue(INT_MAX, INT_MIN, 0);
        
        auto l = largestBSTsubtreeHeight(node->left);
        auto r = largestBSTsubtreeHeight(node->right);
        
        if(l.maxNode < node->val and node->val < r.minNode) {
            sum = max(sum, l.maxSum + r.maxSum + node->val);
            return NodeValue(min(l.minNode, node->val), max(r.maxNode, node->val), l.maxSum + r.maxSum + node->val);
        }
        
        return NodeValue(INT_MIN, INT_MAX, max(l.maxSum, r.maxSum));
    }
    int maxSumBST(TreeNode* root) {
        sum = 0;
        auto ans = largestBSTsubtreeHeight(root);
        return sum;
    }
};