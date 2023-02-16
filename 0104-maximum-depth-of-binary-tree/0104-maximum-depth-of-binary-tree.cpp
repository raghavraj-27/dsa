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
    int maxDepth(TreeNode* root) {
        if( root == nullptr ){
            return 0;
        }

        queue<TreeNode *> q;
        q.push(root);

        int level = 0;

        while(q.size() > 0 ){
            int size = q.size();

            while( size-- > 0 ){
                TreeNode *remNode = q.front();
                q.pop();
                
                if(remNode->left != nullptr ){
                    q.push( remNode->left );
                }
                if( remNode->right != nullptr ){
                    q.push( remNode->right );
                }
            }

            level++;
        }

        return level;
    }
};