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
     int widthOfBinaryTree(TreeNode* root) {
        vector<int> leftmost, rightmost, leftmost_parent;
        stack<tuple<TreeNode*, int, int>> nodes;
        nodes.push(make_tuple(root, 0, 0));
        int fixed_index;
        
        
        while(!nodes.empty()){
            auto node = nodes.top();
            nodes.pop();
            
            TreeNode* cur = get<0>(node);
            int index=get<1>(node), depth = get<2>(node);
            
            if (depth == leftmost.size()){
                leftmost.push_back(index);
                rightmost.push_back(index);
            }
            else{
                rightmost[depth] = index;
            }
            
            if(cur->right || cur->left){
                
                if(depth == leftmost_parent.size()){
                    leftmost_parent.push_back(index);
                }
                fixed_index = index-leftmost_parent[depth];
                
            }
            
            if(cur->right){
                nodes.push(make_tuple(cur->right, 2*fixed_index+1, depth+1));
            }
            
            if(cur->left){
                nodes.push(make_tuple(cur->left, 2*fixed_index, depth+1));
            }
            
        }
        
        int max_width = 0;
        
        for(int i=0;i<leftmost.size();i++){
            max_width = max(rightmost[i]-leftmost[i]+1, max_width);
        }
        return max_width;
    }

    /*
    void setTheTree(TreeNode* root) {
        if(root == NULL) return;
        if(root->left == NULL and root->right == NULL) return;
        
        if(root->left == NULL) {
            root->left = new TreeNode(1000);
            setTheTree(root->right);
            return;
        }
        
        if(root->right == NULL) {
            root->right = new TreeNode(1000);
            setTheTree(root->left);
            return;
        }
        
        setTheTree(root->left);
        setTheTree(root->right);
    }  
    int findHeight(TreeNode* root) {
        if(root == NULL) return 0;
        return max(findHeight(root->left), findHeight(root->right)) + 1;
    }
    int calcLevel(TreeNode* root, int h, int nodes) {
        if(root == NULL) return 0;
        if(h == 1) return 1;
        int a = calcLevel(root->left, h-1, nodes);
        int b = calcLevel(root->right, h-1, nodes);
        return a + b;
    }
    int widthOfBinaryTree(TreeNode* root) {
        int height = findHeight(root);
        setTheTree(root);
        
        int ans = INT_MIN;
        for(int i=1; i<=height; i++) {
            // vector<int> v = calcLevel(root, i);
            ans = max(ans, calcLevel(root, i, 0));
        }
        
        return ans;
    }
    */
};