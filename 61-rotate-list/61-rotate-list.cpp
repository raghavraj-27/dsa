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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        if(k == 0 or head->next == nullptr) return head;
        if(head->next == nullptr) return head;
        
        int len = 0;
        ListNode *ptr = head;
        while(ptr != nullptr) {
            len++;
            ptr = ptr->next;
        }
        
        if(k == len) return head;
        if(k > len) k = k%len;
        if(k == 0) return head;
        
        int last = len - k;
        ptr = head;
        while(last > 1) {
            ptr = ptr->next;
            last--;
        }
        // cout<<ptr->val;
        ListNode* myHead = ptr->next, *prev = ptr;
        ptr = ptr->next;
        prev->next = nullptr;
        
        while(ptr->next != nullptr) {
            ptr = ptr->next;
        }
        
        ptr->next = head;
        
        return myHead;
    }
};