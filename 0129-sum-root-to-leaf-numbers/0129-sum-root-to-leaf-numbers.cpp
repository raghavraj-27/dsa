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
    vector<int> num;
    
    void f(TreeNode* node, string s) {
        if(node == nullptr) return;
        
        if(node->left == nullptr and node->right == nullptr) {
            num.push_back(stoi(s + to_string(node->val)));
            return;
        }
        
        string currVal = s + to_string(node->val);
        f(node->left, currVal);
        f(node->right, currVal);
    }
    
    int sumNumbers(TreeNode* root) {
        num.clear();
        f(root, "");
        
        // int sum = atoi(numString[0]);
        // for(int i=1; i<numString.size(); i++) {
        //     sum += atoi(numString[i]);
        // }
        // return sum;
        return accumulate(num.begin(), num.end(), 0);
    }
};