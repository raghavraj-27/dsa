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
    int camera;
    
    // Greedy approach using post order traversal
    // 0 -> I am covered 
    // 1 -> I have camera
    // -1 -> I need camera
    
    int minCameraCover_(TreeNode* root) {
        // When there is NULL on either side, that means there is not need to look
        // It will tell I am covered
        if(root == nullptr) return 0;
        
        int lchild = minCameraCover_(root->left);
        int rchild = minCameraCover_(root->right);
        
        // if any of my child needs a camera, I will afford camera and fit that in myself
        if(lchild == -1 or rchild == -1) {
            camera++;
            return 1;
        }
        
        // If any of my child has a camera already, I will say I am covered
        if(lchild == 1 or rchild == 1) {
            return 0;
        }
        
        // Else neither I am covered, not I have a camera, that means I needed to be covered
        return -1;
    }
    
    int minCameraCover(TreeNode* root) {
        camera = 0;
        
        // If root itself needed to be covered, then it till say I need a camera
        if(minCameraCover_(root) == -1) camera++;
        return camera;
    }
};