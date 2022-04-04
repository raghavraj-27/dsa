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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* ptr = head;
        vector<int> arr = {-1};
        int len = 0;
        while(ptr != nullptr) {
            arr.push_back(ptr->val);
            len++;
            ptr = ptr->next;
        }
        
        swap(arr[k], arr[len-k+1]);
        
        ptr = head;
        int i = 1;
        while(ptr != nullptr) {
            ptr->val = arr[i];
            i++;
            ptr = ptr->next;
        }
        
        return head;
    }
};