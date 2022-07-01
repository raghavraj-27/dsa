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
    TreeNode * root = NULL;
    int recent_ind = 0; 
    
    TreeNode * buildTree(TreeNode * r, int value)
    {
        if(r==NULL) 
        {
            TreeNode * new_node = new TreeNode(value);
            return new_node;
        }
        
        if(r->val > value)
            r->left = buildTree(r->left, value);
        else if(r->val < value)
            r->right = buildTree(r->right, value);
        
        return r;
    }
    
    int search(int val, int start, int end, vector<int> & inorder) 
    {
        if(start == end) 
            return start; 
        
        int mid = (start + end) / 2; 
        
        if(inorder[mid] == val)
            return mid;
        
        if(inorder[mid] < val)
            return search(val, mid+1, end, inorder);
       
        return search(val, start, mid-1, inorder);
    }
    
    void traverse(int i, int size, int start, int end, vector<int> & preorder, 
                  vector<int> & inorder) 
    {
        if(i >= size) return;
        if(end < start) return;
        if(preorder[i] == -1) return;
        
        int ind = search(preorder[i], start, end, inorder);
        root = buildTree(root, preorder[i]); 
        preorder[i] = -1; 
        recent_ind = i; 
        
        traverse(recent_ind+1, size, start, ind-1, preorder, inorder);
        traverse(recent_ind+1, size, ind+1, end, preorder, inorder);
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        
        vector<int> inorder(preorder.begin(), preorder.end());
        sort(inorder.begin(), inorder.end());
        
        traverse(0, n, 0, n-1, preorder, inorder);
        
        return root;
    }
};