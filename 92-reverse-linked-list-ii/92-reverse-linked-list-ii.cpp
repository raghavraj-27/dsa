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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cnt = 0;
        ListNode* ptr = head, *prev = NULL; 
        
        while(cnt < left-1) {
            cnt++;
            prev = ptr;
            ptr = ptr->next;
        }
        
        ListNode* dummy = new ListNode(); 
        dummy->next = ptr; 
        ListNode *cur = dummy, *pre = dummy, *nex = dummy;
        cur = pre->next;
        nex = cur->next;
        
        for(int i=0; i<right-left; i++) {
            cur->next = nex->next; 
            nex->next = pre->next;
            pre->next = nex; 
            nex = cur->next;
            // prev->next = dummy->next;
        }
        if(prev != nullptr) {
            prev->next = dummy->next;
            return head;
        }
        
        return dummy->next;
    }
};