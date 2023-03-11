/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* f(ListNode* low, ListNode* high) {
        if(low == high) return nullptr;
        
        // if(low == high) {
        //     TreeNode* new_node = new TreeNode(low->val);
        //     return new_node;
        // }
        
        ListNode* slow = low, *fast = low;
        ListNode* prev = nullptr;
        while(fast != high and fast->next != high) {
            slow = slow->next;
            fast = fast->next->next;
            prev = slow;
        }
        
        TreeNode* new_node = new TreeNode(slow->val);
        new_node->left = f(low, slow);
        new_node->right = f(slow->next, high);
        return new_node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return f(head, nullptr);
    }
};