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
    map<int, int> inorderIndex, preorderIndex;
    
    TreeNode * buildingTree(int start, int end, vector<int> & inorder, vector<int> & preorder) 
    {
        if(start>end or end<0 or start>=inorder.size())
            return NULL; 
        
        if(start == end) 
        {
            TreeNode * new_node = new TreeNode(inorder[start]);
            return new_node;
        }
        
        int minIndex = INT_MAX;
        int ind;
        for(int i=start; i<=end; i++) 
        {
            if(minIndex > preorderIndex[inorder[i]])
            {
                minIndex = preorderIndex[inorder[i]]; 
                ind = i;
            }
        }
        
        TreeNode * new_node = new TreeNode(preorder[minIndex]);
        
        new_node->left = buildingTree(start, ind-1, inorder, preorder); 
        new_node->right = buildingTree(ind+1, end, inorder, preorder);
        
        return new_node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        TreeNode * root = new TreeNode(preorder[0]);
        if(preorder.size() == 1) {
            return root;
        }
        
        for(int i=0; i<inorder.size(); i++) 
        {
            inorderIndex[inorder[i]] = i;
            preorderIndex[preorder[i]] = i;
        }    
        
        int ind = inorderIndex[root->val]; 
        root->left = buildingTree(0, ind-1, inorder, preorder);
        root->right = buildingTree(ind+1, inorder.size()-1, inorder, preorder);
        
        return root;
    }
};